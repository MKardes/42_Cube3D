#include "../INC/cube.h"

void    draw_rays(t_cube *ptr)
{
    int         r = 0, mx, my, dof;
    float       ra = ptr->p->a;// - (PI / 6) - 0.05;//60 == 1.05    66 == 1.155   1.15
    if (ra < 0)
        ra += 2 * PI;
    float       dy, dx;
    float distH = 10000;
    float distW = 10000;
    t_vect      rayH, rayW;
    while (r < 5)//22
    {
        float aTan = -1 / tan(ra);
        float nTan = -tan(ra);
        dof = 0;
        if (ra > PI)
        {
            // UP
            rayH.y = (((int)ptr->p->p.y >> 6) << 6) - 0.0001;
            rayH.x = (ptr->p->p.y - rayH.y) * aTan + ptr->p->p.x;
            dy = -64;
            dx = -dy * aTan;
        }
        else if (ra < PI)
        {
            // DOWN
            rayH.y = (((int)ptr->p->p.y >> 6) << 6) + 64;
            rayH.x = (ptr->p->p.y - rayH.y) * aTan + ptr->p->p.x;
            dy = 64;
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
            mx = (int)rayH.x >> 6;
            my = (int)rayH.y >> 6;
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
            rayW.x = (((int)ptr->p->p.x >> 6) << 6) - 0.0001;
            rayW.y = (ptr->p->p.x - rayW.x) * nTan + ptr->p->p.y;
            dx = -64;
            dy = -dx * nTan;
        }
        if (ra < (PI / 2) || ra > (3 * PI / 2))
        {
            // RIGHT
            rayW.x = (((int)ptr->p->p.x >> 6) << 6) + 64;
            rayW.y = (ptr->p->p.x - rayW.x) * nTan + ptr->p->p.y;
            dx = 64;
            dy = -dx * nTan;
        }
        if (dy < -1000000) {
            dy = 5;
            rayW.y = 5;
        }
        if (ra == (PI / 2) || ra == (3 * PI / 2))
        {
            rayW.y = ptr->p->p.y;
            rayW.x = ptr->p->p.x;
            dof = 8;
        }
        while (dof < 8)
        {
            mx = (int)rayW.x >> 6;
            my = (int)rayW.y >> 6;
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
        printf("RayW: %10.2f,%10.2f DistW: %f, RayH: %10.2f,%10.2f DistH: %f\n",rayW.x,rayW.y,distW,rayH.x,rayH.y,distH);
        if (distW < distH)
            draw_line(ptr, ptr->p->p, rayW, BLACK);
        else
            draw_line(ptr, ptr->p->p, rayH, BLACK);
        ra+=0.05;
        if (ra >= (2 * PI))
            ra -= (2 * PI);
        r++;
    }
}
        // printf("<%d> Up: dy:\t%10.2f, dx:\t%10.2f, m:\t%10.3f\n", r, dy, dx, m);
        // printf("<%d> Down: dy:\t%10.2f, dx:\t%10.2f, m:\t%10.3f\n", r, dy, dx, m);
        // printf("%drx:\t%10.2f, ry:\t%10.2f, px:\t%10.2f, py:\t%10.2f\n", ra <= PI, ray.x, ray.y, ptr->p->p.x,ptr->p->p.y);