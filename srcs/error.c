/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscobou <oscobou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 10:42:07 by oboutarf          #+#    #+#             */
/*   Updated: 2022/12/16 11:46:04 by oscobou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	treat_err(int ac, char **av, t_ppx *ppx)
{
	if (ac != 5)
		err_msg(ERR_INPUT);
	ppx->infile = open(av[1], O_RDONLY);
	if (ppx->infile < 0)
		err_msg(ERR_INFILE);
	ppx->outfile = open(av[ac - 1], O_TRUNC | O_CREAT | O_RDWR);
	if (ppx->outfile < 0)
		err_msg(ERR_OUTFILE);
}

void    err_msg(char *err)
{
    perror(err);
    exit(1);
}