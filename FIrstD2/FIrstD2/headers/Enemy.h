#ifndef _ENEMY_H               // Prevent multiple definitions if this 
#define _ENEMY_H                // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "Entity.h"
#include "Link.h"



class Enemy : public Entity
{


protected:



public:

	//Constructor
	Enemy();

	//Destructor
	virtual ~Enemy();


	virtual bool initialize(Game *gamePtr, int startX, int startY, int width, int height, int ncols,
		TextureManager *textureM);


	
	virtual void update(float frameTime);


	/*
	//initiate movement, checks to see which keys are pressed
	//then makes necssary changes thus move animation begins
	void initiateMovement();
	//initiate attack, checks to see if attack kesy are pressed
	//then makes the necessary changes thus attack animation begins
	void initiateAttack();

	//checks to see if attack animation ended
	//then makes the necessary changes to go back to original neutral state
	void checkEndOfMovement();

	//sets the netural animation by direction
	void setNeutralByDir();


	//attack function
	void attack();

	bool collision();
	*/
	virtual void setMoveOffset(){}

	virtual void collisionWithPlayer(Link link);

};







#endif