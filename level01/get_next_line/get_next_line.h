/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:13:31 by alfokin           #+#    #+#             */
/*   Updated: 2025/01/02 17:31:26 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 500
# endif

# include <unistd.h>
# include <stdlib.h>

int		ft_strlen(char *str);
//char	*ft_strdup(char *s);
char	*get_next_line(int fd);
char	*ft_strchr(char *str, char c);
char	*ft_strjoin(char *line, char *buffer);
void	ft_strcpy(char *str, char *new_str, int i);

// size_t	ft_strlen(const char *str);
// char	*ft_strchr(const char *s, int c);
// char	*ft_strjoin(char *s1, char *s2);
// char	*get_next_line(int fd);

#endif
