/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_createmap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 20:39:28 by jutrera-          #+#    #+#             */
/*   Updated: 2024/12/10 17:46:23 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "bsq.h"

static int checkifexists(int *fd)
{
	if (access("./maps/madrid42", F_OK) == 0)
	{
		if (unlink("./maps/madrid42") != 0)
		{
			ft_printf("file error\n");
			return 1;
		}
	}
	*fd = open("./maps/madrid42", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (*fd == -1)
	{
      	ft_printf("file error\n");
	    return 1;
    }
	return 0;
}

static char *read_data_map(int *num_lines)
{
	char 	*data;
	char 	buffer[100];

	data = (char *)malloc(3);
	if (!data)
	{
		ft_printf("memory allocation error\n");
		return NULL;
	}
	ft_printf("Number of lines: ");
    read(STDIN_FILENO, buffer, 100);
	*num_lines = ft_atoi(buffer);
	if (*num_lines < 1)
	{
		ft_printf("Invalid number of lines\n");
		free(data);
		return NULL;
	}
	ft_printf("Character for empty: ");
    read(STDIN_FILENO, buffer, 2);
	data[0] = buffer[0];
    ft_printf("Character for obstacle: ");
    read(STDIN_FILENO, buffer, 2);
	data[1] = buffer[0];
    ft_printf("Character for filled: ");
    read(STDIN_FILENO, buffer, 2);
	data[2] = buffer[0];
	return data;
}

static void	ask_for_lines(int fd, char *data, int num_lines)
{
	int		len;
	char	buffer[1024];
	int		bytes_read;
	char	*numstr;

	ft_printf("Enter ech line of the map (");
	ft_putchar(data[0]);
	ft_printf(": empty, ");
	ft_putchar(data[1]);
	ft_printf(": obstacle)\n");
	len = -1;
    while (++len < num_lines)
	{
		ft_printf("Line ");
		numstr = ft_itoa(len + 1);
		ft_printf(numstr);
		ft_printf(": ");
		free(numstr);
		bytes_read = read(STDIN_FILENO, buffer, 1024);
        buffer[bytes_read - 1] = '\0';
        write(fd, buffer, bytes_read - 1);
        write(fd, "\n", 1);
    }
}

int ft_createmap()
{
    int		fd;
	char 	*data;
    int		num_lines;
	char	buffer[1024];
	int 	len;

	data = read_data_map(&num_lines);
	if (data == NULL)
		return -1;
	if (checkifexists(&fd))
	{
		free(data);
		return -1;
	}
    len = snprintf(buffer, 1024, "%d%c%c%c\n", num_lines, data[0], data[1], data[2]);
    write(fd, buffer, len);
	ask_for_lines(fd, data, num_lines);
    close(fd);
    ft_printf("Map was created successfuly.\n");
	free(data);
	return fd;
}
