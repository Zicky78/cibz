#ifndef _SHADERS_H
#define _SHADERS_H

#define GLEW_STATIC

#include<GL/glew.h>
#include<string>
#include<iostream>
#include<fstream>

using namespace std;

class _shaders
{
    public:
        _shaders();
        virtual ~_shaders();

        void readFiles(char* , string&);
        unsigned vs, fs, program;
        GLint loc1;
        GLint loc2;
        GLint loc3;

        unsigned int loadShader(string& , unsigned int);
        void initShader(char* ,char*);
        void cleanUp();

    protected:

    private:
};

#endif // _SHADERS_H
