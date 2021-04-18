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

    timer->startTimer();

    myPly->playerInit(9, 3);
    myPly->plyImage->loadTexture("images/knight.png");

    arrow->arrowInit();
    arrow->arwImage->loadTexture("images/arrow.png");

    fnts->initFonts("images/fantasyfont.png");
    fnts->buildFont(" <[]", 9.0);

    return true;

}

GLint _glScene::drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    glLoadIdentity();

    glScalef(285.0, 285.0, 1.0);

    //Background
    glPushMatrix();
        glScalef(5.0, 5.0, 1.0);
        glBindTexture(GL_TEXTURE_2D, backGround->plxTexture->tex);
        backGround->scroll(0.005);
        backGround->renderBack(screenWidth, screenHeight);
    glPopMatrix();

    //backGround1->scroll(false, "left", 0.003);

    //Background1
    glPushMatrix();
        glScalef(5.0, 5.0, 1.0);
        //glTranslatef(1.0, -4.0, 0.0);
        glBindTexture(GL_TEXTURE_2D, backGround1->plxTexture->tex);
        //backGround1->renderBack(screenWidth, screenHeight);
    glPopMatrix();

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

    //Fonts
    glPushMatrix();
        //Need to make use an expendable character to translate line of character
        glTranslatef(-9.0, 3.0, 1.0);
        fnts->drawFonts();
    glPopMatrix();
    //ARROW ROTATION
    glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, arrow->arwImage->tex);
        //arrow->drawArrow();
    glPopMatrix();

    //glTranslatef(0.5, 0, -8.0);
    //glBindTexture(GL_TEXTURE_2D, tex);
    //glutSolidTorus(0.2, 0.5, 20, 20);


    //Lesson 2 2/12/2021
    //glTranslatef(0.0f, 0.0f, -8.0f);            //PLaced in the screen by translating to coord (0, 0, -8)
    //glColor3f(0.5f, 0.3f, 0.2f);                //Set a color for the object

    //glBindTexture(GL_TEXTURE_2D, modelTex->tex);
    //modelTeapot->drawModel();

    /*
    glPushMatrix();                             //Grouped my object with push Matrix
        glutSolidTeapot(1.5f);                  //Draw object
    glPopMatrix();                              //exit the group
    */
    //End of Lesson 2
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

		    kbMs->moveEnv(backGround, myPly, 0.005);
		    //kbMs->spotLight(backGround1, myPly);
			break;
		}

		case WM_KEYUP:								// Has A Key Been Released?
		{
		    kbMs->keyUp();
		    kbMs->keyUp(myPly, backGround);
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

