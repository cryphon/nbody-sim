#pragma once
#include <vector>
#include "particle.hpp"

// forward declare GLuint 
typedef unsigned int GLuint;


class Renderer {
public:
    Renderer();
    ~Renderer();
    void render(const std::vector<Particle>& particles);

private:
    GLuint vao;
    GLuint vbo;
};
