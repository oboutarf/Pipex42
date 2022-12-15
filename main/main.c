/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:16:34 by oboutarf          #+#    #+#             */
/*   Updated: 2022/12/15 22:00:17 by oboutarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	t_ppx	*ppx;

	ppx = malloc(sizeof(t_ppx));
	treat_err(ac, av, ppx);
	ppx->paths = treat_paths(env);
	ppx->in_pid = fork();
	if (ppx->in_pid == 0)
		process_inpid_child(ppx, av, env);
	ppx->out_pid = fork();
	if (ppx->out_pid == 0)
		process_outpid_child(ppx, av, env);
	waitpid(ppx->in_pid, NULL, 0);
	waitpid(ppx->out_pid, NULL, 0);
	free_ppx(ppx);
	return (0);
}
