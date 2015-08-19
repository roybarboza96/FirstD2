/************************************************
*
* The ocotorok enemy has just basic vertical and horizontal movements
* and also shoots a projectile as it's only attack
*
*************************************************/
#include "Enemy.h"


Enemy::Enemy()
{

}


Enemy::~Enemy()
{

}


bool Enemy::initialize(Game *gamePtr, int startX, int startY, int width, int height, int ncols,
	TextureManager *textureM)
{
	return (Entity::initialize(gamePtr, startX, startY, width, height, ncols,
		textureM));

}