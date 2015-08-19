/****************************************************************
*
*	The main character/user character. This is where the input is used to give
*   direct control over this character. 
***********************************************************/
#include "Link.h"



Link::Link()
{
	health = 1;
	speed = 0.4f;
	isMoving = false;
	loop = false;
	isAttacking = false;
	direction = 2;
}




bool Link::initialize(Game *gamePtr, int startX, int startY, int width, int height, int ncols,
	TextureManager *textureM)
{
	input = gamePtr->getInput();
	return (Entity::initialize(gamePtr, startX, startY, width, height, ncols,
		textureM));

}

Link::~Link()
{

}




void Link::initiateMovement()
{
	
	moveKeyWasPressed = false;
	if (input->isKeyDown(VK_UP))
	{
		Entity::move(0, -1);
		setImageFrame(LINK_UP_START_X, LINK_UP_START_Y,
			LINK_UP_WIDTH, LINK_UP_HEIGHT);
		moveKeyWasPressed = true;
		flipHorizontal(0);
		direction = 0;

	}
	if (input->isKeyDown(VK_DOWN))
	{
		Entity::move(0, 1);

		setImageFrame(LINK_DOWN_START_X, LINK_DOWN_START_Y,
			LINK_DOWN_WIDTH, LINK_DOWN_HEIGHT);
		moveKeyWasPressed = true;
		flipHorizontal(0);
		direction = 2;
	}


	if (input->isKeyDown(VK_LEFT))
	{
		Entity::move(-1, 0);
		setImageFrame(LINK_SIDE_START_X, LINK_SIDE_START_Y,
			LINK_SIDE_WIDTH, LINK_SIDE_HEIGHT);
		flipHorizontal(1);
		moveKeyWasPressed = true;
		direction = 3;
	}
	if (input->isKeyDown(VK_RIGHT))
	{
		Entity::move(1, 0);
		setImageFrame(LINK_SIDE_START_X, LINK_SIDE_START_Y,
			LINK_SIDE_WIDTH, LINK_SIDE_HEIGHT);
		flipHorizontal(0);
		moveKeyWasPressed = true;

		direction = 1;
	}


	if (moveKeyWasPressed)
	{
		if (isMoving == false)
			setCurrentFrame(1);
		isRunning;
		isMoving = true;
		setFrames(1, 6);
		loop = true;
	}
	else
	{
		isMoving = false;
		setCurrentFrame(0);
		setFrames(0, 7);
		loop = false;
	}


}





void Link::setNeutralByDir()
{
	setCurrentFrame(0);
	if (direction == 0)
	{
		flipHorizontal(0);
		setImageFrame(LINK_UP_START_X, LINK_UP_START_Y, LINK_UP_WIDTH, LINK_UP_HEIGHT);
	}
	else if (direction == 1)
	{
		flipHorizontal(0);
		setImageFrame(LINK_SIDE_START_X, LINK_SIDE_START_Y, LINK_SIDE_WIDTH, LINK_SIDE_HEIGHT);
	}
	else if (direction == 2)
	{
		flipHorizontal(0);
		setImageFrame(LINK_DOWN_START_X, LINK_DOWN_START_Y, LINK_DOWN_WIDTH, LINK_DOWN_HEIGHT);
	}
	else if (direction == 3)
	{
		flipHorizontal(1);
		setImageFrame(LINK_SIDE_START_X, LINK_SIDE_START_Y, LINK_SIDE_WIDTH, LINK_SIDE_HEIGHT);
	}
	//setRect();

}


void Link::update(float frameTime)
{

	bool keyWasPressed = false;
	checkEndOfMovement();


	if (!isAttacking && !isRecoiling)
		initiateMovement();
	else if (isRecoiling)
		recoiling();


	//attack overrides the move
	initiateAttack();



	Entity::update(frameTime);


}


