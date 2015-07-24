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


	if (!mainTexture.initialize(graphics, MAIN_TEXTURE, 8))
		throw (GameError(gameErrorNS::FATAL_ERROR,
		"Error initializing main texture"));


	if (!link.initialize((Game*)this, 0, 0, 16, 24, 8, &mainTexture))
		throw (GameError(gameErrorNS::FATAL_ERROR,
		"Error intializing link image"));

	link.setFrames(0, 7);
	link.setFrameDelay(0.05f);
	link.setCurrentFrame(0);


	link.setScale(1.0f);




    return;
}

//=============================================================================
// Update all game items
//=============================================================================
void ZeldaRogue::update()
{

	link.update(frameTime);


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
	graphics->spriteEnd();
}

//=============================================================================
// The graphics device was lost.
// Release all reserved video memory so graphics device may be reset.
//=============================================================================
void ZeldaRogue::releaseAll()
{
    Game::releaseAll();
	mainTexture.onLostDevice();
    return;
}

//=============================================================================
// The grahics device has been reset.
// Recreate all surfaces.
//=============================================================================
void ZeldaRogue::resetAll()
{
    Game::resetAll();
	mainTexture.onResetDevice();
    return;
}
