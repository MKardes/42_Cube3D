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

void	continue_casting(t_cube *ptr, t_vect d, t_vect *ray, float *dist)
{
	float (dof) = 0;
	int (mx) = 0;
	int (my) = 0;
	while (dof < ptr->map.cd_x + 1)
	{
		mx = (int)ray->x >> BIT;
		my = (int)ray->y >> BIT;
		if (my >= 0 && mx >= 0 && my < ptr->map.cd_y
			&& mx < ptr->map.cd_x + 1 && ptr->map.map[my][mx] == '1')
		{
			*dist = distance(ptr->p->p, *ray);
			break ;
		}
		ray->x += d.x;
		ray->y += d.y;
		dof += 1;
	}
}

void	up_down(t_cube *ptr, float ra, float *distH, t_vect *rayH)
{
	float (aTan) = -1 / tan(ra);
	t_vect (d) = (t_vect){.x = 0};
	if (ra > PI)
	{
		rayH->y = (((int)ptr->p->p.y >> BIT) << BIT) - 0.0001;
		rayH->x = (ptr->p->p.y - rayH->y) * aTan + ptr->p->p.x;
		d.y = -SQR_X;
		d.x = -d.y * aTan;
	}
	if (ra < PI && ra > 0)
	{
		rayH->y = (((int)ptr->p->p.y >> BIT) << BIT) + SQR_X;
		rayH->x = (ptr->p->p.y - rayH->y) * aTan + ptr->p->p.x;
		d.y = SQR_X;
		d.x = -d.y * aTan;
	}
	if (ra == PI || ra == 0)
	{
		rayH->y = ptr->p->p.y;
		rayH->x = ptr->p->p.x;
		return ;
	}
	continue_casting(ptr, d, rayH, distH);
}

void	right_left(t_cube *ptr, float ra, float *distW, t_vect *rayW)
{
	float (nTan) = -tan(ra);
	t_vect (d) = (t_vect){.x = 0};
	if (ra > (PI / 2) && ra < (3 * PI / 2))
	{
		rayW->x = (((int)ptr->p->p.x >> BIT) << BIT) - 0.0001;
		rayW->y = (ptr->p->p.x - rayW->x) * nTan + ptr->p->p.y;
		d.x = -SQR_X;
		d.y = -d.x * nTan;
	}
	if (ra < (PI / 2) || ra > (3 * PI / 2))
	{
		rayW->x = (((int)ptr->p->p.x >> BIT) << BIT) + SQR_X;
		rayW->y = (ptr->p->p.x - rayW->x) * nTan + ptr->p->p.y;
		d.x = SQR_X;
		d.y = -d.x * nTan;
	}
	if (ra == (PI / 2) || ra == (3 * PI / 2))
	{
		rayW->y = ptr->p->p.y;
		rayW->x = ptr->p->p.x;
		return ;
	}
	continue_casting(ptr, d, rayW, distW);
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
