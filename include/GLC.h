#pragma once
#include <GLM/glm.hpp>
#include <GLM/gtc/matrix_transform.hpp>
#include <GLM/gtc/type_ptr.hpp>
using namespace glm;

typedef struct {
    vec3 Front;
    vec3 Up;
    vec3 Right;
} Direction;
class Camera {
    private:
        const vec3 norm_up = vec3(0.0f, 1.0f, 0.0f);
        void update();
    public:
        vec3 Pos;
        Direction direction;
        float Yaw;
        float Pitch;
        float Zoom = 45.0f;
        Camera(vec3 pos = vec3(0.0f, 0.0f, 0.0f), float yaw = -90.0f, float pitch = 0);
        void move(vec3 CDirection);
        void back(vec3 CDirection);
        void turn(float yaw, float pitch);
        void zoom(float dzoom);
        mat4 getView();

};
