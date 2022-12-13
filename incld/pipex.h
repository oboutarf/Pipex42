/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:35:42 by oboutarf          #+#    #+#             */
/*   Updated: 2022/12/13 18:11:59 by oboutarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# define ERR_INPUT "Invalid number of arguments.\n"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>


typedef struct s_ppx
{
    pid_t       w_pid1;
    pid_t       w_pid2;
    int         infile;
    int         outfile;
}              t_ppx;

void    message_error(char *err);

#endif
