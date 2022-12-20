#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <windows.h>
#include <GLM/glm.hpp>
#include <GLM/gtc/matrix_transform.hpp>
#include <GLM/gtc/type_ptr.hpp>
#include <stb_image.h>
enum GameStatus {
    GAME_ACTIVE, 
    GAME_PAUSE, 
    GAME_OUT,
    GAME_MENU
};
class Game {
    public:
        GameStatus status = GAME_MENU;
        GLFWwindow *window;
        glm::mat4 projection;
        Game(unsigned int SCR_WIDTH, unsigned int SCR_HEIGHT);
        ~Game();
        void update(float dTime);
        void turn(GameStatus Status);
        void matrixInit(glm::mat4 projection);
        GameStatus getStatus();
};