#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "myLib.h"
#include "title.h"
#include "tile1.h"
#include "tile2.h"
#include "tile3.h"
#include "tile4.h"
#include "tile5.h"
#include "tile6.h"
#include "tile7.h"
#include "tile8.h"
#include "blanktile.h"
#include "grid.h"
#include "game.h"
#include "welcome.h"
#include "instruction1.h"
#include "instruction2.h"
#include "instruction3.h"
#include "instruction4.h"

// variables
int x_cords[3] = {51, 100, 148 };
int y_cords[3] = {11, 60, 109};
int game_state[3][3];


// prototypes
bool wonGame();
void Welcome();
void loadTiles();
void Instructions();
void startGame();
bool isValidMove();
void switchTile(Move_t move);


// win checking function
bool wonGame() 
{
	bool result = true;

	for (int i = 0; i < WIDTH; ++i)
	{
		for (int j = 0; j < HEIGHT; ++j)
		{
			if (game_grid[i][j].value != ((i * HEIGHT) + j + 1))
			{
				result = false;
			}
		}
	}

	return result;
}

void Welcome()
{
	REG_DISPCTL = MODE3 | BG2_ENABLE;
	WaitForVblank();
	drawImage3(0,0,160,240,title);

	while(!KEY_DOWN_NOW(BUTTON_A));
	while(KEY_DOWN_NOW(BUTTON_A));
}

void Instructions()
{	
	REG_DISPCTL = MODE3 | BG2_ENABLE;

	WaitForVblank();
	drawImage3(0,0,160,240,welcome);
	while(!KEY_DOWN_NOW(BUTTON_A));
	while(KEY_DOWN_NOW(BUTTON_A));
	
	WaitForVblank();
	drawImage3(0,0,160,240,instruction1);
	while(!KEY_DOWN_NOW(BUTTON_A));
	while(KEY_DOWN_NOW(BUTTON_A));

	WaitForVblank();
	drawImage3(0,0,160,240,instruction2);
	while(!KEY_DOWN_NOW(BUTTON_A));
	while(KEY_DOWN_NOW(BUTTON_A));

	WaitForVblank();
	drawImage3(0,0,160,240,instruction3);
	while(!KEY_DOWN_NOW(BUTTON_A));
	while(KEY_DOWN_NOW(BUTTON_A));

	WaitForVblank();
	drawImage3(0,0,160,240,instruction4);
	while(!KEY_DOWN_NOW(BUTTON_A));
	while(KEY_DOWN_NOW(BUTTON_A));


}

void loadTiles()
{
	// instance variables 

	Tile tile_1;
	Tile tile_2;
	Tile tile_3;
	Tile tile_4;
	Tile tile_5;
	Tile tile_6;
	Tile tile_7;
	Tile tile_8;
	Tile tile_blank;

	tile_1.image_data = tile1;
	tile_1.x_cord = 0;
	tile_1.y_cord = 0;
	tile_1.value = 1;

	tile_2.image_data = tile2;
	tile_2.x_cord = 1;
	tile_2.y_cord = 0;
	tile_2.value = 2;

	tile_3.image_data = tile3;
	tile_3.x_cord = 2;
	tile_3.y_cord = 0;
	tile_3.value = 3;

	tile_4.image_data = tile4;
	tile_4.x_cord = 0;
	tile_4.y_cord = 1;
	tile_4.value = 4;

	tile_5.image_data = tile5;
	tile_5.x_cord = 1;
	tile_5.y_cord = 1;
	tile_5.value = 5;

	tile_6.image_data = tile6;
	tile_6.x_cord = 2;
	tile_6.y_cord = 1;
	tile_6.value = 6;

	tile_7.image_data = tile7;
	tile_7.x_cord = 0;
	tile_7.y_cord = 2;
	tile_7.value = 7;

	tile_8.image_data = tile8;
	tile_8.x_cord = 1;
	tile_8.y_cord = 2;
	tile_8.value = 8;

	tile_blank.image_data = blanktile;
	tile_blank.x_cord = 2;
	tile_blank.y_cord = 2;
	tile_blank.value = 9;

	// Settuping up a grid of tiles 
	game_grid[0][0] = tile_8;
	game_grid[0][1] = tile_7;
	game_grid[0][2] = tile_6;
	game_grid[1][0] = tile_5;
	game_grid[1][1] = tile_4;
	game_grid[1][2] = tile_3; 
	game_grid[2][0] = tile_2;
	game_grid[2][1] = tile_1;
	game_grid[2][2] = tile_blank;

	// Updating game state
	game_state[0][0] = 8;
	game_state[0][1] = 7;
	game_state[0][2] = 6;
	game_state[1][0] = 5;
	game_state[1][1] = 4;
	game_state[1][2] = 3;
	game_state[2][0] = 2;
	game_state[2][1] = 1;
	game_state[2][2] = 9;
}

