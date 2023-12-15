/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomes-g <agomes-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:35:45 by agomes-g          #+#    #+#             */
/*   Updated: 2023/11/28 11:58:32 by agomes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	init_data(t_data *ptr)
{
	ptr->x = 0;
	ptr->y = 0;
	ptr->mouse_x = 0;
	ptr->mouse_y = 0;
	ptr->hgt = 100;
	ptr->wdt = 100;
	ptr->zoom = 1;
	ptr->m_hgt = 0;
	ptr->m_wdt = 0;
	ptr->mv_x = 0;
	ptr->mv_y = 0;
	ptr->mlx_ptr = mlx_init();
	ptr->chng = 0;
	if (!ptr->mlx_ptr)
		return (0);
	ptr->win_ptr = mlx_new_window(ptr->mlx_ptr, ptr->wdt, ptr->hgt, "cub3D");
	if (!ptr->win_ptr)
		return (0);
	return (1);
}

int	init_img(t_imge *img, t_data *ptr)
{
	img->bits_per_pixel = 32;
	img->img_ptr = mlx_new_image(ptr->mlx_ptr, ptr->wdt, ptr->hgt);
	if (!img->img_ptr)
		return (0);
	img->size_line = ptr->wdt * (img->bits_per_pixel / 8);
	img->endi = 0;
	img->data = mlx_get_data_addr(img->img_ptr, &(img->bits_per_pixel),
			&(img->size_line), &(img->endi));
	if (!img->data)
		return (0);
	return (1);
}
