/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 20:52:34 by home              #+#    #+#             */
/*   Updated: 2021/03/05 15:49:54 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	slide_left(int *board, int *lock, int offset)
{
	int i;
	int j;

	i = 0;
	while (i <= 3)
	{
		j = i - 1;
		while (j >= 0 && board[j + offset] == 0)
			j--;

		if (j >= 0 && board[i + offset] == board[j + offset] && lock[j + offset] == 0)
		{
			board[j + offset] += board[i + offset];
			board[i + offset] = 0;
			lock[j + offset] = 1;
		}
		else if (board[j + 1 + offset] == 0)
		{
			board[j + 1 + offset] = board[i + offset];
			board[i + offset] = 0;
		}
		i++;
	}
}

void	slide_right(int *board, int *lock, int offset)
{
	int i;
	int j;

	i = 3;
	while (i >= 0)
	{
		j = i + 1;
		while (j <= 3 && board[j + offset] == 0)
			j++;

		if (j <= 3 && board[i + offset] == board[j + offset] && lock[j + offset] == 0)
		{
			board[j + offset] += board[i + offset];
			board[i + offset] = 0;
			lock[j + offset] = 1;
		}
		else if (board[j - 1 + offset] == 0)
		{
			board[j - 1 + offset] = board[i + offset];
			board[i + offset] = 0;
		}
		i--;
	}
}

void	slide_down(int *board, int *lock, int offset)
{
	int i;
	int j;

	i = 12;
	while (i >= 0)
	{
		j = i + 4;
		while (j <= 12 && board[j + offset] == 0)
			j += 4;

		if (j <= 12 && board[i + offset] == board[j + offset] && lock[j + offset] == 0)
		{
			board[j + offset] += board[i + offset];
			board[i + offset] = 0;
			lock[j + offset] = 1;
		}
		else if (board[j - 4 + offset] == 0)
		{
			board[j - 4 + offset] = board[i + offset];
			board[i + offset] = 0;
		}
		i -= 4;
	}
}

void	slide_up(int *board, int *lock, int offset)
{
	int i;
	int j;

	i = 0;
	while (i <= 12)
	{
		j = i - 4;
		while (j >= 0 && board[j + offset] == 0)
			j -= 4;

		if (j >= 0 && board[i + offset] == board[j + offset] && lock[j + offset] == 0)
		{
			board[j + offset] += board[i + offset];
			board[i + offset] = 0;
			lock[j + offset] = 1;
		}
		else if (board[j + 4 + offset] == 0)
		{
			board[j + 4 + offset] = board[i + offset];
			board[i + offset] = 0;
		}
		i += 4;
	}
}

/*
** Maybe if I get the time I can combine these functions.
** These version are more robust and I am much more confident that
** in their behavior and functionality. But I need to test and validate them.
*/
void	slide_board(int *board, int *lock, int action)
{
	if (action == RIGHT)
	{
		slide_right(board, lock,  0);
		slide_right(board, lock,  4);
		slide_right(board, lock,  8);
		slide_right(board, lock, 12);
	}
	if (action == LEFT)
	{
		slide_left(board, lock,  0);
		slide_left(board, lock,  4);
		slide_left(board, lock,  8);
		slide_left(board, lock, 12);
	}
	if (action == DOWN)
	{
		slide_down(board, lock, 0);
		slide_down(board, lock, 1);
		slide_down(board, lock, 2);
		slide_down(board, lock, 3);
	}
	if (action == UP)
	{
		slide_up(board, lock, 0);
		slide_up(board, lock, 1);
		slide_up(board, lock, 2);
		slide_up(board, lock, 3);
	}
}

void	spawn_tiles(int *board)
{
	int	i;
	int	spawn_chance;

	i = 0;
	while (i < 16)
	{
		if (board[i] == 0)
		{
			spawn_chance = rand() % 50;
			if (spawn_chance < 2)
				board[i] = 2;
			else if (spawn_chance < 3)
				board[i] = 4;
		}
		i++;
	}
}

void	update_game_state(t_game_context *game_state)
{

	if (game_state->action != NONE)
	{
		bzero(game_state->lock, sizeof(game_state->lock));
		memcpy(game_state->prev_board, game_state->board, sizeof(game_state->prev_board));
		slide_board(game_state->board, game_state->lock, game_state->action);
		spawn_tiles(game_state->board);
	}

	game_state->action = NONE;
}
