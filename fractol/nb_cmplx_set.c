/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nb_cmplx_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmimault <tmimault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:51:26 by tmimault          #+#    #+#             */
/*   Updated: 2024/03/28 23:53:39 by tmimault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int		tester_cmplx_nb(char *str)
{
	int	i;
	int	size_str;

	i = 0;
	size_str = strlen(str);
	while(i < size_str && (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r')))
		i++;
	if (i < size_str - 1 && (str[i] == '+' || str[i] == '-'))
		i++;
	while (i < size_str && str[i] >= '0' && str[i] <= '9')
		i++;
	if (i < size_str - 1 &&  str[i] == '.')
		i++;
	while (i < size_str && str[i] >= '0' && str[i] <= '9')
		i++;
	if (i < size_str - 1 && (str[i] == 'e' || str[i] == 'E'))
		i++;
	if (i < size_str - 1 && (str[i] == '+'))
		i++;
	while (i < size_str && str[i] >= '0' && str[i] <= '9')
		i++;
	if (i == size_str)
		return (1);
	return (0);
}

t_cmplx_nb *add_in_cmplx_nb_lst(char *c_real_nb, char *c_img_nb)
{
	double	d_real_nb;
	double	d_img_nb;
	t_cmplx_nb	*fnl_cmplx_nb;

	
	if (tester_cmplx_nb(c_real_nb) == 1 && tester_cmplx_nb(c_img_nb) == 1)
	{
		d_real_nb = atof(c_real_nb);
		d_img_nb = atof(c_img_nb);
		fnl_cmplx_nb = calloc(1, sizeof(*fnl_cmplx_nb));
	}
	else
		return ((void *) 0);
	if (!fnl_cmplx_nb)
		return ((void *)0);
	if (c_img_nb == NULL)
		(*fnl_cmplx_nb).nb_i = 0;
	else
		(*fnl_cmplx_nb).nb_i = d_img_nb;
	if (c_real_nb == NULL)
		(*fnl_cmplx_nb).nb_r = 0;
	else
		(*fnl_cmplx_nb).nb_r = d_real_nb;
	return(fnl_cmplx_nb);
}

void	print_nb_cmplx(t_cmplx_nb *cmplx_nb)
{
	printf("cmplx_nb = %lf + %lfi\n", cmplx_nb->nb_r, cmplx_nb->nb_i);
}

t_cmplx_nb	*dbl_to_cmplx(double int_real_nb, double int_img_nb, int unit)
{
	double		d_real_nb;
	double		d_img_nb;
	t_cmplx_nb	*fnl_cmplx_nb;

	if (unit == 0 || int_real_nb == 0 )
		d_real_nb = int_real_nb;
	else
		d_real_nb = int_real_nb / unit;
	if (unit ==0 || int_img_nb == 0 )
		d_img_nb = int_img_nb;
	else
		d_img_nb = int_img_nb / unit;
	fnl_cmplx_nb = calloc(1, sizeof(*fnl_cmplx_nb));
	if (!fnl_cmplx_nb)
		return ((void *) 0);
	(*fnl_cmplx_nb).nb_i = d_img_nb;
	(*fnl_cmplx_nb).nb_r = d_real_nb;
	return (fnl_cmplx_nb); 
}

