#ifndef _OCTOROK_H               // Prevent multiple definitions if this 
#define _OCTOROK_H                // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "Entity.h"



#define OCT_UP_START_X 0
#define OCT_UP_START_Y 18
#define OCT_UP_WIDTH 16
#define OCT_UP_HEIGHT 16

#define OCT_DOWN_START_X 0
#define OCT_DOWN_START_Y 0
#define OCT_DOWN_WIDTH 16
#define OCT_DOWN_HEIGHT 17

#define OCT_SIDE_START_X 0
#define OCT_SIDE_START_Y 35
#define OCT_SIDE_WIDTH 18
#define OCT_SIDE_HEIGHT 16

#define OCT_UP_ATK_START_X 0
#define OCT_UP_ATK_START_Y 0
#define OCT_UP_ATK_WIDTH 0
#define OCT_UP_ATK_HEIGHT 0

#define OCT_DOWN_ATK_START_X 0
#define OCT_DOWN_ATK_START_Y 0
#define OCT_DOWN_ATK_WIDTH 0
#define OCT_DOWN_ATK_HEIGHT 0

#define OCT_SIDE_ATK_START_X 0
#define OCT_SIDE_ATK_START_Y 0
#define OCT_SIDE_ATK_WIDTH 0
#define OCT_SIDE_ATK_HEIGHT 0





class Octorok : public Entity
{


protected:

	Entity projectile;
	int numSteps;
	int endSteps;
	bool isIdle;
	int idleCounter;
	int idleEnd;

	Input *input;


public:

	//Constructor
	Octorok();

	//Destructor
	virtual ~Octorok();


	virtual bool initialize(Game *gamePtr, int startX, int startY, int width, int height, int ncols,
		TextureManager *textureM);

	virtual void update(float frameTime);

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

	void setMoveOffset();


	//attack function
	void attack();



};



#endif