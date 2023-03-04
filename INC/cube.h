#ifndef CUBE_H
# define CUBE_H

# include <math.h>
# include <stdio.h>
# include <string.h>
# include <stdbool.h>
# include "../Others/mlx/mlx.h"
# include "../Others/libft/LIB/libft.h"

# define PI M_PI//3.1415926535

# define A 0
# define S 1
# define D 2
# define W 13
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
# define L_ 123
# define R_ 124
# define ESC 53

# define WIN_X 1000
# define WIN_Y 1080

# define HEIGH 11
# define WEIGH 11

# define MAP_X (WEIGH * 64)
# define MAP_Y (HEIGH * 64)

# define ERR_MAP "Map Error!"
# define MAP_RET -12

# define SQR_X 64
# define SQR_Y 64
# define SQR_LENGTH (SQR_X - 1)

# define PLAYER 20
# define P_SPD 0.5

# ifndef P_SPD
#  define P_SPD (SQR_X / 5)
# endif


# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF
# define CYAN 0x0000FFFF
# define WHITE 0x00FFFFFF
# define BLACK 0x00000000

typedef struct s_vect
{
    double x;
    double y;
}   t_vect;

typedef struct s_keys
{
    bool    w;
    bool    a;
    bool    s;
    bool    d;
    bool    r;
    bool    l;
}   t_keys;

typedef struct s_player
{
    t_vect p;
    double dx;
    double dy;
    double a;
}   t_player;

typedef struct s_data
{
    int     *addr;
    void    *img;
}   t_data;

typedef struct s_cube
{
    void        *mlx;
    void        *win;
    char        **f_map;
    t_keys      keys;
    t_player    *p;
    t_data      *map;
}   t_cube;


//window
t_cube  *start_window(void);

//loop
int     loop(t_cube *ptr);

//player
int     player_put(t_cube *ptr);

//map
int     map_put(t_cube *ptr);

//keys;
int     key_press(int keycode, t_cube *cube);
int     key_release(int keycode, t_cube *cube);
void	move_direction(t_keys keycode, t_cube *ptr);
void	move_angle(t_keys keycode, t_cube *ptr);
int     ft_key_esc(t_cube *ptr);

//utils
int	ft_error(char *str);

//draw
void    draw_rays(t_cube *ptr);
void    draw_line(t_cube *ptr, t_vect start, t_vect end, int rgb);
void    draw_line1(t_cube *ptr, t_vect start, t_vect end, int rgb);// fazla
float   distance(t_vect p1, t_vect p2);

#endif
