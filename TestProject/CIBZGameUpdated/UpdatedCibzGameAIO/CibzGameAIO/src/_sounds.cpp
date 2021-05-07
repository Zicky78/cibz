#include "_sounds.h"

_sounds::_sounds()
{
    //ctor
}

_sounds::~_sounds()
{
    //dtor
    sndEng->drop();
}

void _sounds::playMusic(char* fileName)
{
    sndEng->play2D(fileName, true);         //true is for repeating the music on a loop
}

void _sounds::playSounds(char* fileName)
{
    sndEng->play2D(fileName, false);
}

void _sounds::pauseSound(char* fileName)
{
    sndEng->play2D(fileName, true, false);
}

void _sounds::stopAllSounds()
{
    sndEng->stopAllSounds();
}

int _sounds::initSounds()
{
    if(!sndEng){
        cout << "Could NOT start Sound Engine/n";
        return 0;
    }
    return 1;
}
