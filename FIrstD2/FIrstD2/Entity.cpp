/************************
 * Entity Class
 * It will represent the generic entity and will be the parent class of specific entities i.e. player
 * and enemies
 ************************/

#include "Entity.h"


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


