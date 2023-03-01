#include "../INC/cube.h"

static void	line_put(t_cube *ptr, t_vect start, t_vect end, int rgb)
{
	int (i) = -1;
	double (dx) = end.x - start.x;
	double (dy) = end.y - start.y;
	int (steps) = fabs(dy);
	if (fabs(dx) > fabs(dy))
		steps = fabs(dx);
	double (Xinc) = dx / (double) steps;
	double (Yinc) = dy / (double) steps;
	while (++i < 125 && (roundf(start.x) != end.x && roundf(start.y) != end.y))
	{
		mlx_pixel_put(ptr->mlx, ptr->win,
			(int)roundf(start.x), (int)roundf(start.y), rgb);
		start.x += Xinc;
		start.y += Yinc;
	}
}

void    draw_rays(t_cube *ptr)
{
    int      r = 0, mx, my, dof;
    float       ra = ptr->p->a - (11 * PI / 60), xo, yo;
    t_vect      ray;
    while (r < 1)
    {
        float m = tan(ra);
        dof = 0;
        if (ra < PI)
        {
            ray.y = (((int)ptr->p->p.y >> 6) << 6) - 1;
            ray.x = ptr->p->p.x - (ray.y - ptr->p->p.y) / m;
            yo = -64;
            xo = -yo / m;
            //looking up
            printf("Up: ry: %d, rx: %d, yo: %f, xo: %f, m: %f\n", (int)ray.y >> 6, (int)ray.x >> 6, yo, xo, m);
        }
        else if (ra > PI)
        {
            ray.y = (((int)ptr->p->p.y >> 6) << 6) + 1;
            ray.x = ptr->p->p.x - (ray.y - ptr->p->p.y) / m;
            yo = 64;
            xo = -yo / m;
            //looking down
            printf("Down: ry: %d, rx: %d, yo: %f, xo: %f, m: %f\n", (int)ray.y >> 6, (int)ray.x >> 6, yo, xo, m);
        }
        if (ra == PI || ra == 0)
        {
            ray.y = ptr->p->p.y;
            ray.x = ptr->p->p.x;
            dof = 8;
            //looking straight left or right
        }
        while (dof < 4)
        {
            mx = (int)ray.x >> 6;
            my = (int)ray.y >> 6;
            if (my >= 0 && mx >= 0 && my < 10 && mx < 10 && ptr->f_map[my][mx] == '1')
                dof = 8; 
            else
            {
                ray.x += xo;
                ray.y += yo;
                dof += 1;
            }
        }
        line_put(ptr, ptr->p->p, ray, RED | BLUE);
        ra+=0.05;
        r++;
    }
    // r = 0;
    // while (r < 1)
    // {
    //     float m = tan(ra);
    //     dof = 0;
    //     if (ra > (PI / 2) && ra < (3 * PI / 2))
    //     {
    //         ray.x = (((int)ptr->p->p.x >> 6) << 6) - 1;
    //         ray.y = ptr->p->p.y + (ray.x - ptr->p->p.x) * m;
    //         xo = -64;
    //         yo = -xo * m;
    //         printf("Left: ry: %d, rx: %d, yo: %f, xo: %f, m: %f\n", (int)ray.y >> 6, (int)ray.x >> 6, yo, xo, m);
    //         //looking left
    //     }
    //     if (ra < (PI / 2) || ra > (3 * PI / 2))
    //     {
    //         ray.x = (((int)ptr->p->p.x >> 6) << 6) + 64;
    //         ray.y = ptr->p->p.y + (ray.x - ptr->p->p.x) * m;
    //         xo = 64;
    //         yo = -xo * m;
    //         printf("Right: ry: %d, rx: %d, yo: %f, xo: %f, m: %f\n", (int)ray.y >> 6, (int)ray.x >> 6, yo, xo, m);
    //         //looking right
    //     }
    //     if (ra == PI / 2 || ra == 3 * PI / 2)
    //     {
    //         ray.y = ptr->p->p.y;
    //         ray.x = ptr->p->p.x;
    //         dof = 8;
    //         //looking straight up or down
    //     }
    //     while (dof < 8)
    //     {
    //         mx = (int)ray.x >> 6;
    //         my = (int)ray.y >> 6;
    //         printf("mx: %d, my: %d\n", mx, my);
    //         if (my >= 0 && mx >= 0 && my < 10 && mx < 10 && ptr->f_map[my][mx] == '1')
    //             dof = 8; 
    //         else
    //         {
    //             ray.x += xo;
    //             ray.y += yo;
    //             dof += 1;
    //         }
    //     }
    //     line_put(ptr, ptr->p->p, ray, BLACK);
    //     ra+=0.05;
    //     r++;
    // }
}