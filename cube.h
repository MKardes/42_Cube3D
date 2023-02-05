#ifndef CUBE_H
# define CUBE_H

# include <stdio.h>
# include "mlx.h"
# include "mlx_int.h"

# define WIN_X 1000
# define WIN_Y 1000

typedef struct s_cube
{
    void    *mlx;
    void    *win;
}   t_cube;


#endif