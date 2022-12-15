/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_paths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:55:17 by oboutarf          #+#    #+#             */
/*   Updated: 2022/12/15 21:09:22 by oboutarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


int		count_paths_columns(char *path)
{
	int		i[2];

	i[0] = 0;
	i[1] = 0;
	while (path[i[0]])
	{
		if (path[i[0]] == ':')
			i[1]++;
		i[0]++;
	}
	return (i[1] + 1);
}

int		ft_seplen(char *str, int pos, char sep)
{
	int		path_len;

	path_len = pos;
	while (str[path_len] != sep && str[path_len])
		path_len++;
	return (path_len - pos);
}

char	**split_path_env(char *paths, char sep)
{
	char	**new_path;
	int		i[5];

	i[0] = 5;
	i[3] = count_paths_columns(paths);
	new_path = malloc(sizeof(char *) * i[3]);
	if (!new_path)
		return (NULL);
	i[2] = 0;
	while (i[3]-- > 0)
	{
		i[4] = 0;
		i[1] = ft_seplen(paths, i[0], sep);
		new_path[i[2]] = malloc(sizeof(char) * (i[1] + 1));
		if (!new_path[i[2]])
			return (NULL);
		while (paths[i[0]] != sep)
		{
			if (paths[i[0]] == '\0')
				break ;
			new_path[i[2]][i[4]] = paths[i[0]];
			i[0]++;
			i[4]++;
		}
		i[0]++;
		i[2]++;
	}
	return (new_path);
}

char	**treat_paths(char **env)
{
    char    **new_path;
    char    *path;
    int     i[2];

    i[0] = 0;
    path = "PATH=/";
    while (env[i[0]])
    {
        i[1] = 0;
        if (env[i[0]][0] == 'P')
        {
            while (path[i[1]] == env[i[0]][i[1]])
            {
				if (i[1] == 5)
				{
					new_path = split_path_env(env[i[0]], ':');
					return (new_path);
				}
				i[1]++;
            }
        }
        i[0]++;
    }
	new_path = NULL;
	return (new_path);
}