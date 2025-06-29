#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/random.hpp>
#include <vector>
#include "particle.hpp"
#include "simulator.hpp"
#include "renderer.hpp"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800
#define DT 0.0001f

GLFWwindow* start_GLFW();

int main(int argc, char** argv) {
    GLFWwindow* window = start_GLFW();
    if (!window) return -1;

    if (!gladLoadGL()) {
        std::cerr << "Failed to initialize glad!" << std::endl;
        return -1;
    }

    glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

    std::vector<Particle> particles;

    for (int i = 0; i < 100; i++) {
        particles.push_back({
            glm::linearRand(glm::vec2(-1.0f), glm::vec2(1.0f)),
            glm::vec2(0.0f),
            glm::linearRand(0.5f, 1.5f)
        });
    }

    Simulator simulator(particles);
    Renderer renderer;

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        simulator.update(DT);
        renderer.render(particles);

        glfwSwapBuffers(window);
    }
    return 0;
}

GLFWwindow* start_GLFW() {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize glfw; panic!" << std::endl;
        return nullptr;
    }

    GLFWwindow* window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "gravity_sim", NULL, NULL);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return nullptr;
    }

    glfwMakeContextCurrent(window);
    return window;
}

