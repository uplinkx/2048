/***************************************************************************
 * FILENAME:    level_scene.c
 * DESCRIPTION: Handles the main level
 *
 * ENVIRONMENT:
 *     macOS Catalina 10.15.7
 *     Visual Studio Code 1.56.2
 * AUTHORS:
 *     Kevin Colour
 * DATES:
 *     Created: 19Oct2021
***************************************************************************/

#include "main.h"

typedef struct	s_level_scene
{
	SDL_Texture	*texture;
	SDL_Rect	*src_rect;

	int			action;
	int			lock[16];
	int			prev_board[16];
	int			board[16];
}				t_level_scene;

void	*level_select_init(t_game_context *context, void *vp_scene)
{
	t_level_scene	*scene;
	SDL_Renderer	*renderer;

	renderer = SDLX_GetDisplay()->renderer;
	scene = new_scene(sizeof(*scene), context, NULL, level_select_close, level_select_update);

	scene->texture = IMG_LoadTexture(renderer, "resources/2048_texture.png");
	scene->src_rect = carve_2048_texture();

	scene->action = NONE;

	bzero(scene->board, sizeof(scene->board));

	(void)vp_scene;
	return (NULL);
}

void	*level_select_close(t_game_context *context, void *vp_scene)
{
	(void)context;
	(void)vp_scene;
	return (NULL);
}

void	*level_select_update(t_game_context *context, void *vp_scene)
{
	t_level_scene	*scene;
	SDLX_Display	*display;

	scene = vp_scene;
	display = SDLX_GetDisplay();

	context->shouldQuit = process_user_input(&(scene->action), scene->board, scene->prev_board, sizeof(scene->board));

	if (scene->action != NONE)
	{
		bzero(scene->lock, sizeof(scene->lock));
		memcpy(scene->prev_board, scene->board, sizeof(scene->prev_board));
		slide_board(scene->board, scene->lock, scene->action);
		spawn_tiles(scene->board);
	}

	scene->action = NONE;

	draw_grid(display);
	draw_board(scene->board, scene->texture, scene->src_rect);
	(void)context;
	return (NULL);
}
