#ifndef MAIN_H
# define MAIN_H

# include "SDLX/SDLX.h"

# include "structs.h"

# define TILE_SIZE	(16)

# define TILE (1)

SDL_Rect	*carve_2048_texture(void);

SDL_bool	process_user_input(int *action_ptr, int *board, int *old_board, size_t board_size);
SDL_bool	game_over(int *board);
SDLX_iMap	*game_key_mapper(size_t *size);
void		*button_trigger_scene_switch(SDLX_button *self, void *vp_context, SDL_UNUSED size_t length);

void	draw_board(int *board, SDL_Texture *texture, SDL_Rect *rects);
void	draw_grid(SDLX_Display *display);
int		slide_board(int *board, int *lock, int action);
void	spawn_tiles(int *board);

void	itow(int n, SDL_Rect dest, SDLX_Display *dislay);
void	*new_scene(size_t size, t_game_context *context, char *background_path, void *(close)(t_game_context *, void *), void *(update)(t_game_context *, void *));

void	*level_init(t_game_context *context, void *vp_scene);
void	*level_close(t_game_context *context, void *vp_scene);
void	*level_update(t_game_context *context, void *vp_scene);

void	*main_menu_init(t_game_context *context, void *vp_scene);
void	*main_menu_close(t_game_context *context, void *vp_scene);
void	*main_menu_update(t_game_context *context, void *vp_scene);

void	*gameover_scene_init(t_game_context *context, void *vp_scene);
void	*gameover_scene_close(t_game_context *context, void *vp_scene);
void	*gameover_scene_update(t_game_context *context, void *vp_scene);

int		fetch_button_sprite(SDLX_Sprite_Data **dst, int no);

#endif