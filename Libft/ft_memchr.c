/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buramert <buramert@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 20:17:28 by buramert          #+#    #+#             */
/*   Updated: 2024/10/13 17:09:47 by buramert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;
	const void		*first_occurence;
	size_t			i;

	p = (unsigned char *)s;
	first_occurence = NULL;
	i = 0;
	while (i < n)
	{
		if (*p == (unsigned char)c)
		{
			first_occurence = p;
			return ((char *) first_occurence);
		}
		p++;
		i++;
	}
	return (NULL);
}
