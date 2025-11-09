/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 22:23:16 by iarslan           #+#    #+#             */
/*   Updated: 2024/10/27 02:52:52 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*final;
	int		i;
	int		j;
	int		s1size;
	int		s2size;

	i = 0;
	j = 0;
	s1size = ft_strlen(s1);
	s2size = ft_strlen(s2);
	final = malloc(sizeof(char) * (s1size + s2size + 1));
	if (!final)
		return (NULL);
	while (s1[i])
		final[j++] = s1[i++];
	i = 0;
	while (s2[i])
		final[j++] = s2[i++];
	final[j] = '\0';
	return (final);
}
