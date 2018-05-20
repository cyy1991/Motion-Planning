/*
 * Particle.h
 *
 *  Created on: May 19, 2018
 *      Author: LuQiang
 */

#ifndef PARTICLE_H_
#define PARTICLE_H_

namespace qiang {

struct Particle {
	double m_x;
	double m_y;

	double m_xspeed;
	double m_yspeed;


public:
	Particle();
	virtual ~Particle();
	void update(); // update particle's position.
};

} /* namespace qiang */

#endif /* PARTICLE_H_ */
