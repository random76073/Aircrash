#include <sprite.h>
Sprite2D::Sprite2D(const char *vs, const char *fs, float vertices[], const char *gs){
    vertices = vertices;

    shader vertexShader(vs, GL_VERTEX_SHADER);
    vertexShader.getinfo();
    shader fragmentShader(fs, GL_FRAGMENT_SHADER);
    fragmentShader.getinfo();
    if (gs){
        shader geometryShader(gs, GL_GEOMETRY_SHADER);
        geometryShader.getinfo();
    }

    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader.id);
    if (geometryShader.id)
        glAttachShader(shaderProgram, geometryShader.id);
    glAttachShader(shaderProgram, fragmentShader.id);
    glLinkProgram(shaderProgram);

    switch (sclass){
        case TEXTURE_SPRITE:
            glActiveTexture(GL_TEXTURE0);
            glBindVertexArray(VAO);
            vertexShader.set("texture", shaderProgram, 0);
        case COLOR_SPRITE:
            glBindVertexArray(VAO);
            vertexShader.set("oColor", shaderProgram, color);
    }
    glDrawArrays(GL_TRIANGLES, 0, 6);

}
void Sprite2D::apperance(Texture tex){
    /*
    If you set apperance with texture, your shader code must has
    a sampler uniform "texture" to bind texture unit. And if you
    set apperance with color, your shader code must contain an
    uniform "oColor" to set object color.
    */
    texture = tex;
    sclass = TEXTURE_SPRITE;
}
void Sprite2D::apperance(glm::vec3 color) {
    this -> color = color;
    sclass = COLOR_SPRITE;
}
void Sprite2D::render(float x, float y) {
    glActiveTexture(GL_TEXTURE0);
    texture.bind();
    glUseProgram(shaderProgram);
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    texture.unbind();
}