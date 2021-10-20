#ifndef MAIN_H
# define MAIN_H

# include "SDLX/SDLX.h"

# include "structs.h"

# define TILE_SIZE	(16)

# define TILE (1)

SDL_Rect	*carve_2048_texture(void);

void	process_user_input(t_game_context *game_state);
void	update_game_state(t_game_context *game_state);

void	draw_board(t_game_context *game_state, SDLX_Display *display);
void	draw_grid(t_game_context *game_state, SDLX_Display *display);

void	itow(int n, SDL_Rect dest, SDLX_Display *dislay);
void	*new_scene(size_t size, t_game_context *context, char *background_path, void *(close)(t_game_context *, void *), void *(update)(t_game_context *, void *));

void	*level_select_init(t_game_context *context, void *vp_scene);
void	*level_select_close(t_game_context *context, void *vp_scene);
void	*level_select_update(t_game_context *context, void *vp_scene);

void	*main_menu_select_init(t_game_context *context, void *vp_scene);
void	*main_menu_select_close(t_game_context *context, void *vp_scene);
void	*main_menu_select_update(t_game_context *context, void *vp_scene);

void	*gameover_scene_select_init(t_game_context *context, void *vp_scene);
void	*gameover_scene_select_close(t_game_context *context, void *vp_scene);
void	*gameover_scene_select_update(t_game_context *context, void *vp_scene);

#endif