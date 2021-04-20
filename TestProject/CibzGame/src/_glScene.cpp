#include "_glScene.h"
#include <_glLight.h>
#include <SOIL.h>

_glScene::_glScene()
{
    //ctor
}

_glScene::~_glScene()
{
    //dtor
}
GLint _glScene::initGL()
{
    glShadeModel(GL_SMOOTH);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);

    glEnable(GL_COLOR_MATERIAL);
    _glLight myLight(GL_LIGHT0);

    //modelTex->loadTexture("images/SkyrimBackground.jpg");
    backGround->parallaxInit("images/dungeonFloor.jpg", 10.0, 5.0);
    backGround1->parallaxInit("images/visibility.png");
    backGround1->plxPos.z = -2.0;

    timer->startTimer();

    myPly->playerInit(9, 3);
    myPly->plyImage->loadTexture("images/knight.png");

    arrow->arrowInit();
    arrow->arwImage->loadTexture("images/arrow.png");

    fnts->initFonts("images/fantasyfont.png");
    fnts->buildFont(" ]Level 1]", 9.0);

    numOfEnms = 5;
    texEnms->loadTexture("images/zombie_n_skeleton2.png");
    for(int i = 0; i < numOfEnms; i++){
        enms[i].tex = texEnms->tex;
        enms[i].posE.x = (float)rand()/float(RAND_MAX) * 5.0 - 3.0;
        enms[i].posE.y = (float)rand()/float(RAND_MAX) * 5.0 - 3.0;
        //enms[i].posE.z =

        enms[i].placeEnms(enms[i].posE);
        enms[i].sizeE.y = enms[i].sizeE.x = 0.3;    //(float)(rand() % 12)/50.0;
    }

    return true;

}

GLint _glScene::drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    glLoadIdentity();

    gluLookAt(0.0, 0.0, 1.0, 0.0, 0.0,0.0, 0.0, 1.0, 0.0);
    glScalef(285.0, 285.0, 1.0);

    //Background
    glPushMatrix();
        glScalef(5.0, 5.0, 1.0);
        glBindTexture(GL_TEXTURE_2D, backGround->plxTexture->tex);
        backGround->scroll(0.005);
        backGround->renderBack(screenWidth, screenHeight);
    glPopMatrix();

    //backGround1->scroll(false, "left", 0.003);

    //Player
    glPushMatrix();
        //glScalef(2.0, 2.0, 1.0);
        glBindTexture(GL_TEXTURE_2D, myPly->plyImage->tex);
        glTranslatef(myPly->playerPos.x , myPly->playerPos.y, myPly->playerPos.z);
        myPly->drawPlayer();


    if(timer->getTicks() > 150)
    {
        myPly->actions();
        timer->resetTime();
    }
    glPopMatrix();

    //Enemies
    for(int i = 0; i < numOfEnms; i++){
        if(enms[i].posE.x > 5.0){
            enms[i].actionTrigger = enms[i].LEFT;           //Enemy moving Left
            enms[i].facingDirection = enms[i].LEFT;
            enms[i].xSpeed = -0.004;
        }
        else if(enms[i].posE.x < -5.0){
            enms[i].actionTrigger = enms[i].RIGHT;          //Enemy moving Right
            enms[i].facingDirection = enms[i].RIGHT;
            enms[i].xSpeed =  0.004;
        }
        else if(enms[i].posE.y < -5.0){
            enms[i].actionTrigger = enms[i].UP;             //Enemy moving Up
            enms[i].facingDirection = enms[i].UP;
            enms[i].ySpeed =  0.004;
        }
        else if(enms[i].posE.y > 5.0){
            enms[i].actionTrigger = enms[i].DOWN;           //Enemy moving Down
            enms[i].facingDirection = enms[i].DOWN;
            enms[i].ySpeed = -0.004;
        }

        enms[i].moveCausedByPlayer();                                   //Enemy moving in relation to Player movements: setting values for xSpeed2 and ySpeed2
        enms[i].randAction();                                           //Random Enemy movement: setting values for xSpeed and ySpeed
        enms[i].posE.x += (enms[i].xSpeed + enms[i].xSpeed2);           //Enemy Total X movement
        enms[i].posE.y += (enms[i].ySpeed + enms[i].ySpeed2);           //Enemy Total Y movement
        if(myPly->isAttacking && myPly->playerPos.x){
            if(collided->detectCollision(myPly->playerPos.x, myPly->playerPos.y, myPly->radiusPlayer,
                                          enms[i].posE.x, enms[i].posE.y, enms[i].radiusEnemy))
        }

        enms[i].actionsEnms();                                          //Changing Animation to match Enemy's Random movement
        enms[i].drawEnms();                                             //Draw enemies
    }


    //ARROW ROTATION
    glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, arrow->arwImage->tex);
        //arrow->drawArrow();
    glPopMatrix();

    //Background1
    glPushMatrix();
        //glTranslatef(0.0, 0.0, backGround1->plxPos.z);
        glScalef(5.0, 5.0, 1.0);

        glBindTexture(GL_TEXTURE_2D, backGround1->plxTexture->tex);
        backGround1->renderBack(screenWidth, screenHeight);
    glPopMatrix();

    //Fonts
    glPushMatrix();
        //Need to make use an expendable character to translate line of character
        glColor3f(1.0, 0.0, 0.0);
        glTranslatef(-9.0, 4.0, 1.0);
        fnts->drawFonts();
    glPopMatrix();
}

