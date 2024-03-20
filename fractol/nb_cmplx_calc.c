/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nb_cmplx_calc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmimault <tmimault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:19:02 by tmimault          #+#    #+#             */
/*   Updated: 2024/03/19 16:01:11 by tmimault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

t_cmplx_nb *	calc_cmplx_square(t_cmplx_nb *cmplx_nb)
{
	t_cmplx_nb	*cmplx_fnl;

	cmplx_fnl = calloc (1, sizeof(*cmplx_fnl));
	if (!cmplx_fnl)
		return ((void *) 0);
	cmplx_fnl->nb_r = pow(cmplx_nb->nb_r, 2) - pow(cmplx_nb->nb_i, 2);
	cmplx_fnl->nb_i = 2 * cmplx_nb->nb_r * cmplx_nb->nb_i;
	//print_nb_cmplx(cmplx_fnl);
	free(cmplx_nb);
	return (cmplx_fnl);
}
double	calc_cmplx_norm(t_cmplx_nb *cmplx_nb)
{
	double norm;

	norm = sqrt(pow(cmplx_nb->nb_r, 2) + pow(cmplx_nb->nb_i, 2));
	//printf("norm = %f \n",norm);
	return (norm);
}
double	calc_cmplx_argum(t_cmplx_nb *cmplx_nb)
{
	double argu;

	argu = atan(cmplx_nb->nb_i / cmplx_nb->nb_r);
	return (argu);
}

t_cmplx_nb	*calc_cmplx_add(t_cmplx_nb *cmplx_nb1, t_cmplx_nb *cmplx_nb2)
{
	t_cmplx_nb *cmplx_add;

	cmplx_add = calloc (1, sizeof(*cmplx_add));
	if (!cmplx_add)
		return ((void *)0);
	cmplx_add->nb_r  = cmplx_nb1->nb_r + cmplx_nb2->nb_r;
	cmplx_add->nb_i  = cmplx_nb1->nb_i + cmplx_nb2->nb_i;
	free(cmplx_nb1);
	return (cmplx_add);
}