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
#include "text.h"
#include "welcome.h"
#include "instruction1.h"
#include "instruction2.h"
#include "instruction3.h"
#include "instruction4.h"
#include "win.h"
#include "lose.h"

// variables
int x_cords[3] = {51, 100, 148 };
int y_cords[3] = {11, 60, 109};
int game_state[3][3];

u16 colors[] = {RED, GREEN, BLUE, CYAN, MAGENTA, YELLOW, WHITE, BLACK, LTGRAY};

// prototypes
bool wonGame();
void Welcome();
void loadTiles();
void startGame();
bool isValidMove();
void switchTile(Move_t move);
void printGameState();
void checkReset();
void drawNum(int r, int c, int num, u16 color);
void intro0();
void intro1();
void intro2();
void intro3();
void intro4();

// win checking function
bool wonGame() 
{
	bool result = true;

	for (int i = 0; i < WIDTH; ++i)
	{
		for (int j = 0; j < HEIGHT; ++j)
		{
			if (game_state[j][i] != ((i * HEIGHT) + j + 1))
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

	while(!KEY_DOWN_NOW(BUTTON_A) && !KEY_DOWN_NOW(BUTTON_SELECT));

	if (KEY_DOWN_NOW(BUTTON_A))
	{
		state = INTRO0;
	} else 
	{
		state = WELCOME;
	}

	while(KEY_DOWN_NOW(BUTTON_A)|| KEY_DOWN_NOW(BUTTON_SELECT));


}

void intro0()
{
	REG_DISPCTL = MODE3 | BG2_ENABLE;

	WaitForVblank();
	drawImage3(0,0,160,240,welcome);

	while(!KEY_DOWN_NOW(BUTTON_A) && !KEY_DOWN_NOW(BUTTON_SELECT));
		if (KEY_DOWN_NOW(BUTTON_A))
		{
			state = INTRO1;
		} else 
		{
			state = WELCOME;
		}
	while(KEY_DOWN_NOW(BUTTON_A)|| KEY_DOWN_NOW(BUTTON_SELECT));
}

void intro1()
{
	REG_DISPCTL = MODE3 | BG2_ENABLE;

	WaitForVblank();
	drawImage3(0,0,160,240,instruction1);

	while(!KEY_DOWN_NOW(BUTTON_A) && !KEY_DOWN_NOW(BUTTON_SELECT));
		if (KEY_DOWN_NOW(BUTTON_A))
		{
			state = INTRO2;
		} else 
		{
			state = WELCOME;
		}
	while(KEY_DOWN_NOW(BUTTON_A)|| KEY_DOWN_NOW(BUTTON_SELECT));
}

void intro2()
{
	REG_DISPCTL = MODE3 | BG2_ENABLE;

	WaitForVblank();
	drawImage3(0,0,160,240,instruction2);

	while(!KEY_DOWN_NOW(BUTTON_A) && !KEY_DOWN_NOW(BUTTON_SELECT));
		if (KEY_DOWN_NOW(BUTTON_A))
		{
			state = INTRO3;
		} else 
		{
			state = WELCOME;
		}
	while(KEY_DOWN_NOW(BUTTON_A)|| KEY_DOWN_NOW(BUTTON_SELECT));
}

void intro3()
{
	REG_DISPCTL = MODE3 | BG2_ENABLE;

	WaitForVblank();
	drawImage3(0,0,160,240,instruction3);

	while(!KEY_DOWN_NOW(BUTTON_A) && !KEY_DOWN_NOW(BUTTON_SELECT));
		if (KEY_DOWN_NOW(BUTTON_A))
		{
			state = INTRO4;
		} else 
		{
			state = WELCOME;
		}
	while(KEY_DOWN_NOW(BUTTON_A)|| KEY_DOWN_NOW(BUTTON_SELECT));
}

void intro4()
{
	REG_DISPCTL = MODE3 | BG2_ENABLE;

	WaitForVblank();
	drawImage3(0,0,160,240,instruction4);

	while(!KEY_DOWN_NOW(BUTTON_A) && !KEY_DOWN_NOW(BUTTON_SELECT));
		if (KEY_DOWN_NOW(BUTTON_A))
		{
			state = PLAYING;
		} else 
		{
			state = WELCOME;
		}
	while(KEY_DOWN_NOW(BUTTON_A)|| KEY_DOWN_NOW(BUTTON_SELECT));
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
	tile_1.x_cord = 1;
	tile_1.y_cord = 2;
	tile_1.value = 1;

	tile_2.image_data = tile2;
	tile_2.x_cord = 0;
	tile_2.y_cord = 2;
	tile_2.value = 2;

	tile_3.image_data = tile3;
	tile_3.x_cord = 2;
	tile_3.y_cord = 1;
	tile_3.value = 3;

	tile_4.image_data = tile4;
	tile_4.x_cord = 1;
	tile_4.y_cord = 1;
	tile_4.value = 4;

	tile_5.image_data = tile5;
	tile_5.x_cord = 0;
	tile_5.y_cord = 1;
	tile_5.value = 5;

	tile_6.image_data = tile6;
	tile_6.x_cord = 2;
	tile_6.y_cord = 0;
	tile_6.value = 6;

	tile_7.image_data = tile7;
	tile_7.x_cord = 1;
	tile_7.y_cord = 0;
	tile_7.value = 7;

	tile_8.image_data = tile8;
	tile_8.x_cord = 0;
	tile_8.y_cord = 0;
	tile_8.value = 8;

	tile_blank.image_data = blanktile;
	tile_blank.x_cord = 2;
	tile_blank.y_cord = 2;
	tile_blank.value = 9;

	// Settuping up a grid of tiles 
	game_grid[0] = tile_blank;
	game_grid[1] = tile_1;
	game_grid[2] = tile_2;
	game_grid[3] = tile_3;
	game_grid[4] = tile_4;
	game_grid[5] = tile_5; 
	game_grid[6] = tile_6;
	game_grid[7] = tile_7;
	game_grid[8] = tile_8;

	// Updating game state
	game_state[0][0] = 8;
	game_state[0][1] = 5;
	game_state[0][2] = 2;
	game_state[1][0] = 7;
	game_state[1][1] = 4;
	game_state[1][2] = 1;
	game_state[2][0] = 6;
	game_state[2][1] = 3;
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
			// 8, 7, 6,
			// 5, 4, 3, 
			// 2, 1, 0
			drawImage3( y_cords[i], x_cords[j], TILE1_WIDTH, TILE1_HEIGHT, game_grid[((WIDTH * HEIGHT) - 1) - (WIDTH * i) - j].image_data);
		}
	}
}

