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


void Link::update(float frameTime)
{
	



	bool keyWasPressed = false;
	
	if (input->isKeyDown(VK_UP))
	{
		Entity::move(0, -1);
		start_x = LINK_UP_START_X;
		start_y = LINK_UP_START_Y;
		spriteData.width = LINK_UP_WIDTH;
		spriteData.height = LINK_UP_HEIGHT;
		flipHorizontal(0);
		keyWasPressed = true;
		isRunning = true;
		
	}
	if (input->isKeyDown(VK_DOWN))
	{
		Entity::move(0, 1);
		start_x = LINK_DOWN_START_X;
		start_y = LINK_DOWN_START_Y;
		spriteData.width = LINK_DOWN_WIDTH;
		spriteData.height = LINK_DOWN_HEIGHT;
		flipHorizontal(0);
		keyWasPressed = true;
		isRunning = true;
	}


	if (input->isKeyDown(VK_LEFT))
	{
		Entity::move(-1, 0);
		start_x = LINK_SIDE_START_X;
		start_y = LINK_SIDE_START_Y;
		spriteData.width = LINK_SIDE_WIDTH;
		spriteData.height = LINK_SIDE_HEIGHT;
		flipHorizontal(1);
		keyWasPressed = true;
		isRunning = true;
	}
	if (input->isKeyDown(VK_RIGHT))
	{
		Entity::move(1, 0);
		start_x = LINK_SIDE_START_X;
		start_y = LINK_SIDE_START_Y;
		spriteData.width = LINK_SIDE_WIDTH;
		spriteData.height = LINK_SIDE_HEIGHT;
		flipHorizontal(0);
		keyWasPressed = true;
		isRunning = true;
	}


	if (keyWasPressed)
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


	Entity::update(frameTime);




}



