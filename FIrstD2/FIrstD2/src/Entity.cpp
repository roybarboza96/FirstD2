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

Entity::~Entity()
{

}

bool Entity::initialize(Game *gamePtr,int startX, int startY, int width, int height, int ncols,
	TextureManager *textureM)
{
	hitBox.x = 0.0f;
	hitBox.y = 0.0f;
	hitBox.width = width;
	hitBox.height = height;
	return (Image::initialize(gamePtr->getGraphics(), startX, startY, width, height, ncols,
		textureM));

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
	{
		spriteData.x += speed;
		hitBox.x = spriteData.x;
	}
	else if (x == -1)
	{
		spriteData.x -= speed;
		hitBox.x = spriteData.x;
	}

	if (y == 1)
	{
		spriteData.y += speed;
		hitBox.y = spriteData.y;
	}
	else if (y == -1)
	{
		spriteData.y -= speed;
		hitBox.y = spriteData.y;
	}

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


void Entity::changeHitBox(int x, int y, int width, int height)
{
	hitBox.x = x;
	hitBox.y = y;
	hitBox.width = width;
	hitBox.height = height;
}



void Entity::startHitRecoil()
{
	if (gotHit)
	{
		float midHeight = float(hitBox.height) / 2.0f;
		float midWidth = float(hitBox.width) / 2.0f;
		float midX = hitBox.x + midWidth;
		float midY = hitBox.y + midHeight;
		VECTOR2 midHitBox = VECTOR2(midX, midY);


		float totalRecoil = 1;

		//After this hitMove will be filled up with data to move
		if (hitVector.x == midX && hitVector.y == midY)
		{
			//don't know what to do here
		}
		else
		{
			VECTOR2 temp = hitVector - midHitBox;
			D3DXVec2Normalize(&hitMove, &(temp));
		}

		
		isRecoiling = true;
		gotHit = false;
	}

}




void Entity::recoiling()
{
	spriteData.x = spriteData.x + hitMove.x * 0.2f;
	spriteData.y = spriteData.y + hitMove.y * 0.2f;
	recoilCounter++;

	if (recoilCounter == 5)
	{
		recoilCounter = 0;
		isRecoiling = false;
	}
}







void Entity::setX(float newX)
{
	hitBox.x = newX;
	spriteData.x = newX;
}

void Entity::setY(float newY)
{
	hitBox.y = newY;
	spriteData.y = newY;
}


