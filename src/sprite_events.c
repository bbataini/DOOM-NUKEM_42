/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbataini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 21:32:27 by bbataini          #+#    #+#             */
/*   Updated: 2019/04/18 21:32:29 by bbataini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

static void		flyisabug(t_struct *p)
{
	float	s;
	int		nb;

	s = 0.5;
	nb = (rand() % 4);
	if (nb == 0 && p->map[p->k][(int)(p->sprite[4].x + s)]
			[(int)(p->sprite[4].y)] == 0)
		p->sprite[4].x += s;
	else if (nb == 1 && p->map[p->k][(int)(p->sprite[4].x)]
			[(int)(p->sprite[4].y + s)] == 0)
		p->sprite[4].y += s;
	else if (nb == 2 && p->map[p->k][(int)(p->sprite[4].x - s)]
			[(int)(p->sprite[4].y)] == 0)
		p->sprite[4].x -= s;
	else if (nb == 3 && p->map[p->k][(int)(p->sprite[4].x)]
			[(int)(p->sprite[4].y - s)] == 0)
		p->sprite[4].y -= s;
}

static void		mvmy(t_struct *p, int i, float sx, float sy)
{
	int		j;

	j = 4;
	while (j < 10)
	{
		if (p->sprite[j].k == 5 && ((int)(p->sprite[i].x + sx)
					== (int)p->sprite[j].x && (int)(p->sprite[i].y + sy)
						== (int)p->sprite[j].y && j != i))
			break ;
		else if (j >= 9)
		{
			p->sprite[i].x += sx;
			p->sprite[i].y += sy;
		}
		j++;
	}
	flyisabug(p);
}

static void		mvmy2(t_struct *p, int i, float sx, float sy)
{
	int		j;

	j = 10;
	while (j < 15)
	{
		if (p->sprite[j].k == 8 && ((int)(p->sprite[i].x + sx)
					== (int)p->sprite[j].x && (int)(p->sprite[i].y + sy)
						== (int)p->sprite[j].y && j != i))
			break ;
		else if (j >= 14)
		{
			p->sprite[i].x += sx;
			p->sprite[i].y += sy;
		}
		j++;
	}
}

void			movemy(t_struct *p, int i)
{
	float		sx;
	float		sy;

	while (p->k == 5 && i < 10)
	{
		if ((p->temp % 20) < 10)
			p->sprite[i].id = 82;
		else
			p->sprite[i].id = 83;
		if (p->sprite[i].x >= p->c->p_x)
			sx = -0.05;
		else
			sx = 0.05;
		if (p->sprite[i].y >= p->c->p_y)
			sy = -0.05;
		else
			sy = 0.05;
		if (p->map[p->k][(int)(p->sprite[i].x + sx)][(int)(p->sprite[i].y + sy)]
				== 0 && p->sprite[i].k == 5)
			mvmy(p, i, sx, sy);
		i++;
	}
}

void			movemy2(t_struct *p, int i)
{
	float		sx;
	float		sy;

	while (p->k == 8 && i < 16)
	{
		if (p->temp % 20 < 10)
			p->sprite[i].id = 84;
		else
			p->sprite[i].id = 85;
		if (p->sprite[i].x >= p->c->p_x)
			sx = -0.02;
		else
			sx = 0.02;
		if (p->sprite[i].y >= p->c->p_y)
			sy = -0.02;
		else
			sy = 0.02;
		if (p->map[p->k][(int)(p->sprite[i].x + sx)][(int)(p->sprite[i].y + sy)]
				== 0 && p->sprite[i].k == 8)
			mvmy2(p, i, sx, sy);
		i++;
	}
}
