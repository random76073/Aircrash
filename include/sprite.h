#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "shader.h"
#include "texture.h"
enum spriteClass {
    TEXTURE_SPRITE, 
    COLOR_SPRITE
};
class Sprite2D {
    public:
        shader vertexShader, fragmentShader, geometryShader;
        Texture texture;
        spriteClass sclass;
        glm::vec3 color;
        unsigned int VAO, VBO, shaderProgram;
        float vertices[];
        Sprite2D(const char *vs, const char *fs, float vertices[], const char *gs = nullptr);
        void apperance(Texture tex);
        void apperance(glm::vec3 color);
        void render(float x, float y);
};