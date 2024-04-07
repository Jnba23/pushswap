/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:52:51 by asayad            #+#    #+#             */
/*   Updated: 2024/04/04 22:03:58 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <unistd.h>
# include <limits.h>
# include <libc.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*make_line(char *line_read);
char	*make_stash(char *line_read);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s, int i);
int		ft_strchr(char *s, char c);
int		ft_strlen(char *s);
char	*ft_strlcpy_g(char *s1, char *s2, char *line, int l);

#endif