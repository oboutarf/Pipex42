/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscobou <oscobou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:16:34 by oboutarf          #+#    #+#             */
/*   Updated: 2022/12/16 11:46:28 by oscobou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	t_ppx	*ppx;

	ppx = malloc(sizeof(t_ppx));
	treat_err(ac, av, ppx);
	ppx->paths = treat_paths(env);
	if (pipe(ppx->pipe_fd) != 0)
		err_msg(ERR_PIPE);
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
