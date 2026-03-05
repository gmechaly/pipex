/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmechaly <gmechaly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:09:10 by gmechaly          #+#    #+#             */
/*   Updated: 2024/12/11 20:46:06 by gmechaly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>
# include <limits.h>
# include "../libft/includes/libft.h"

// pipex.c
void	parent(int *fds);
void	execute(char *argv, char **env, char *shell);
void	child(char **argv, char **env, int *fds, char *shell);
void	child2(char **argv, char **env, int *fds, char *shell);
int		ft_parse_args(int argc, char **argv, char *shell);
int		ft_check_cmds(char **argv, char **env);

// tools.c
void	free_tab(char **tab, int code);
int		create_outfile(char *outfile, char *shell);
char	*get_path(char *cmd, char **env);
char	*ft_fstrjoin(char *s1, char *s2);
char	*get_shell(char **env);

#endif