/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rricol <rricol@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:47:00 by rricol            #+#    #+#             */
/*   Updated: 2022/03/19 00:10:45 by rricol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_getpath (char *cmd, char **env)
{
	char	*path;
	char	*dir;
	char	*bin;
	int		i;

	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5))
		i++;
	if (env[i] == NULL) // Pas vraiment nécessaire ?
		return (cmd);
	path = env[i] + 5; // se déplace après "PATH="
	while (path && ft_strichr(path, ':') > -1)
	{
		dir = ft_strndup(path, ft_strichr(path, ':'));
		bin = ft_join_path(dir, cmd);
		free(dir);
		if (access(bin, F_OK) == 0)
			return (bin);
		free(bin);
		path += ft_strichr(path, ':') + 1;
	}
	return (cmd);
}

int	ft_open_file(char *filename, int mode)
{
	if (mode == STDIN) // control si le fichier transmis en paramètre est l'input
	{
		if (access(filename, F_OK)) // control que le fichier existe
		{
			ft_putstr_fd("Pipex: ", STDERR);
			ft_putstr_fd(filename, STDERR);
			ft_putstr_fd(ERR_FILE, STDERR);
			return (ERR);
		}
		return (open(filename, O_RDONLY));
	}
	else
		return (open(filename, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU));
}

void	ft_redir(char *cmd, char **env, int fdin)
{
	pid_t	pid;
	int		fd[2];
	// fd[1] = write
	// fd[0] = read
	
	pipe(fd);
	pid = fork(); // à partir de la deux process sont lancés 1 parent et 1 child
	if (pid == 0)
	{
		// Child process -> écrit via fd[1]
		ft_putstr_fd("child in action\n", STDERR);
		close(fd[0]);
		dup2(fd[1], STDOUT);
		if (fdin == 0) // check que openfile n'est pas renvoyé un fd 0 dans la première étape
			exit(ERR);
		else
			ft_exec(cmd, env);
	}
	else
	{
		// Parent Process -> lis via fd[0]
		ft_putstr_fd("parent in action\n", STDERR);
		close(fd[1]);
		dup2(fd[0], STDIN);
		wait(NULL);//waitpid(pid, NULL, 0); // attend sur le child process pour terminer
	}
}

void	ft_exec(char *cmd, char **env)
{
	char	**args;
	char	*path;

	args = ft_split(cmd, ' '); // sépare la commande et les arguments
	if (ft_strichr(args[0], '/') > -1) 
		path = args[0]; // si la cmd donnée contient deja un path
	else
		path = ft_getpath(args[0], env); // sinon aller chercher le path dans l'environnement
	execve(path, args, env);  // Le code après cette ligne n'est executé que s'il y a eu une erreur
	ft_putstr_fd("Pipex: ", STDERR);
	ft_putstr_fd(cmd, STDERR);
	ft_putstr_fd(ERR_CMD, STDERR);
	exit(ERR);
}

int	main(int argc, char **argv, char **env)
{
	int fdin;
	int	fdout;

	if (argc == 5)
	{
		fdin = ft_open_file(argv[1], STDIN);
		fdout = ft_open_file(argv[argc - 1], STDOUT);
		dup2(fdin, STDIN); // redéfini le Standard Input par le fichier fdin
		dup2(fdout, STDOUT); // redéfini le Standard Output par le fichier fdout
		ft_redir(argv[2], env, fdin);
		ft_exec(argv[3], env);
	}
	else
		ft_putstr_fd(ERR_ARG, STDERR);
	return (0);
}
