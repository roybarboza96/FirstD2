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
	speed = 0.2f;
	isMoving = false;
	loop = false;
	isAttacking = false;
	direction = 2;
	numSteps = 1;
	endSteps = 0;
	isIdle = false;
	idleCounter = 0;
	idleEnd = 1;
}


Octorok::~Octorok()
{

}


bool Octorok::initialize(Game *gamePtr, int startX, int startY, int width, int height, int ncols,
	TextureManager *textureM)
{
	setFrames(0, 3);
	setFrameDelay(0.07f);
	setCurrentFrame(0);
	setScale(2.0f);

	input = gamePtr->getInput();


	return (Entity::initialize(gamePtr, startX, startY, width, height, ncols,
		textureM));

}


void Octorok::update(float frameTime)
{
	if (!isAttacking)
	{
		if (numSteps >= endSteps || idleCounter == idleEnd)
			initiateMovement();

		if (!isIdle)
		{
			Entity::moveByDir();
			if (animTimer + frameTime > frameDelay)
				numSteps++;
		}
		else
			idleCounter++;
		

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
		idleCounter = 0;
		idleEnd = (rand() % 20) + 100;
		numSteps = 0;
		endSteps = 1;
		isMoving = false;
	}
	else
	{
		direction = rand() % 4;
		
		endSteps = (rand() % 3) + 15;
		numSteps = 0;
		
		isIdle = false;
		idleCounter = 0;
		idleEnd = 1;
		
		
		isMoving = true;
		loop = true;
		isRunning = true;


		if (direction == 0)
		{
			flipHorizontal(0);
			setImageFrame(OCT_UP_START_X, OCT_UP_START_Y
				, OCT_UP_WIDTH, OCT_UP_HEIGHT);
		}
		else if (direction == 1)
		{
			flipHorizontal(1);
			setImageFrame(OCT_SIDE_START_X, OCT_SIDE_START_Y
				, OCT_SIDE_WIDTH, OCT_SIDE_HEIGHT);
		}
		else if (direction == 2)
		{
			flipHorizontal(0);
			setImageFrame(OCT_DOWN_START_X, OCT_DOWN_START_Y
				, OCT_DOWN_WIDTH, OCT_DOWN_HEIGHT);
		}
		else if (direction == 3)
		{
			flipHorizontal(0);
			setImageFrame(OCT_SIDE_START_X, OCT_SIDE_START_Y
				, OCT_SIDE_WIDTH, OCT_SIDE_HEIGHT);
		}


	}

	
	/*
	isIdle = false;
	isMoving = true;
	loop = true;
	isRunning = true;

	if (input->isKeyDown(VK_UP))
	{
		direction = 0;

	}
	if (input->isKeyDown(VK_DOWN))
	{
		direction = 2;
	}


	if (input->isKeyDown(VK_LEFT))
	{
		direction = 3;
	}
	if (input->isKeyDown(VK_RIGHT))
	{
		direction = 1;
	}



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
	*/

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


bool Octorok::collision()
{

	
	return false;
}