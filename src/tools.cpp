#include <tools.h>
Game::Game(unsigned int SCR_WIDTH, unsigned int SCR_HEIGHT) {
    int CHANNELS = 3;
    void frameSizeCallback(GLFWwindow *window, int width, int height);
    HWND console = FindWindow("ConsoleWindowClass", nullptr);
    if (console) {
        ShowWindow(console, SW_HIDE);
    }
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Aircrash", nullptr, nullptr);
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, frameSizeCallback);
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

    
    GLFWimage icon;
    icon.width = 32;
    icon.height = 32;
    icon.pixels = stbi_load("resources/image/host/Aircraft.png", &icon.width, &icon.height, &CHANNELS, 4);
    glfwSetWindowIcon(window, 1, &icon);
    stbi_image_free(&icon.pixels);

}
void frameSizeCallback([[maybe_unused]] GLFWwindow *window, int width, int height){
    glViewport(0, 0, width, height);
}
Game::~Game(){
    glfwTerminate();
}
void Game::turn(GameStatus Status) {
    status = Status;
}
void Game::update(float dTime) {
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window);
    glfwPollEvents();
}
GameStatus Game::getStatus() {
    return status;
}
void Game::matrixInit(glm::mat4 projection) {
    this -> projection = projection;
}