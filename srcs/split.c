/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscobou <oscobou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:15:27 by oboutarf          #+#    #+#             */
/*   Updated: 2022/12/16 10:49:42 by oscobou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*ft_mystrlcpy(char *dest, char *src, int size, int i)
{
	int		j;

	j = 0;
	while (size--)
	{
		dest[j] = src[i];
		j++;
		i++;
	}
	dest[j] = '\0';
	return (dest);
}

static int	tablength(char const *s, char c)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
		{
			i++;
			if (s[i] == '\0')
				return (count);
		}
		while (s[i] != c && s[i])
			i++;
		count++;
	}
	return (count);
}

static int	myanti_c(char const *s, int i, char c)
{
	int		base;

	base = i;
	while (s[i] != c && s[i])
		i++;
	i -= base;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		a;
	int		alloc;

	i = 0;
	a = 0;
	alloc = tablength(s, c);
	tab = (char **)malloc(sizeof(char *) * (alloc + 1));
	if (!tab)
		return (NULL);
	while (a < alloc)
	{
		while (s[i] == c)
			i++;
		tab[a] = malloc(sizeof(char) * myanti_c(s, i, c) + 1);
		if (!tab[a])
			return (mallocrash(tab));
		ft_mystrlcpy(tab[a], (char *)s, myanti_c(s, i, c), i);
		while (s[i] != c && s[i])
			i++;
		a++;
	}
	tab[a] = NULL;
	return (tab);
}
