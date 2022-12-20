#include <windows.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb_image.h>
#include <GLC.h>
#include <shader.h>
#include <iostream>
#include <ft2build.h>
#include FT_FREETYPE_H

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;
const glm::vec3 Up = glm::vec3(0.0f, 1.0f, 0.0f);
int CHANNELS = 3;
float CMR_SPEED = 5;

void frameSizeCallback(GLFWwindow *window, int width, int height);
void mouseCallback(GLFWwindow *window, double x, double y);
void scrollCallback(GLFWwindow *window, double xoffset, double yoffset);

unsigned int VAO, VBO, shaderProgram, LightShaderProgram, LightVAO;

float vertices[] = {
    -0.5f, -0.5f, -0.5f,
     0.5f, -0.5f, -0.5f,
     0.5f,  0.5f, -0.5f,
     0.5f,  0.5f, -0.5f,
    -0.5f,  0.5f, -0.5f,
    -0.5f, -0.5f, -0.5f,

    -0.5f, -0.5f,  0.5f,
     0.5f, -0.5f,  0.5f,
     0.5f,  0.5f,  0.5f,
     0.5f,  0.5f,  0.5f,
    -0.5f,  0.5f,  0.5f,
    -0.5f, -0.5f,  0.5f,

    -0.5f,  0.5f,  0.5f,
    -0.5f,  0.5f, -0.5f,
    -0.5f, -0.5f, -0.5f,
    -0.5f, -0.5f, -0.5f,
    -0.5f, -0.5f,  0.5f,
    -0.5f,  0.5f,  0.5f,

     0.5f,  0.5f,  0.5f,
     0.5f,  0.5f, -0.5f,
     0.5f, -0.5f, -0.5f,
     0.5f, -0.5f, -0.5f,
     0.5f, -0.5f,  0.5f,
     0.5f,  0.5f,  0.5f,

    -0.5f, -0.5f, -0.5f,
     0.5f, -0.5f, -0.5f,
     0.5f, -0.5f,  0.5f,
     0.5f, -0.5f,  0.5f,
    -0.5f, -0.5f,  0.5f,
    -0.5f, -0.5f, -0.5f,

    -0.5f,  0.5f, -0.5f,
     0.5f,  0.5f, -0.5f,
     0.5f,  0.5f,  0.5f,
     0.5f,  0.5f,  0.5f,
    -0.5f,  0.5f,  0.5f,
    -0.5f,  0.5f, -0.5f,
};
glm::vec3 cube[] = {
    glm::vec3( 3.0f,  2.3f, -4.0f), 
    glm::vec3( 2.0f,  5.0f, -5.0f), 
    glm::vec3(-1.5f, -2.2f, -2.5f),  
    glm::vec3(-3.8f, -2.0f, -2.3f),  
    glm::vec3( 2.4f, -0.4f, -3.5f),  
    glm::vec3(-1.7f,  3.0f, -7.5f),  
    glm::vec3( 1.3f, -2.0f, -2.5f),  
    glm::vec3( 1.5f,  2.0f, -2.5f), 
    glm::vec3( 1.5f,  0.2f, -1.5f), 
    glm::vec3(-1.3f,  1.0f, -1.5f)  
};
float dTime, lastFrame=0, currentFrame;
bool firstMouse = true;
Camera camera;
float lastX = SCR_WIDTH / 2, lastY = SCR_HEIGHT / 2;

const char *vs = "#version 410 core\n"
"layout (location = 0) in vec3 aPos;\n"

"uniform mat4 model;\n"
"uniform mat4 view;\n"
"uniform mat4 projection;\n"
"void main(){\n"
    "gl_Position = projection * view * model * vec4(aPos, 1.0f);\n"
"}\n";

const char *fs = "#version 410 core\n"
"out vec4 FragColor;\n"
"uniform vec3 oColor;\n"
"uniform vec3 lightColor;\n"
"void main()\n"
"{\n"
	"FragColor = vec4(lightColor * oColor, 1.0);\n"
"}\n";

const char *lightfs = "#version 330 core\n"
"out vec4 FragColor;\n"

"void main()\n"
"{\n"
    "FragColor = vec4(1.0);\n"
"}";

HWND console;

int main(){
    console = FindWindow("ConsoleWindowClass", nullptr);
    if (console) {
        ShowWindow(console, SW_HIDE);
    }
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);
#ifndef __APPLE__
    glfwWindowHint(GLFW_OPENGL_COMPAT_PROFILE, GL_TRUE);
