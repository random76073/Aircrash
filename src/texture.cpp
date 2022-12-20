#include <texture.h>
Texture::Texture(unsigned int width, unsigned int height, unsigned char *data, GLuint WRAP_S, GLuint WRAP_T, GLuint MAG_FILTER, GLuint MIN_FILTER) {
    glGenTextures(1, &id);
    glBindTexture(GL_TEXTURE_2D, id);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, WRAP_S);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, WRAP_T);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, MAG_FILTER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, MIN_FILTER);
    glBindTexture(GL_TEXTURE_2D, 0);
}
Texture::Texture(){}
void Texture::bind() {
    glBindTexture(GL_TEXTURE_2D, id);
}
void Texture::unbind() {
    glBindTexture(GL_TEXTURE_2D, 0);
}