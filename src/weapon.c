/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbataini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 21:33:15 by bbataini          #+#    #+#             */
/*   Updated: 2019/04/18 21:33:16 by bbataini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

static void		weapon2(t_struct *p)
{
	if (p->temp == 0 && p->sound == 1)
		system("afplay ./doomzik/chainsaw_attack_middle.mp3 & 2>&1");
	if (p->trons == 1)
	{
		p->trons = 0;
		if (p->sound == 1)
			system("afplay ./doomzik/chainsaw_attack_in.mp3 & 2>&1");
	}
	mlx_put_image_to_window(p->mlx_ptr, p->w_ptr, p->tex[88].img_ptr, 610, 583);
}

void			weapon(t_struct *p)
{
	if (p->weapon.id == 1)
	{
		if (p->temp % 40 == 0 && p->sound == 1)
			system("afplay ./doomzik/chainsaw_sustain.mp3 & 2>&1");
		if (p->keypress[KEY_SPACEBAR] == 0)
		{
			mlx_put_image_to_window(p->mlx_ptr, p->w_ptr, p->tex[87].img_ptr,
					610, 697);
			if (p->trons == 0)
			{
				p->trons = 1;
				if (p->sound == 1)
					system("afplay ./doomzik/chainsaw_attack_out.mp3 & 2>&1");
			}
		}
		else if (p->keypress[KEY_SPACEBAR] == 1)
			weapon2(p);
	}
	weapon3(p);
}
