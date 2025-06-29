#pragma once
#include <vector>
#include "particle.hpp"

class Simulator {
    public:
        Simulator(std::vector<Particle>& particles);

        void update(float dt);

    private:
        std::vector<Particle>& m_particles;
        const float G = 1.0f;
};
