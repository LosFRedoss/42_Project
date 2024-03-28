/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmimault <tmimault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:41:00 by tmimault          #+#    #+#             */
/*   Updated: 2024/03/28 23:31:19 by tmimault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int hook_key (int key, t_all_mlx *all)
{
	if (key == XK_Escape)
		hook_destroy(all);
	if(key == XK_Up || key == XK_Down || key == XK_Left || key == XK_Right
		|| key == XK_r)
	{
		mlx_destroy_image(all->mlx, all->mlx_img->img);
		if(key == XK_Up)
			all->origin_y -= 100;
		if(key == XK_Down)
			all->origin_y += 100;
		if(key == XK_Left)
			all->origin_x -= 100;
		if(key == XK_Right)
			all->origin_x += 100;
		if (key == XK_r)
		{
			all->origin_x = 0;
			all->origin_y = 0;
			all->zoom = 1;
		}
		all->mlx_img->img = mlx_new_image(all->mlx, all->wind_wid,
			all->wind_hei);
		create_fract (all);
	}
	return (1);
}

int hook_destroy (t_all_mlx *all_mlx)
{
	mlx_destroy_image(all_mlx->mlx,all_mlx->mlx_img->img);
	free(all_mlx->mlx_img);
	mlx_destroy_window(all_mlx->mlx,all_mlx->mlx_wind);
	mlx_destroy_display(all_mlx->mlx);
	free(all_mlx->mlx);
	if (all_mlx->cmplx_C != (void*)0)
		free(all_mlx->cmplx_C);
	free(all_mlx->mlx_x_y);
	free(all_mlx);
	exit(0);
	return(1);
}

int	determine_unit(int width, int height)
{
	if (width > height)
		return (height / 4);
	else
		return (width / 4);
}

int mouse_hook(int button, int x, int y, t_all_mlx *mlx_all)
{
	if (!x || !y)
		return (-1);
	if (button == 5 || button == 4)
	{
		mlx_destroy_image(mlx_all->mlx, mlx_all->mlx_img->img);
		if (button == 4)
		{
			mlx_all->zoom /= 1.1;
			mlx_all->origin_x += mlx_all->origin_x * 0.1;
			mlx_all->origin_y += mlx_all->origin_y * 0.1;
		}
		else if (button == 5)
		{	
			mlx_all->origin_x -= mlx_all->origin_x * 0.1;
			mlx_all->origin_y -= mlx_all->origin_y * 0.1;
			mlx_all->zoom = mlx_all->zoom * 1.1;
		}
		mlx_all->mlx_img->img = mlx_new_image(mlx_all->mlx, mlx_all->wind_wid,
			mlx_all->wind_hei);
		create_fract(mlx_all);
	}
	return (1);
}
