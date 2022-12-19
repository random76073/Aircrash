#version 410 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec4 aColor;
out vec4 oColor;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
void main(){
    gl_Position = projection * view * model * vec4(aPos, 1.0f);
    oColor = aColor;
}
