#ifndef _ENTITY_H               // Prevent multiple definitions if this 
#define _ENTITY_H                // file is included in more than one place
#define WIN32_LEAN_AND_MEAN


#include "game.h"
#include "image.h"


typedef struct Box
{
	float x;
	float y;
	int width;
	int height;
};


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
	  bool isRecoiling;



	  //boolean to tell if the entity got hit
	  bool gotHit;

	  //the point at which point entity was hit
	  //also it is repsective to the hit box x and y values
	  //also these are only accurate if and only if gotHit is set to true
	  //Note: that if these values are greater than x + width and y + height then these
	  //      are in valid
	  VECTOR2 hitVector;

	  //the vector to move in the direction of getting hit
	  VECTOR2 hitMove;



	  //the hit box to the body
	  Box hitBox;







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


	  //collision with any entity besides the player character
	  bool virtual collision(){
		  return false;
	  }


	  //function that checks with collision of player character only
	  bool virtual collisionWithPlayer(Entity player){
		  return false;
	  }


	  //the move when hit, figures out where the movement of the recoils is
	  void startHitRecoil();
	  //the actual movement of recoiling
	  void recoiling();


	  //changing the hitbox
	  void changeHitBox(int x, int y, int width, int height);


	  void setX(float newX);
	  void setY(float newY);








};






#endif