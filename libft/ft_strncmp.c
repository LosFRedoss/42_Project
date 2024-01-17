/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmimault <tmimault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:33:07 by tmimault          #+#    #+#             */
/*   Updated: 2024/01/11 12:59:38 by tmimault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		y;
	size_t	i;

	i = 0;
	y = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && y == 0 && n != 0 && i < n)
	{
		if (s1[i] == s2[i])
			y = 0;
		else
			y = (const unsigned char)s1[i] - (const unsigned char)s2[i];
		i++;
	}
	return (y);
}
