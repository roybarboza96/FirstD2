// Programming 2D Games
// Copyright (c) 2011 by: 
// Charles Kelly
// Game Engine Part 1
// Chapter 4 spacewar.cpp v1.0
// Spacewar is the class we create.

#include "ZeldaRogue.h"

//=============================================================================
// Constructor
//=============================================================================
ZeldaRogue::ZeldaRogue()
{}

//=============================================================================
// Destructor
//=============================================================================
ZeldaRogue::~ZeldaRogue()
{
    releaseAll();           // call onLostDevice() for every graphics item
}

//=============================================================================
// Initializes the game
// Throws GameError on error
//=============================================================================
void ZeldaRogue::initialize(HWND hwnd)
{
    Game::initialize(hwnd); // throws GameError


	if (!linkTexture.initialize(graphics, LINK_TEXTURE, 8))
		throw (GameError(gameErrorNS::FATAL_ERROR,
		"Error initializing LINK texture"));

	if (!small_enemiesTexture.initialize(graphics, SMALL_ENEMIES_TEXTURE, 8))
		throw (GameError(gameErrorNS::FATAL_ERROR,
		"Error initializing SMALL ENEMIES texture"));




	if (!link.initialize((Game*)this, 0, 0, 16, 24, 8, &linkTexture))
		throw (GameError(gameErrorNS::FATAL_ERROR,
		"Error intializing link image"));

	if (!octorok.initialize((Game*)this, 0, 0, 16, 16, 4, &small_enemiesTexture))
		throw (GameError(gameErrorNS::FATAL_ERROR,
		"Error intializing octorok image"));

	link.setFrames(0, 7);
	link.setFrameDelay(0.04f);
	link.setCurrentFrame(0);

	link.setScale(2.0);


	octorok.setX(50.0f);
	octorok.setY(50.0f);



    return;
}

//=============================================================================
// Update all game items
//=============================================================================
void ZeldaRogue::update()
{

	link.update(frameTime);
	octorok.update(frameTime);


}

//=============================================================================
// Artificial Intelligence
//=============================================================================
void ZeldaRogue::ai()
{}

//=============================================================================
// Handle collisions
//=============================================================================
void ZeldaRogue::collisions()
{}

//=============================================================================
// Render game items
//=============================================================================
void ZeldaRogue::render()
{
	graphics->spriteBegin();
	link.draw();
	octorok.draw();
	graphics->spriteEnd();
}

//=============================================================================
// The graphics device was lost.
// Release all reserved video memory so graphics device may be reset.
//=============================================================================
void ZeldaRogue::releaseAll()
{
    Game::releaseAll();
	linkTexture.onLostDevice();
	small_enemiesTexture.onLostDevice();
    return;
}

//=============================================================================
// The grahics device has been reset.
// Recreate all surfaces.
//=============================================================================
void ZeldaRogue::resetAll()
{
    Game::resetAll();
	linkTexture.onResetDevice();
	small_enemiesTexture.onResetDevice();
    return;
}
