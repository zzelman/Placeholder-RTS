/*
 * IRenderable.h
 *
 *  Created on: Oct 10, 2013
 *      Author: zZelman
 */

#ifndef ARENDER_H_
#define ARENDER_H_

#include "../include_sfml.h"
#include "../Graphics/CTexture.h"
#include "../Graphics/CSprite.h"

#include "../Interfaces/IRenderable.h"

class ARender : public IRenderable
{
public:
	ARender(sf::RenderWindow* pWindow,
	        CTexture* pTexture,
	        const sf::Vector2<int>& currSub);

	// if this constructor is used, note that this object then takes responsibility
	//		for the CSprite*
	ARender(CSprite* pSprite);
	virtual ~ARender();

	CSprite* const getSprite();
	sf::Sprite* const getSprite_API();
	sf::FloatRect getGlobalBounds();

	void setPosition(float x, float y);

	virtual void render();


protected:
	CSprite* m_pSprite;
};


#endif /* IRENDERABLE_H_ */
