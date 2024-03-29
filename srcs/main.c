#include "main.h"

#ifdef EMCC
 # include <emscripten.h>
#endif

void	game_context_initialize(t_game_context *game_state)
{
	game_state->active = true;
	game_state->shouldChange = SDL_TRUE;
	game_state->shouldQuit = SDL_FALSE;

	game_state->init_fn = level_init;

	game_state->game_over = false;

	g_GameInput.key_mapper.map_arr = game_key_mapper(&(g_GameInput.key_mapper.amount));

	game_state->score = 0;
	game_state->hiscore = 0;

	srand(time(NULL));
}

void	main_loop(void *context_addr)
{
	t_game_context	*context;

	context = context_addr;
	context->shouldQuit = SDLX_poll();
	if (context->shouldChange == SDL_TRUE)
	{
		context->init_fn(context, context->meta);
		context->shouldChange = SDL_FALSE;
	}

	SDLX_KeyMap(&(g_GameInput.key_mapper), g_GameInput.keystate);
	SDLX_GameInput_Mouse_Fill(&(g_GameInput), SDL_TRUE);

	context->update_fn(context, context->meta);

	if (context->shouldQuit != SDL_TRUE && SDLX_discrete_frames(NULL) != EXIT_FAILURE)
	{
		SDLX_RenderQueue_Flush(NULL, NULL, SDL_FALSE);
		SDLX_ScreenReset(SDLX_GetDisplay()->renderer, NULL);
	}

	SDLX_record_input(NULL);

	if (context->shouldChange == SDL_TRUE)
	{
		SDLX_CollisionBucket_Flush(NULL);
		SDLX_RenderQueue_Flush(NULL, SDLX_GetDisplay()->renderer, SDL_FALSE);

		context->close_fn(context, context->meta);
	}
}

int main(void)
{
	t_game_context	cxt;

	SDLX_GetDisplay();

	printf("Hi, there!\n");
	printf("Random tiles spawn when you slide the board.\n");
	printf("To slide the board use the arrow keys.\n");
	printf("You are allowed one undo move, press U key\n");
	printf("Goodluck and have fun!\n");

	game_context_initialize(&(cxt));

#ifdef EMCC
	emscripten_set_main_loop_arg(main_loop, (void *)&(cxt), 0, SDL_TRUE);
#else
	while (cxt.shouldQuit == SDL_FALSE)
		main_loop(&(cxt));
#endif


	return (0);
}