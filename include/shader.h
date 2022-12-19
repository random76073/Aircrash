#pragma once
#include <GLM/glm.hpp>
#include <GLM/gtc/matrix_transform.hpp>
#include <GLM/gtc/type_ptr.hpp>
class shader {
    public:
        int id;
        int type;
        char *code;
        shader(const char *code, int type);
        ~shader();
        void getinfo() const;
        
        void set(const char *name, int program, int value);
        void set(const char *name, int program, bool value);
        void set(const char *name, int program, float value);
        void set(const char *name, int program, glm::mat4 value);
        void set(const char *name, int program, glm::vec3 value);
        void set(const char *name, int program, glm::vec4 value);
};


