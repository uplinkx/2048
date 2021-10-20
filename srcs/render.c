/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 02:38:19 by home              #+#    #+#             */
/*   Updated: 2021/10/19 23:09:06 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	color_tiles(int val, SDL_Texture *texture)
{
	// printf("val: %d\n", val);
	if (val == 2)
		SDL_SetTextureColorMod(texture, 100, 140, 190);
	else if (val == 4)
		SDL_SetTextureColorMod(texture, 105, 188, 220);
	else if (val == 8)
		SDL_SetTextureColorMod(texture, 30, 218, 198);
	else if (val == 16)
		SDL_SetTextureColorMod(texture, 50, 218, 118);
	else if (val == 32)
		SDL_SetTextureColorMod(texture, 125, 188, 30);
	else if (val == 64)
		SDL_SetTextureColorMod(texture, 165, 188, 0);
	else if (val == 128)
		SDL_SetTextureColorMod(texture, 215, 215, 0);
	else if (val == 256)
		SDL_SetTextureColorMod(texture, 215, 180, 0);
	else if (val == 512)
		SDL_SetTextureColorMod(texture, 215, 100, 0);
	else if (val == 1024)
		SDL_SetTextureColorMod(texture, 215, 40, 0);
	else if (val == 2048)
		SDL_SetTextureColorMod(texture, 255, 0, 0);
}

void	draw_tile(int val, int x, int y, SDL_Texture *texture, SDL_Rect *src_rect)
{
	SDL_Rect	dest;
	SDL_Rect	num_dest;

	dest.h = TILE_SIZE * DISPLAY_SCALE;
	dest.w = TILE_SIZE * DISPLAY_SCALE;
	dest.x = (x * DISPLAY_SCALE * TILE_SIZE);
	dest.y = (y * DISPLAY_SCALE * TILE_SIZE);
	color_tiles(val, texture);
	SDL_RenderCopy(SDLX_GetDisplay()->renderer, texture, &(src_rect[TILE]), &dest);

	num_dest.h = TILE_SIZE;
	num_dest.w = TILE_SIZE;
	num_dest.x = (x + 1) * DISPLAY_SCALE * TILE_SIZE - (num_dest.w) - 20;
	num_dest.y = (y) * DISPLAY_SCALE * TILE_SIZE + 32;

	itow(val, num_dest, SDLX_GetDisplay());
}


void	draw_board(int *board, SDL_Texture *texture, SDL_Rect *rects)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (board[i] != 0)
			draw_tile(board[i], i % 4, i / 4, texture, rects);
		i++;
	}
}

void	draw_grid(SDLX_Display *display)
{
	int	row;
	int	col;

	row = 1;
	while (row < 4)
	{
		col = 1;
		while (col < 4)
		{
			SDL_SetRenderDrawColor(display->renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
			SDL_RenderDrawLine(display->renderer, col * TILE_SIZE * DISPLAY_SCALE, 0, col * TILE_SIZE * DISPLAY_SCALE, WIN_HEIGHT);
			SDL_RenderDrawLine(display->renderer, 0, row * TILE_SIZE * DISPLAY_SCALE, WIN_WIDTH, row * TILE_SIZE * DISPLAY_SCALE);
			col++;
		}
		row++;
	}
	SDL_SetRenderDrawColor(display->renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
}
