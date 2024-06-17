/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaume <lmaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 16:50:55 by lmaume            #+#    #+#             */
/*   Updated: 2024/06/17 17:37:11 by lmaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	fork_free(t_pipex p)
{
	int	i;

	i = 0;
	close(p.infile);
	close(p.outfile);
	if (p.pid == 0)
	{
		close(p.tube[1]);
		close(p.tube[0]);
	}
	while (p.splitted_paths[i])
	{
		free(p.splitted_paths[i]);
		i++;
	}
	free(p.splitted_paths);
}

void	free_child(t_pipex p)
{
	int	i;

	i = 0;
	while (p.args[i])
	{
		if (p.args[i])
			free(p.args[i]);
		i++;
	}
	free(p.args);
}

int	child(t_pipex p, int argc)
{
	if (close(p.tube[0]) == -1)
		return (close(p.tube[1]), -1);
	if (p.index == 2)
		if (dup2(p.infile, STDIN_FILENO) == -1)
			return (close(p.tube[1]), -1);
	if (p.index == argc - 2)
	{
		if (dup2(p.outfile, STDOUT_FILENO) == -1)
			return (close(p.tube[1]), -1);
	}
	else
	{
		if (dup2(p.tube[1], STDOUT_FILENO) == -1)
			return (close(p.tube[1]), -1);
	}
	return (0);
}

void	pipex(t_pipex p, int argc, char **argv, char **env)
{
	p.index = 2;
	while (p.index <= argc - 2)
	{
		if (pipe(p.tube) < 0)
			error(ERR_PIPE, ERR_OUT);
		p.pid = fork();
		if (p.pid == -1)
			return ;
		if (p.pid == 0)
		{
			if (child(p, argc) == -1)
				return ;
			execute_command(p, argv, env);
			fork_free(p);
			exit(1);
		}
		else
		{
			if ((close(p.tube[1]) == -1 || \
			dup2(p.tube[0], 0) == -1 || close(p.tube[0]) == -1))
				return ;
		}
		p.index++;
	}
	wait(NULL);
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	p;
	int		i;

	i = 0;
	p.cmd = NULL;
	if (argc < 5)
		return (error(NOT_ENOUGH_ARGC, ERR_OUT), 1);
	p.infile = open(argv[1], O_RDONLY);
	if (p.infile < 0)
		return (error(ERR_INFILE, ERR_OUT), 1);
	p.outfile = open(argv[argc - 1], O_TRUNC | O_CREAT | O_WRONLY, 0644);
	if (p.outfile < 0)
		return (close (p.infile), error(ERR_INFILE, ERR_OUT), 1);
	while (env[i] != NULL && ft_strncmp("PATH=", env[i], 5))
		i++;
	if (env[i] == NULL)
		return (close(p.outfile), close(p.infile), 0);
	p.paths_line = ft_substr(env[i], 5, ft_strlen(env[i]));
	p.splitted_paths = ft_split(p.paths_line, ':');
	if (p.splitted_paths == NULL)
		return (close(p.outfile), close(p.infile), free(p.paths_line), 0);
	free(p.paths_line);
	pipex(p, argc, argv, env);
	p.pid = -9;
	return (fork_free(p), 0);
}
