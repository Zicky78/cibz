#ifndef _GLLIGHT_H
#define _GLLIGHT_H
#include<_glScene.h>

class _glLight:_glScene
{
    public:
        _glLight(GLenum light);
        virtual ~_glLight();

        float lightAmbient[4] = {1.0f, 0.0f, 0.0f, 1.0f};                   //Light from the environment
        float lightDiffuse[4] = {1.0f, 1.0f, 1.0f, 1.0f};                   //Shaders or the shadows created by the object due to the lights position (Light * Normals = cos(Theta)
        float lightSpectular[4] = {1.0f, 1.0f, 1.0f, 1.0f};                 //Shininess or reflection of the object due to the lights position
        float lightPosition[4] = {2.0f, 5.0f, 5.0f, 1.0f};

        float matAmbient[4] {0.7f, 0.7f, 0.7f, 1.0f};                       //Ambient lighting of the material
        float matDiffuse[4] {0.8f, 0.8f, 0.8f, 1.0f};                       //Diffuse lighting of the material
        float matSpectular[4] {1.0f, 1.0f, 1.0f, 1.0f};                     //Spectular lighting of the material
        float highShininess[1] = {100};

        void setLight(GLenum);

    protected:

    private:
};

#endif // _GLLIGHT_H
