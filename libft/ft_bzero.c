/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:10:10 by rlebaill          #+#    #+#             */
/*   Updated: 2024/10/23 15:12:34 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*m;
	size_t	i;

	m = (char *)s;
	i = 0;
	while (i < n)
	{
		m[i] = '\0';
		i++;
	}
}

/*int	main(void)
{
	int	*a;
	int	i;

	i = 0;
	a = malloc(5);
	if (!a)
		return (0);
	a = ft_bzero((void *)a, 5);
	while (i < 5)
	{
		printf("%d\n", a[i]);
		i++;
	}
	return (0);
}*/
