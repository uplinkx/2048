/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 11:30:10 by home              #+#    #+#             */
/*   Updated: 2021/10/19 23:10:51 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

SDL_bool	process_user_input(int *action_ptr, int *board, int *old_board, size_t board_size)
{
	SDL_Event		e;

	while (SDL_PollEvent(&e) != 0)
	{
		if (e.type == SDL_QUIT)
			return (SDL_TRUE);
		else if (e.type == SDL_KEYUP)
		{
			if (e.key.keysym.scancode == SDL_SCANCODE_LEFT)
				*(action_ptr) = LEFT;
			else if (e.key.keysym.scancode == SDL_SCANCODE_RIGHT)
				*(action_ptr) = RIGHT;
			else if (e.key.keysym.scancode == SDL_SCANCODE_UP)
				*(action_ptr) = UP;
			else if (e.key.keysym.scancode == SDL_SCANCODE_DOWN)
				*(action_ptr) = DOWN;

			if (e.key.keysym.scancode == SDL_SCANCODE_U)
				memcpy(board, old_board, board_size);
		}
	}
	return (SDL_FALSE);
}