void _glScene::resizeGLScene(int width, int height)
{
    screenWidth = width;
    screenHeight = height;

    float aspectRatio = (float)width/(float)height;

    glViewport(0.0, 0.0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //gluPerspective(45.0, aspectRatio, 0.1, 100.0);              //Can change this to glOrtho()
    glOrtho(-width, width, -height, height, 0.1, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}
///*
int _glScene::winMsg(	HWND	hWnd,			// Handle For This Window
							UINT	uMsg,			// Message For This Window
							WPARAM	wParam,			// Additional Message Information
							LPARAM	lParam)
{
    kbMs->wParam = wParam;

    switch (uMsg)									// Check For Windows Messages
	{
		case WM_KEYDOWN:							// Is A Key Being Held Down?
		{
		    kbMs->keyPressed(modelTeapot);
		    //kbMs->keyPressed(myPly);
            //for(int j = 0; j < numOfEnms; j++)
            kbMs->moveEnv(backGround, myPly, enms, numOfEnms, 0.005);
		    //kbMs->spotLight(backGround1, myPly);
			break;
		}

		case WM_KEYUP:								// Has A Key Been Released?
		{
		    kbMs->keyUp();
            kbMs->keyUp(myPly, backGround, enms, numOfEnms);
            break;
		}

		case WM_LBUTTONDOWN:                        //Left mouse button down
        {
            kbMs->mouseDown(modelTeapot, LOWORD(lParam), HIWORD(lParam));
            kbMs->mouseDown(myPly, backGround, LOWORD(lParam), HIWORD(lParam));
            break;
        }

        case WM_RBUTTONDOWN:                        //Right mouse button down
        {
            kbMs->mouseDown(modelTeapot, LOWORD(lParam), HIWORD(lParam));
            kbMs->mouseDown(myPly, backGround, LOWORD(lParam), HIWORD(lParam));
            break;
        }

        case WM_MBUTTONDOWN:                        //Middle mouse button down
        {
            break;
        }

        case WM_RBUTTONUP:                          //Right mouse button up
        {
            kbMs->mouseUp(myPly, backGround);
        }
        case WM_MBUTTONUP:                          //Middle mouse button up
        {
        }
        case WM_LBUTTONUP:                          //Left mouse button up
        {
            kbMs->mouseUp();
            kbMs->mouseUp(myPly, backGround);
            break;
        }

        case WM_MOUSEMOVE:                          //Detecting mouse movement
        {
            kbMs->mouseMove(modelTeapot, LOWORD(lParam), HIWORD(lParam));
            kbMs->mouseMove(arrow, LOWORD(lParam), HIWORD(lParam));
            break;
        }

        case WM_MOUSEWHEEL:                         //Detection mouse scroll wheel movement
        {
            kbMs->mouseWheel(modelTeapot, (float)GET_WHEEL_DELTA_WPARAM(wParam));
            break;
        }
	}
}

