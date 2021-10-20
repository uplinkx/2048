#ifndef MAIN_H
# define MAIN_H

# include <time.h>

# include "SDLX/SDLX.h"

# include "structs.h"

# define TILE_SIZE	(16)

# define TILE (1)

SDL_Rect	*carve_2048_texture(void);

void		process_user_input(t_game_context *game_state);
void		update_game_state(t_game_context *game_state);

void		draw_board(t_game_context *game_state, SDLX_Display *display);
void		draw_grid(t_game_context *game_state, SDLX_Display *display);

void		itow(int n, SDL_Rect dest, SDLX_Display *dislay);

#endif