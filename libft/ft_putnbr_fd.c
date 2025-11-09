/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 23:11:09 by iarslan           #+#    #+#             */
/*   Updated: 2024/10/26 23:15:25 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	x;
	long	number;

	number = (long)n;
	if (number < 0)
	{
		write(fd, "-", 1);
		number = -number;
	}
	if (number > 9)
	{
		ft_putnbr_fd((number) / 10, fd);
		ft_putnbr_fd((number) % 10, fd);
	}
	else
	{
		x = number + '0';
		write(fd, &x, 1);
	}
}
