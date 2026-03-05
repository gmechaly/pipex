/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmechaly <gmechaly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:06:34 by gmechaly          #+#    #+#             */
/*   Updated: 2024/12/11 20:16:48 by gmechaly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"

void	child(char **argv, char **env, int *fds, char *shell)
{
	int		fdin;

	close(fds[0]);
	fdin = open(argv[1], O_RDONLY);
	if (fdin == -1)
	{
		ft_printf("%s: permission denied: %s\n", shell, argv[1]);
		free(shell);
		exit(EXIT_FAILURE);
	}
	if (dup2(fdin, STDIN_FILENO) == -1 || dup2(fds[1], STDOUT_FILENO) == -1)
	{
		free(shell);
		exit(EXIT_FAILURE);
	}
	close(fds[1]);
	close(fdin);
	execute(argv[2], env, shell);
}

void	child2(char **argv, char **env, int *fds, char *shell)
{
	int		fdout;

	close(fds[1]);
	fdout = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fdout == -1)
	{
		ft_printf("%s: permission denied: %s\n", shell, argv[4]);
		free(shell);
		exit(EXIT_FAILURE);
	}
	if (dup2(fds[0], STDIN_FILENO) == -1 || dup2(fdout, STDOUT_FILENO) == -1)
	{
		free(shell);
		exit(EXIT_FAILURE);
	}
	close(fds[0]);
	close(fdout);
	execute(argv[3], env, shell);
}

void	parent(int *fds)
{
	close(fds[0]);
	close(fds[1]);
}

void	execute(char *argv, char **env, char *shell)
{
	char	**cmd;
	char	*cmd_path;

	cmd = ft_split(argv, ' ');
	if (cmd == NULL)
		exit(EXIT_FAILURE);
	cmd_path = get_path(cmd[0], env);
	if (cmd_path == NULL)
	{
		ft_putstr_fd(shell, 2);
		ft_putstr_fd(": command not found: ", 2);
		write(2, argv, ft_strlen(argv));
		ft_putchar_fd('\n', 2);
		free_tab(cmd, 1);
		free(shell);
		exit(EXIT_FAILURE);
	}
	free(shell);
	if (execve(cmd_path, cmd, env) == -1)
	{
		free_tab(cmd, 1);
		free(cmd_path);
		exit(EXIT_FAILURE);
	}
}

/*
*	In case of wrong usage of arguments for pipex, 
*	the ft_parse_args() function will display an error message
*	according to the behaviour of the command line 
*	and will return 0. In case of success,
*	the function will return a positive value
*/

int	ft_parse_args(int argc, char **argv, char *shell)
{
	if (argc != 5)
	{
		if (argc < 5)
			ft_putstr_fd("Error: too few arguments\n", 2);
		else
			ft_putstr_fd("Error: too much arguments\n", 2);
		ft_putstr_fd("usage : ./pipex <infile> <cmd1> <cmd2> <outfile>\n", 2);
		return (0);
	}
	if (access(argv[1], F_OK))
		return (ft_printf("%s: no such file or directory: %s\n", \
							shell, argv[1]), 0);
	if (access(argv[1], R_OK))
		return (ft_printf("%s: permission denied: %s\n", shell, argv[1]), 0);
	else
	{
		if (!ft_strlen(argv[2]) || !ft_strlen(argv[3]))
			return (ft_printf("%s: permission denied:\n", shell), 0);
	}
	return (1);
}
