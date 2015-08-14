#ifndef _ENTITY_H               // Prevent multiple definitions if this 
#define _ENTITY_H                // file is included in more than one place
#define WIN32_LEAN_AND_MEAN


#include "game.h"
#include "image.h"


class Entity : public Image
{



  protected:

	  int health;
	  float speed;
	  int direction;

	  bool isMoving;
	  bool isAttacking;

	  bool isRunning;
	  bool loopingDown;
	  bool frameChanged;





  public:

	  //Constructor
	  Entity();

	  //Destructor
	  virtual ~Entity();


	  //initializer
	  bool initialize(Game *gamePtr, int startX, int startY, int width, int height, int ncols,
		  TextureManager *textureM);


	  //check collisions with the input entity
	  bool check_collision(Entity* other, VECTOR2 *hit);



	  //move based on entity speed note that x and y don't represent how much
	  //the entity is moving but just the direction of the movement
	  void move(int x, int y);

	  //move based by direction
	  //it will call the move function
	  void moveByDir();

	  //Setters
	  void set_speed(float new_speed){ speed = new_speed; }
	  void set_health(int new_health){ health = new_health; }
	  void set_isMoving(bool isNowMoving){ isMoving = isNowMoving; }
	


	  //Getters
	  float get_speed(){ return speed; }
	  int get_health(){ return health; }
	  bool get_isMoving(){ return isMoving; }


	  //
	  void update(float frameTime);


	  //checks frame animations and directions to make correct offset
	  //thus adjustments to animation frames can be made to make them look
	  //smoother
	  void virtual setMoveOffset(){};




	  //sets the animation frame by parameters passed
	  void setImageFrame(int startX, int startY, int width, int height);








};






#endif