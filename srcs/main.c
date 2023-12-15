/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomes-g <agomes-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:35:14 by agomes-g          #+#    #+#             */
/*   Updated: 2023/11/28 12:10:49 by agomes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	algo(t_data *ptr, t_imge *img, char **map)
{
	int	i;

	i = 0;
	while (map[0][i])
		i ++;
	ptr->m_wdt = i;
	i = 0;
	while (map[i])
		i ++;
	ptr->m_hgt = i;
	ptr->r_hgt = ptr->hgt / ptr->m_hgt;
	ptr->r_wdt = ptr->wdt / ptr->m_wdt;
	ptr->x = -1;
	while (++ptr->x < ptr->wdt)
	{
		ptr->y = -1;
		while (++ptr->y < ptr->hgt)
			draw(ptr, map[ptr->y / ptr->r_hgt][ptr->x / ptr->r_wdt], img);
	}
	manage_window(ptr, img);
}

int	main(int argc, char **argv)
{
	t_data	*ptr;
	char	*map[6];
	t_imge	*img;

	(void)argc;
	(void)argv;
	
	ptr = (t_data *)malloc(sizeof(t_data));
	if (!ptr)
		return (0);
	if (!init_data(ptr))
		return (free(ptr), 0);
	img = (t_imge *)malloc(sizeof(t_imge));
	if (!img)
		return (free(ptr->win_ptr), free(ptr), 0);
	if (!init_img(img, ptr))
		return (free(img), free(ptr->win_ptr), free(ptr), 0);
	map[0] = "11111";
	map[1] = "10001";
	map[2] = "10101";
	map[3] = "10001";
	map[4] = "11111";
	map[5] = NULL;
	algo(ptr, img, map);
	mlx_hook(ptr->win_ptr, 17, 0, &close_window, ptr);
	mlx_hook(ptr->win_ptr, KeyPress, KeyPressMask, &key_press, ptr);
	mlx_loop(ptr->mlx_ptr);
	return (0);
}
