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
	const static int NPARTICLES = 5000;

private:
	Particle  *m_pParticles;
	int lastTime;

public:
	Swarm();
	virtual ~Swarm();
	void update(int elapsed);
	const Particle * const getParticles() { return m_pParticles; }
};

} /* namespace qiang */

#endif /* SWARM_H_ */
