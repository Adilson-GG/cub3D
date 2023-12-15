/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomes-g <agomes-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:33:06 by agomes-g          #+#    #+#             */
/*   Updated: 2023/11/28 12:02:20 by agomes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"

typedef struct s_data
{
	int				x;
	int				y;
	int				mouse_x;
	int				mouse_y;
	int				hgt;
	int				wdt;
	int				zoom;
	int				size;
	int				fract;
	int				mv_x;
	int				mv_y;
	int				m_hgt;
	int				m_wdt;
	int				r_wdt;
	int				r_hgt;
	int				chng;
	void			*mlx_ptr;
	void			*win_ptr;
	double			cr;
	double			ci;
	unsigned int	shift_x;
	unsigned int	shift_y;
	unsigned int	shift_z;
}	t_data;

typedef struct s_imge
{
	void	*img_ptr;
	char	*data;
	int		size_line;
	int		bits_per_pixel;
	int		endi;
}	t_imge;

// INIT
int		init_img(t_imge *img, t_data *ptr);
int		init_data(t_data *ptr);

// UTILS
void	manage_window(t_data *ptr, t_imge *img);
void	draw(t_data *ptr, char c, t_imge *img);
void	free_ptr(t_data *ptr);

// GESTION
int		key_press(int keycode, void *param);
int		close_window(void *param);


#endif