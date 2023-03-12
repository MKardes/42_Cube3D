/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkardes <mkardes@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:11:23 by mkardes           #+#    #+#             */
/*   Updated: 2023/03/12 18:37:17 by mkardes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/cube.h"

//60 == 1.05    66 == 1.155   1.15
void	up_down(t_cube *ptr, float ra, float *distH, t_vect *rayH)
{
	float (aTan) = -1 / tan(ra);
	float (dof) = 0;
	int (mx) = 0;
	int (my) = 0;
	float (dy) = 0;
	float (dx) = 0;
	if (ra > PI)
	{
		rayH->y = (((int)ptr->p->p.y >> BIT) << BIT) - 0.0001;
		rayH->x = (ptr->p->p.y - rayH->y) * aTan + ptr->p->p.x;
		dy = -SQR_X;
		dx = -dy * aTan;
	}
	if (ra < PI && ra > 0)
	{
		rayH->y = (((int)ptr->p->p.y >> BIT) << BIT) + SQR_X;
		rayH->x = (ptr->p->p.y - rayH->y) * aTan + ptr->p->p.x;
		dy = SQR_X;
		dx = -dy * aTan;
	}
	if (ra == PI || ra == 0)
	{
		rayH->y = ptr->p->p.y;
		rayH->x = ptr->p->p.x;
		dof = 8;
	}
	while (dof < HEIGH)
	{
		mx = (int)rayH->x >> BIT;
		my = (int)rayH->y >> BIT;
		if (my >= 0 && mx >= 0 && my < HEIGH - 1
			&& mx < WEIGH - 1 && ptr->f_map[my][mx] == '1')
		{
			*distH = distance(ptr->p->p, *rayH);
			dof = HEIGH;
		}
		else
		{
			rayH->x += dx;
			rayH->y += dy;
			dof += 1;
		}
	}
}

void	right_left(t_cube *ptr, float ra, float *distW, t_vect *rayW)
{
	float (nTan) = -tan(ra);
	float (dof) = 0;
	int (mx) = 0;
	int (my) = 0;
	float (dy) = 0;
	float (dx) = 0;
	if (ra > (PI / 2) && ra < (3 * PI / 2))
	{
		rayW->x = (((int)ptr->p->p.x >> BIT) << BIT) - 0.0001;
		rayW->y = (ptr->p->p.x - rayW->x) * nTan + ptr->p->p.y;
		dx = -SQR_X;
		dy = -dx * nTan;
	}
	if (ra < (PI / 2) || ra > (3 * PI / 2))
	{
		rayW->x = (((int)ptr->p->p.x >> BIT) << BIT) + SQR_X;
		rayW->y = (ptr->p->p.x - rayW->x) * nTan + ptr->p->p.y;
		dx = SQR_X;
		dy = -dx * nTan;
	}
	if (ra == (PI / 2) || ra == (3 * PI / 2))
	{
		rayW->y = ptr->p->p.y;
		rayW->x = ptr->p->p.x;
		dof = 8;
	}
	while (dof < WEIGH)
	{
		mx = (int)rayW->x >> BIT;
		my = (int)rayW->y >> BIT;
		if (my >= 0 && mx >= 0 && my < HEIGH - 1
			&& mx < WEIGH - 1 && ptr->f_map[my][mx] == '1')
		{
			*distW = distance(ptr->p->p, *rayW);
			dof = WEIGH;
		}
		else
		{
			rayW->x += dx;
			rayW->y += dy;
			dof += 1;
		}
	}
}

int	get_correct_dist(float distW, float *distH, float *Hx, float Wy)
{
	if (distW < *distH)
	{
		*distH = distW;
		*Hx = Wy;
		return (0);
	}
	else
		return (1);
	return (0);
}

void	draw_rays(t_cube *ptr)
{
	t_vect (rayH) = (t_vect){.x = 0};
	t_vect (rayW) = (t_vect){.x = 0};
	int (r) = 0;
	float (ra) = ptr->p->a - (((float)ANGLE / 2) * DR);
	int (direction) = 0;
	float (distW) = 10000;
	float (distH) = 10000;
	if (ra < 0)
		ra += 2 * PI;
	while (r < ANGLE * DEG)
	{
		distW = 10000;
		distH = 10000;
		up_down(ptr, ra, &distH, &rayH);
		right_left(ptr, ra, &distW, &rayW);
		direction = get_correct_dist(distW, &distH, &rayH.x, rayW.y);
		get_it_3d(ptr, distH, (t_vect){.x = ra, .y = r},
			(t_vect){.x = rayH.x, .y = direction});
		ra += DR / DEG;
		if (ra >= (2 * PI))
			ra -= (2 * PI);
		r++;
	}
}
