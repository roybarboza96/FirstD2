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
		start_x = LINK_UP_START_X;
		start_y = LINK_UP_START_Y;
		spriteData.width = LINK_UP_WIDTH;
		spriteData.height = LINK_UP_HEIGHT;
		flipHorizontal(0);
		moveKeyWasPressed = true;
		isRunning = true;
		direction = 0;

	}
	if (input->isKeyDown(VK_DOWN))
	{
		Entity::move(0, 1);
		start_x = LINK_DOWN_START_X;
		start_y = LINK_DOWN_START_Y;
		spriteData.width = LINK_DOWN_WIDTH;
		spriteData.height = LINK_DOWN_HEIGHT;
		flipHorizontal(0);
		moveKeyWasPressed = true;
		isRunning = true;
		direction = 2;
	}


	if (input->isKeyDown(VK_LEFT))
	{
		Entity::move(-1, 0);
		start_x = LINK_SIDE_START_X;
		start_y = LINK_SIDE_START_Y;
		spriteData.width = LINK_SIDE_WIDTH;
		spriteData.height = LINK_SIDE_HEIGHT;
		flipHorizontal(1);
		moveKeyWasPressed = true;
		isRunning = true;
		direction = 3;
	}
	if (input->isKeyDown(VK_RIGHT))
	{
		Entity::move(1, 0);
		start_x = LINK_SIDE_START_X;
		start_y = LINK_SIDE_START_Y;
		spriteData.width = LINK_SIDE_WIDTH;
		spriteData.height = LINK_SIDE_HEIGHT;
		flipHorizontal(0);
		moveKeyWasPressed = true;
		isRunning = true;
		direction = 1;
	}


	if (moveKeyWasPressed)
	{
		if (isMoving == false)
			setCurrentFrame(1);
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


void Link::setImageFrame(int startX, int startY, int width, int height)
{
		start_x = startX;
		start_y = startY;
		spriteData.width = width;
		spriteData.height = height;
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
	setRect();

}


void Link::update(float frameTime)
{
	



	bool keyWasPressed = false;

	checkEndOfMovement();


	if (!isAttacking)
		initiateMovement();


		
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
		}
		else if (direction == 1)
		{

			setImageFrame(LINK_ATK_SIDE_START_X, LINK_ATK_SIDE_START_Y
				, LINK_ATK_SIDE_WIDTH, LINK_ATK_SIDE_HEIGHT);

		}
		else if (direction == 2)
		{

			setImageFrame(LINK_ATK_DOWN_START_X, LINK_ATK_DOWN_START_Y
				, LINK_ATK_SIDE_WIDTH, LINK_ATK_SIDE_HEIGHT);
			setX(spriteData.x - 4);
			setY(spriteData.y + 3);


		}
		else if (direction == 3)
		{

			setImageFrame(LINK_ATK_SIDE_START_X, LINK_ATK_SIDE_START_Y
				, LINK_ATK_SIDE_WIDTH, LINK_ATK_SIDE_HEIGHT);
			flipHorizontal(1);
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


		if (direction == 2)
		{
			setX(spriteData.x + 4);
			setY(spriteData.y - 3);
		}


	}
}


