/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 20:39:16 by jutrera-          #+#    #+#             */
/*   Updated: 2025/01/02 00:13:47 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define YELLOW "\033[0;33m"
# define RESET 	"\033[0m"

// ft_findlargest.c
char	**find_largest(char **basemap, int lines, char *chars);
// ft_checkmap.c
char	**ft_checkmap(char *filename, int *lines, char **chars);
// ft_createmap.c
int		ft_createmap(void);
// ft_utilities.c
int		ft_printf(char *str);
void	ft_freemaps(char **amap);
int		ft_addchartostr(char **src, char *c, size_t *bytes_read, int fd);
void	free_dp(int **dp, int lines);
void	ft_copymap(char **map, char **resultmap, int lines);
// ft_utilities2.c
int		ft_strlen(char *str);
char	*ft_itoa(int num);
int		ft_atoi(char *str);
int		ft_putchar(char c);
int		get_num_lines(int *num_lines);
// ft_utilities3.c
int		there_are_errors(int error, int fd, char **map);
#endif
