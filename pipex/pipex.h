/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rricol <rricol@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:34:05 by rricol            #+#    #+#             */
/*   Updated: 2022/03/18 23:36:24 by rricol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/* includes */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <fcntl.h>
#include <sys/wait.h>

/* defines */
# define ERR -1
# define TRUE 1
# define FALSE 0
# define ERR_MSG "Error\n"
# define ERR_ARG "invalid number of arguments.\n"
# define ERR_FILE ": No such file or directory.\n"
# define ERR_CMD ": command not found.\n"
# define STDIN	0
# define STDOUT	1
# define STDERR	2

/* prototypes */
void	ft_putstr_fd(char *s, int fd);
char	*ft_getpath (char *cmd, char **env);
int		ft_open_file(char *filename, int mode);
void	ft_redir(char *cmd, char **env, int fdin);
void	ft_exec(char *cmd, char **env);
int 	ft_strichr(char *s, int c);
int		ft_strncmp(char *s1, char *s2, size_t n);
char	*ft_strndup(char *s, int n);
char	**ft_split (char *str, char sep);
char	*ft_join_path (char *path, char *bin);

int		ft_strlen(char *s);

#endif