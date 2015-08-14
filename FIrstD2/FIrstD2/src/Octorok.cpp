/************************************************
*
* The ocotorok enemy has just basic vertical and horizontal movements
* and also shoots a projectile as it's only attack
*
*************************************************/
#include "Octorok.h"


Octorok::Octorok()
{
	health = 2;
	speed = 0.02f;
	isMoving = false;
	loop = false;
	isAttacking = false;
	direction = 2;
	numSteps = 1;
	endSteps = 0;
	isIdle = false;
}


Octorok::~Octorok()
{

}


bool Octorok::initialize(Game *gamePtr, int startX, int startY, int width, int height, int ncols,
	TextureManager *textureM)
{
	setFrames(0, 3);
	setFrameDelay(0.03f);
	setCurrentFrame(0);
	setScale(2.0f);
	return (Entity::initialize(gamePtr, startX, startY, width, height, ncols,
		textureM));

}


void Octorok::update(float frameTime)
{
	if (!isAttacking)
	{
		isMoving = true;
		if (numSteps >= endSteps)
			initiateMovement();

		if (!isIdle)
		{
			Entity::moveByDir();

		}

		//if (animTimer + frameTime > frameDelay)
			//numSteps++;

		

	}

	

	Entity::update(frameTime);
}


void Octorok::initiateMovement()
{
	//set up new direction and number of steps to take in that direction
	//this could be also a no direction with no speed
	if ((rand() % 2 == 0) && (isIdle == false))
	{
		isIdle = true;
		numSteps = 0;
		endSteps = (rand() % 3) + 1;
	//	isMoving = false;
	}
	else
	{
		//direction = rand() % 4;
		direction = 0;
		endSteps = (rand() % 3) + 6;
		numSteps = 0;
		isIdle = false;
		isMoving = true;
		loop = false;
		isRunning = true;


		if (direction == 0)
		{
			setImageFrame(OCT_UP_START_X, OCT_UP_START_Y
				, OCT_UP_WIDTH, OCT_UP_HEIGHT);
		}
		else if (direction == 1)
		{
			setImageFrame(OCT_SIDE_START_X, OCT_SIDE_START_Y
				, OCT_SIDE_WIDTH, OCT_SIDE_HEIGHT);
		}
		else if (direction == 2)
		{
			setImageFrame(OCT_DOWN_START_X, OCT_DOWN_START_Y
				, OCT_DOWN_WIDTH, OCT_DOWN_HEIGHT);
		}
		else if (direction == 3)
		{
			setImageFrame(OCT_SIDE_START_X, OCT_SIDE_START_Y
				, OCT_SIDE_WIDTH, OCT_SIDE_HEIGHT);
		}


	}




}


void Octorok::initiateAttack()
{

}


void Octorok::checkEndOfMovement()
{

}


void Octorok::setNeutralByDir()
{

}


void Octorok::attack()
{
	if (direction == 0)
	{
		
	}
}


void Octorok::setMoveOffset()
{

}