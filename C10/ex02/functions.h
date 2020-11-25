/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 09:28:43 by sfournio          #+#    #+#             */
/*   Updated: 2020/10/26 09:31:26 by sfournio         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include <unistd.h>
# include <libgen.h>
# include <errno.h>
# include <fcntl.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	default_op(int fd, int i, char **av, char c);
void	custom_op(int fd, int i, char **av, char c, int index);
int		ft_strlen(char *str);
int		is_num(char *str);
int		ft_atoi(char *str);
int		ft_strcmp(char *s1, char *s2);
int		custom_while(char **av, int ac, char c, int i, int fd);
int		default_while(char **av, int ac, char c, int i, int fd);

#endif
