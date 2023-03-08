#include "../INC/cube.h"

void    get_it_3d(t_cube *ptr, float distance, float ra, int r, int direction)
{
    float (ca) = ptr->p->a - ra;
    if (ca < 0)
        ca += 2 * PI;
    if (ca > 2 * PI)
        ca -= 2 * PI;
    distance = distance * cos(ca);
    float (lineH) = WIN_Y * 10 / distance ;
    if (lineH > 500)
        lineH = 500;
    t_vect (start) = (t_vect){.x = r * 1, .y = WIN_Y / 2 - lineH / 2};
    t_vect (end) = (t_vect){.x = r * 1, .y = WIN_Y / 2 + lineH / 2};
    if (direction)
        draw_line(ptr, start, end, CYAN);
    else
        draw_line(ptr, start, end, 0x0000CFCF);
}