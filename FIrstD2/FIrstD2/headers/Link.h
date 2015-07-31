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

class Link : public Entity
{



protected:

	Input *input;
	bool isAttacking;
	bool moveKeyWasPressed;



public:

	//Constructor
	Link();

	//Destructor
	virtual ~Link();


	virtual bool initialize(Game *gamePtr, int startX, int startY, int width, int height, int ncols,
		TextureManager *textureM);

	virtual void update(float frameTime);


	void initateMovement();


	void setNeutral(int startX, int startY, int width, int height);


	void setNeutralByDir();


};






#endif