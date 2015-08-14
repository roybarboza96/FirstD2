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
	direction = 0;
	isMoving = false;
	isRunning = false;
	loopingDown = false;
	frameChanged = false;


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



void Entity::moveByDir()
{
	if (direction == 0)
		Entity::move(0, -1);
	else if (direction == 1)
		Entity::move(1, 0);
	else if (direction == 2)
		Entity::move(0, 1);
	else if (direction == 3)
		Entity::move(-1, 0);
}

void Entity::update(float frameTime)
{

	if (endFrame - startFrame > 0 && isMoving)          // if animated sprite
	{
		animTimer += frameTime;             // total elapsed time

		if (animTimer > frameDelay)
		{
			frameChanged = true;
			animTimer -= frameDelay;
			if (isRunning)
			{
				if (loopingDown)
					currentFrame--;
				else
					currentFrame++;
			}
			else
				currentFrame++;

			this->setMoveOffset();


			if (currentFrame < startFrame || currentFrame > endFrame)
			{

				if (loop == true)            // if looping animation
				{

					if (isRunning)
					{

						if (currentFrame > endFrame)
						{

							loopingDown = true;
							currentFrame = endFrame;

						}
						else if (currentFrame < startFrame)
						{

							loopingDown = false;
							currentFrame = startFrame;

						}
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
		else
		{
			frameChanged = false;
		}
	}

}


void Entity::setImageFrame(int startX, int startY, int width, int height)
{
	start_x = startX;
	start_y = startY;
	spriteData.width = width;
	spriteData.height = height;
}