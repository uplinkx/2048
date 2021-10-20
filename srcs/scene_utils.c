/***************************************************************************
 * FILENAME:    scene_utils.c
 * DESCRIPTION: Utility functions for the scene
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

void	*new_scene(size_t size, t_game_context *context, char *background_path, void *(close)(t_game_context *, void *), void *(update)(t_game_context *, void *))
{
	void *result;

	result = SDL_calloc(1, size);

	SDL_assert(close != NULL);
	SDL_assert(update != NULL);

	context->close_fn = close;
	context->update_fn = update;
	context->meta = result;
	context->shouldChange = SDL_FALSE;

	if (background_path != NULL)
	{
		context->background = SDLX_Sprite_Static(background_path);
		SDLX_SetBackground(&(context->background));
	}
	else
		SDLX_SetBackground(NULL);

	return (result);
}

SDL_bool	game_over(int *board)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < 16)
	{
		if (board[i] != 0)
			count++;
		i++;
	}

	if (count == 16) { return (SDL_TRUE); }
	else { return (SDL_FALSE); }
}

void	*button_trigger_scene_switch(SDLX_button *self, void *vp_context, SDL_UNUSED size_t length)
{
	t_game_context *context;

	if (SDLX_GAME_RELEASE(g_GameInput, g_GameInput_prev, primleft))
	{
		context = vp_context;
		context->init_fn = self->meta1;
		context->shouldChange = SDL_TRUE;
	}

	return (NULL);
}