// Programming 2D Games
// Copyright (c) 2011 by: 
// Charles Kelly
// Game Engine Part 1
// Chapter 4 spacewar.cpp v1.0
// Spacewar is the class we create.

#include "spaceWar.h"

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

    return;
}

//=============================================================================
// Update all game items
//=============================================================================
void ZeldaRogue::update()
{}

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
{}

//=============================================================================
// The graphics device was lost.
// Release all reserved video memory so graphics device may be reset.
//=============================================================================
void ZeldaRogue::releaseAll()
{
    Game::releaseAll();
    return;
}

//=============================================================================
// The grahics device has been reset.
// Recreate all surfaces.
//=============================================================================
void ZeldaRogue::resetAll()
{
    Game::resetAll();
    return;
}
