/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:35:42 by oboutarf          #+#    #+#             */
/*   Updated: 2022/12/16 15:44:58 by oboutarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# define ERR_PIPE "Couldn't create pipe! Try again!\n"
# define ERR_INPUT "Invalid number of arguments.\n"
# define ERR_OUTFILE "Error outfile!\n"
# define ERR_INFILE "Error infile!\n"

// ----------------------- #Includes --------------------------
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

// ----------------------- #Struct ----------------------------
typedef struct s_ppx
{
	int			pipe_fd[2];
	int			outfile;
	int			infile;
	pid_t		out_pid;
	pid_t		in_pid;
	char		**cmd_args;
	char		**paths;
	char		*cmd;
}				t_ppx;
// ---------------------- #Allocs -----------------------------
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memset(void *s, int c, size_t n);
// ---------------------- #Errors -----------------------------
void	treat_err(int ac, char **av, t_ppx *ppx);
void	err_msg(char *err);
// --------------------- #FindPath ----------------------------
char	**treat_paths(char **env);
// ----------------------- #Split -----------------------------
char	**ft_split(char const *s, char c);
// ----------------------- #Free ------------------------------
char	**mallocrash(char **tab);
void	free_tab(char **_free_t_);
void	free_ppx(t_ppx *ppx);
// ------------------ #Process Childs -------------------------
void	process_inpid_child(t_ppx *ppx, char **av, char **env);
void	process_outpid_child(t_ppx *ppx, char **av, char **env);
// ----------------------- # # # ------------------------------
#endif
