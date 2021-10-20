/***************************************************************************
 * FILENAME:    game_over.c
 * DESCRIPTION: Handles the game_over scenes
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

typedef struct	s_gameover_scene
{
	SDLX_button	redo;
	int	ticks;

	SDL_Rect	s_rect;
	int			score;
}				t_gameover_scene;

void	*gameover_scene_init(t_game_context *context, void *vp_scene)
{
	t_gameover_scene *scene;

	scene = new_scene(sizeof(*scene), context, "resources/game_over.png", gameover_scene_close, gameover_scene_update);

	SDLX_Button_Init(&(scene->redo), fetch_button_sprite, 0, (SDL_Rect){(4 * 16 - 32) / 2, 40, 32, 16}, NULL);
	SDLX_Style_Button(&(scene->redo), 0, 1);
	scene->redo.trigger_fn = button_trigger_scene_switch;
	scene->redo.meta = context;
	scene->redo.meta1 = level_init;

	scene->ticks = 0;

	scene->score = context->score;

	scene->s_rect.h = 8 * DISPLAY_SCALE;
	scene->s_rect.w = 7 * DISPLAY_SCALE;
	scene->s_rect.y = 165;
	scene->s_rect.x = (340 + ((int)SDL_log10(context->score)) * scene->s_rect.w) / 2;

	(void)vp_scene;
	return (NULL);
}

void	*gameover_scene_close(t_game_context *context, void *vp_scene)
{
	t_gameover_scene	*scene;

	scene = vp_scene;

	SDL_free(context->background.sprite_data);
	SDL_free(scene);

	return (NULL);
}

void	*gameover_scene_update(t_game_context *context, void *vp_scene)
{
	t_gameover_scene *scene;

	scene = vp_scene;

	SDLX_Button_Update(&(scene->redo));
	scene->redo.sprite.current = scene->ticks / 3;

	itow(context->score, scene->s_rect, SDLX_GetDisplay());

	scene->ticks++;
	(void)context;
	return (NULL);
}