#endif

    GLFWwindow *window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Aircrash", nullptr, nullptr);
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, frameSizeCallback);
    glfwSetCursorPosCallback(window, mouseCallback);
    glfwSetScrollCallback(window, scrollCallback);
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    glEnable(GL_DEPTH_TEST);

    GLFWimage icon;
    icon.width = 32;
    icon.height = 32;
    icon.pixels = stbi_load("resources/image/host/Aircraft.png", &icon.width, &icon.height, &CHANNELS, 4);
    glfwSetWindowIcon(window, 1, &icon);
    stbi_image_free(&icon.pixels);

    shader vertexShader(vs, GL_VERTEX_SHADER);
    vertexShader.getinfo();
    shader fragmentShader(fs, GL_FRAGMENT_SHADER);
    fragmentShader.getinfo();
    shader LightFragmentShader(lightfs, GL_FRAGMENT_SHADER);
    LightFragmentShader.getinfo();

    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader.id);
    glAttachShader(shaderProgram, fragmentShader.id);
    glLinkProgram(shaderProgram);

    LightShaderProgram = glCreateProgram();
    glAttachShader(LightShaderProgram, vertexShader.id);
    glAttachShader(LightShaderProgram, LightFragmentShader.id);

    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    glGenVertexArrays(1, &LightVAO);
    glBindVertexArray(LightVAO);

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    while (!glfwWindowShouldClose(window)){
        currentFrame = static_cast<float>(glfwGetTime());
        dTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        
        glm::mat4 projection = perspective(radians(camera.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
        vertexShader.set("projection", shaderProgram, projection);
        
        glm::mat4 view = camera.getView();
        vertexShader.set("view", shaderProgram, view);
        
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
            glfwSetWindowShouldClose(window, GL_TRUE);
        }

        if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS){
            camera.move(normalize(glm::vec3(camera.direction.Front.x, 0.0f, camera.direction.Front.z)) * (CMR_SPEED * dTime));
        }
        if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS){
            camera.back(normalize(glm::vec3(camera.direction.Front.x, 0.0f, camera.direction.Front.z)) * (CMR_SPEED * dTime));
        }
        if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS){
            camera.back(normalize(cross(glm::vec3(camera.direction.Front.x, 0.0f, camera.direction.Front.z), Up)) * (CMR_SPEED * dTime));
        }
        if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS){
            camera.move(normalize(cross(glm::vec3(camera.direction.Front.x, 0.0f, camera.direction.Front.z), Up)) * (CMR_SPEED * dTime));
        }
        if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {
            camera.move(Up * (CMR_SPEED * dTime));
        }
        if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) {
            camera.back(Up * (CMR_SPEED * dTime));
        }
        

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glUseProgram(shaderProgram);
        glBindVertexArray(VAO);
        fragmentShader.set("oColor", shaderProgram, vec3(1.0f, 0.5f, 0.31f));
        fragmentShader.set("lightColor", shaderProgram, vec3(1.0f, 1.0f, 1.0f));
        for (int i = 0;i<sizeof(cube)/sizeof(glm::vec3);i++){
            glm::mat4 model = glm::mat4(1.0f);
            model = glm::translate(model, cube[i]);
            vertexShader.set("model", shaderProgram, model);
            glDrawArrays(GL_TRIANGLES, 0, 36);
        }
        glUseProgram(LightShaderProgram);
        vertexShader.set("projection", LightShaderProgram, projection);
        vertexShader.set("view", LightShaderProgram, view);
        mat4 model = glm::mat4(1.0f);
        model = translate(model, glm::vec3(3.0f, -0.8f, -2.3f));
        model = scale(model, vec3(0.2f));
        vertexShader.set("model", LightShaderProgram, model);
        glBindVertexArray(LightVAO);
        glDrawArrays(GL_TRIANGLES, 0, 36);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glDeleteProgram(shaderProgram);
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glfwTerminate();

    return 0;
}
void frameSizeCallback([[maybe_unused]] GLFWwindow *window, int width, int height){
    glViewport(0, 0, width, height);
}
void mouseCallback(GLFWwindow *window, double x, double y){
    float xpos = static_cast<float>(x);
    float ypos = static_cast<float>(y);
    
    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; 
    lastX = xpos;
    lastY = ypos;

    camera.turn(xoffset * 0.1f, yoffset * 0.1f);
}
void scrollCallback(GLFWwindow *window, double xoffset, double yoffset) {
    camera.zoom(yoffset);
}