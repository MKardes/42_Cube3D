#include "../INC/cube.h"

int get_image(int direction, float ra)
{
    if (direction)
    {
        //up down
        if (ra <= 2 * PI && ra >= PI)
            return (0);         //NORTH
        else
            return (1);         //SOUTH
    }
    else
    {
        //right left
        if (ra <= 3 * PI / 2 && ra >= PI / 2)
            return (2);         //WEST
        else
            return (3);         //EAST
    }
    return (0);
}

/* void    draw_column(t_cube *cube, t_vect start, t_vect end, int img, float ty_step, float ty_off)
{
}
 */
void    get_it_3d(t_cube *ptr, float distance, float ra, int r, int direction, float x)
{
    int (img) = get_image(direction, ra);
    float (ca) = ptr->p->a - ra;
    if (ca < 0)
        ca += 2 * PI;
    if (ca > 2 * PI)
        ca -= 2 * PI;
    distance = distance * cos(ca);

    float (lineH) = WIN_Y * 10 / distance * LENGTH;

    float ty_step = (ptr->textures[img].length / 4) /(float)lineH;
    float ty_off = 0;
    if (lineH > 500 * WALLH)
    {
        ty_off = (lineH - 500 * WALLH) / 2.0;
        lineH = 500 * WALLH;
    }

    t_vect (start) = (t_vect){.x = r, .y = WIN_Y / 2 - lineH / 2};
    t_vect (end) = (t_vect){.x = r, .y = WIN_Y / 2 + lineH / 2};

    float ty = ty_step * ty_off;
    float tx = (int)(x * SQR_X * 16); 
    while (start.y <= end.y)
    {
        /* if ((int)tx + (int)ty * (ptr->textures[img].length / 4) > (ptr->textures[img].length / 4) * (ptr->textures[img].length / 4))
        {
            ty-=ty_step;
        } */
        ptr->frame->addr[(int)start.x + (int)start.y * WIN_X] = ptr->textures[img].addr[(int)tx + (int)ty * (ptr->textures[img].length / 4)];
        start.y++;
        ty+=ty_step;
    }
    /* if (direction)
        draw_line(ptr, start, end, CYAN);
    else
        draw_line(ptr, start, end, 0x0000CFCF); */
}