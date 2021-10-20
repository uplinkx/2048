/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 20:52:34 by home              #+#    #+#             */
/*   Updated: 2021/10/20 00:06:25 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	slide_left(int *board, int *lock, int offset)
{
	int i;
	int j;
	int	score_add;

	i = 0;
	score_add = 0;
	while (i <= 3)
	{
		j = i - 1;
		while (j >= 0 && board[j + offset] == 0)
			j--;

		if (j >= 0 && board[i + offset] == board[j + offset] && lock[j + offset] == 0)
		{
			score_add += board[i + offset];
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
	return (score_add);
}

int	slide_right(int *board, int *lock, int offset)
{
	int i;
	int j;
	int	score_add;

	i = 3;
	score_add = 0;
	while (i >= 0)
	{
		j = i + 1;
		while (j <= 3 && board[j + offset] == 0)
			j++;

		if (j <= 3 && board[i + offset] == board[j + offset] && lock[j + offset] == 0)
		{
			score_add += board[i + offset];
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
	return (score_add);
}

int	slide_down(int *board, int *lock, int offset)
{
	int i;
	int j;
	int	score_add;

	i = 12;
	score_add = 0;
	while (i >= 0)
	{
		j = i + 4;
		while (j <= 12 && board[j + offset] == 0)
			j += 4;

		if (j <= 12 && board[i + offset] == board[j + offset] && lock[j + offset] == 0)
		{
			score_add += board[i + offset];
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
	return (score_add);
}

int	slide_up(int *board, int *lock, int offset)
{
	int i;
	int j;
	int	score_add;

	i = 0;
	score_add = 0;
	while (i <= 12)
	{
		j = i - 4;
		while (j >= 0 && board[j + offset] == 0)
			j -= 4;

		if (j >= 0 && board[i + offset] == board[j + offset] && lock[j + offset] == 0)
		{
			score_add += board[i + offset];
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
	return (score_add);
}

/*
** Maybe if I get the time I can combine these functions.
** These version are more robust and I am much more confident that
** in their behavior and functionality. But I need to test and validate them.
*/
int	slide_board(int *board, int *lock, int action)
{
	int	score_add;

	score_add = 0;
	if (action == RIGHT)
	{
		score_add += slide_right(board, lock,  0);
		score_add += slide_right(board, lock,  4);
		score_add += slide_right(board, lock,  8);
		score_add += slide_right(board, lock, 12);
	}
	if (action == LEFT)
	{
		score_add += slide_left(board, lock,  0);
		score_add += slide_left(board, lock,  4);
		score_add += slide_left(board, lock,  8);
		score_add += slide_left(board, lock, 12);
	}
	if (action == DOWN)
	{
		score_add += slide_down(board, lock, 0);
		score_add += slide_down(board, lock, 1);
		score_add += slide_down(board, lock, 2);
		score_add += slide_down(board, lock, 3);
	}
	if (action == UP)
	{
		score_add += slide_up(board, lock, 0);
		score_add += slide_up(board, lock, 1);
		score_add += slide_up(board, lock, 2);
		score_add += slide_up(board, lock, 3);
	}

	return (score_add);
}

void	spawn_tiles(int *board)
{
	int	i;
	int	spawn_chance;
	SDL_bool	spawned;

	spawned = SDL_FALSE;
	while (spawned == SDL_FALSE)
	{
		i = 0;
		while (i < 16)
		{
			if (board[i] == 0)
			{
				spawn_chance = rand() % 50;
				if (spawn_chance < 2)
				{
					board[i] = 2;
					spawned = SDL_TRUE;
				}
				else if (spawn_chance < 3)
				{
					board[i] = 4;
					spawned = SDL_TRUE;
				}
			}
			i++;
		}
	}
}

