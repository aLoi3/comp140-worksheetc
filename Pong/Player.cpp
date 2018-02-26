#include "Player.h"
#include <assert.h>
#include <windows.h>


void Player::init()
{
	w = 10;
	h = 60;

	posX = 0;
	posY = 220;

	speed = 10;
}

void Player::Move()
{
	assert(mySide != Side_Undefined);

	float delta = 0;

	/*
	if(mySide == Side_Left)
	{		
		posY = serialInterface->getPot1();
	}

	if(mySide == Side_Right)
	{
		posY = serialInterface->getPot2();
	}
	
	if(( posY + delta > 100) && ((posY + delta) < (600 - h )))
	{
		posY += delta;
	}*/
}

void Player::SetSide(Side eSide)
{
	mySide = eSide;

	if(mySide == Side_Left)
	{
		posX = 30;
	}

	if(mySide == Side_Right)
	{
		posX = 760;
	}
}

void Player::SetPosY(float newPosY)
{
	posY = newPosY;
}

float Player::GetPosY()
{
	return posY;
}
