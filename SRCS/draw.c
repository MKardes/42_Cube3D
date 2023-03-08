#include "../INC/cube.h"
//60 == 1.05    66 == 1.155   1.15

void    draw_rays(t_cube *ptr)
{
    int         r = 0, mx, my, dof;
    float       ra = ptr->p->a - ((ANGLE / 2) * DR);
    int         direction;
    if (ra < 0)
        ra += 2 * PI;
    float       dy, dx, dist;
    t_vect  rayH, rayW;
    while (r < ANGLE * DEG)
    {
        float distW = 10000;
        float distH = 10000;
        float aTan = -1 / tan(ra);
        float nTan = -tan(ra);
        dof = 0;
        if (ra > PI)
        {
            // UP
            rayH.y = (((int)ptr->p->p.y >> BIT) << BIT) - 0.0001;
            rayH.x = (ptr->p->p.y - rayH.y) * aTan + ptr->p->p.x;
            dy = -SQR_X;
            dx = -dy * aTan;
        }
        if (ra < PI && ra > 0)
        {
            // DOWN
            rayH.y = (((int)ptr->p->p.y >> BIT) << BIT) + SQR_X;
            rayH.x = (ptr->p->p.y - rayH.y) * aTan + ptr->p->p.x;
            dy = SQR_X;
            dx = -dy * aTan;
        }
        if (ra == PI || ra == 0)
        {
            rayH.y = ptr->p->p.y;
            rayH.x = ptr->p->p.x;
            dof = 8;
        }
        while (dof < 8)
        {
            mx = (int)rayH.x >> BIT;
            my = (int)rayH.y >> BIT;
            if (my >= 0 && mx >= 0 && my < 10 && mx < 10 && ptr->f_map[my][mx] == '1')
            {
                distH = distance(ptr->p->p, rayH);
                dof = 8;
            } 
            else
            {
                rayH.x += dx;
                rayH.y += dy;
                dof += 1;
            }
        }
        dof = 0;
        if (ra > (PI / 2) && ra < (3 * PI / 2))
        {
            // LEFT
            rayW.x = (((int)ptr->p->p.x >> BIT) << BIT) - 0.0001;
            rayW.y = (ptr->p->p.x - rayW.x) * nTan + ptr->p->p.y;
            dx = -SQR_X;
            dy = -dx * nTan;
        }
        if (ra < (PI / 2) || ra > (3 * PI / 2))
        {
            // RIGHT
            rayW.x = (((int)ptr->p->p.x >> BIT) << BIT) + SQR_X;
            rayW.y = (ptr->p->p.x - rayW.x) * nTan + ptr->p->p.y;
            dx = SQR_X;
            dy = -dx * nTan;
        }
        if (ra == (PI / 2) || ra == (3 * PI / 2))
        {
            rayW.y = ptr->p->p.y;
            rayW.x = ptr->p->p.x;
            dof = 8;
        }
        while (dof < 8)
        {
            mx = (int)rayW.x >> BIT;
            my = (int)rayW.y >> BIT;
            if (my >= 0 && mx >= 0 && my < 10 && mx < 10 && ptr->f_map[my][mx] == '1')
            {
                distW = distance(ptr->p->p, rayW);
                dof = 8;
            }
            else
            {
                rayW.x += dx;
                rayW.y += dy;
                dof += 1;
            }
        }
        if (distW < distH)
        {
            dist = distW;
            direction = 0;
            // draw_line(ptr, ptr->p->p, rayW, BLACK);
        }
        else
        {
            dist = distH;
            direction = 1;
            // draw_line(ptr, ptr->p->p, rayH, BLACK);
        }
        get_it_3d(ptr, dist, ra, r, direction);
        ra += DR / DEG;
        if (ra >= (2 * PI))
            ra -= (2 * PI);
        r++;
    }
}
