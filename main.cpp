#include <tools.h>
#include <shader.h>
#include <sprite.h>

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;
int CHANNELS = 3;

float dTime, lastFrame=0, currentFrame;

int main(){
    Game game(SCR_WIDTH, SCR_HEIGHT);
    while (!glfwWindowShouldClose(game.window)){
        currentFrame = static_cast<float>(glfwGetTime());
        dTime = currentFrame - lastFrame;
        lastFrame = currentFrame;
        
        if (glfwGetKey(game.window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
            glfwSetWindowShouldClose(game.window, GL_TRUE);
        }
        game.update(dTime);
    }
    return 0;
}
