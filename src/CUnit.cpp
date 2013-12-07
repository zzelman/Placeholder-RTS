/*
 * CUnit.cpp
 *
 *  Created on: Dec 7, 2013
 *      Author: zZelman
 */

#include "CUnit.h"
#include "CTexture.h"
#include "CSprite.h"
#include "CGrid.h"
#include "include_sfml.h"
#include <iostream>

CUnit::CUnit(sf::RenderWindow* pWindow,
             CGrid* pGrid,
             CTexture* pTexture,
             const sf::Vector2<int>& currSub)
{
	m_pGrid = pGrid;

	m_pSprite = new CSprite(pWindow, pTexture, currSub);

	m_sMovement.nullAll();
//	m_sMovement.isLeft	= true;
	m_sMovement.isRight	= true;
//	m_sMovement.isUp 	= true;
	m_sMovement.isDown 	= true;

	m_isFirstUpdate = true;
}


CUnit::~CUnit()
{
	delete m_pSprite;
	m_pSprite = NULL;
}


CSprite* const CUnit::getSprite()
{
	return m_pSprite;
}


void CUnit::update()
{
	if (m_isFirstUpdate)
	{
		m_sPhysics.nullAll();
		m_isFirstUpdate = false;
	}

	int stepSize_y = m_sPhysics.velosity_y;
	m_sPhysics.velosity_x = 5;
	int stepSize_x = m_sPhysics.velosity_x;

	if (canMove_horizontal())
	{
		if (m_sMovement.isLeft)
		{
			m_pSprite->move(-stepSize_x, 0);
		}
		else if (m_sMovement.isRight)
		{
			m_pSprite->move(stepSize_x, 0);
		}
	}

	if (canMove_vertical())
	{
		if (m_sMovement.isDown)
		{
			m_pSprite->move(0, stepSize_y);
		}
		else if (m_sMovement.isUp)
		{
			m_pSprite->move(0, -stepSize_y);
		}
	}

}


void CUnit::render()
{
	m_pSprite->render();
}


bool CUnit::canMove_vertical()
{
	sf::FloatRect futureRect = m_pSprite->getGlobalBounds();
	sf::FloatRect unitRect = m_pSprite->getGlobalBounds();

	CSprite* returnedSprite;

	if (m_sMovement.isDown)
	{
		futureRect.top += m_sPhysics.velosity_y; // test the future
		if (m_pGrid->isCollision(futureRect, returnedSprite))
		{
			sf::FloatRect tileRect = returnedSprite->getGlobalBounds();

			int newY = tileRect.top - futureRect.height;
			m_pSprite->setPosition(unitRect.left, newY);

			m_sPhysics.gravityTimer.restart();

			return false;
		}

	}
	else if (m_sMovement.isUp)
	{
		futureRect.top -= m_sPhysics.velosity_y; // test the future
		if (m_pGrid->isCollision(futureRect, returnedSprite))
		{
			sf::FloatRect tileRect = returnedSprite->getGlobalBounds();

			int newY = tileRect.top + tileRect.height;
			m_pSprite->setPosition(unitRect.left, newY);

			m_sPhysics.gravityTimer.restart();

			return false;
		}
	}

	return true;
}


bool CUnit::canMove_horizontal()
{
	sf::FloatRect futureRect = m_pSprite->getGlobalBounds();
	sf::FloatRect unitRect = m_pSprite->getGlobalBounds();

	CSprite* returnedSprite;

	if (m_sMovement.isRight)
	{
		futureRect.left += m_sPhysics.velosity_x; // test the future
		if (m_pGrid->isCollision(futureRect, returnedSprite))
		{
			sf::FloatRect tileRect = returnedSprite->getGlobalBounds();

			int newX = tileRect.left - futureRect.width;
			m_pSprite->setPosition(newX, unitRect.top);

			return false;
		}
	}
	else if (m_sMovement.isLeft)
	{
		futureRect.left -= m_sPhysics.velosity_x; // test the future
		if (m_pGrid->isCollision(futureRect, returnedSprite))
		{
			sf::FloatRect tileRect = returnedSprite->getGlobalBounds();

			int newX = tileRect.left + tileRect.width;
			m_pSprite->setPosition(newX, unitRect.top);

			return false;
		}
	}

//	futureRect.left += m_sPhysics.velosity_x; // test the future
//
//	if (m_pGrid->isCollision(futureRect, returnedSprite))
//	{
//		sf::FloatRect tileRect = returnedSprite->getGlobalBounds();
//
//		if (m_sMovement.isLeft)
//		{
//			int newX = tileRect.left + tileRect.width;
//			m_pSprite->setPosition(newX, unitRect.top);
//		}
//		else if (m_sMovement.isRight)
//		{
//			int newX = tileRect.left - futureRect.width;
//			m_pSprite->setPosition(newX, unitRect.top);
//		}
//
//		return false;
//	}

	return true;
}
