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

}				t_level_scene;

void	*level_select_init(t_game_context *context, void *vp_scene)
{
	t_level_scene	*scene;

	scene = new_scene(sizeof(*scene), context, NULL, level_select_close, level_select_update);
	return (NULL);
}

void	*level_select_close(t_game_context *context, void *vp_scene)
{
	return (NULL);
}

void	*level_select_update(t_game_context *context, void *vp_scene)
{
	return (NULL);
}
