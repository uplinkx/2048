/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 11:30:10 by home              #+#    #+#             */
/*   Updated: 2021/03/05 15:48:32 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	process_user_input(t_game_context *game_state)
{
	SDL_Event		e;

	while (SDL_PollEvent(&e) != 0)
	{
		if (e.type == SDL_QUIT)
		{
			game_state->active = false;
			break ;
		}
		else if (e.type == SDL_KEYUP)
		{
			if (e.key.keysym.scancode == SDL_SCANCODE_LEFT)
				game_state->action = LEFT;
			else if (e.key.keysym.scancode == SDL_SCANCODE_RIGHT)
				game_state->action = RIGHT;
			else if (e.key.keysym.scancode == SDL_SCANCODE_UP)
				game_state->action = UP;
			else if (e.key.keysym.scancode == SDL_SCANCODE_DOWN)
				game_state->action = DOWN;

			if (e.key.keysym.scancode == SDL_SCANCODE_U)
				memcpy(game_state->board, game_state->prev_board, sizeof(game_state->board));
		}
	}
}
