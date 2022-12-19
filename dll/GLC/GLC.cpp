#include <GLC.h>
#define mat4() glm::mat4(1.0f)
using namespace glm;

Camera::Camera(vec3 pos, float yaw, float pitch){
    Pos = pos;
    this -> Yaw = yaw;
    this -> Pitch = pitch;
    update();
};
void Camera::update(){
    vec3 front;
    front.x = cos(radians(Yaw)) * cos(radians(Pitch));
    front.y = sin(radians(Pitch));
    front.z = sin(radians(Yaw)) * cos(radians(Pitch));
    direction.Front = normalize(front);
    direction.Right = normalize(cross(direction.Front, norm_up));
    direction.Up = normalize(cross(direction.Right, direction.Front));
}
mat4 Camera::getView(){
    return lookAt(Pos, Pos + direction.Front, norm_up);
}
void Camera::move(vec3 CDirection){
    Pos += CDirection;
}
void Camera::back(vec3 CDirection){
    Pos -= CDirection;
}
void Camera::turn(float dyaw, float dpitch){
    Yaw += dyaw;
    Pitch += dpitch;
    if (Pitch > 89.0f)
        Pitch = 89.0f;
    if (Pitch < -89.0f)
        Pitch = -89.0f;
    update();
}
void Camera::zoom(float dzoom){
    Zoom -= (float)dzoom;
    if (Zoom < 1.0f)
        Zoom = 1.0f;
    if (Zoom > 45.0f)
        Zoom = 45.0f;
}