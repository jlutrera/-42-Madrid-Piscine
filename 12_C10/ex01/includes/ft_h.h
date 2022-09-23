/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_h.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:30:52 by jutrera-          #+#    #+#             */
/*   Updated: 2022/07/28 15:36:02 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H_H
# define FT_H_H

# include <unistd.h>
# include <fcntl.h>
# include <sys/errno.h>
# include <libgen.h>

void	ft_display_custom_error(int eno, char *argv);
int		ft_cat(char *file);
void	ft_stdin(void);

#endif
