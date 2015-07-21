#ifndef _LINK_H               // Prevent multiple definitions if this 
#define _LINK_H                // file is included in more than one place
#define WIN32_LEAN_AND_MEAN


#include "Entity.h"


class Link : public Entity
{



protected:

	Input *input;



public:

	//Constructor
	Link();

	//Destructor
	virtual ~Link();


	virtual bool initialize(Game *gamePtr, int width, int height, int ncols,
		TextureManager *textureM);

	virtual void update(float frameTime);


};






#endif