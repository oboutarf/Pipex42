/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:16:34 by oboutarf          #+#    #+#             */
/*   Updated: 2022/12/16 21:29:53 by oboutarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	t_ppx	*ppx;

	ppx = malloc(sizeof(t_ppx));
	treat_err(ac, av, ppx);
	if (*env)
		ppx->paths = treat_paths(env);
	if (pipe(ppx->pipe_fd) != 0)
		err_msg(ERR_PIPE);
	ppx->in_pid = fork();
	if (ppx->in_pid == 0)
		process_inpid_child(ppx, av, env);
	if (ppx->in_pid > 0)
	{
		ppx->out_pid = fork();
		if (ppx->out_pid == 0)
			process_outpid_child(ppx, av, env);
	}
	close(ppx->pipe_fd[0]);
	close(ppx->pipe_fd[1]);
	waitpid(ppx->in_pid, NULL, 0);
	waitpid(ppx->out_pid, NULL, 0);
	free_ppx(ppx);
	return (0);
}
