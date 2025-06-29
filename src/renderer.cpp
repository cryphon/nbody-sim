#include "renderer.hpp"
#include <glad/glad.h>
#include <glm/glm.hpp>


Renderer::Renderer() {
    // Generate VAO and VBO
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);

    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    // Allocate initial empty buffer
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 2 * 1000, nullptr, GL_DYNAMIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

Renderer::~Renderer() {
    glDeleteBuffers(1, &vbo);
    glDeleteVertexArrays(1, &vao);
}

void Renderer::render(const std::vector<Particle>& particles) {
    std::vector<glm::vec2> positions;
    positions.reserve(particles.size());

    for (const auto& p : particles) {
        positions.push_back(p.pos);
    }

    glClear(GL_COLOR_BUFFER_BIT);

    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    glBufferData(GL_ARRAY_BUFFER, positions.size() * sizeof(glm::vec2), positions.data(), GL_DYNAMIC_DRAW);

    glDrawArrays(GL_POINTS, 0, positions.size());

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

