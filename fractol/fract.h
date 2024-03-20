/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmimault <tmimault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:54:19 by tmimault          #+#    #+#             */
/*   Updated: 2024/03/20 20:33:25 by tmimault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> 
#include <math.h>
#include <unistd.h>
#include <stdio.h>
#include <X11/keysym.h>
#include <string.h> //a suprimer
#include "mlx_linux/mlx.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_cmplx_nb {
	double	nb_r;
	double	nb_i;
}				t_cmplx_nb;

typedef struct s_all_mlx
{
	t_data	*mlx_img;
	void	*mlx;
	void	*mlx_wind;
}				t_all_mlx;

typedef struct s_
{
	int	width;
	int	height;
}				t_size_wind;

int			print_arg();
void		my_mlx_put_pxl(t_data *data, int x, int y, int color);
void		my_mlx_draw(void *mlx,void *mlx_win,t_data img);
t_cmplx_nb	*add_in_cmplx_nb_lst(char *c_real_nb, char *c_img_nb);
t_size_wind *set_size_wnd_lst(char *str_width, char *str_height);
void		print_nb_cmplx(t_cmplx_nb *cmplx_nb);
int			start_mandelbrot(t_size_wind *size_wind);
int			start_julia(t_size_wind *t_size_wind, t_cmplx_nb *nb_cmplx_C);
t_all_mlx	*my_mlx_set(char *wind_name, int width, int height);
t_cmplx_nb	*dbl_to_cmplx(double int_real_nb, double int_img_nb, int unit);
t_cmplx_nb	*calc_cmplx_add(t_cmplx_nb *cmplx_nb1, t_cmplx_nb *cmplx_nb2);
t_cmplx_nb	*calc_cmplx_square(t_cmplx_nb *cmplx_nb);
double		calc_cmplx_argum(t_cmplx_nb *cmplx_nb);
double		calc_cmplx_norm(t_cmplx_nb *cmplx_nb);
t_cmplx_nb	*int_to_double_cmplx(double int_real_nb, double int_img_nb, int unit);
int			free_all_mlx(t_all_mlx * all_mlx);
int			ft_printf(const char *test, ...);
size_t		ft_strlen(const char *s);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_atoi(const char *nptr);
int			hook_close (int keynote, t_all_mlx *all_mlx);
int			hook_destroy (t_all_mlx *all_mlx);
int			determine_unit(int width, int height);
int			begin_mlx(t_size_wind *size_wind, t_cmplx_nb *nb_cmplx_C);



