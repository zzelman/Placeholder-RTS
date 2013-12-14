/*
 * CUnit.h
 *
 *  Created on: Dec 7, 2013
 *      Author: zZelman
 */

#ifndef CUNIT_H_
#define CUNIT_H_

#include "ARender.h"
#include "AUpdate.h"
#include "CSprite.h"
#include "include_sfml.h"
#include "CTile_Container.h"
#include "Utills.h"
#include "DPhysics.h"

class CUnit: public AUpdate, public ARender, public DPhysics
{
public:
	CUnit(sf::RenderWindow* pWindow, 			// rendering window
	      CTile_Container* pGrid,
	      CTexture* pTexture, 				// texture that this sprite will render with
	      const sf::Vector2<int>& currSub);	// LENGTH current sub image being rendered
	~CUnit();

	void update();

private:
	CTile_Container* m_pGrid;

	// * Controls how the sprite is moving during the update phase
	// * these flags are set elsewhere, then passively acted on as they precist
	struct SDirections m_sMovement;

	// collision detection between
	bool canMove_vertical();
	bool canMove_horizontal();
};

#endif /* CUNIT_H_ */
