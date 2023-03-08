#include "../INC/cube.h"

void    draw_line(t_cube *ptr, t_vect start, t_vect end, int rgb)
{
    int x1 = start.x, y1 = start.y;
    int x2 = end.x, y2 = end.y;

    int dx = abs(x2 - x1), dy = abs(y2 - y1);
    int sx = x1 < x2 ? 1 : -1, sy = y1 < y2 ? 1 : -1;
    int err = dx - dy;

    while (1)
    {
		if (x1 + y1 * WIN_X >= (WIN_X * WIN_Y) || x1 + y1 * WIN_X < 0)
		{
			break ;
		}
		else
        	ptr->frame->addr[x1 + y1 * WIN_X]= rgb;
        if (x1 == x2 && y1 == y2) break;
        int e2 = err * 2;
        if (e2 > -dy) { err -= dy; x1 += sx; }
        if (e2 < dx) { err += dx; y1 += sy; }
    }
}

float   distance(t_vect p1, t_vect p2)
{
    return (sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y)));
}
