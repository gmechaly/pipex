/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmechaly <gmechaly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:52:46 by gmechaly          #+#    #+#             */
/*   Updated: 2024/12/11 20:31:48 by gmechaly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"

int	main(int argc, char **argv, char **env)
{
	int		fds[2];
	pid_t	pid;
	pid_t	pid2;
	char	*shell;

	shell = get_shell(env);
	if (ft_parse_args(argc, argv, shell))
	{
		pipe(fds);
		pid = fork();
		if (pid == -1)
			exit(EXIT_FAILURE);
		if (pid == 0)
			child(argv, env, fds, shell);
		wait(NULL);
		pid2 = fork();
		if (pid2 == -1)
			exit(EXIT_FAILURE);
		if (pid2 == 0)
			child2(argv, env, fds, shell);
		parent(fds);
	}
	else if (argv[4])
		create_outfile(argv[4], shell);
	return (free(shell), 0);
}
