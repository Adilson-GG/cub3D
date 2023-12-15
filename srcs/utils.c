/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomes-g <agomes-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:35:05 by agomes-g          #+#    #+#             */
/*   Updated: 2023/11/28 11:58:48 by agomes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_ptr(t_data *ptr)
{
	mlx_clear_window(ptr->mlx_ptr, ptr->win_ptr);
	mlx_destroy_window(ptr->mlx_ptr, ptr->win_ptr);
	mlx_destroy_display(ptr->mlx_ptr);
	free(ptr->mlx_ptr);
	free(ptr);
}

void	draw(t_data *ptr, char c, t_imge *img)
{
	unsigned int	color;
	char			*dst;

	if (c == '1')
		color = 0xFFFFFF;
	else
		color = 0;
	if (abs(ptr->x) > ptr->wdt || abs(ptr->y) > ptr->hgt
		|| ptr->x < 0 || ptr->y < 0)
		return ;
	dst = img->data + ((ptr->y * ptr->wdt + ptr->x)
			* (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	manage_window(t_data *ptr, t_imge *img)
{
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr, img->img_ptr, 0, 0);
	mlx_string_put(ptr->mlx_ptr, ptr->win_ptr, 200, 50, 0xFFFFFF,
		"Zoom : 5 / Dezoom : 4 / Ou Molette / Depalcements avec les fleches");
	mlx_string_put(ptr->mlx_ptr, ptr->win_ptr, 300, 800, 0xDF08F8,
		"---> 3 <----- : Pour revenir a la position de depart");
	mlx_destroy_image(ptr->mlx_ptr, img->img_ptr);
	free(img);
}
