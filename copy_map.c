/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adores <adores@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:28:51 by adores            #+#    #+#             */
/*   Updated: 2025/07/03 15:03:10 by adores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_rows(char **map)
{
	int	rows;

	rows = 0;
	while (map[rows])
		rows++;
	return (rows);
}

static int	count_cols(char *row)
{
	int	j;

	j = 0;
	while (row[j])
		j++;
	return (j);
}

char	**copy_map(char **map)
{
	int		rows;
	int		cols;
	char	**copy;
	int		i;
	int		j;

	rows = count_rows(map);
	copy = malloc(sizeof(char *) * (rows + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		cols = count_cols(map[i]);
		copy[i] = malloc(sizeof(char) * (cols + 1));
		if (!copy[i])
			return (NULL);
		j = -1;
		while (++j < cols)
			copy[i][j] = map[i][j];
		copy[i++][j] = '\0';
	}
	copy[i] = NULL;
	return (copy);
}
