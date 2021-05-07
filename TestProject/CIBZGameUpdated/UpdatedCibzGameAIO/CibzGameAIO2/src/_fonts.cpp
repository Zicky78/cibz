#include "_fonts.h"

_fonts::_fonts()
{
    //ctor
    chrCount = 0;
    xRotate = 0;
    yRotate = 0;
    zRotate = 0;

    xPos = 1.5;
    yPos = 0.0;
    zPos = -4.0;
}

_fonts::~_fonts()
{
    //dtor
}

void _fonts::initFonts(char* fileName)
{
    charTex->loadTexture(fileName);

}

void _fonts::buildFont(char* str, float numOfFrames)
{
    frames = numOfFrames;

    chrCount = 0;
    for(int i = 0; i < strlen(str); i++){
        //*
        switch(str[i])
        {
        //Capital Letters
        case 'A':
            chr[chrCount].xMin = 0.1/frames;
            chr[chrCount].xMax = 0.99/frames;

            chr[chrCount].yMin = 0.1/frames;
            chr[chrCount].yMax = 0.99/frames;
            break;

        case 'B':
            chr[chrCount].xMin = 1.1/frames;
            chr[chrCount].xMax = 1.99/frames;

            chr[chrCount].yMin = 0.1/frames;
            chr[chrCount].yMax = 0.99/frames;
            break;

        case 'C':
            chr[chrCount].xMin = 2.1/frames;
            chr[chrCount].xMax = 2.99/frames;

            chr[chrCount].yMin = 0.1/frames;
            chr[chrCount].yMax = 0.99/frames;
            break;

        case 'D':
            chr[chrCount].xMin = 3.1/frames;
            chr[chrCount].xMax = 3.99/frames;

            chr[chrCount].yMin = 0.1/frames;
            chr[chrCount].yMax = 0.99/frames;
            break;

        case 'E':
            chr[chrCount].xMin = 4.1/frames;
            chr[chrCount].xMax = 4.99/frames;

            chr[chrCount].yMin = 0.1/frames;
            chr[chrCount].yMax = 0.99/frames;
            break;

        case 'F':
            chr[chrCount].xMin = 5.1/frames;
            chr[chrCount].xMax = 5.99/frames;

            chr[chrCount].yMin = 0.1/frames;
            chr[chrCount].yMax = 0.99/frames;
            break;

        case 'G':
            chr[chrCount].xMin = 6.1/frames;
            chr[chrCount].xMax = 6.99/frames;

            chr[chrCount].yMin = 0.1/frames;
            chr[chrCount].yMax = 0.99/frames;
            break;

        case 'H':
            chr[chrCount].xMin = 7.1/frames;
            chr[chrCount].xMax = 7.99/frames;

            chr[chrCount].yMin = 0.1/frames;
            chr[chrCount].yMax = 0.99/frames;
            break;

        case 'I':
            chr[chrCount].xMin = 8.1/frames;
            chr[chrCount].xMax = 8.99/frames;

            chr[chrCount].yMin = 0.1/frames;
            chr[chrCount].yMax = 0.99/frames;
            break;

        case 'J':
            chr[chrCount].xMin = 0.1/frames;
            chr[chrCount].xMax = 0.99/frames;

            chr[chrCount].yMin = 1.1/frames;
            chr[chrCount].yMax = 1.99/frames;
            break;

        case 'K':
            chr[chrCount].xMin = 1.1/frames;
            chr[chrCount].xMax = 1.99/frames;

            chr[chrCount].yMin = 1.1/frames;
            chr[chrCount].yMax = 1.99/frames;
            break;

        case 'L':
            chr[chrCount].xMin = 2.1/frames;
            chr[chrCount].xMax = 2.99/frames;

            chr[chrCount].yMin = 1.1/frames;
            chr[chrCount].yMax = 1.99/frames;
            break;

        case 'M':
            chr[chrCount].xMin = 3.1/frames;
            chr[chrCount].xMax = 3.99/frames;

            chr[chrCount].yMin = 1.1/frames;
            chr[chrCount].yMax = 1.99/frames;
            break;

        case 'N':
            chr[chrCount].xMin = 4.1/frames;
            chr[chrCount].xMax = 4.99/frames;

            chr[chrCount].yMin = 1.1/frames;
            chr[chrCount].yMax = 1.99/frames;
            break;

        case 'O':
            chr[chrCount].xMin = 5.1/frames;
            chr[chrCount].xMax = 5.99/frames;

            chr[chrCount].yMin = 1.1/frames;
            chr[chrCount].yMax = 1.99/frames;
            break;

        case 'P':
            chr[chrCount].xMin = 6.1/frames;
            chr[chrCount].xMax = 6.99/frames;

            chr[chrCount].yMin = 1.1/frames;
            chr[chrCount].yMax = 1.99/frames;
            break;

        case 'Q':
            chr[chrCount].xMin = 7.1/frames;
            chr[chrCount].xMax = 7.99/frames;

            chr[chrCount].yMin = 1.1/frames;
            chr[chrCount].yMax = 1.99/frames;
            break;

        case 'R':
            chr[chrCount].xMin = 8.1/frames;
            chr[chrCount].xMax = 8.99/frames;

            chr[chrCount].yMin = 1.1/frames;
            chr[chrCount].yMax = 1.99/frames;
            break;

        case 'S':
            chr[chrCount].xMin = 0.1/frames;
            chr[chrCount].xMax = 0.99/frames;

            chr[chrCount].yMin = 2.1/frames;
            chr[chrCount].yMax = 2.99/frames;
            break;

        case 'T':
            chr[chrCount].xMin = 1.1/frames;
            chr[chrCount].xMax = 1.99/frames;

            chr[chrCount].yMin = 2.1/frames;
            chr[chrCount].yMax = 2.99/frames;
            break;

        case 'U':
            chr[chrCount].xMin = 2.1/frames;
            chr[chrCount].xMax = 2.99/frames;

            chr[chrCount].yMin = 2.1/frames;
            chr[chrCount].yMax = 2.99/frames;
            break;

        case 'V':
            chr[chrCount].xMin = 3.1/frames;
            chr[chrCount].xMax = 3.99/frames;

            chr[chrCount].yMin = 2.1/frames;
            chr[chrCount].yMax = 2.99/frames;
            break;

        case 'W':
            chr[chrCount].xMin = 4.1/frames;
            chr[chrCount].xMax = 4.99/frames;

            chr[chrCount].yMin = 2.1/frames;
            chr[chrCount].yMax = 2.99/frames;
            break;

        case 'X':
            chr[chrCount].xMin = 5.1/frames;
            chr[chrCount].xMax = 5.99/frames;

            chr[chrCount].yMin = 2.1/frames;
            chr[chrCount].yMax = 2.99/frames;
            break;

        case 'Y':
            chr[chrCount].xMin = 6.1/frames;
            chr[chrCount].xMax = 6.99/frames;

            chr[chrCount].yMin = 2.1/frames;
            chr[chrCount].yMax = 2.99/frames;
            break;

        case 'Z':
            chr[chrCount].xMin = 7.1/frames;
            chr[chrCount].xMax = 7.99/frames;

            chr[chrCount].yMin = 2.1/frames;
            chr[chrCount].yMax = 2.99/frames;
            break;
        //End of Capital Letters

        //Lower Case Letters
        case 'a':
            chr[chrCount].xMin = 0.1/frames;
            chr[chrCount].xMax = 0.99/frames;

            chr[chrCount].yMin = 3.1/frames;
            chr[chrCount].yMax = 3.99/frames;
            break;

        case 'b':
            chr[chrCount].xMin = 1.1/frames;
            chr[chrCount].xMax = 1.99/frames;

            chr[chrCount].yMin = 3.1/frames;
            chr[chrCount].yMax = 3.99/frames;
            break;

        case 'c':
            chr[chrCount].xMin = 2.1/frames;
            chr[chrCount].xMax = 2.99/frames;

            chr[chrCount].yMin = 3.1/frames;
            chr[chrCount].yMax = 3.99/frames;
            break;

        case 'd':
            chr[chrCount].xMin = 3.1/frames;
            chr[chrCount].xMax = 3.99/frames;

            chr[chrCount].yMin = 3.1/frames;
            chr[chrCount].yMax = 3.99/frames;
            break;

        case 'e':
            chr[chrCount].xMin = 4.1/frames;
            chr[chrCount].xMax = 4.99/frames;

            chr[chrCount].yMin = 3.1/frames;
            chr[chrCount].yMax = 3.99/frames;
            break;

        case 'f':
            chr[chrCount].xMin = 5.1/frames;
            chr[chrCount].xMax = 5.99/frames;

            chr[chrCount].yMin = 3.1/frames;
            chr[chrCount].yMax = 3.99/frames;
            break;

        case 'g':
            chr[chrCount].xMin = 6.1/frames;
            chr[chrCount].xMax = 6.99/frames;

            chr[chrCount].yMin = 3.1/frames;
            chr[chrCount].yMax = 3.99/frames;
            break;

        case 'h':
            chr[chrCount].xMin = 7.1/frames;
            chr[chrCount].xMax = 7.99/frames;

            chr[chrCount].yMin = 3.1/frames;
            chr[chrCount].yMax = 3.99/frames;
            break;

        case 'i':
            chr[chrCount].xMin = 8.1/frames;
            chr[chrCount].xMax = 8.99/frames;

            chr[chrCount].yMin = 3.1/frames;
            chr[chrCount].yMax = 3.99/frames;
            break;

        case 'j':
            chr[chrCount].xMin = 0.1/frames;
            chr[chrCount].xMax = 0.99/frames;

            chr[chrCount].yMin = 4.1/frames;
            chr[chrCount].yMax = 4.99/frames;
            break;

        case 'k':
            chr[chrCount].xMin = 1.1/frames;
            chr[chrCount].xMax = 1.99/frames;

            chr[chrCount].yMin = 4.1/frames;
            chr[chrCount].yMax = 4.99/frames;
            break;

        case 'l':
            chr[chrCount].xMin = 2.1/frames;
            chr[chrCount].xMax = 2.99/frames;

            chr[chrCount].yMin = 4.1/frames;
            chr[chrCount].yMax = 4.99/frames;
            break;

        case 'm':
            chr[chrCount].xMin = 3.1/frames;
            chr[chrCount].xMax = 3.99/frames;

            chr[chrCount].yMin = 4.1/frames;
            chr[chrCount].yMax = 4.99/frames;
            break;

        case 'n':
            chr[chrCount].xMin = 4.1/frames;
            chr[chrCount].xMax = 4.99/frames;

            chr[chrCount].yMin = 4.1/frames;
            chr[chrCount].yMax = 4.99/frames;
            break;

        case 'o':
            chr[chrCount].xMin = 5.1/frames;
            chr[chrCount].xMax = 5.99/frames;

            chr[chrCount].yMin = 4.1/frames;
            chr[chrCount].yMax = 4.99/frames;
            break;

        case 'p':
            chr[chrCount].xMin = 6.1/frames;
            chr[chrCount].xMax = 6.99/frames;

            chr[chrCount].yMin = 4.1/frames;
            chr[chrCount].yMax = 4.99/frames;
            break;

        case 'q':
            chr[chrCount].xMin = 7.1/frames;
            chr[chrCount].xMax = 7.99/frames;

            chr[chrCount].yMin = 4.1/frames;
            chr[chrCount].yMax = 4.99/frames;
            break;

        case 'r':
            chr[chrCount].xMin = 8.1/frames;
            chr[chrCount].xMax = 8.99/frames;

            chr[chrCount].yMin = 4.1/frames;
            chr[chrCount].yMax = 4.99/frames;
            break;

        case 's':
            chr[chrCount].xMin = 0.1/frames;
            chr[chrCount].xMax = 0.99/frames;

            chr[chrCount].yMin = 5.1/frames;
            chr[chrCount].yMax = 5.99/frames;
            break;

        case 't':
            chr[chrCount].xMin = 1.1/frames;
            chr[chrCount].xMax = 1.99/frames;

            chr[chrCount].yMin = 5.1/frames;
            chr[chrCount].yMax = 5.99/frames;
            break;

        case 'u':
            chr[chrCount].xMin = 2.1/frames;
            chr[chrCount].xMax = 2.99/frames;

            chr[chrCount].yMin = 5.1/frames;
            chr[chrCount].yMax = 5.99/frames;
            break;

        case 'v':
            chr[chrCount].xMin = 3.1/frames;
            chr[chrCount].xMax = 3.99/frames;

            chr[chrCount].yMin = 5.1/frames;
            chr[chrCount].yMax = 5.99/frames;
            break;

        case 'w':
            chr[chrCount].xMin = 4.1/frames;
            chr[chrCount].xMax = 4.99/frames;

            chr[chrCount].yMin = 5.1/frames;
            chr[chrCount].yMax = 5.99/frames;
            break;

        case 'x':
            chr[chrCount].xMin = 5.1/frames;
            chr[chrCount].xMax = 5.99/frames;

            chr[chrCount].yMin = 5.1/frames;
            chr[chrCount].yMax = 5.99/frames;
            break;

        case 'y':
            chr[chrCount].xMin = 6.1/frames;
            chr[chrCount].xMax = 6.99/frames;

            chr[chrCount].yMin = 5.1/frames;
            chr[chrCount].yMax = 5.99/frames;
            break;

        case 'z':
            chr[chrCount].xMin = 7.1/frames;
            chr[chrCount].xMax = 7.99/frames;

            chr[chrCount].yMin = 5.1/frames;
            chr[chrCount].yMax = 5.99/frames;
            break;
        //End of Lower case Letters

        //Numbers 0 - 9
        case '0':
            chr[chrCount].xMin = 0.1/frames;
            chr[chrCount].xMax = 0.99/frames;

            chr[chrCount].yMin = 6.1/frames;
            chr[chrCount].yMax = 6.99/frames;
            break;

        case '1':
            chr[chrCount].xMin = 1.1/frames;
            chr[chrCount].xMax = 1.99/frames;

            chr[chrCount].yMin = 6.1/frames;
            chr[chrCount].yMax = 6.99/frames;
            break;

        case '2':
            chr[chrCount].xMin = 2.1/frames;
            chr[chrCount].xMax = 2.99/frames;

            chr[chrCount].yMin = 6.1/frames;
            chr[chrCount].yMax = 6.99/frames;
            break;

        case '3':
            chr[chrCount].xMin = 3.1/frames;
            chr[chrCount].xMax = 3.99/frames;

            chr[chrCount].yMin = 6.1/frames;
            chr[chrCount].yMax = 6.99/frames;
            break;

        case '4':
            chr[chrCount].xMin = 4.1/frames;
            chr[chrCount].xMax = 4.99/frames;

            chr[chrCount].yMin = 6.1/frames;
            chr[chrCount].yMax = 6.99/frames;
            break;

        case '5':
            chr[chrCount].xMin = 5.1/frames;
            chr[chrCount].xMax = 5.99/frames;

            chr[chrCount].yMin = 6.1/frames;
            chr[chrCount].yMax = 6.99/frames;
            break;

        case '6':
            chr[chrCount].xMin = 6.1/frames;
            chr[chrCount].xMax = 6.99/frames;

            chr[chrCount].yMin = 6.1/frames;
            chr[chrCount].yMax = 6.99/frames;
            break;

        case '7':
            chr[chrCount].xMin = 7.1/frames;
            chr[chrCount].xMax = 7.99/frames;

            chr[chrCount].yMin = 6.1/frames;
            chr[chrCount].yMax = 6.99/frames;
            break;

        case '8':
            chr[chrCount].xMin = 8.1/frames;
            chr[chrCount].xMax = 8.99/frames;

            chr[chrCount].yMin = 6.1/frames;
            chr[chrCount].yMax = 6.99/frames;
            break;

        case '9':
            chr[chrCount].xMin = 0.1/frames;
            chr[chrCount].xMax = 0.99/frames;

            chr[chrCount].yMin = 7.1/frames;
            chr[chrCount].yMax = 7.99/frames;
            break;
        //End of Numbers

        //Special Characters
        case ' ':                                       //Space
            chr[chrCount].xMin = 8.1/frames;
            chr[chrCount].xMax = 8.99/frames;

            chr[chrCount].yMin = 2.1/frames;
            chr[chrCount].yMax = 2.99/frames;
            break;

        case '.':
            chr[chrCount].xMin = 1.1/frames;
            chr[chrCount].xMax = 1.99/frames;

            chr[chrCount].yMin = 7.1/frames;
            chr[chrCount].yMax = 7.99/frames;
            break;

        case ',':
            chr[chrCount].xMin = 2.1/frames;
            chr[chrCount].xMax = 2.99/frames;

            chr[chrCount].yMin = 7.1/frames;
            chr[chrCount].yMax = 7.99/frames;
            break;

        case ';':
            chr[chrCount].xMin = 3.1/frames;
            chr[chrCount].xMax = 3.99/frames;

            chr[chrCount].yMin = 7.1/frames;
            chr[chrCount].yMax = 7.99/frames;
            break;

        case ':':
            chr[chrCount].xMin = 4.1/frames;
            chr[chrCount].xMax = 4.99/frames;

            chr[chrCount].yMin = 7.1/frames;
            chr[chrCount].yMax = 7.99/frames;
            break;

        case '$':
            chr[chrCount].xMin = 5.1/frames;
            chr[chrCount].xMax = 5.99/frames;

            chr[chrCount].yMin = 7.1/frames;
            chr[chrCount].yMax = 7.99/frames;
            break;

        //Case for special f character (row 8, column 7)
        case '<':
            chr[chrCount].xMin = 6.1/frames;
            chr[chrCount].xMax = 6.99/frames;

            chr[chrCount].yMin = 7.1/frames;
            chr[chrCount].yMax = 7.99/frames;
            break;

        //Case for ' character
        case '[':
            chr[chrCount].xMin = 7.1/frames;
            chr[chrCount].xMax = 7.99/frames;

            chr[chrCount].yMin = 7.1/frames;
            chr[chrCount].yMax = 7.99/frames;
            break;

        case '!':
            chr[chrCount].xMin = 8.1/frames;
            chr[chrCount].xMax = 8.99/frames;

            chr[chrCount].yMin = 7.1/frames;
            chr[chrCount].yMax = 7.99/frames;
            break;

        //Case for " character
        case ']':
            chr[chrCount].xMin = 0.1/frames;
            chr[chrCount].xMax = 0.99/frames;

            chr[chrCount].yMin = 8.1/frames;
            chr[chrCount].yMax = 8.99/frames;
            break;

        case '/':
            chr[chrCount].xMin = 1.1/frames;
            chr[chrCount].xMax = 1.99/frames;

            chr[chrCount].yMin = 8.1/frames;
            chr[chrCount].yMax = 8.99/frames;
            break;

        case '?':
            chr[chrCount].xMin = 2.1/frames;
            chr[chrCount].xMax = 2.99/frames;

            chr[chrCount].yMin = 8.1/frames;
            chr[chrCount].yMax = 8.99/frames;
            break;

        case '%':
            chr[chrCount].xMin = 3.1/frames;
            chr[chrCount].xMax = 3.99/frames;

            chr[chrCount].yMin = 8.1/frames;
            chr[chrCount].yMax = 8.99/frames;
            break;

        case '&':
            chr[chrCount].xMin = 4.1/frames;
            chr[chrCount].xMax = 4.99/frames;

            chr[chrCount].yMin = 8.1/frames;
            chr[chrCount].yMax = 8.99/frames;
            break;

        case '(':
            chr[chrCount].xMin = 5.1/frames;
            chr[chrCount].xMax = 5.99/frames;

            chr[chrCount].yMin = 8.1/frames;
            chr[chrCount].yMax = 8.99/frames;
            break;

        case ')':
            chr[chrCount].xMin = 6.1/frames;
            chr[chrCount].xMax = 6.99/frames;

            chr[chrCount].yMin = 8.1/frames;
            chr[chrCount].yMax = 8.99/frames;
            break;

        case '@':
            chr[chrCount].xMin = 7.1/frames;
            chr[chrCount].xMax = 7.99/frames;

            chr[chrCount].yMin = 8.1/frames;
            chr[chrCount].yMax = 8.99/frames;
            break;
        //End of Special characters
        }
        //*/
        chrCount++;
    }
}