bool isValidMove()
{
	if (game_grid[0].x_cord < 2 && move == RIGHT)
	{
		return true;
	} else if (game_grid[0].x_cord > 0 && move == LEFT)
	{
		return true;
	} else if (game_grid[0].y_cord < 2 && move == DOWN)
	{
		return true;
	} else if (game_grid[0].y_cord > 0 && move == UP)
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
		//drawRect3(80,120,10,10,WHITE);
		move = UP;

	} else if (KEY_DOWN_NOW(BUTTON_DOWN))
	{
		//drawRect3(80,120,10,10,RED);
		move = DOWN;

	} else if (KEY_DOWN_NOW(BUTTON_LEFT))
	{
		//drawRect3(80,120,10,10,BLUE);
		move = LEFT;

	}else if (KEY_DOWN_NOW(BUTTON_RIGHT))
	{
		//drawRect3(80,120,10,10,GREEN);
		move = RIGHT;

	}else if (KEY_DOWN_NOW(BUTTON_SELECT))
	{
		state = WELCOME;
		move = INVALID;
		//drawRect3(80,120,10,10, CYAN);
	} else
	{
		move = INVALID;
	}

	while(KEY_DOWN_NOW(BUTTON_UP) || KEY_DOWN_NOW(BUTTON_DOWN) || KEY_DOWN_NOW(BUTTON_LEFT) || KEY_DOWN_NOW(BUTTON_RIGHT) || KEY_DOWN_NOW(BUTTON_SELECT));

}

