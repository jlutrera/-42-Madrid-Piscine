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

static char	**ft_createresultmap(char **map, int lines)
{
	char	**resultmap;
	int		i;

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

static int	ft_min(int i, int j, int **dp)
{
	int	min1;
	int	min2;

	if (dp[i - 1][j - 1] < dp[i - 1][j])
		min1 = dp[i - 1][j - 1];
	else
		min1 = dp[i - 1][j];
	if (min1 < dp[i][j - 1])
		min2 = min1;
	else
		min2 = dp[i][j - 1];
	return (min2 + 1);
}

static void	searchingsquare(char **map, int **dp, int values[], char *chars)
{
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
				dp[values[0]][values[1]] = ft_min(values[0], values[1], dp);
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

static int	**alloc_dp_search(int lines, int values[], char **map, char *chars)
{
	int	**dp;

	dp = (int **)malloc(lines * sizeof(int *));
	if (!dp)
		return (NULL);
	values[0] = -1;
	values[2] = 0;
	values[3] = 0;
	values[4] = 0;
	while (++values[0] < lines)
	{
		dp[values[0]] = (int *)malloc(values[5] * sizeof(int));
		if (!dp[values[0]])
		{
			free_dp(dp, values[0] - 1);
			ft_freemaps(map);
			return (NULL);
		}
		searchingsquare(map, dp, values, chars);
	}
	return (dp);
}

char	**find_largest(char **basemap, int lines, char *chars)
{
	int		**dp;
	char	**map;
	int		values[6];

	values[5] = ft_strlen(basemap[lines - 1]);
	map = ft_createresultmap(basemap, lines);
	if (!map)
		return (NULL);
	dp = alloc_dp_search(lines, values, map, chars);
	values[0] = values[3] + 1;
	while (--values[0] > values[3] - values[2])
	{
		values[1] = values[4] + 1;
		while (--values[1] > values[4] - values[2])
			map[values[0]][values[1]] = chars[2];
	}
	free_dp(dp, lines);
	return (map);
}
