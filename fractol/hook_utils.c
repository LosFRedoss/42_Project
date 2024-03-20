/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmimault <tmimault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:41:00 by tmimault          #+#    #+#             */
/*   Updated: 2024/03/20 16:37:10 by tmimault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int hook_close (int keynote, t_all_mlx *all_mlx)
{
	if (keynote == XK_Escape)
	{
		mlx_destroy_image(all_mlx->mlx,all_mlx->mlx_img->img);
		free(all_mlx->mlx_img);
		mlx_destroy_window(all_mlx->mlx,all_mlx->mlx_wind);
		mlx_destroy_display(all_mlx->mlx);
		free(all_mlx->mlx);
		free(all_mlx);
		exit(0);
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
	free(all_mlx);
	exit(0);
	return(1);
}

int	determine_unit(int width, int height)
{
	if (width / 4 > height / 4)
		return (height / 4);
	else
		return (width / 4);
}