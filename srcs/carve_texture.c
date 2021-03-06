/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carve_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 19:51:55 by home              #+#    #+#             */
/*   Updated: 2021/03/05 15:32:40 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

SDL_Rect	*carve_2048_texture(void)
{
	int			row;
	int			col;
	SDL_Rect	*result;

	row = 0;
	result = malloc(sizeof(*result) * (2 * 1));
	while (row < 1)
	{
		col = 0;
		while (col < 2)
		{
			result[row * 2 + col].h = TILE_SIZE;
			result[row * 2 + col].w = TILE_SIZE;
			result[row * 2 + col].x = (col * TILE_SIZE);
			result[row * 2 + col].y = (row * TILE_SIZE);
			col++;
		}
		row++;
	}
	return (result);
}
