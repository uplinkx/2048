/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 03:05:42 by home              #+#    #+#             */
/*   Updated: 2021/10/19 22:34:41 by home             ###   ########.fr       */
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

struct s_context;
typedef void *(t_scene_fn)(struct s_context *, void *);

typedef struct	s_game_context
{
	bool		active;
	SDL_bool	shouldChange;
	SDL_bool	shouldQuit;
	SDLX_Sprite	background;

	t_scene_fn	*init_fn;
	t_scene_fn	*update_fn;
	t_scene_fn	*close_fn;

	void		*meta;



	SDL_Texture	*texture;
	SDL_Rect	*src_rect;
	int			action;
	int			lock[16];
	int			prev_board[16];
	int			board[16];

	bool		game_over;
}				t_game_context;

#endif
