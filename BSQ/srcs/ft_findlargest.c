/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findlargest.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 22:16:43 by jutrera-          #+#    #+#             */
/*   Updated: 2024/12/08 22:16:43 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	**ft_copymap(char **map, int lines)
{
	char	**resultmap;
	int 	i;
	int		j;

	resultmap = (char **)malloc((lines + 1) * sizeof(char *));
	if (!resultmap)
		return (NULL);
	i = -1;
	while (++i < lines)
	{
		resultmap[i] = (char *)malloc(ft_strlen(map[i]) * sizeof(char));
		if (!resultmap[i])
		{
			ft_freemaps(resultmap);
			return (NULL);
		}
		resultmap[i][0] = '\0';
	}
	resultmap[i] = '\0';
	i = -1;
	while (++i < lines)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			resultmap[i][j] = map[i][j];
			j++;
		}
		resultmap[i][j] = '\0';
	}
	return (resultmap);
}

char **find_largest(char **basemap, int lines, char *chars)
{
 	int cols;
    int **dp;
    int max_size;
	int end_line;
	int end_col;
	char **map;
	int i;
	int j;
	int min1;
	int min2; 

    max_size = 0;
	end_line = 0;
	end_col = 0;
	cols = ft_strlen(basemap[0]);
	map = ft_copymap(basemap, lines);
	if (!map)
		return (NULL);
	dp = (int **)malloc(lines * sizeof(int *));
	if (!dp)
		return (NULL);
	i = -1;
    while (++i < lines)
	{
        j = -1;
		dp[i] = (int *)malloc(cols * sizeof(int));
		if (!dp[i])
		{
			ft_freemaps((char **)dp);
			ft_freemaps(map);
			return (NULL);
		}
		while (++j < cols)
		{
            if (map[i][j] == chars[1])
                dp[i][j] = 0;
			else if (i == 0 || j == 0)
				dp[i][j] = (map[i][j] == chars[0]);
			else
			{
                if (map[i][j] == chars[0])
				{
    				if (dp[i - 1][j - 1] < dp[i - 1][j])
        				min1 = dp[i - 1][j - 1];
    				else
        				min1 = dp[i - 1][j];
				    if (min1 < dp[i][j - 1])
        				min2 = min1;
    				else
        				min2 = dp[i][j - 1];
				    dp[i][j] = 1 + min2;
				}
				else
					dp[i][j] = 0;
			}
            if (dp[i][j] > max_size) 
			{
                max_size = dp[i][j];
                end_line = i;
                end_col = j;
            }
        }
    }
	i = end_line + 1;
	while (--i > end_line - max_size)
	{
		j = end_col + 1;
		while (--j > end_col - max_size)
			map[i][j] = chars[2];
	}
	ft_freemaps((char **)dp);
	return (map);
}