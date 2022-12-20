#pragma once
#include <glad/glad.h>
class Texture {
    public:
        unsigned int id;
        unsigned int width;
        unsigned int height;
        Texture(unsigned int width, unsigned int height, unsigned char *data, GLuint WRAP_S = GL_REPEAT, GLuint WRAP_T = GL_REPEAT, GLuint MAG_FILTER = GL_LINEAR, GLuint MIN_FILTER = GL_LINEAR);
        Texture();
        void bind();
        void unbind();
};