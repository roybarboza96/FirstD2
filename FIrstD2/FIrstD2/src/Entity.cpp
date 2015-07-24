/************************
 * Entity Class
 * It will represent the generic entity and will be the parent class of specific entities i.e. player
 * and enemies
 ************************/

#include "Entity.h"


Entity::Entity()
{
	speed = 1.0f;
	health = 3;
	isMoving = false;
	isRunning = false;
	loopingDown = false;


}

bool Entity::initialize(Game *gamePtr,int startX, int startY, int width, int height, int ncols,
	TextureManager *textureM)
{
	return (Image::initialize(gamePtr->getGraphics(), startX, startY, width, height, ncols,
		textureM));

}

Entity::~Entity()
{

}

bool Entity::check_collision(Entity *other, VECTOR2 *hit)
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
void Entity::move(int x, int y)
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

void Entity::update(float frameTime)
{

	if (endFrame - startFrame > 0 && isMoving)          // if animated sprite
	{
		animTimer += frameTime;             // total elapsed time
		if (animTimer > frameDelay)
		{
			animTimer -= frameDelay;
			if (loopingDown)
				currentFrame--;
			else
				currentFrame++;
			if (currentFrame < startFrame || currentFrame > endFrame)
			{
				if (loop == true)            // if looping animation
				{
					if (isRunning)
					{
						if (currentFrame > endFrame)
							loopingDown = true;
						else if (currentFrame < startFrame)
							loopingDown = false;
					}
					else
						currentFrame = startFrame;

				}
				else                        // not looping animation
				{
					currentFrame = endFrame;
					animComplete = true;    // animation complete
				}
			}
			setRect();                      // set spriteData.rect
		}
	}

}


