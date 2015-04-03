#include <stdbool.h>

// Creating enums for game state
typedef enum state
{
    WELCOME,
    INTRO0,
    INTRO1,
    INTRO2,
    INTRO3,
    INTRO4,
    PLAYING,
    WON,
    LOSE
} State_t;

// creating enums for move types
typedef enum move
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
	INVALID
} Move_t;

// Creating struct for Tiles 
typedef struct Tile
{
	// All tiles must have the following properties
	int x_cord;
	int y_cord;
	int value;
	const u16* image_data;

} Tile;

// grid dimensions
#define WIDTH 3
#define HEIGHT 3

// variables 
extern Tile game_grid[WIDTH * HEIGHT];
extern Move_t move;
extern State_t state;

// prototypes
bool wonGame();
void Welcome();
void loadTiles();
void startGame();
bool isValidMove();
void waitForMove();
void switchTile(Move_t move);
void printGameState();
void checkReset();
void drawNum(int r, int c, int num, u16 color);
void intro0();
void intro1();
void intro2();
void intro3();
void intro4();
