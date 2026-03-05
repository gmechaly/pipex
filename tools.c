/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmechaly <gmechaly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:55:27 by gmechaly          #+#    #+#             */
/*   Updated: 2024/12/11 19:28:42 by gmechaly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"

int	create_outfile(char *outfile, char *shell)
{
	int	fd;

	fd = open(outfile, O_WRONLY | O_CREAT | O_TRUNC);
	if (fd == -1)
		return (ft_printf("%s: permission denied: %s\n", shell, outfile), 0);
	close (fd);
	return (1);
}

char	*ft_fstrjoin(char *s1, char *s2)
{
	char	*dst;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	dst = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (dst == NULL)
		return (free(s1), NULL);
	while (s1 != NULL && s1[i])
		dst[j++] = s1[i++];
	i = 0;
	free (s1);
	while (s2 != NULL && s2[i])
		dst[j++] = s2[i++];
	dst[j] = '\0';
	return (dst);
}

char	*get_path(char *cmd, char **env)
{
	int		i;
	char	*folder;
	char	*path;
	char	**cmd_paths;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], "PATH=", 5))
			break ;
		i++;
	}
	cmd_paths = ft_split(env[i], ':');
	i = 0;
	while (cmd_paths[i] && cmd)
	{
		folder = ft_fstrjoin(cmd_paths[i], "/");
		path = ft_fstrjoin(folder, cmd);
		if (access(path, F_OK | X_OK) == 0)
			return (free_tab(&cmd_paths[i + 1], 0), path);
		free(path);
		i++;
	}
	free(cmd_paths);
	return (NULL);
}

/*
*	code = 0 -> don't free the double pointer
*	code = 1 -> free it
*/
void	free_tab(char **tab, int code)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	if (code != 0)
		free(tab);
}

char	*get_shell(char **env)
{
	int		i;
	int		j;
	char	*shell;
	char	**shell_line;

	i = 0;
	j = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], "SHELL=", 5))
			break ;
		i++;
	}
	shell_line = ft_split(env[i], '/');
	while (shell_line[j] != NULL)
		j++;
	shell = malloc(sizeof(char) * (ft_strlen(shell_line[j - 1]) + 1));
	ft_strlcpy(shell, shell_line[j - 1], \
						ft_strlen(shell_line[j - 1]) + 1);
	free_tab(shell_line, 1);
	return (shell);
}
