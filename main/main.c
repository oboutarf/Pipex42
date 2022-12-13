/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:16:34 by oboutarf          #+#    #+#             */
/*   Updated: 2022/12/13 18:12:15 by oboutarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	t_ppx	pipex;

	if (ac != 5)
		message_error(ERR_INPUT);
	(void)pipex;
	(void)env;
	(void)av;
	return (0);
}




// #AuthorizedFunctions#
/*

open
close
read
write
malloc
free
perror
strerror
access
dup
dup2
execve
exit
fork
pipe
unlink
wait
waitpid

*/