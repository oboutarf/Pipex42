/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 10:42:07 by oboutarf          #+#    #+#             */
/*   Updated: 2022/12/16 21:52:07 by oboutarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	treat_err(int ac, char **av, t_ppx *ppx)
{
	if (ac != 5)
		err_msg(ERR_INPUT);
	ppx->infile = open(av[1], O_RDONLY);
	if (ppx->infile < 0)
		err_msg(ERR_FILE);
	ppx->outfile = open(av[ac - 1], O_TRUNC | O_CREAT | O_RDWR, 0000644);
	if (ppx->outfile < 0)
		err_msg(ERR_FILE);
}

void	err_msg(char *err)
{
	perror(err);
	exit(1);
}
