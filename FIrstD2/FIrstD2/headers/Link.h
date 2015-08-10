#ifndef _LINK_H               // Prevent multiple definitions if this 
#define _LINK_H                // file is included in more than one place
#define WIN32_LEAN_AND_MEAN


#include "Entity.h"


#define LINK_SIDE_START_X 0
#define LINK_SIDE_START_Y 25
#define LINK_SIDE_WIDTH 19
#define LINK_SIDE_HEIGHT 24


#define LINK_DOWN_START_X 0
#define LINK_DOWN_START_Y 0
#define LINK_DOWN_WIDTH 16
#define LINK_DOWN_HEIGHT 24


#define LINK_UP_START_X 0
#define LINK_UP_START_Y 50
#define LINK_UP_WIDTH 17
#define LINK_UP_HEIGHT 24


#define LINK_ATK_DOWN_START_X 0
#define LINK_ATK_DOWN_START_Y 80
#define LINK_ATK_DOWN_WIDTH 32
#define LINK_ATK_DOWN_HEIGHT 32


#define LINK_ATK_UP_START_X 0
#define LINK_ATK_UP_START_Y 113
#define LINK_ATK_UP_WIDTH 32
#define LINK_ATK_UP_HEIGHT 38

#define LINK_ATK_SIDE_START_X 0
#define LINK_ATK_SIDE_START_Y 152
#define LINK_ATK_SIDE_WIDTH 31
#define LINK_ATK_SIDE_HEIGHT 31

class Link : public Entity
{



protected:

	Input *input;
	bool moveKeyWasPressed;



public:

	//Constructor
	Link();

	//Destructor
	virtual ~Link();


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


	//sets the animation frame by parameters passed
	void setImageFrame(int startX, int startY, int width, int height);


	//sets the netural animation by direction
	void setNeutralByDir();








};






#endif