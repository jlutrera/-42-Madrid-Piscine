#ifndef BSQ_H
#define BSQ_H

#include <fcntl.h>
#include <stdlib.h>
/* #include <unistd.h> */
#include <io.h>
#include <stdio.h>

char	*ft_strdup(char *src);
int     ft_squares(char **basemap, int lines, char *items, int width);
int		ft_checkmap(char *filename);
char	*ft_create_map(void);
void    ft_searching(char *filename, int lines, char *items, int width);

#endif
