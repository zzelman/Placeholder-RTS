/*
 * Utills.h
 *
 *  Created on: Dec 7, 2013
 *      Author: zZelman
 */

#ifndef UTILLS_H_
#define UTILLS_H_

#include "include_sfml.h"

// arbitrary direction bools
struct SDirections
{
	bool isUp;
	bool isDown;
	bool isRight;
	bool isLeft;

	inline void nullAll()
	{
		isUp = false;
		isDown = false;
		isRight = false;
		isLeft = false;
	}
};


// data fileds for arbitrary keys that are accptable for individual object input
struct SAcceptableKeys
{
	sf::Keyboard::Key up, down, left, right;
};


// phisics data
struct SPhysics
{
	sf::Clock gravityTimer; // used in parabolic curve modeling
	int velosity_x;
	int velosity_y;

	inline void nullAll()
	{
		gravityTimer.restart();
		velosity_x = 0;
		velosity_y = 0;
	}
};


#endif /* UTILLS_H_ */