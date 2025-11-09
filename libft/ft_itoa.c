/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 20:18:28 by iarslan           #+#    #+#             */
/*   Updated: 2024/10/26 22:00:54 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbrlen(long x)
{
	int	len;

	len = 1;
	if (x < 0)
		len++;
	while (x > 9 || x < -9)
	{
		x = x / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*final;
	int		digitnmbr;
	long	nlong;

	nlong = (long)n;
	digitnmbr = nbrlen(nlong);
	final = malloc(sizeof(char) * (digitnmbr + 1));
	if (!final)
		return (NULL);
	final[digitnmbr] = '\0';
	if (nlong < 0)
	{
		final[0] = '-';
		nlong = -nlong;
	}
	digitnmbr--;
	while (nlong > 9)
	{
		final[digitnmbr] = (nlong % 10) + '0';
		nlong = nlong / 10;
		digitnmbr--;
	}
	final[digitnmbr] = nlong + '0';
	return (final);
}
