/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buramert <buramert@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 18:25:17 by buramert          #+#    #+#             */
/*   Updated: 2024/10/21 21:00:43 by buramert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	free_alloc(char **final, int count)
{
	int	i;

	if (!final)
		return ;
	i = 0;
	while (i < count)
	{
		free(final[i]);
		i++;
	}
	free(final);
}

static int	word_counter(const char *s, char c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			counter++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (counter);
}

static char	*assign(const char *s, int start, int end)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(sizeof(char) * (end - start + 1));
	if (!str)
		return (NULL);
	while (start < end)
	{
		str[i] = s[start];
		start++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	*separator(const char *s, char c, int *index)
{
	int	start;
	int	end;

	start = *index;
	while (s[start] && s[start] == c)
		start++;
	end = start;
	while (s[end] && s[end] != c)
		end++;
	*index = end;
	return (assign(s, start, end));
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**final;
	char	*str;

	i = 0;
	j = 0;
	final = malloc(sizeof(char *) * (word_counter(s, c) + 1));
	if (!final)
		return (NULL);
	while (i < word_counter(s, c))
	{
		str = separator(s, c, &j);
		if (!str)
		{
			free_alloc(final, i);
			return (NULL);
		}
		final[i++] = str;
	}
	final[i] = NULL;
	return (final);
}