void startGame() 
{
	// draw grid
	WaitForVblank();
	drawImage3(0,0,160,240, grid);

	// draw tiles
	WaitForVblank();
	for (int i = 0; i < HEIGHT; ++i)
	{
		for (int j = 0; j < WIDTH; ++j)
		{
			drawImage3(y_cords[j], x_cords[i], TILE1_WIDTH, TILE1_HEIGHT, game_grid[i][j].image_data);
		}
	}
}

bool isValidMove()
{
	if (game_grid[2][2].x_cord < 2 && move == RIGHT)
	{
		return true;
	} else if (game_grid[2][2].x_cord > 0 && move == LEFT)
	{
		return true;
	} else if (game_grid[2][2].y_cord < 2 && move == DOWN)
	{
		return true;
	} else if (game_grid[2][2].x_cord > 0 && move == UP)
	{
		return true;
	} else
	{
		return false;
	}

}

void waitForMove()
{
	while(!KEY_DOWN_NOW(BUTTON_UP) && !KEY_DOWN_NOW(BUTTON_DOWN) && !KEY_DOWN_NOW(BUTTON_LEFT) && !KEY_DOWN_NOW(BUTTON_RIGHT) && !KEY_DOWN_NOW(BUTTON_SELECT));
	
	if (KEY_DOWN_NOW(BUTTON_UP))
	{
		drawRect3(80,120,10,10,WHITE);
		move = UP;

	} else if (KEY_DOWN_NOW(BUTTON_DOWN))
	{
		drawRect3(80,120,10,10,RED);
		move = DOWN;

	} else if (KEY_DOWN_NOW(BUTTON_LEFT))
	{
		drawRect3(80,120,10,10,BLUE);
		move = LEFT;

	}else if (KEY_DOWN_NOW(BUTTON_RIGHT))
	{
		drawRect3(80,120,10,10,GREEN);
		move = RIGHT;

	}else if (KEY_DOWN_NOW(BUTTON_SELECT))
	{
		state = INTRO;
		move = INVALID;
		drawRect3(80,120,10,10, CYAN);
	} else
	{
		move = INVALID;
	}

	while(KEY_DOWN_NOW(BUTTON_UP) || KEY_DOWN_NOW(BUTTON_DOWN) || KEY_DOWN_NOW(BUTTON_LEFT) || KEY_DOWN_NOW(BUTTON_RIGHT) || KEY_DOWN_NOW(BUTTON_SELECT));

}

void switchTile(Move_t move)
{
	// get blank tiles current co-ordinates 
	int x_blank = game_grid[2][2].x_cord;
	int y_blank = game_grid[2][2].y_cord;

	int x_tile;
	int y_tile;


	if (move == UP)
	{
		x_tile = x_blank;
		y_tile = y_blank - 1;
	} else if (move == DOWN)
	{
		x_tile = x_blank;
		y_tile = y_blank + 1;
	} else if (move == RIGHT)
	{
		x_tile = x_blank + 1;
		y_tile = y_blank;
	} else if (move == LEFT)
	{
		x_tile = x_blank - 1;
		y_tile = y_blank;
	}
}



// Draw functions:
// have to switch the game state as well as 
// have to draw the 2 switched tiles again in new locations


// can have a check for valid move function.


