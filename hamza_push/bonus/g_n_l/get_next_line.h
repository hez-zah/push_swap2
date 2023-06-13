/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hez-zahi <hez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:16:41 by hez-zahi          #+#    #+#             */
/*   Updated: 2023/01/29 17:20:04 by hez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <fcntl.h>
# include <sys/types.h>

# include <sys/wait.h>

size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
char	*copy(char *txt, char *save, int i);
char	*ft_strrchr(const char *s, int c);
char	*conc(char *stash, char *buf);
char	*get_next_line(int fd);
char	*save_static(char *txt);
char	*read_line(char *stash);
char	*read_static(char *stash, int fd);
char	*lock(char *stash, char *buf, int ret);
#endif
