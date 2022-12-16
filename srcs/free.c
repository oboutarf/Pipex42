/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 21:05:20 by oboutarf          #+#    #+#             */
/*   Updated: 2022/12/16 22:00:34 by oboutarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**mallocrash(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

void	free_tab(char **_free_t_)
{
	int		j;

	j = -1;
	if (_free_t_)
	{
		while (_free_t_[++j])
			free(_free_t_[j]);
	}
	free(_free_t_);
}

void	free_ppx(t_ppx *ppx)
{
	close(ppx->infile);
	close(ppx->outfile);
	free_tab(ppx->paths);
	free(ppx);
}
