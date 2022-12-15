/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:16:34 by oboutarf          #+#    #+#             */
/*   Updated: 2022/12/15 21:10:02 by oboutarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


int	main(int ac, char **av, char **env)
{
	t_ppx	*ppx;

	ppx = malloc(sizeof(t_ppx));
	treat_err(ac, av, ppx);	
	ppx->paths = treat_paths(env);
	(void)av;
	(void)ppx;
	return (0);
}
