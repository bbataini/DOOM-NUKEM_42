/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbataini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 21:30:55 by bbataini          #+#    #+#             */
/*   Updated: 2019/04/18 21:30:58 by bbataini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

static void		elevator2(t_struct *p)
{
	if (p->keypress[KEY_1] == 1 || p->keypress[KEY_PAD_1] == 1)
		p->k = 7;
	else if (p->keypress[KEY_2] == 1 || p->keypress[KEY_PAD_2] == 1)
		p->k = 0;
	else if (p->keypress[KEY_3] == 1 || p->keypress[KEY_PAD_3] == 1)
		p->k = 5;
	else if (p->keypress[KEY_4] == 1 || p->keypress[KEY_PAD_4] == 1)
		p->k = 8;
	else if (p->keypress[KEY_5] == 1 || p->keypress[KEY_PAD_5] == 1)
	{
		if (p->sprite[17].k == 6)
			p->sprite[18].k = 6;
		p->k = 9;
	}
	p->elevator = 0;
	p->c->p_x = 6.5;
	p->c->p_y = 7.5;
	p->c->dir_x = -1;
	p->c->dir_y = 0;
	p->c->plane_x = 0;
	p->c->plane_y = 1;
	p->door[0].open = 0;
	p->door[0].poort = 1;
}

void			elevator(t_struct *p)
{
	p->elevator = (p->k == 0) ? 2 : p->elevator;
	p->elevator = (p->k == 5) ? 3 : p->elevator;
	p->elevator = (p->k == 7) ? 1 : p->elevator;
	p->elevator = (p->k == 8) ? 4 : p->elevator;
	p->elevator = (p->k == 9) ? 5 : p->elevator;
	if (p->keypress[KEY_1] == 1 || p->keypress[KEY_2] == 1
			|| p->keypress[KEY_3] == 1 || p->keypress[KEY_4] == 1
			|| p->keypress[KEY_5] == 1 || p->keypress[KEY_PAD_1] == 1
			|| p->keypress[KEY_PAD_2] == 1 || p->keypress[KEY_PAD_3] == 1
			|| p->keypress[KEY_PAD_4] == 1 || p->keypress[KEY_PAD_5] == 1)
	{
		if (p->sound == 1)
			system("afplay ./doomzik/elevator_beep.mp3 & 2>&1");
		p->h = (p->k == 7) ? 0 : p->h;
		elevator2(p);
	}
}
