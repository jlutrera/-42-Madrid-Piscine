/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 20:39:16 by jutrera-          #+#    #+#             */
/*   Updated: 2024/12/09 23:50:33 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define YELLOW "\033[0;33m"
# define RED 	"\033[0;31m"
# define GREEN 	"\033[0;32m"
# define RESET 	"\033[0m"

// ft_findlargest.c
char 	**find_largest(char **basemap, int lines, char *chars);
// ft_checkmap.c
char	**ft_checkmap(char *filename, int *lines, char **chars);
// ft_createmap.c
int		ft_createmap(void);
// ft_utilities.c
int		ft_printf(char *str);
void	ft_freemaps(char **amap);
char 	*ft_addchartostr(char *src, char c);
// ft_utilities2.c
int		ft_strlen(char *str);
char	*ft_itoa(int num);
int		ft_atoi(char *str);
int 	ft_putchar(char c);

#endif
