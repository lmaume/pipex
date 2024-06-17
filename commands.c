/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaume <lmaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 16:51:45 by lmaume            #+#    #+#             */
/*   Updated: 2024/06/17 11:46:12 by lmaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <signal.h>

char	*get_command(char **paths, char *cmd)
{
	int		i;
	char	*temp;
	char	*command;

	i = 0;
	if (!cmd)
		return (NULL);
	while (paths[i])
	{
		temp = ft_strjoin(paths[i], "/");
		command = ft_strjoin(temp, cmd);
		free(temp);
		if (access(command, 0) == 0)
			return (command);
		free(command);
		i++;
	}
	return (NULL);
}

void	execute_command(t_pipex pipex, char **argv, char **env)
{
	pipex.args = ft_split(argv[pipex.index], ' ');
	pipex.cmd = get_command(pipex.splitted_paths, pipex.args[0]);
	if (pipex.cmd == NULL)
	{
		error("command not found : ", 2);
		error(pipex.args[0], 2);
		error("\n", 2);
		free_child(pipex);
	}
	else if (execve(pipex.cmd, pipex.args, env) == -1)
		perror("execve error.");
}

void	error(char *error_message, int error_or_perror)
{
	if (error_or_perror == 2)
		ft_putstr_fd(error_message, 2);
	else
	{
		perror(error_message);
		exit(1);
	}
}
