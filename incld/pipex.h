/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:35:42 by oboutarf          #+#    #+#             */
/*   Updated: 2022/12/15 22:01:17 by oboutarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# define ERR_PIPE "Couldn't create pipe! Try again!\n"
# define ERR_INPUT "Invalid number of arguments.\n"
# define ERR_OUTFILE "Error outfile!\n"
# define ERR_INFILE "Error infile!\n"

// ----------------------- #Includes --------------------------
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// ----------------------- #Struct ----------------------------
typedef struct s_ppx
{
    pid_t       in_pid;
    pid_t       out_pid;
    int         infile;
    int         outfile;
    int         pipe_fd[2];
    char        **paths;
    char        *cmd;
}              t_ppx;
// ---------------------- #Errors -----------------------------
void	treat_err(int ac, char **av, t_ppx *ppx);
void    err_msg(char *err);
// --------------------- #FindPath ----------------------------
char    **treat_paths(char **env);
// ----------------------- #Free ------------------------------
char	**mallocrash(char **tab);
void	free_tab(char **_free_t_);
void    free_ppx(t_ppx *ppx);
// ------------------ #Process Childs -------------------------
void    process_inpid_child(t_ppx *ppx, char **av, char **env);
void    process_outpid_child(t_ppx *ppx, char **av, char **env);
// ----------------------- # # # ------------------------------
#endif
