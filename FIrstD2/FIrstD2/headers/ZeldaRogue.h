// Programming 2D Games
// Copyright (c) 2011 by: 
// Charles Kelly
// Chapter 4 spacewar.h v1.0

#ifndef _SPACEWAR_H             // prevent multiple definitions if this 
#define _SPACEWAR_H             // ..file is included in more than one place
#define WIN32_LEAN_AND_MEAN


#define LINK_TEXTURE "./res/LinkSpriteSheet.png"
#define SMALL_ENEMIES_TEXTURE "./res/small_enemies.png"

#include "game.h"
#include "Entity.h"
#include "Link.h"
#include "Octorok.h"

//=============================================================================
// Create game class
//=============================================================================
class ZeldaRogue : public Game
{
private:
    // variables

	TextureManager linkTexture;       //LINK texture

	TextureManager small_enemiesTexture; //small enemies texture


	Link link;

	Octorok octorok;

public:
    // Constructor
    ZeldaRogue();

    // Destructor
    virtual ~ZeldaRogue();

    // Initialize the game
    void initialize(HWND hwnd);
    void update();      // must override pure virtual from Game
    void ai();          // "
    void collisions();  // "
    void render();      // "
    void releaseAll();
    void resetAll();
};

#endif
