#include "../INC/cube.h"

static void	line_put(t_cube *ptr, t_vect start, t_vect end)
{
	int (i) = -1;
	double (dx) = end.x - start.x;
	double (dy) = end.y - start.y;
	int (steps) = fabs(dy);
	if (fabs(dx) > fabs(dy))
		steps = fabs(dx);
	double (Xinc) = dx / (double) steps;
	double (Yinc) = dy / (double) steps;
	while (++i < 150 && (roundf(start.x) != end.x && roundf(start.y) != end.y))
	{
		mlx_pixel_put(ptr->mlx, ptr->win,
			(int)roundf(start.x), (int)roundf(start.y), BLACK);
		start.x += Xinc;
		start.y += Yinc;
	}
}

void    draw_rays(t_cube *ptr)
{
    int      r = 0, mx, my, mp, dof;
    float       ra = ptr->p->a - (11 * PI) / 60, xo, yo;
    t_vect      ray;
    while (ra < ptr->p->a + (11 * PI) / 60)
    {
        float m = tan(ra);
        dof = 0;
        if (ra < PI)
        {
            ray.y = (((int)ptr->p->p.y >> 6) << 6) - 0.0001;
            ray.x = ptr->p->p.x - (ray.y - ptr->p->p.y) / m;
            yo = -64;
            xo = -yo * (1 / m);
            printf("Up: ry: %f, rx: %f, yo: %f, xo: %f, atan: %f\n", ray.y, ray.x, yo, xo, m);
            //looking up
        }
        if (ra > PI)
        {
            ray.y = (((int)ptr->p->p.y >> 6) << 6) + 64;
            ray.x = ptr->p->p.x - (ray.y - ptr->p->p.y) / m;
            yo = 64;
            xo = -yo * (1 / m);
            printf("Down: ry: %f, rx: %f, yo: %f, xo: %f, atan: %f\n", ray.y, ray.x, yo, xo, m);
            //looking down
        }
        if (ra == PI || ra == 0)
        {
            ray.y = ptr->p->p.y;
            ray.x = ptr->p->p.x;
            dof = 8;
            //looking straight left or right
        }
        while (dof < 8)
        {
            mx = (int)ray.x >> 6;
            my = (int)ray.y >> 6;
            printf("mp: %d, mx: %d, my: %d\n", mp, mx, my);
            /* if (my > 0 && mx > 0 && my < 10 && mx < 10 && ptr->f_map[my][mx] == '1')
                dof = 8; */
            {
                printf("b\n");
                ray.x += xo;
                ray.y += yo;
                dof += 1;
            }
        }
        line_put(ptr, ptr->p->p, ray);
        ra += 0.02;
    }
/* 
    int     r = 0, mx, my, mp, dof = 0;
    double  ra = ptr->p->a - (11 * PI) / 60, xo, yo, m = tan(ra);
    while(ra < ptr->p->a + (11 * PI) / 60)
    {
        t_vect  ray;
        m = tan(ra);
        if (ra < PI)
        {
            my = ((int)(ptr->p->p.y) - (PLAYER / 2)) / SQR_Y;
            mx = ((int)(ptr->p->p.x) - (PLAYER / 2)) / SQR_X;
        }
        else if (ra > PI)
        {
            my = ((int)(ptr->p->p.y) + (PLAYER / 2)) / SQR_Y;
            mx = ((int)(ptr->p->p.x) + (PLAYER / 2)) / SQR_Y;
        }
        else if (ra == PI || ra == 0)
        {
            //nothing
        }
        while (dof < 4)
        {
            if (ptr->f_map[my - 1][mx] == '1')
            {
                ray.y = my * SQR_Y;
                ray.x = ptr->p->p.x - (ray.y - ptr->p->p.y) / m;
                break ;
            }
            my -= 1;
            dof++;
        }
        line_put(ptr, ptr->p->p, ray);
        ra += 0.05;
    } */
}