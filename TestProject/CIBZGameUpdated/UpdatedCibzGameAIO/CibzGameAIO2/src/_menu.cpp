#include "_menu.h"

_menu::_menu()
{
    //ctor
    xMax =1.0;
    yMax =0.0;
    xMin =0.0;
    yMin =1.0;

    newGame = true;
}

_menu::~_menu()
{
    //dtor
}
void _menu::drawSquare(float width, float height, char menuID)
{
    glColor3f(1.0,1.0,1.0);
//    bTex->TextureBinder();
/*
    if(menuID == 'l')
    {
        landingImage->TextureBinder("images/MainMenu.png");
    }

    if(menuID == 'm')
    {
        menuImage->TextureBinder("images/MenuSelection.png");
    }

    if(menuID == 'h')
    {
        helpImage->TextureBinder("images/help.png");
    }

    if(menuID == 'p')
    {
        pauseImage->TextureBinder("images/pause.png");
    }

    if(menuID == 'c')
    {
        creditImage->TextureBinder("images/Credits1.png");
    }

*/
    glBegin(GL_POLYGON);
    glTexCoord2f(xMin,yMin);
    glVertex3f(-width/height, -1, -1.0); //glVertex3f(-width/height, -1, -3.0);
    glTexCoord2f(xMax,yMin);
    glVertex3f(width/height, -1, -1.0); //glVertex3f(width/height, -1, -3.0);
    glTexCoord2f(xMax,yMax);
    glVertex3f(width/height, 1, -1.0); //glVertex3f(width/height, 1, -3.0);
    glTexCoord2f(xMin,yMax);
    glVertex3f(-width/height, 1, -1.0); //glVertex3f(-width/height, 1, -3.0);

    glEnd();
}

void _menu::menuInit() //char* fileName
{
    //bTex->loadTexture(fileName);
    landingImage->loadTexture("images/MainMenu.png");
    menuImage->loadTexture("images/MenuSelection.png");
    helpImage->loadTexture("images/help.png");
    pauseImage->loadTexture("images/pause.png");
    creditImage->loadTexture("images/Credits1.png");
    newMenuImage->loadTexture("images/NewMenu.png");

    transition1->loadTexture("images/previewLevel1.png");
    transition2->loadTexture("images/previewLevel2.png");
    transition3->loadTexture("images/previewLevel3.png");
    transition4->loadTexture("images/previewLevel4.png");
    transition5->loadTexture("images/previewLevel5.png");
    gameOverImage->loadTexture("images/GameOver.png");
    gameWinImage->loadTexture("images/GameWin.png");

}
