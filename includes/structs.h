/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 03:05:42 by home              #+#    #+#             */
/*   Updated: 2020/07/23 02:33:37 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

#include <SDL2/SDL.h>
#include <stdbool.h>

typedef struct	s_display
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
}				t_display;

typedef enum	actions
{
	NONE =	0b00001,
	LEFT =	0b00010,
	RIGHT =	0b00100,
	UP =	0b01000,
	DOWN =	0b10000,
}				e_actions;

typedef struct	s_game_context
{
	bool		active;

	SDL_Texture	*texture;
	SDL_Rect	*src_rect;

	bool		game_over;

	int			action;

	int			lock[16];

	int			prev_board[16];
	int			board[16];
}				t_game_context;

#endif
