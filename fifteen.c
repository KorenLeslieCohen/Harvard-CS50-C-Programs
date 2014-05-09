/**
 * fifteen.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Implements the Game of Fifteen (generalized to d x d).
 *
 * Usage: ./fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [MIN,MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// board's minimal dimension
#define MIN 3

// board's maximal dimension
#define MAX 9

// board, whereby board[i][j] represents row i and column j
int board[MAX][MAX];

// board's dimension
int d;

// initialize global variables
int tile;
int blankspace;
int x;
int y;
int i;
int j;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);
void save(void);

/**
 * Main function - sets up how game will operate.
 */
int main(int argc, string argv[])
{
    // greet player
    greet();

    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: ./fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < MIN || d > MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            MIN, MIN, MAX, MAX);
        return 2;
    }
    
    // initialixing x and y here so 0 does not reset every time you call move function
    else
    {
        x = (d - 1);
        y = (d - 1);
    }

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // saves the current state of the board (for testing)
        save();

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = GetInt();

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep for animation's sake
        usleep(500000);
    }

    // that's all folks
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1,
 * (i.e., fills board with values but does not actually print them),
 * whereby board[i][j] represents row i and column j.
 */
void init(void)
{
    // TODO
    int dsquared = (d * d);
    int n = 0;

    // two for loops to iterate through 2d array - rows/columns
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            // this will initialize the array counting from largest number down to d * d - 1
            // n is used as a counter so we are subtracting by one more each time 
            n = n + 1;
            board[i][j] = (dsquared - n);
        }
    }   
    // if d is even and the tiles on board odd, swap 1 and 2 so game can be won
    if ((d % 2) == 0)
    {
        int temp = board[d - 1][d - 2];
        board[d - 1][d - 2] = board[d - 1][d - 3];
        board[d - 1][d - 3] = temp; 
    }               
}

/**
 * Prints the board in its current state.
 */
void draw(void)
{
    // TODO nested loops to draw board initialized above
    
    // initialize variables
    int n = 0;
    
    // iterate over rows
    for (int i = 0; i < d; i++)
    {
        // iterate over columns
        for (int j = 0; j < d; j++)
        {
            // subtract by one more each time
            n = (n + 1); 
            
            // print the number of the tile except for the 0 tile
            if (board[i][j] > 0) 
            {
                printf("| %2d ", board[i][j]);
            }
            
            // for 0 tile, print the space for tiles to move
            if (board[i][j] == 0) 
            {
                printf("| __ ");
            }
        }
        // print two lines after each row to make board
        printf("|\n\n"); 
    }    
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
bool move(int tile)
{
    // TODO 
    // search board for user tile
    // iterate through rows to find tile
    for (int i = 0; i < d; i++) 
    {
        // iterate through columns to find tile
        for (int j = 0; j < d; j++) 
        {
            // if user entered tile that exists on the board
            if(tile == board[i][j]) 
            {
                // initialize variable for 0 
                int blankspace = 0;       
                
                // test if tile is adjacent to blankspace
                if (((x == (i - 1)) && (j == y)) ||  ((x == (i + 1)) && (j == y)) ||
                ((i == x) && (y == (j - 1))) || ((i == x) && (y == (j + 1))))
                {
                    // printf("before:  tile %d, blankspace %d\n", tile, blankspace)
                    
                    // swap tile with blankspace if tile is adjacent to blankspace
                    board[x][y] = tile;
                    board[i][j] = blankspace;
                    x=i;
                    y=j;
 
                    // printf("The position of the tile is board[%d][%d] = %2d.  Tile is %d\n", i, j, board[i][j], tile);
                    // printf("Blankspace position is: board[%d][%d] = %d\n", x, y, blankspace);
                    
                    return true;
                }   
            } 
        }
    }
    return false;
}

/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
bool won(void)
{
    // TODO
    // initializes variables
    int n = -1;
    
    // iterates through board
    for (int i = 0; i < d; i++) 
    {
        for (int j = 0; j < d; j++)
        {
            // creates counter
            n = n + 1;
            
            // if any tile does not equal the counter, which is counting from 0, return false
            if (board[i][j] != n)
            {
            return false;
            }
        } 
    }
    // otherwise, all tiles count up from 0, game won
    return true;
}

/**
 * Saves the current state of the board to disk (for testing).
 */
void save(void)
{
    // log
    const string log = "log.txt";

    // delete existing log, if any, before first save
    static bool saved = false;
    if (!saved)
    {
        unlink(log);
        saved = true;
    }

    // open log
    FILE* p = fopen(log, "a");
    if (p == NULL)
    {
        return;
    }

    // log board
    fprintf(p, "{");
    for (int i = 0; i < d; i++)
    {
        fprintf(p, "{");
        for (int j = 0; j < d; j++)
        {
            fprintf(p, "%i", board[i][j]);
            if (j < d - 1)
            {
                fprintf(p, ",");
            }
        }
        fprintf(p, "}");
        if (i < d - 1)
        {
            fprintf(p, ",");
        }
    }
    fprintf(p, "}\n");

    // close log
    fclose(p);
}
