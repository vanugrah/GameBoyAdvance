#include "myLib.h"
#include "game.h"
#include "text.h"
#include "win.h"
#include "lose.h"


// global variables
Tile game_grid[WIDTH * HEIGHT];
State_t state = WELCOME;
Move_t move = INVALID;
int move_counter = 0;

int main()
{
	REG_DISPCTL = MODE3 | BG2_ENABLE;
	
	
	
	while(1) // Game Loop
	{
		
		// load title image
		while (state == WELCOME) 
		{
			Welcome();
			move_counter = 0;
			// load the tile image_data and the grid into program
			loadTiles();
			
		} // welcome state

		// load the welcome page and instructions
		while (state == INTRO0) 
		{
			intro0();
			
		} //  intro state

		while (state == INTRO1) 
		{
			intro1();
			
			
		} //  intro state

		while (state == INTRO2) 
		{
			intro2();
			
		} //  intro state

		while (state == INTRO3) 
		{
			intro3();
			
		} //  intro state

		while (state == INTRO4) 
		{
			intro4();
			
		} //  intro state


		startGame();

		while (state == PLAYING) 
		{
			// wait for a move
			waitForMove();


			// if the move is valid then switch tiles 
			if (isValidMove(move))
			{
				move_counter++;
				switchTile(move);
			}

			// draw number of moves
			if (state == PLAYING) {
				drawString(0,0, "MOVES: ", LTGRAY);
				drawRect3(10, 10, 20,20, BLACK);
				drawNum(10, 10, move_counter, LTGRAY);
			}
			

			// check win condition
			if (wonGame())
			{
				state = WON;
			}

			// check lose
			if (move_counter >100)
			{
				state = LOSE;
			}

		} // playing state

		while (state == WON)
		{
			drawImage3(0,0,160,240, win);
			waitForMove();
		}

		while (state == LOSE)
		{
			drawImage3(0,0,160,240, lose);
			waitForMove();
		}

	

	} // while gameloop
}
