/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 11:30:10 by home              #+#    #+#             */
/*   Updated: 2021/10/20 01:03:23 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

SDLX_iMap	*game_key_mapper(size_t *size)
{
	static SDLX_iMap	key_map[] =
	{
		(SDLX_iMap){&BMAP(button_DPAD_LEFT),	2, SDL_SCANCODE_LEFT},
		(SDLX_iMap){&BMAP(button_DPAD_UP),		2, SDL_SCANCODE_UP},
		(SDLX_iMap){&BMAP(button_DPAD_DOWN),	2, SDL_SCANCODE_DOWN},
		(SDLX_iMap){&BMAP(button_DPAD_RIGHT),	2, SDL_SCANCODE_RIGHT},

		(SDLX_iMap){&BMAP(button_DPAD_LEFT),	2, SDL_SCANCODE_A},
		(SDLX_iMap){&BMAP(button_DPAD_UP),		2, SDL_SCANCODE_W},
		(SDLX_iMap){&BMAP(button_DPAD_DOWN),	2, SDL_SCANCODE_S},
		(SDLX_iMap){&BMAP(button_DPAD_RIGHT),	2, SDL_SCANCODE_D},

		(SDLX_iMap){&BMAP(button_B),	2, SDL_SCANCODE_U},
	};

	*size = sizeof(key_map) / sizeof(*key_map);
	return (&key_map[0]);
}

SDL_bool	process_user_input(int *action_ptr, int *board, int *old_board, size_t board_size)
{
	if (SDLX_GAME_PRESS(g_GameInput, g_GameInput_prev, DPAD_LEFT))
		*(action_ptr) = LEFT;
	else if (SDLX_GAME_PRESS(g_GameInput, g_GameInput_prev, DPAD_RIGHT))
		*(action_ptr) = RIGHT;
	else if (SDLX_GAME_PRESS(g_GameInput, g_GameInput_prev, DPAD_UP))
		*(action_ptr) = UP;
	else if (SDLX_GAME_PRESS(g_GameInput, g_GameInput_prev, DPAD_DOWN))
		*(action_ptr) = DOWN;

	if (SDLX_GAME_PRESS(g_GameInput, g_GameInput_prev, B))
		memcpy(board, old_board, board_size);

	return (SDL_FALSE);
}

int		catch_gesture(void)
{
	int		dx, dy;
	double	dist;
	double	angle;
	int		deg;

	dx = g_GameInput.GameInput.primary_delta.x;
	dy = g_GameInput.GameInput.primary_delta.y;
	dist = SDL_sqrt(dx * dx + dy * dy);

	if (dist > 40 && g_GameInput.GameInput.button_primleft)
	{
		angle = SDL_atan2(dx, dy);
		deg = SDLX_Radian_to_Degree(angle) + 360 + 45;
		deg %= 360;

		// SDL_Log("%d", deg);
		if (deg < 90)
			g_GameInput.GameInput.button_DPAD_LEFT |= 2;
		else if (deg < 180)
			g_GameInput.GameInput.button_DPAD_DOWN |= 2;
		else if (deg < 270)
			g_GameInput.GameInput.button_DPAD_RIGHT |= 2;
		else
			g_GameInput.GameInput.button_DPAD_UP |= 2;

	}

	return (NONE);
}
