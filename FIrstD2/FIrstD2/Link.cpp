/****************************************************************
*
*	The main character/user character. This is where the input is used to give
*   direct control over this character. 
***********************************************************/
#include "Link.h"



Link::Link()
{
	health = 1;
	speed = 3;
	isMoving = false;
	loop = false;
}




bool Link::initialize(Game *gamePtr, int width, int height, int ncols,
	TextureManager *textureM)
{
	input = gamePtr->getInput();
	return (Entity::initialize(gamePtr, width, height, ncols,
		textureM));

}

Link::~Link()
{

}


void Link::update(float frameTime)
{
	Entity::update(frameTime);


	if (input->anyKeyPressed())
		loop = true;

	if (input->isKeyDown(VK_UP))
		Entity::move(0, -1);
	if (input->isKeyDown(VK_DOWN))
		Entity::move(0, 1);
	if (input->isKeyDown(VK_LEFT))
		Entity::move(-1, 0);
	if (input->isKeyDown(VK_RIGHT))
		Entity::move(1, 0);


}



