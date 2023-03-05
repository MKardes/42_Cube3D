#include "../INC/cube.h"

void	draw_line2(t_cube *ptr, t_vect start, t_vect end, int direction)
{
    int i = 0;
    while (i < (end.y - start.y) / 4)
    {
        if (direction)
            mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->weightl->img, start.x, start.y + (i * 4));
        else
            mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->weightd->img, start.x, start.y + (i * 4));
        i++;
    }
}

void    get_it_3d(t_cube *ptr, float distance, float ra, int r, int direction)
{
    int i = 0;
    float   lineH = WIN_Y * 10 / distance ;
    // float   lineO = 160 - lineH/2;
    float   ca = ptr->p->a - ra;
    if (ca < 0)
        ca += 2 * PI;
    if (ca > 2 * PI)
        ca -= 2 * PI;
    distance = distance * cos(ca);
    t_vect start = (t_vect){.x = r * 16, .y = WIN_Y / 2 - lineH / 2};
    t_vect end = (t_vect){.x = r * 16, .y = WIN_Y / 2 + lineH / 2};
    draw_line2(ptr, start, end, direction);
}