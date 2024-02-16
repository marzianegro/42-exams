/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:49:42 by mnegro            #+#    #+#             */
/*   Updated: 2023/10/18 11:23:58 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

int	ft_error(char *s1, char *s2)
{
	while (*s1)
		write(2, s1++, 1);
	if (s2)
		while (*s2)
			write(2, s2++, 1);
	write(2, "\n", 1);
	return (1);
}

int	ft_exec(char **av, int i, int tmp_fd, char **env)
{
	av[i] = NULL;
	dup2(tmp_fd, 0);
	execve(av[0], av, env);
	return (ft_error("error: cannot execute ", av[0]));
}

int	main(int ac, char **av, char **env)
{
	int i;
	int	fd[2];
	int	tmp_fd;

	(void)ac;
	i = 0;
	tmp_fd = dup(0);
	while (av[i] && av[i + 1])
	{
		av = &av[i + 1];
		i = 0;
		while (av[i] && strcmp(av[i], "|") && strcmp(av[i], ";"))
			i++;
		if (!strcmp(av[0], "cd"))
		{
			if (i != 2)
				ft_error("error: cd: bad arguments", NULL);
			else if (chdir(av[1]))
				ft_error("error: cd: cannot change directory to ", av[1]);
		}
		else if (i && (!av[i] || !strcmp(av[i], ";")))
		{
			if (!fork())
			{
				if (ft_exec(av, i, tmp_fd, env))
					return (1);
			}
			else
			{
				close(tmp_fd);
				while (waitpid(-1, NULL, WUNTRACED) != -1)
					continue ;
				tmp_fd = dup(0);
			}
		}
		else if (i && !strcmp(av[i], "|"))
		{
			pipe(fd);
			if (!fork())
			{
				dup2(fd[1], 1);
				close(fd[0]);
				close(fd[1]);
				if (ft_exec(av, i, tmp_fd, env))
					return (1);
			}
			else
			{
				close(fd[1]);
				close(tmp_fd);
				tmp_fd = dup(fd[0]);
				close(fd[0]);
			}		}
	}
	close(tmp_fd);
	return (0);
}
