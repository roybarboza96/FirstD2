/************************
 * Entity Class
 * It will represent the generic entity and will be the parent class of specific entities i.e. player
 * and enemies
 ************************/


#include "headers/Entity.h"


Entity::Entity()
{
	speed = 1;
	health = 3;


}

bool Entity::initialize(Game *gamePtr, int width, int height, int ncols,
	TextureManager *textureM)
{
	return (Image::initialize(gamePtr->getGraphics(), width, height, ncols,
		textureM));

}

Entity::~Entity()
{

}

bool Entity::check_collisions(Entity *other, VECTOR2 *hit)
{
	return false;
}



/**********************
*
*	move - x -> either 1,0,-1 to signal to move in the x-direction right, 
*	            no movement, or left in that order
*	       y -> either 1,0,-1 to signal to move in the y-direction down, 
*               no movement, or up in that order
************************/
void move(int x, int y)
{
	if (x == 1)
		spriteData.x += speed;
	else if (x == -1)
		spriteData.x -= speed;

	if (y == 1)
		spriteData.y += speed;
	else if (y == -1)
		spriteData.y -= speed;

}


