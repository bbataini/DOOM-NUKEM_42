/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   against_glitch.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbataini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 21:21:53 by bbataini          #+#    #+#             */
/*   Updated: 2019/04/18 21:21:57 by bbataini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

static int		against_glitch_straff2(t_struct *p, int move, double s)
{
	if (p->map[p->k][(int)((p->c->p_x))][(int)((p->c->p_y)) - 1] > 0
			&& (p->map[p->k][(int)((p->c->p_x)) - 1][(int)((p->c->p_y))] > 0))
	{
		if (p->map[p->k][(int)((p->c->p_x)) - 1][(int)((p->c->p_y)) - 1] == 0)
		{
			if ((int)(p->c->p_x + p->c->plane_x * s) == (int)p->c->p_x - 1
				|| (int)(p->c->p_y + p->c->plane_y * s) == (int)p->c->p_y - 1)
				move = 1;
		}
	}
	if (p->map[p->k][(int)((p->c->p_x)) - 1][(int)((p->c->p_y))] > 0
			&& (p->map[p->k][(int)((p->c->p_x))][(int)((p->c->p_y)) + 1] > 0))
	{
		if (p->map[p->k][(int)((p->c->p_x)) - 1][(int)((p->c->p_y)) + 1] == 0)
		{
			if ((int)(p->c->p_x + p->c->plane_x * s) == (int)p->c->p_x - 1
				|| (int)(p->c->p_y + p->c->plane_y * s) == (int)p->c->p_y + 1)
				move = 1;
		}
	}
	return (move);
}

int				against_glitch_straff(t_struct *p, int move, double s)
{
	if (p->map[p->k][(int)((p->c->p_x))][(int)((p->c->p_y))] == 0)
	{
		if (p->map[p->k][(int)((p->c->p_x))][(int)((p->c->p_y)) + 1] > 0
				&& (p->map[p->k][(int)((p->c->p_x)) + 1][(int)p->c->p_y] > 0))
		{
			if (p->map[p->k][(int)((p->c->p_x)) + 1][(int)p->c->p_y + 1] == 0)
			{
				if ((int)(p->c->p_x + p->c->plane_x * s) == (int)p->c->p_x + 1
				|| (int)(p->c->p_y + p->c->plane_y * s) == (int)p->c->p_y + 1)
					move = 1;
			}
		}
	}
	if (p->map[p->k][(int)((p->c->p_x))][(int)((p->c->p_y)) - 1] > 0
			&& (p->map[p->k][(int)((p->c->p_x)) + 1][(int)((p->c->p_y))] > 0))
	{
		if (p->map[p->k][(int)((p->c->p_x)) + 1][(int)((p->c->p_y)) - 1] == 0)
		{
			if ((int)(p->c->p_x + p->c->plane_x * s) == (int)p->c->p_x + 1
				|| (int)(p->c->p_y + p->c->plane_y * s) == (int)p->c->p_y - 1)
				move = 1;
		}
	}
	move = against_glitch_straff2(p, move, s);
	return (move);
}

static int		against_glitch2(t_struct *p, int move, double s)
{
	if (p->map[p->k][(int)((p->c->p_x))][(int)((p->c->p_y)) - 1] > 0
			&& (p->map[p->k][(int)((p->c->p_x)) - 1][(int)((p->c->p_y))] > 0))
	{
		if (p->map[p->k][(int)((p->c->p_x)) - 1][(int)((p->c->p_y)) - 1] == 0)
		{
			if ((int)(p->c->p_x + p->c->dir_x * s) == (int)p->c->p_x - 1
				|| (int)(p->c->p_y + p->c->dir_y * s) == (int)p->c->p_y - 1)
				move = 1;
		}
	}
	if (p->map[p->k][(int)((p->c->p_x)) - 1][(int)((p->c->p_y))] > 0
			&& (p->map[p->k][(int)((p->c->p_x))][(int)((p->c->p_y)) + 1] > 0))
	{
		if (p->map[p->k][(int)((p->c->p_x)) - 1][(int)((p->c->p_y)) + 1] == 0)
		{
			if ((int)(p->c->p_x + p->c->dir_x * s) == (int)p->c->p_x - 1
					|| (int)(p->c->p_y + p->c->dir_y * s) == (int)p->c->p_y + 1)
				move = 1;
		}
	}
	return (move);
}

int				against_glitch(t_struct *p, int move, double s)
{
	if (p->map[p->k][(int)((p->c->p_x))][(int)((p->c->p_y))] == 0)
	{
		if (p->map[p->k][(int)((p->c->p_x))][(int)((p->c->p_y)) + 1] > 0
			&& (p->map[p->k][(int)((p->c->p_x)) + 1][(int)(p->c->p_y)] > 0))
		{
			if (p->map[p->k][(int)((p->c->p_x)) + 1][(int)p->c->p_y + 1] == 0)
			{
				if ((int)(p->c->p_x + p->c->dir_x * s) == (int)p->c->p_x + 1
				|| (int)(p->c->p_y + p->c->dir_y * s) == (int)p->c->p_y + 1)
					move = 1;
			}
		}
	}
	if (p->map[p->k][(int)((p->c->p_x))][(int)((p->c->p_y)) - 1] > 0
			&& (p->map[p->k][(int)((p->c->p_x)) + 1][(int)((p->c->p_y))] > 0))
	{
		if (p->map[p->k][(int)((p->c->p_x)) + 1][(int)((p->c->p_y)) - 1] == 0)
		{
			if ((int)(p->c->p_x + p->c->dir_x * s) == (int)p->c->p_x + 1
				|| (int)(p->c->p_y + p->c->dir_y * s) == (int)p->c->p_y - 1)
				move = 1;
		}
	}
	move = against_glitch2(p, move, s);
	return (move);
}
