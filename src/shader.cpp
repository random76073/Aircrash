#include "shader.h"
#include "glad/glad.h"
#include <iostream>
shader::shader(const char *code, int type) {
    this -> id = glCreateShader(type);
    this -> type = type;
    glShaderSource(this -> id, 1, &code, nullptr);
    glCompileShader(this -> id);
}
shader::shader() {id = 0;}
shader::~shader() {
    glDeleteShader(this -> id);
}

void shader::getinfo() const {
    int success;
    char infoLog[512];
    glGetShaderiv(this -> id, GL_COMPILE_STATUS, &success);
    if (!success){
        glGetShaderInfoLog(this -> id, 512, nullptr, infoLog);
        std::cout << "ERROR::" << ((this -> type == GL_FRAGMENT_SHADER) ? "FRAGMENT_SHADER" : ((this -> type == GL_VERTEX_SHADER) ? "VERTEX_SHADER" : "GEOMETRY_SHADER")) << std::endl << infoLog;
    }
}
void shader::set(const char *name, int program, int value) {
    glUniform1i(glGetUniformLocation(program, name), value);
}
void shader::set(const char *name, int program, bool value) {
    glUniform1i(glGetUniformLocation(program, name), (int)value);
}
void shader::set(const char *name, int program, float value) {
    glUniform1f(glGetUniformLocation(program, name), value);
}
void shader::set(const char *name, int program, glm::mat4 value) {
    glUniformMatrix4fv(glGetUniformLocation(program, name), 1, GL_FALSE, &value[0][0]);
}
void shader::set(const char *name, int program, glm::vec3 value) {
    glUniform3fv(glGetUniformLocation(program, name), 1, &value[0]);
}
void shader::set(const char *name, int program, glm::vec4 value) {
    glUniform4fv(glGetUniformLocation(program, name), 1, &value[0]);
}