/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:24:41 by mnegro            #+#    #+#             */
/*   Updated: 2023/10/18 11:57:36 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

int	err(char *str)
{
	while (*str)
		write(2, str++, 1);
	return (1);
}

int	cd(char **argv, int i)
{
	if (i != 2)
		return (err("error: cd: bad arguments\n"));
	else if (chdir(argv[1]) == -1)
		return (err("error: cd: cannot change directory to "), err(argv[1]), err("\n"));
	return (0);
}

int	exec(char **argv, char **envp, int i)
{
	int	fd[2];
	int	pid;
	int	status;
	int	flag_pipe;

	flag_pipe = 0;
	if (argv[i] && !strcmp(argv[i], "|"))
		flag_pipe = 1;
}
