/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 21:51:00 by oboutarf          #+#    #+#             */
/*   Updated: 2022/12/16 16:04:39 by oboutarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		all_length;
	char	*dest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	all_length = ((ft_strlen(s1)) + (ft_strlen(s2)));
	dest = (char *)malloc(sizeof(char) * (all_length + 1));
	while (s1[j])
		dest[i++] = s1[j++];
	j = 0;
	while (s2[j])
		dest[i++] = s2[j++];
	dest[i] = '\0';
	return (dest);
}

char	*find_access(t_ppx *ppx)
{
	char	*tmp;
	int		i;

	i = 0;
	if (ppx->cmd_args[i] == NULL)
		return (NULL);
	while (ppx->paths[i])
	{
		tmp = ft_strjoin(ppx->paths[i], "/");
		ppx->cmd = ft_strjoin(tmp, ppx->cmd_args[0]);
		free(tmp);
		if (access(ppx->cmd, F_OK) == 0)
			return (ppx->cmd);
		free(ppx->cmd);
		i++;
	}
	return (NULL);
}

void	process_inpid_child(t_ppx *ppx, char **av, char **env)
{
	dup2(ppx->pipe_fd[1], STDOUT_FILENO);
	close(ppx->pipe_fd[0]);
	dup2(ppx->infile, STDIN_FILENO);
	ppx->cmd_args = ft_split(av[2], ' ');
	ppx->cmd = find_access(ppx);
	if (ppx->cmd == NULL)
		return (free_tab(ppx->cmd_args));
	execve(ppx->cmd, ppx->cmd_args, env);
}

void	process_outpid_child(t_ppx *ppx, char **av, char **env)
{
	dup2(ppx->pipe_fd[0], STDIN_FILENO);
	close(ppx->pipe_fd[1]);
	dup2(ppx->outfile, STDOUT_FILENO);
	ppx->cmd_args = ft_split(av[3], ' ');
	ppx->cmd = find_access(ppx);
	if (ppx->cmd == NULL)
		return (free_tab(ppx->cmd_args));
	execve(ppx->cmd, ppx->cmd_args, env);
}
