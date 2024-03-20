/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_step.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmimault <tmimault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:41:50 by tmimault          #+#    #+#             */
/*   Updated: 2024/03/20 21:00:04 by tmimault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int test_arg(int argc, char **argv, t_cmplx_nb **nb_cmplx)
{
	if(argc > 1)
	{
		if(ft_strncmp("julia", argv[1], ft_strlen(argv[1])) == 0 && argc <= 6 && argc >= 3)
		{
				if (argc == 3)
					nb_cmplx[0] = add_in_cmplx_nb_lst(argv[2],"");
				else 
					nb_cmplx[0] = add_in_cmplx_nb_lst(argv[2],argv [3]);
				return (1);
		}
		else if (ft_strncmp("mandelbrot", argv[1], ft_strlen(argv[1])) == 0 && argc <= 4)
			return (2);
	}
	return (0);
}

int	set_mandelbrot(int argc,char **argv)
{
	t_size_wind	*size_wind;

	size_wind =(void *) 0;
	if (argc == 2)
		size_wind = set_size_wnd_lst("1000", "1000");
	if (argc == 3)
		size_wind = set_size_wnd_lst(argv[2], "");
	if (argc == 4)
		size_wind = set_size_wnd_lst(argv[2], argv[3]);
	if (!size_wind)
	{
		free(size_wind);
		return (print_arg());
	}
	return (begin_mlx(size_wind, NULL));
}

int main(int argc, char **argv)
{
	t_cmplx_nb	*nb_cmplx;
	t_size_wind	*size_wind;
	int			res;

	res = test_arg(argc, argv, &nb_cmplx);
	if (res == 1)
	{
		if (!nb_cmplx)
			return (print_arg());
		if (argc <= 4)
			size_wind = set_size_wnd_lst("1000","1000");
		else if (argc == 5)
			size_wind = set_size_wnd_lst(argv[4],"");
		else 
			size_wind = set_size_wnd_lst(argv[4],argv [5]);
		if (!size_wind)
		{
			free(nb_cmplx);
			return (print_arg());
		}
		return (begin_mlx(size_wind, nb_cmplx));
	}
	else if (res == 2)
		return(set_mandelbrot(argc, argv));
	return(print_arg());
}
int	print_arg()
{
	ft_printf("ERROR ARG\n");
	ft_printf("argv[1] = Type of fractal : 'julia' or 'mandelbrot'\n");
	ft_printf("if julia\n");
	ft_printf("		argv[2] = real number for c (123.123)\n");
	ft_printf("		argv[3] = imginarie number for c (123.123)\n");
	ft_printf("		argv[4] = (optional)width screen of the screen (between 100 and 2000 px)\n");
	ft_printf("		argv[5] = (optional)heigth screen of the screen (between 100 and 2000 px)\n");
	ft_printf("if mandelbrot\n");
	ft_printf("		argv[2] = (optional)width screen of the screen (between 100 and 2000 px)\n");
	ft_printf("		argv[3] = (optional)heigth screen of the screen (between 100 and 2000 px)\n");
	return (0);
}

/*
	// DEBUT DE MLX (creation de windows, creation d'image, ecriture dans l'image avec my_mlx_draw()...)
	ARG arg[1] == julia ou mandelbrot
	si mandelbrot 
		(arg[2] == width arg[3] == height)
	si julia 
		arg[2] == reel arg[3] == imgnb  (arg[4] == width arg[5] == height)
		
*/

/*
Etapes

determiner le type de Fract a faire 
	
	Julia (argc = 4 ; argv[1] = int precision calc, (soit c = a + bi) argv[2] = double a, argv[3] = double [b])
		Z -> Z^2 + C avec c = 1 nombre complexe donne,
		test avec z0 = tout les differents point du plan complexe
		avec de plus en plus de precision (concernant les points, en
		fonction du zoom)
		si la suite tester est borne (vers 0), point noir, n0 plus proche de zero que n1
		sinon point blanc (variation de couleur en fonction du temp que la suite met a diverger)
		
	
	Mandelbrot (argv = 1; argv[1] = precision calc)
		Z -> Z^2 + C avec c =  Test avec TOUT LES POINTS DU PLAN COMPLEXE (x allant de -2 a 2 et y = i);
		z0 = 0
		si c'est borne, point noir,
		sinon point blanc

	
	si argv
		Julia
			fonct qui test argv et le split pour dans t_cmplx_nb
			fonct qui balai tout les point de l'ecran (creer minilib x et different info)
				fonct qui ecrit si converge;
					fonct qui execute suite plusieur fois de suite et qui verifie si ca converge ou non (return int arg : t_cmplx_nb C (determiner en argv), t_cmplx_nb z0 (recup du point balayer) nb_iteration (Precision qui permettra de gerer la couleur))
						fonct utilitaire, multiplication de fract avec calcul de Norme (racine de (x^2 + y^2)) et argument (tengente(arg) = y / x))
	sinon
		Madelbrot
			fonct qui balai tout les point de l'ecran
				fonct qui ecrit si converge;
					fonct qui execute suite plusieur fois de suite et qui verifie si ca converge ou non (return int arg : t_cmplx_nb C (recup du point balayer), t_cmplx_nb z0 = 0, nb_iteration (Precision qui permettra de gerer la couleur))
						fonct utilitaire, multiplication de fract avec calcul de Norme (racine de (x^2 + y^2)) et argument (tengente(arg) = y / x))

A GERER EN PLUS : GESTION DE LA MINILIBX COMMENT AVEC ECRIRE UN POINT

*/