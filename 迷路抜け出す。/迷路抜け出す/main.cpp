#include <stdio.h> 
#include <stdlib.h> 
#include <windows.h> 
#include <conio.h> 

#define MAZE_BOARD_HEIGHT 10
#define MAZE_BOARD_WIDTH 10
#define POINT_X 4  //スタート座標　X
#define POINT_Y 2  //スタート座標　Y

#define LEFT 75 
#define RIGHT 77 
#define UP 72 
#define DOWN 80 

#define DELAY 100 
#define EXIT 50 


void gotoxy(int x, int y);           
void setmap();                        
bool move(char ch);                

char startx = 0;                        
char starty = 0;                        
char endx = 0;                         
char endy = 0;                        



char map[25][25] =
{
 {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
 {1,2,1,0,1,1,0,1,0,0,0,1,0,0,0,0,1,1,0,0,1,0,0,0,1},
 {1,0,1,0,0,0,0,1,0,1,0,1,0,0,1,0,0,0,0,1,1,0,1,0,1},
 {1,0,1,0,1,1,0,1,0,0,0,1,1,0,1,1,0,1,0,1,0,0,1,0,1},
 {1,0,1,0,0,0,0,1,1,0,1,1,0,0,0,1,1,1,0,1,0,1,1,0,1},
 {1,0,1,1,1,1,0,0,0,0,0,1,0,1,0,0,0,1,0,0,0,1,1,0,1},
 {1,0,0,0,0,0,0,1,0,1,0,1,0,1,1,0,0,1,0,1,1,1,1,0,1},
 {1,0,1,1,0,1,0,1,0,1,0,1,0,0,1,0,0,1,0,1,0,0,1,0,1},
 {1,0,1,0,0,1,0,1,0,1,0,1,0,0,1,0,0,1,0,1,0,0,1,0,1},
 {1,0,1,0,1,0,0,1,0,1,0,1,0,0,1,0,0,1,0,0,0,0,1,0,1},
 {1,0,1,0,1,0,1,1,0,1,0,1,0,0,1,1,0,1,1,1,0,0,1,0,1},
 {1,0,1,0,0,0,1,0,0,1,0,0,0,0,0,1,0,1,0,1,0,0,1,0,1},
 {1,0,1,1,1,1,1,0,1,1,1,1,0,1,1,1,0,1,0,1,0,1,1,0,1},
 {1,0,0,0,0,0,1,0,0,0,0,1,0,1,0,0,0,0,0,1,0,1,0,0,1},
 {1,1,1,1,0,1,1,0,1,0,0,1,0,1,0,0,1,1,1,1,0,1,1,0,1},
 {1,0,0,1,0,0,0,0,1,0,0,1,0,1,1,0,0,1,0,0,1,0,0,0,1},
 {1,0,1,1,0,0,1,0,1,1,1,1,0,1,0,0,1,1,0,1,1,1,0,1,1},
 {1,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,1,0,1,0,1,0,1,1},
 {1,0,1,1,0,1,1,1,1,1,0,1,0,0,1,1,1,0,0,1,0,1,0,1,1},
 {1,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,1,0,0,0,1},
 {1,0,1,0,1,1,1,0,1,0,1,1,0,1,1,1,0,0,0,1,0,1,0,1,1},
 {1,0,1,0,0,0,0,0,1,0,0,1,0,0,0,1,1,1,0,1,0,1,0,0,1},
 {1,0,1,1,1,1,1,1,1,1,0,1,1,1,0,1,0,0,0,1,0,1,1,0,1},
 {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,3,1},
 {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};


void main()
{
    setmap();
    while (true)
    {
        if (move(_getch()))
        {
            break;
        }
    }
    while (_getch() != 27)
    {
        gotoxy(0, 26);
        printf("clear\n終了 esc\n");
    }
}


bool move(char ch)
{
    switch (ch)
    {
    case LEFT:
        if (map[starty][startx - 1] != 1)
        {
            printf(" ");
            startx--;
        }
        break;
    case RIGHT:
        if (map[starty][startx + 1] != 1)
        {
            printf(" ");
            startx++;
        }
        break;
    case UP:
        if (map[starty - 1][startx] != 1)
        {
            printf(" ");
            starty--;
        }
        break;
    case DOWN:
        if (map[starty + 1][startx] != 1)
        {
            printf(" ");
            starty++;
        }
        break;
    }
    gotoxy(startx * 2, starty);
    printf("◎");
    gotoxy(startx * 2, starty);
    if (map[startx][starty] == map[endx][endy])
    {
        return true;
    }
    else
    {
        return false;
    }
}

void setmap()
{
    char ch;

    for (int i = 0; i < sizeof(map) / sizeof(map[0]); i++)
    {
        for (int j = 0; j < sizeof(map[0]) / sizeof(map[0][0]); j++)
        {
            ch = map[i][j];
            switch (ch)
            {
            case 0:
                printf("■");
                break;
            case 1:
                printf("■");
                break;
            case 2:
                printf("◎");
                startx = i;
                starty = j;
                break;
            case 3:
                printf("★");
                endx = i;
                endy = j;
                break;
            }
        }
        printf("\n");
    }
    gotoxy(startx * 2, starty);
}


void gotoxy(int x, int y)
{
    COORD position = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}