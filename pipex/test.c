/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmimault <tmimault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:08:06 by tmimault          #+#    #+#             */
/*   Updated: 2024/02/29 17:00:05 by tmimault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char *find_path(char *cmd, char **envp);
int child_fonct (char *file, int *p, char **cmd1, char **envp);
int dad_fonct(char *file, int *p, char **cmd2, char **envp);
int return_perror(char *str, char *ptr, char **dbl_ptr);
int	path_error(char *str, char *ptr, char **dbl_ptr);
int	count_double_ptr(char ** ptr);
int cmd_special(char *file, int *p, char **cmd, char **envp);

char	**freeall(char **big_array, size_t ind_array)
{
	while (ind_array > 0)
	{
		ind_array--;
		free(*(big_array + ind_array));
	}
	free(big_array);
	return (NULL);
}

char *find_path(char *cmd, char **envp)
{
	int		path_i;
	char	*new_path;
	char	**all_path;

	path_i = -1;
	while (envp[++path_i])
		if (envp[path_i][0] == 'P' && envp[path_i][2] == 'T')
			break;
	new_path = malloc (ft_strlen(envp[path_i]) - 4);
	if (!new_path)
		return (NULL);
	ft_memmove(new_path,envp[path_i] + 5,ft_strlen(envp[path_i]) - 5);
	new_path[ft_strlen(envp[path_i]) - 5] = '\0';
	all_path = ft_split(new_path, ':');
	free(new_path);
	path_i = -1;
	while (all_path[++path_i])
	{
		new_path = test_path(...);
		if (new_path)
			return(new_path);
	}
	return(freeall(all_path, count_double_ptr(all_path)), NULL);
}

int main (int argc, char **argv, char **envp)
{
	int	p[2];
	pid_t child;

	
	if (argc != 5)
	{
		errno = 7;
		return (return_perror("argv",NULL,NULL));
	}
	if (pipe(p) < 0)
		return (return_perror("pipe",NULL,NULL));
	child = fork();
	if (child < 0)
		return (return_perror("fork",NULL,NULL));
	if (child > 0)
	{
		waitpid(child,NULL,0);
		if(dad_fonct(argv[4], p, ft_split(argv[3],' '), envp) == -1)
			exit(EXIT_FAILURE);
	}
	if (child == 0)
		if(child_fonct(argv[1], p, ft_split(argv[2],' '), envp) == -1)
			exit(EXIT_FAILURE);
	return (1);
}

int child_fonct(char *file, int *p, char **cmd1, char **envp)
{
	int		fd_file1;
	char	*path;

	close(p[0]);
	if (!*cmd1)
	{
		close(p[1]);
		return(path_error(" ", NULL, cmd1));
	}
	if (ft_strchr(cmd1[0], '/'))
		return (cmd_special(file, p, cmd1, envp));
	path = find_path(cmd1[0], envp);
	if (!path)
	{
		close(p[1]);
		return (path_error(cmd1[0], NULL, cmd1));
	}
	fd_file1 = open(file,O_RDONLY);
	if (fd_file1 == -1)
	{
		close(p[1]);
		return(return_perror(file, path, cmd1));
	}
	dup2(fd_file1, 0);
	close(fd_file1);
	dup2(p[1], 1);
	close(p[1]);
	if (execve(path, cmd1, envp) == -1)
		return ( return_perror("execve", path, cmd1));
	free(path);
	freeall(cmd1, count_double_ptr(cmd1));
	return (1);
}

int dad_fonct(char *file, int *p, char **cmd2, char **envp)
{
	int		fd_file2;
	char	*path;
	
	close(p[1]);
	if (!*cmd2)
	{
		close(p[0]);
		return(path_error(" ", NULL, cmd2));
	}
	if (ft_strchr(cmd2[0], '/'))
		return (cmd_special(file, p, cmd2, envp));
	path = find_path(cmd2[0],envp);
	if (!path)
	{
		close (p[0]);
		return (path_error(cmd2[0], NULL, cmd2));
	}
	fd_file2 = open(file ,O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_file2 == -1)
	{
		close (p[0]);
		return(return_perror(file, path, cmd2));
	}
	dup2(p[0], 0);
	dup2(fd_file2, 1);
	close(fd_file2);
	close(p[0]);
	if (execve(path, cmd2, envp) == -1)
		return (return_perror("execve", path, cmd2));
	free(path);
	freeall(cmd2, count_double_ptr(cmd2));
	return (1);
}

int return_perror(char *str, char *ptr, char **dbl_ptr)
{
	close(0);
	close(1);
	if (ptr)
		free(ptr);
	if (dbl_ptr)
		freeall(dbl_ptr, count_double_ptr(dbl_ptr));
	perror (str);
	return (EXIT_FAILURE);
}

int	count_double_ptr(char ** ptr)
{
	int i;

	i = 0;
	while (ptr[i] != NULL)
		i++;
	return (i);
}

int cmd_special(char *file, int *p, char **cmd, char **envp)
{
	int fd_file;
	
	fd_file = open(file,O_RDONLY);
	if (fd_file == -1)
	{
		close(p[1]);
		return(return_perror(file, NULL, cmd));
	}
	dup2(fd_file, 0);
	close(fd_file);
	dup2(p[1], 1);
	close(p[1]);
	if (execve(cmd[0], cmd, envp) == -1)
		return ( return_perror("execve", NULL, cmd));
	freeall(cmd, count_double_ptr(cmd));
	return (1);
}

int	path_error(char *str, char *ptr, char **dbl_ptr)
{
	close(0);
	close(1);
	if (!str)
		write(2, "arg: command not found\n", 23);
	else 
	{
		write(2, str, ft_strlen(str));
		write(2, ": command not found\n", 20);
	}
	if (ptr)
		free(ptr);
	if (dbl_ptr)
		freeall(dbl_ptr, count_double_ptr(dbl_ptr));
	return (EXIT_FAILURE);
}

char *test_path()
{
	char *new_path;

	new_path = calloc(ft_strlen(all_path[path_i]) + 2 + ft_strlen(cmd), 1);
	if (!new_path)
		return (freeall(all_path, count_double_ptr(all_path)),NULL);
	strcat(new_path, all_path[path_i]);
	strcat(new_path, "/");
	strcat(new_path, cmd);
	if (access(new_path, F_OK | R_OK | X_OK) != -1)
		return(freeall(all_path, count_double_ptr(all_path)),new_path);
	free(new_path);
}

/*
dup2(ancien_fd, nouveau fd assigne a l'ancien);

cat wc 

pid = 0 enfant
pid > 0 parent





main 

child fonct

dad fonct




*/