void Link::initiateAttack()
{

	if (input->isKeyDown(0x41) && !isAttacking)
	{

		flipHorizontal(0);

		setFrameDelay(0.5f);


		if (direction == 0)
		{

			setImageFrame(LINK_ATK_UP_START_X, LINK_ATK_UP_START_Y
				, LINK_ATK_UP_WIDTH, LINK_ATK_UP_HEIGHT);

			setY(spriteData.y - 27);
			
		}
		else if (direction == 1)
		{

			setImageFrame(LINK_ATK_SIDE_START_X, LINK_ATK_SIDE_START_Y
				, LINK_ATK_SIDE_WIDTH, LINK_ATK_SIDE_HEIGHT);

			setY(spriteData.y - 16);

		}
		else if (direction == 2)
		{

			setImageFrame(LINK_ATK_DOWN_START_X, LINK_ATK_DOWN_START_Y
				, LINK_ATK_SIDE_WIDTH, LINK_ATK_SIDE_HEIGHT);

			setX(spriteData.x - 15);
			setY(spriteData.y + 3);


		}
		else if (direction == 3)
		{

			setImageFrame(LINK_ATK_SIDE_START_X, LINK_ATK_SIDE_START_Y
				, LINK_ATK_SIDE_WIDTH, LINK_ATK_SIDE_HEIGHT);
			flipHorizontal(1);

			setX(spriteData.x - 24);
			setY(spriteData.y - 16);
		}
		



		setCurrentFrame(0);
		setFrames(0, 5);







		loop = false;
		isRunning = false;
		isAttacking = true;
		isMoving = true;
		animComplete = false;


	}

}


void Link::checkEndOfMovement()
{
	if (isAttacking && animComplete)
	{
		isMoving = false;
		isAttacking = false;
		loop = false;
		setNeutralByDir();
		animComplete = false;

		if (direction == 0)
		{
			setY(spriteData.y + 27);
		}
		else if (direction == 1)
		{
			setY(spriteData.y + 16);
		}
		else if (direction == 2)
		{
			setX(spriteData.x + 15);
			setY(spriteData.y - 3);
		}
		else if (direction == 3)
		{
			setX(spriteData.x + 24);
			setY(spriteData.y + 16);
		}
		
		


	}
}


/*
* Makes any necessary offset to position to make animation work
* correctly. Any initial offset will be done in initiatAttack function (because of currentFrame == 0)
* but this is where the frame by frame correction will happen.
*/
void Link::setMoveOffset()
{


	if (isAttacking)
	{



		if (direction == 0)
		{
			if (currentFrame == 4)
			{
				//actual offset
				setX(spriteData.x - 18);
			}
			else if (currentFrame == 5)
			{
				//actual offset
				setX(spriteData.x - 6);
			}
			else if (currentFrame == 6)
			{
				//revert back to original
				setX(spriteData.x + 24);
			}

		}


		else if (direction == 1)
		{
			if (currentFrame == 1)
			{
				//actual offset
				setX(spriteData.x + 3);
			}
			else if (currentFrame == 2)
			{
				//actual offset
				setX(spriteData.x + 3);
			}
			else if (currentFrame == 4)
			{
				//actual offset
				setY(spriteData.y + 12);

				//revert back to original
				setX(spriteData.x - 6);
			}
			else if (currentFrame == 5)
			{
				setY(spriteData.y + 4);
			}
			else if (currentFrame == 6)
			{
				setY(spriteData.y - 16);
			}
		}


		else if (direction == 2)
		{
			if (currentFrame == 3)
			{
				//actual offset
				setY(spriteData.y + 5);
			}
			else if (currentFrame == 4)
			{
				//revert back to original
				setY(spriteData.y - 5);
			}
			else if (currentFrame == 5)
			{
				//actual offset
				setX(spriteData.x + 2);
			}
			else if (currentFrame == 6)
			{
				//revert back to original
				setX(spriteData.x - 2);
			}
		}



		else if (direction == 3)
		{
			if (currentFrame == 1)
			{
				//actual offset
				setX(spriteData.x - 3);
			}
			else if (currentFrame == 2)
			{
				//actual offset
				setX(spriteData.x - 3);
			}
			else if (currentFrame == 4)
			{
				//actual offset
				setY(spriteData.y + 12);

				//revert to original
				setX(spriteData.x + 6);
			}
			else if (currentFrame == 5)
			{
				setY(spriteData.y + 4);
			}
			else if (currentFrame == 6)
			{
				//revert to original
				setY(spriteData.y - 16);
			}
		}




	}
}

bool Link::collision()
{
	return false;
}