void switchTile(Move_t move)
{
	REG_DISPCTL = MODE3 | BG2_ENABLE;

	// get blank tiles current co-ordinates 
	int x_blank = game_grid[0].x_cord;
	int y_blank = game_grid[0].y_cord;

	// calcualte co-ordinates for the tile that you need to switch with the blank tile
	int x_tile = 0;
	int y_tile = 0;
	int tile_to_move = 0;

	if (move == UP)
	{
		x_tile = x_blank;
		y_tile = y_blank - 1;
		// draw black tiles over the 2 tiles you need to move


	} else if (move == DOWN)
	{
		x_tile = x_blank;
		y_tile = y_blank + 1;
	} else if (move == RIGHT)
	{
		x_tile = x_blank + 1;
		y_tile = y_blank;
	} else //(move == LEFT)
	{
		x_tile = x_blank - 1;
		y_tile = y_blank;
	}

	tile_to_move = game_state[x_tile][y_tile];

	// draw black tiles over the 2 tiles you need to move
	WaitForVblank();
	drawRect3(y_cords[y_tile], x_cords[x_tile], TILE1_WIDTH, TILE1_HEIGHT, BLACK);
	drawRect3(y_cords[y_blank], x_cords[x_blank], TILE1_WIDTH, TILE1_HEIGHT, BLACK);

	// draw the two tiles 
	WaitForVblank();
	drawImage3(y_cords[y_tile], x_cords[x_tile], TILE1_WIDTH, TILE1_HEIGHT, game_grid[0].image_data);
	drawImage3(y_cords[y_blank], x_cords[x_blank], TILE1_WIDTH, TILE1_HEIGHT, game_grid[tile_to_move].image_data);		

	// update game_grid
	game_grid[tile_to_move].x_cord = x_blank;
	game_grid[tile_to_move].y_cord = y_blank;

	game_grid[0].x_cord = x_tile;
	game_grid[0].y_cord = y_tile;

	// update game_state
	game_state[x_blank][y_blank] = tile_to_move;
	game_state[x_tile][y_tile] = 9;

}

void printGameState() 
{
	REG_DISPCTL = MODE3 | BG2_ENABLE;

	for (int i = 0; i < WIDTH; ++i)
	{
		for (int j = 0; j < HEIGHT; ++j)
		{
			drawChar( (10 * ((3 * i)+j)), 0, game_state[i][j] + 48, WHITE);
		}
	}

}



void clearGameState()
{
	REG_DISPCTL = MODE3 | BG2_ENABLE;

	drawRect3(0,0, 20, 120, BLACK);
}

void checkReset()
{
	if (KEY_DOWN_NOW(BUTTON_SELECT)) 
	{
		state = WELCOME;
	}
}

void drawNum(int r, int c, int num, u16 color)
{
	int counter = 0;
	int numbers[3];

	while (num != 0)
	{
		numbers[counter] = num%10;
		num = num/10;
		counter++;
	}

	if (counter == 0)
	{
		drawChar(r, c ,48, color);
	} else if (counter == 1)
	{
		drawChar(r, c, numbers[0] + 48, color);	 
	} else if (counter == 2)
	{
		drawChar(r, c  , numbers[1] + 48, color);
		drawChar(r, c + 5, numbers[0] + 48, color);
	} else 
	{
		drawChar(r, c , numbers[2] + 48, color);
		drawChar(r, c + 5 , numbers[1] + 48, color);
		drawChar(r, c + 10, numbers[0] + 48, color);
	}
}


