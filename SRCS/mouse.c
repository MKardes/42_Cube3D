#include "../INC/cube.h"

int mouse_move(int x, int y, t_cube *cube)
{
    cube->mouse_last = x;
    mlx_mouse_hide();
    mlx_mouse_get_pos(cube->win, &x, &y);
    if (cube->mouse_first > cube->mouse_last)
    {
        cube->p->a -= 0.1 * P_SPD * 2;
        if (cube->p->a < 2 * PI)
            cube->p->a += 2 * PI;
        cube->p->dx = cos(cube->p->a) * 5;
        cube->p->dy = sin(cube->p->a) * 5;
    }
    else
    {
        cube->p->a += 0.1 * P_SPD * 2;
        if (cube->p->a > 2 * PI)
            cube->p->a -= 2 * PI;
        cube->p->dx = cos(cube->p->a) * 5;
        cube->p->dy = sin(cube->p->a) * 5;
    }
    if (cube->mouse_last > WIN_X)
        mlx_mouse_move(cube->win, 0, WIN_Y / 2);
    if (cube->mouse_last <= 0)
        mlx_mouse_move(cube->win, WIN_X, WIN_Y / 2);
    cube->mouse_first = cube->mouse_last;
    //mlx_mouse_show();
    return (0);
}
