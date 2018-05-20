/*
 * Swarm.h
 *
 *  Created on: May 19, 2018
 *      Author: LuQiang
 */

#ifndef SWARM_H_
#define SWARM_H_

#include "Particle.h"

namespace qiang {

class Swarm {
public:
	const static int NPARTICLES = 500;

private:
	Particle  *m_pParticles;
public:
	Swarm();
	virtual ~Swarm();
	void update();
	const Particle * const getParticles() { return m_pParticles; }
};

} /* namespace qiang */

#endif /* SWARM_H_ */
