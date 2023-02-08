#ifndef CUBE_H
# define CUBE_H

# include <math.h>
# include <stdio.h>
# include "mlx/mlx.h"
# include "mlx/mlx_int.h"
# include "Others/libft/LIB/libft.h"

# define PI 3.1415926535

# define A 97//0
# define S 115//1
# define D 100//2
# define W 119//13
# define O 111//31
# define P 112//35
# define Z 122//6
# define X 120//7
# define C 99//8
# define V 118//9
# define B1 49//18
# define B2 50//19
# define B3 51//20
# define B4 52//21
# define B5 53//23
# define B6 54//22
# define B7 55//26
# define U_ 65362//126
# define D_ 65364//125
# define L_ 65361//123
# define R_ 65363//124
# define ESC 65307//53

# define WIN_X 330
# define WIN_Y 330

# define ERR_MAP "Map Error!"
# define MAP_RET -12

# define SQR_X 33
# define SQR_Y 33
# define SQR_LENGTH 30

# define PLAYER 5
# define P_SPD 2

# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF
# define CYAN 0x0000FFFF
# define WHITE 0x00FFFFFF
# define BLACK 0x00000000

int map[10][10] = {
    {1,1,1,1,1,1,1,1,1,1},
    {1,0,0,1,0,0,0,0,0,1},
    {1,0,0,1,0,0,0,0,0,1},
    {1,0,0,1,0,0,0,1,1,1},
    {1,0,0,1,0,0,0,0,0,1},
    {1,0,0,0,0,0,1,1,1,1},
    {1,0,1,0,0,0,0,0,0,1},
    {1,0,1,0,0,1,1,0,0,1},
    {1,0,0,0,0,0,2,0,0,1},
    {1,1,1,1,1,1,1,1,1,1},
};

typedef struct s_player
{
    int x;
    int y;
    int dx;
    int dy;
    int a;
}   t_player;

typedef struct s_cube
{
    void        *mlx;
    void        *win;
    t_player    *p;
}   t_cube;


#endif