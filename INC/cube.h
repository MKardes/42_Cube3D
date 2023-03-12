#ifndef CUBE_H
# define CUBE_H

# include <math.h>
# include <stdio.h>
# include <string.h>
# include <stdbool.h>
# include <unistd.h>
# include "../Others/mlx/mlx.h"
# include "../Others/libft/LIB/libft.h"


# define PI 3.1415926535//M_PI
# define DR 0.0174532925

# if defined(__APPLE__)
#  define A 0
#  define S 1
#  define D 2
#  define W 13
#  define M 46
#  define O 31
#  define P 35
#  define Z 6
#  define X 7
#  define C 8
#  define V 9
#  define TAB 48
#  define SHIFT 257
#  define B1 18
#  define B2 19
#  define B3 20
#  define B4 21
#  define B5 23
#  define B6 22
#  define B7 26
#  define U_ 126
#  define D_ 125
#  define L_ 123
#  define R_ 124
#  define ESC 53
# endif

# if defined(linux)
#  define A 97
#  define S 115
#  define D 100
#  define W 119
#  define O 111
#  define P 112
#  define Z 122
#  define X 120
#  define C 99 
#  define V 118
#  define B1 49
#  define B2 50
#  define B3 51
#  define B4 52
#  define B5 53
#  define B6 54
#  define B7 55
#  define U_ 65362
#  define D_ 65364
#  define L_ 65361
#  define R_ 65363
#  define ESC 65307
# endif

# define WIN_X 1660
# define WIN_Y 948

# define ANGLE 66

# define WALLH  1.89
# define LENGTH 2
# define DEG    25.15
# define BIT 4

# define SQR_X 16
# define SQR_Y 16
# define SQR_LENGTH (SQR_X - 1)

#  define PLAYER 10
#  define P_SPD 0.1

# define S_SPD 0.2

# define HEIGH 21
# define WEIGH 23

# define MAP_X (WEIGH * SQR_X)
# define MAP_Y (HEIGH * SQR_Y)

# define ERR_MAP "Map Error!"
# define MAP_RET -12

# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF
# define CYAN 0x0000FFFF
# define WHITE 0x00FFFFFF
# define BLACK 0x00000000


typedef struct s_vect
{
    float x;
    float y;
}   t_vect;

typedef struct s_keys
{
    bool    w;
    bool    a;
    bool    s;
    bool    d;
    bool    r;
    bool    l;
    bool    m;
    bool    tab;
    bool    shift;
}   t_keys;

typedef struct s_player
{
    t_vect p;
    float dx;
    float dy;
    float a;
}   t_player;

typedef struct s_data
{
    int     *addr;
    void    *img;
    int     length;
}   t_data;

typedef struct s_cube
{
    void        *mlx;
    void        *win;
    char        **f_map;
    int         mouse_first;
    int         mouse_last;
    t_keys      keys;
    t_player    *p;
    t_data      *frame;
    t_data      *textures;
}   t_cube;

char    **get_it(void);// Temporarly

//window
t_cube  *start_window(void);

// to image
int	map_to_img(t_cube *ptr);
int	top_bot_to_img(t_cube *ptr);

//loop
int     loop(t_cube *ptr);

//put functions
int     player_put(t_cube *ptr);

//keys;
int     key_press(int keycode, t_cube *cube);
int     key_release(int keycode, t_cube *cube);
void	move_direction(t_keys keycode, t_cube *ptr);
void	move_angle(t_keys keycode, t_cube *ptr);
int     mouse_move(int x, int y, t_cube *cube);
int     ft_key_esc(t_cube *ptr);
void    key_w(t_cube *ptr, t_vect p, int px_add_dx, int py_add_dy);
void    key_s(t_cube *ptr, t_vect p, int px_sub_dx, int py_sub_dy);
void    key_a(t_cube *ptr, t_vect p, int px_add_dy, int py_sub_dx);
void    key_d(t_cube *ptr, t_vect p, int px_sub_dy, int py_add_dx);


//utils
int	ft_error(char *str);

//draw
void    draw_rays(t_cube *ptr);
void    draw_line(t_cube *ptr, t_vect start, t_vect end, int rgb);
float   distance(t_vect p1, t_vect p2);

void    get_it_3d(t_cube *ptr, float distance, t_vect r, t_vect x_dr);

#endif
