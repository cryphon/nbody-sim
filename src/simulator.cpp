#include "simulator.hpp"
#include <glad/glad.h>


Simulator::Simulator(std::vector<Particle>& particles)
    : m_particles(particles) {
        glPointSize(2.0f);
    }

void Simulator::update(float dt) {
    const size_t n = m_particles.size();

    for(size_t i = 0; i < n; i++) {
        glm::vec2 force(0.0f);

        for(size_t j = 0; j < n; j++) {
            if(i == j) continue;
            glm::vec2 dir = m_particles[j].pos - m_particles[i].pos;
            float dist_sq = glm::dot(dir, dir) + 1e-5f; // softening factor
            float inv_dist = 1.0f / sqrt(dist_sq);
            force += G * m_particles[j].mass * dir * inv_dist * inv_dist * inv_dist;
        }
        m_particles[i].vel += dt * force;
    }

    // integrate positions
    for(auto& p : m_particles) {
        p.pos += dt * p.vel;
    }
}
