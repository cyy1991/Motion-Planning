/*
 * Swarm.cpp
 *
 *  Created on: May 19, 2018
 *      Author: LuQiang
 */

#include "Swarm.h"

namespace qiang {

Swarm::Swarm() {
	m_pParticles = new Particle[NPARTICLES];

}

Swarm::~Swarm() {
	delete [] m_pParticles;
}

void Swarm::update() {
	for(int i = 0; i < Swarm::NPARTICLES; i ++) {
		m_pParticles[i].update();
	}
}

} /* namespace qiang */
