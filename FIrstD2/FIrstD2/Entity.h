


#ifndef _ENTITY_H               // Prevent multiple definitions if this 
#define _ENTITY_H                // file is included in more than one place
#define WIN32_LEAN_AND_MEAN


#include "game.h"
#include "image.h"


class Entity : public Image
{



  protected:

	  int health;
	  int speed;




  public:

	  //Constructor
	  Entity();

	  //Destructor
	  virtual ~Entity();


	  //initializer
	  bool initialize(Game *gamePtr, int width, int height, int ncols,
		  TextureManager *textureM);


	  //check collisions with the input entity
	  bool check_collision(Entity &other, VECTOR2);



	  //move based on entity speed note that x and y don't represent how much
	  //the entity is moving but just the direction of the movement
	  void move(int x, int y);

	  //Setters
	  void set_speed(int new_speed){ speed = new_speed; }
	  void set_health(int new_health){ health = new_health; }


	  //Getters
	  int get_speed(){ return speed; }
	  int get_health(){ return health; }








};






#endif