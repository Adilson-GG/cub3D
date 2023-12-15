/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomes-g <agomes-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:38:40 by agomes-g          #+#    #+#             */
/*   Updated: 2023/11/28 11:58:38 by agomes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	close_window(void *param)
{
	t_data	*ptr2;

	ptr2 = (t_data *)param;
	free_ptr(ptr2);
	exit(0);
}

void	key_press2(int keycode, t_data *ptr2)
{
	if (keycode == 51)
	{
		ptr2->zoom = 1;
		ptr2->mv_x = 0;
		ptr2->mv_y = 0;
		ptr2->chng = 0;
	}
	if ((keycode >= 65361 && keycode <= 65364)
		|| keycode == 53 || keycode == 52 || keycode == 51)
	{
		if (keycode == 53)
		{
			ptr2->mv_x += 40 * ptr2->zoom;
			ptr2->mv_y += 40 * ptr2->zoom;
			ptr2->chng ++;
		}
		if (keycode == 52 && ptr2->chng)
		{
			ptr2->mv_x -= 40 * ptr2->zoom * 2;
			ptr2->mv_y -= 40 * ptr2->zoom * 2;
			ptr2->chng --;
		}
		mlx_clear_window(ptr2->mlx_ptr, ptr2->win_ptr);
	}
}

int	key_press(int keycode, void *param)
{
	t_data	*ptr2;

	ptr2 = (t_data *)param;
	if (keycode == XK_Escape)
	{
		free_ptr(ptr2);
		exit(0);
	}
	else if (keycode == 53)
		ptr2->zoom *= 2;
	else if (keycode == 52)
	{
		if (ptr2->zoom > 1)
			ptr2->zoom /= 2;
	}
	else if (keycode == 65362)
		ptr2->mv_y += 10 * ptr2->zoom;
	else if (keycode == 65364)
		ptr2->mv_y -= 10 * ptr2->zoom;
	else if (keycode == 65363)
		ptr2->mv_x -= 10 * ptr2->zoom;
	else if (keycode == 65361)
		ptr2->mv_x += 10 * ptr2->zoom;
	key_press2(keycode, ptr2);
	return (0);
}
