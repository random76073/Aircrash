#include <windows.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb_image.h>
#include <GLC.h>
#include <shader.h>
#include <iostream>

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;
const glm::vec3 Up = glm::vec3(0.0f, 1.0f, 0.0f);
int CHANNELS = 3;
float CMR_SPEED = 5;

void frameSizeCallback(GLFWwindow *window, int width, int height);
void mouseCallback(GLFWwindow *window, double x, double y);
void scrollCallback(GLFWwindow *window, double xoffset, double yoffset);

unsigned int VAO, VBO, shaderProgram, texture;

float vertices[] = {
    -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
     0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
     0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
    -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

    -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
    -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
    -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
     0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
     0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
     0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
     0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
     0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
     0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
    -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
};
glm::vec3 cube[] = {
    glm::vec3(1.5f,  2.0f, -2.5f)
};
float dTime, lastFrame=0, currentFrame;
bool firstMouse = true;
Camera camera;
float lastX = SCR_WIDTH / 2, lastY = SCR_HEIGHT / 2;

const char *vs = "#version 410 core\n"
"layout (location = 0) in vec3 aPos;\n"
"layout (location = 1) in vec2 aTexCoord;\n"
"out vec2 TexCoord;\n"

"uniform mat4 model;\n"
"uniform mat4 view;\n"
"uniform mat4 projection;\n"
"void main(){\n"
    "gl_Position = projection * view * model * vec4(aPos, 1.0f);\n"
    "TexCoord = aTexCoord;\n"
"}\n";

const char *fs = "#version 410 core\n"
"out vec4 FragColor;\n"
"in vec2 TexCoord;\n"
"uniform sampler2D texture1;\n"
"void main()\n"
"{\n"
	"FragColor = texture(texture1, TexCoord);\n"
"}\n";

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

    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader.id);
    glAttachShader(shaderProgram, fragmentShader.id);
    glLinkProgram(shaderProgram);

    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    stbi_set_flip_vertically_on_load(true);
    int x, y;
    unsigned char *image = stbi_load("resources/image/test.jpg", &x, &y, &CHANNELS, 0);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, x, y, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
    glGenerateMipmap(GL_TEXTURE_2D);
    stbi_image_free(image);
    fragmentShader.set("texture1", shaderProgram, 1);
    

    while (!glfwWindowShouldClose(window)){
        currentFrame = static_cast<float>(glfwGetTime());
        dTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        
        glm::mat4 projection = perspective(radians(camera.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
        vertexShader.set("projection", shaderProgram, projection);
        
        glm::mat4 view = camera.getView();
        vertexShader.set("view", shaderProgram, view);
        
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture);
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
            glfwSetWindowShouldClose(window, GL_TRUE);
        }

        if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS){
            camera.move(normalize(vec3(camera.direction.Front.x, 0.0f, camera.direction.Front.z)) * (CMR_SPEED * dTime));
        }
        if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS){
            camera.back(normalize(vec3(camera.direction.Front.x, 0.0f, camera.direction.Front.z)) * (CMR_SPEED * dTime));
        }
        if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS){
            camera.back(normalize(cross(vec3(camera.direction.Front.x, 0.0f, camera.direction.Front.z), Up)) * (CMR_SPEED * dTime));
        }
        if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS){
            camera.move(normalize(cross(vec3(camera.direction.Front.x, 0.0f, camera.direction.Front.z), Up)) * (CMR_SPEED * dTime));
        }
        if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {
            camera.move(Up * (CMR_SPEED * dTime));
        }
        if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) {
            camera.back(Up * (CMR_SPEED * dTime));
        }
        

        glClearColor(0.4f, 0.7f, 0.2f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glUseProgram(shaderProgram);
        glBindVertexArray(VAO);
        for (int i = 0;i<sizeof(cube)/sizeof(glm::vec3);i++){
            glm::mat4 model = glm::mat4(1.0f);
            model = glm::translate(model, cube[i]);
            vertexShader.set("model", shaderProgram, model);
            glDrawArrays(GL_TRIANGLES, 0, 36);
        }
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