void _fonts::setPosition(int, int)
{
    //place xPos, yPos, zPos
}

void _fonts::drawFonts()
{
    //PLEASE NOTE:
    //      That to translate the positions of instances of fonts drawn
    //      you need to add an expendable character to the char str in
    //      the buildFont function when called in the initialization of
    //      the glScene.cpp

    glColor3f(1.0, 0.0, 0.0);
    glScalef(1.0, 1.0, 1.0);
    glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, charTex->tex);
        glTranslatef(0.0, 0.0, zPos);

        //glLoadIdentity();
        for(int i = 0; i < chrCount; i++){
            glTranslatef(xPos + (-1.0), yPos, 0.0);
            glBegin(GL_QUADS);
                glTexCoord2f(chr[i].xMax, chr[i].yMin);
                glVertex3f( 0.5,  0.5, 0.0);

                glTexCoord2f(chr[i].xMin, chr[i].yMin);
                glVertex3f(-0.5,  0.5, 0.0);

                glTexCoord2f(chr[i].xMin, chr[i].yMax);
                glVertex3f(-0.5, -0.5, 0.0);

                glTexCoord2f(chr[i].xMax, chr[i].yMax);
                glVertex3f( 0.5, -0.5, 0.0);

            glEnd();
            }


    glPopMatrix();
}
