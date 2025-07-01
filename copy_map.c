/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adores <adores@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:28:51 by adores            #+#    #+#             */
/*   Updated: 2025/07/01 14:29:23 by adores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**copy_map(char **map)
{
	int		rows;
	int		cols;
	char	**copy;
	int		i;
	int		j;

	while(map[rows])
		rows++;
	copy = malloc(sizeof(char *) * (rows + 1));
	if(!copy)
		return (NULL);
	i = 0;
	cols = 0;
	while(i < rows)
	{
		while(map[i][cols])
			cols++;
		copy[i] = malloc(sizeof(char) * (cols + 1));
		if(!copy[i])
			return (NULL);
		j = 0;
		while(j < cols)
		{
			copy[i][j] = map[i][j];
			j++;
		}
		copy[i][j] = '\0';
		i++;
	}
	copy[i] = NULL;
	return (copy);
}
