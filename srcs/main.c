#include "main.h"
#include <emscripten.h>

void	game_context_initialize(t_game_context *game_state, SDLX_Display *display)
{
	game_state->active = true;

	game_state->texture = IMG_LoadTexture(display->renderer, "resources/2048_texture.png");
	game_state->src_rect = carve_2048_texture();

	if (game_state->texture == NULL)
		printf("Texture does not exist\n");

	game_state->game_over = false;

	game_state->action = NONE;

	bzero(game_state->board, sizeof(game_state->board));

	srand(time(NULL));
}

void	main_loop(void *v_cxt)
{
	t_game_context *cxt;
	SDLX_Display	*display;

	cxt = v_cxt;

	display = SDLX_GetDisplay();

	process_user_input(cxt);

	update_game_state(cxt);

	draw_grid(cxt, display);
	draw_board(cxt, display);

	SDL_RenderPresent(display->renderer);
	SDL_RenderClear(display->renderer);

}

int main(void)
{
	t_game_context	cxt;
	SDLX_Display	*display;

	printf("Hi, there!\n");
	printf("Random tiles spawn when you slide the board.\n");
	printf("To slide the board use the arrow keys.\n");
	printf("You are allowed one undo move, press U key\n");
	printf("Goodluck and have fun!\n");

	display = SDLX_GetDisplay();
	game_context_initialize(&(cxt), display);
	emscripten_set_main_loop_arg(main_loop, (void *)&(cxt), 0, SDL_TRUE);

	return (0);
}