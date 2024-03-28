/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmimault <tmimault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:54:19 by tmimault          #+#    #+#             */
/*   Updated: 2024/03/28 22:15:01 by tmimault         ###   ########.fr       */
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

typedef struct s_size_wind
{
	int	width;
	int	height;
}				t_size_wind;

typedef struct	s_cmplx_nb {
	double	nb_r;
	double	nb_i;
}				t_cmplx_nb;

typedef struct s_all_mlx
{
	void		*mlx;
	t_data		*mlx_img;
	void		*mlx_wind;
	t_cmplx_nb	*mlx_x_y;
	int			origin_x;
	int			origin_y;
	t_cmplx_nb	*cmplx_C;
	int			wind_wid;
	int			wind_hei;
	double		zoom;

}				t_all_mlx;

int			print_arg();
void		my_mlx_put_pxl(t_data *data, int x, int y, int color);
void		my_mlx_draw(void *mlx,void *mlx_win,t_data img);
t_data		*my_mlx_img_set(t_all_mlx *all_mlx);
t_all_mlx	*my_mlx_set(char *wind_name, t_size_wind *wind_size, t_cmplx_nb *cmplx_c);
t_cmplx_nb	*add_in_cmplx_nb_lst(char *c_real_nb, char *c_img_nb);
t_size_wind *set_size_wnd_lst(char *str_width, char *str_height);
void		print_nb_cmplx(t_cmplx_nb *cmplx_nb);
int			start_mandelbrot(t_size_wind *size_wind);
int			start_julia(t_size_wind *t_size_wind, t_cmplx_nb *nb_cmplx_C);
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
double		ft_atof(char *s);
int			hook_key (int keynote, t_all_mlx *all_mlx);
int			hook_destroy (t_all_mlx *all_mlx);
int			determine_unit(int width, int height);
int			begin_mlx(t_size_wind *size_wind, t_cmplx_nb *nb_cmplx_C);
int			create_fract (t_all_mlx *mlx_all);
int			mouse_hook(int button, int x, int y, t_all_mlx *mlx_all);
