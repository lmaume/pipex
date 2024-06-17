/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaume <lmaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 16:52:17 by lmaume            #+#    #+#             */
/*   Updated: 2024/06/17 11:46:01 by lmaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "printf/libft/libft.h"
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <stdio.h>

# define ERR_PIPE "Pipe error.\n"
# define ERR_INFILE "Infile error.\n"
# define ERR_OUTFILE "Outfile error.\n"
# define NOT_ENOUGH_ARGC "Not enough arg.\n"

enum e_enum
{
	STD_OUT = 1,
	ERR_OUT = 2
};

typedef struct s_pipex
{
	char	**splitted_paths;
	char	**args;
	char	*paths_line;
	char	*cmd;
	int		tube[2];
	int		outfile;
	int		infile;
	int		index;
	pid_t	pid;
}				t_pipex;

void	execute_command(t_pipex pipex, char **argv, char **env);
void	fork_free(t_pipex p);
void	free_child(t_pipex p);
void	error(char *error_message, int fd);

#endif