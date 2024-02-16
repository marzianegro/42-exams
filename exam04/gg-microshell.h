/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:49:46 by mnegro            #+#    #+#             */
/*   Updated: 2023/10/12 15:54:58 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MICROSHELL_H
# define MICROSHELL_H

# include <unistd.h>
# include <string.h>
# include <sys/wait.h>

int     ft_error(char *s1, char *s2);
int     ft_exec(char **av, int i, int tmp_fd, char **env);

#endif
