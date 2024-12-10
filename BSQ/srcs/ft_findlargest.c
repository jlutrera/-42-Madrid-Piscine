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

static void	ft_copymap(char **map, char **resultmap, int lines)
{
	int	i;
	int	j;

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
}

static char	**ft_createresultmap(char **map, int lines)
{
	char	**resultmap;
	int 	i;

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
	ft_copymap(map, resultmap, lines);
	return (resultmap);
}

static void	searchingsqaure(char **map, int **dp, int values[], char *chars)
{
	int min1;
	int min2;

	values[1] = -1;
	while (++values[1] < values[5])
	{
		if (map[values[0]][values[1]] == chars[1])
			dp[values[0]][values[1]] = 0;
		else if (values[0] == 0 || values[1] == 0)
			dp[values[0]][values[1]] = (map[values[0]][values[1]] == chars[0]);
		else
		{
			if (map[values[0]][values[1]] == chars[0])
			{
				if (dp[values[0] - 1][values[1] - 1] < dp[values[0] - 1][values[1]])
					min1 = dp[values[0] - 1][values[1] - 1];
				else
					min1 = dp[values[0] - 1][values[1]];
				if (min1 < dp[values[0]][values[1] - 1])
					min2 = min1;
				else
					min2 = dp[values[0]][values[1] - 1];
				dp[values[0]][values[1]] = 1 + min2;
			}
			else
				dp[values[0]][values[1]] = 0;
		}
		if (dp[values[0]][values[1]] > values[2]) 
		{
			values[2] = dp[values[0]][values[1]];
			values[3] = values[0];
			values[4] = values[1];
		}
	}
}

char **find_largest(char **basemap, int lines, char *chars)
{
    int **dp;
	char **map;
	int values[6]; // 0 = i, 1 = j, 2 = max_size, 3 = end_line, 4 = end_col, 5 = cols

	values[0] = -1;
    values[2] = 0;
	values[3] = 0;
	values[4] = 0;
	values[5] = ft_strlen(basemap[lines - 1]);
	map = ft_createresultmap(basemap, lines);
	if (!map)
		return (NULL);
	dp = (int **)malloc(lines * sizeof(int *));
	if (!dp)
		return (NULL);
    while (++values[0] < lines)
	{
		dp[values[0]] = (int *)malloc(values[5] * sizeof(int));
		if (!dp[values[0]])
		{
			ft_freemaps((char **)dp);
			ft_freemaps(map);
			return (NULL);
		}
		searchingsqaure(map, dp, values, chars);
 	}
	values[0] = values[3] + 1;
	while (--values[0] > values[3] - values[2])
	{
		values[1] = values[4] + 1;
		while (--values[1] > values[4] - values[2])
			map[values[0]][values[1]] = chars[2];
	}
	
	ft_freemaps((char **)dp);
	return (map);
}