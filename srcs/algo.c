/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 11:04:59 by ycucchi           #+#    #+#             */
/*   Updated: 2022/08/11 11:05:01 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".././includes/filler.h"

void	do_algo(t_board *data, t_solved *sol, int i, int j)
{
	if (sol->sum == 0 || (data->sum < sol->sum && data->turn > 20)) // closest possible
	{
		dprintf(2, "closest || sum == 0\n");
		sol->x = i;
		sol->y = j;
		sol->sum = data->sum;
		dprintf(2, "i = %d\n", i);
		dprintf(2, "j = %d\n", j);
		dprintf(2, "sol->x = %d\n", sol->x);
		dprintf(2, "sol->y = %d\n", sol->y);
	}
	else if (data->turn <= 10 && sol->sum != 0)
	{
		dprintf(2, "10 premier tours : ==> ");
		if (!anyone_left(data, i, j) && j < sol->y && j < 3)
		{
			dprintf(2, "go gauche\n");
			dprintf(2, "sol sum = %d\n", sol->sum);
			sol->x = i;
			sol->y = j;
			sol->sum = data->sum;
			dprintf(2, "i = %d\n", i);
			dprintf(2, "j = %d\n", j);
			dprintf(2, "sol->x = %d\n", sol->x);
			dprintf(2, "sol->y = %d\n", sol->y);
		}
		else if (anyone_left(data, i, j) && i < sol->x)
		{
			dprintf(2, "go top\n");
			dprintf(2, "sol sum = %d\n", sol->sum);
			sol->x = i;
			sol->y = j;
			sol->sum = data->sum;
			dprintf(2, "i = %d\n", i);
			dprintf(2, "j = %d\n", j);
			dprintf(2, "sol->x = %d\n", sol->x);
			dprintf(2, "sol->y = %d\n", sol->y);
		}
		else if (anyone_left(data, i, j) && anyone_up(data, i, j) && j > sol->y)
		{
			dprintf(2, "go right\n");
			dprintf(2, "sol sum = %d\n", sol->sum);
			sol->x = i;
			sol->y = j;
			sol->sum = data->sum;
			dprintf(2, "i = %d\n", i);
			dprintf(2, "j = %d\n", j);
			dprintf(2, "sol->x = %d\n", sol->x);
			dprintf(2, "sol->y = %d\n", sol->y);
		}
	}
	else if (data->turn <= 20 && sol->sum != 0)
	{
		if (!anyone_left(data, i, j) && j < sol->y)
		{
			dprintf(2, "go gauche\n");
			dprintf(2, "sol sum = %d\n", sol->sum);
			sol->x = i;
			sol->y = j;
			sol->sum = data->sum;
			dprintf(2, "i = %d\n", i);
			dprintf(2, "j = %d\n", j);
			dprintf(2, "sol->x = %d\n", sol->x);
			dprintf(2, "sol->y = %d\n", sol->y);
		}
		else if (anyone_left(data, i, j) && i < sol->x)
		{
			dprintf(2, "go top\n");
			dprintf(2, "sol sum = %d\n", sol->sum);
			sol->x = i;
			sol->y = j;
			sol->sum = data->sum;
			dprintf(2, "i = %d\n", i);
			dprintf(2, "j = %d\n", j);
			dprintf(2, "sol->x = %d\n", sol->x);
			dprintf(2, "sol->y = %d\n", sol->y);
		}
		else if (anyone_left(data, i, j) && anyone_up(data, i, j) && j > sol->y)
		{
			dprintf(2, "go right\n");
			dprintf(2, "sol sum = %d\n", sol->sum);
			sol->x = i;
			sol->y = j;
			sol->sum = data->sum;
			dprintf(2, "i = %d\n", i);
			dprintf(2, "j = %d\n", j);
			dprintf(2, "sol->x = %d\n", sol->x);
			dprintf(2, "sol->y = %d\n", sol->y);
		}
	}
}

void	do_algo_closest(t_board *data, t_solved *sol, int i, int j)
{
	if ((data->sum < sol->sum || sol->sum == 0)) // closest possible
	{
		dprintf(2, "closest\n");
		sol->x = i;
		sol->y = j;
		sol->sum = data->sum;
		dprintf(2, "i = %d\n", i);
		dprintf(2, "j = %d\n", j);
		dprintf(2, "sol->x = %d\n", sol->x);
		dprintf(2, "sol->y = %d\n", sol->y);
	}
}

void	do_algo_test(t_board *data, t_solved *sol, int i, int j)
{
	// le but serait si au milieu go top left sinon go au plus proche
	if (data->turn < 15 && (i < sol->x || sol->sum == 0) && !sol->special_case)
	{
		dprintf(2, "go top\n");
		dprintf(2, "sol sum = %d\n", sol->sum);
		sol->x = i;
		sol->y = j;
		sol->sum = data->sum;
		sol->special_case = 1;
		dprintf(2, "i = %d\n", i);
		dprintf(2, "j = %d\n", j);
		dprintf(2, "sol->x = %d\n", sol->x);
		dprintf(2, "sol->y = %d\n", sol->y);
	}
	else if (in_the_middle(data) && (i < sol->x || j < sol->y) && data->turn < 50 && data->turn > 15)
	{
		dprintf(2, "ALGO TEST\n");
		sol->x = i;
		sol->y = j;
		sol->sum = data->sum;
		sol->special_case = 1;
		dprintf(2, "i = %d\n", i);
		dprintf(2, "j = %d\n", j);
		dprintf(2, "sol->x = %d\n", sol->x);
		dprintf(2, "sol->y = %d\n", sol->y);
	}
	else if ((data->sum < sol->sum || sol->sum == 0) && !sol->special_case)
	{
		dprintf(2, "closest no choice\n");
		sol->x = i;
		sol->y = j;
		sol->sum = data->sum;
		dprintf(2, "i = %d\n", i);
		dprintf(2, "j = %d\n", j);
		dprintf(2, "sol->x = %d\n", sol->x);
		dprintf(2, "sol->y = %d\n", sol->y);
	}
	dprintf(2, "data turn = [%d]\n", data->turn);
	dprintf(2, "sol x = [%d]\n", sol->x);
	dprintf(2, "sol y = [%d]\n", sol->y);
}

void	do_algo_expand(t_board *data, t_solved *sol, int i, int j)
{
	// cherche a aller le plus sur le coté avec i ou j le plus proche de 0
	// comment etre le plus a gauche ou a droite possible ? ...
	// qui dirait en gros que si la distance la piece pose et lennemib est de :::
// tu peux poser
	if (sol->sum == 0) // haut gauche
	{
		dprintf(2, "expand up\n");
		sol->x = i;
		sol->y = j;
		sol->sum = data->sum;
		dprintf(2, "i = %d\n", i);
		dprintf(2, "j = %d\n", j);
		dprintf(2, "sol->x = %d\n", sol->x);
		dprintf(2, "sol->y = %d\n", sol->y);
	}
}

void	do_algo_top_right(t_board *data, t_solved *sol, int i, int j)
{
	// 
	//
	//
	if (((j > sol->y && i <= sol->x) || sol->sum == 0) && (anyone_up(data, i, j) && anyone_left(data, i, j)))
	{
		dprintf(2, "turn = %d\n", data->turn);
		dprintf(2, "PB GAUCHE/TOP ==> go haut droite \n");
		dprintf(2, "sol sum = %d\n", sol->sum);
		sol->x = i;
		sol->y = j;
		sol->sum = data->sum;
		sol->special_case = 1;
		dprintf(2, "i = %d\n", i);
		dprintf(2, "j = %d\n", j);
		dprintf(2, "sol->x = %d\n", sol->x);
		dprintf(2, "sol->y = %d\n", sol->y);
	}
	else if (((j > sol->y && i < sol->x) || sol->sum == 0) && (anyone_up(data, i, j) && anyone_left(data, i, j)) && sol->special_case)
	{
		dprintf(2, "turn = %d\n", data->turn);
		dprintf(2, "PB GAUCHE/TOP ==> go haut droite \n");
		dprintf(2, "sol sum = %d\n", sol->sum);
		sol->x = i;
		sol->y = j;
		sol->sum = data->sum;
		dprintf(2, "i = %d\n", i);
		dprintf(2, "j = %d\n", j);
		dprintf(2, "sol->x = %d\n", sol->x);
		dprintf(2, "sol->y = %d\n", sol->y);
	}
	else if ((i < sol->x || sol->sum == 0) && anyone_left(data, i, j))
	{
		dprintf(2, "turn = %d\n", data->turn);
		dprintf(2, "PB GAUCHE ==> go haut \n");
		dprintf(2, "sol sum = %d\n", sol->sum);
		sol->x = i;
		sol->y = j;
		sol->sum = data->sum;
		sol->special_case = 1;
		dprintf(2, "i = %d\n", i);
		dprintf(2, "j = %d\n", j);
		dprintf(2, "sol->x = %d\n", sol->x);
		dprintf(2, "sol->y = %d\n", sol->y);
	}
	else if ((i < sol->x || sol->sum == 0) && anyone_left(data, i, j) && sol->special_case)
	{
		dprintf(2, "turn = %d\n", data->turn);
		dprintf(2, "PB GAUCHE ==> go haut \n");
		dprintf(2, "sol sum = %d\n", sol->sum);
		sol->x = i;
		sol->y = j;
		sol->sum = data->sum;
		dprintf(2, "i = %d\n", i);
		dprintf(2, "j = %d\n", j);
		dprintf(2, "sol->x = %d\n", sol->x);
		dprintf(2, "sol->y = %d\n", sol->y);
	}
	else if ((data->sum < sol->sum || sol->sum == 0) && !sol->special_case) // closest possible
	{
		dprintf(2, "closest\n");
		sol->x = i;
		sol->y = j;
		sol->sum = data->sum;
		dprintf(2, "i = %d\n", i);
		dprintf(2, "j = %d\n", j);
		dprintf(2, "sol->x = %d\n", sol->x);
		dprintf(2, "sol->y = %d\n", sol->y);
	}
}

void	do_algo_top_left(t_board *data, t_solved *sol, int i, int j)
{
	// il faudrait voir comme faire pour trouver le plus proche
	// mais aussi le plus haut gauche possible
	// j < sol->y ==> plus a gauche
	// i < sol->x ==> plus en haut
	// plus en haut a gauche = ???
	// if (j < sol->y && i < sol->x)

	// si l'adversaire est trop rapide et descend trop vite, il faut changer
	// de stratégie
	if ((j < sol->y || sol->sum == 0) && data->turn < 15)
	{
		dprintf(2, "turn = %d\n", data->turn);
		dprintf(2, "15 premier tours ==> go gauche\n");
		dprintf(2, "sol sum = %d\n", sol->sum);
		sol->x = i;
		sol->y = j;
		sol->sum = data->sum;
		dprintf(2, "i = %d\n", i);
		dprintf(2, "j = %d\n", j);
		dprintf(2, "sol->x = %d\n", sol->x);
		dprintf(2, "sol->y = %d\n", sol->y);
	}
	else if (((j < sol->y && i < sol->x) || sol->sum == 0) && data->turn < 20)
	{
		dprintf(2, "turn = %d\n", data->turn);
		dprintf(2, "20 premier tours ==> go haut gauche \n");
		dprintf(2, "sol sum = %d\n", sol->sum);
		sol->x = i;
		sol->y = j;
		sol->sum = data->sum;
		dprintf(2, "i = %d\n", i);
		dprintf(2, "j = %d\n", j);
		dprintf(2, "sol->x = %d\n", sol->x);
		dprintf(2, "sol->y = %d\n", sol->y);
	}
	else if (j < sol->y && i < sol->x && data->turn >= 20 && (i > 4 || j > 4))
	{
		dprintf(2, "turn = %d\n", data->turn);
		dprintf(2, "+ de 20 tours ==> go haut gauche \n");
		dprintf(2, "sol sum = %d\n", sol->sum);
		sol->x = i;
		sol->y = j;
		sol->sum = data->sum;
		sol->special_case = 1;
		dprintf(2, "i = %d\n", i);
		dprintf(2, "j = %d\n", j);
		dprintf(2, "sol->x = %d\n", sol->x);
		dprintf(2, "sol->y = %d\n", sol->y);
		dprintf(2, "sol sum after = %d\n", sol->sum);
	}
	else if ((data->sum < sol->sum || sol->sum == 0) && data->turn >= 20 && !sol->special_case)
	{
		dprintf(2, "turn = %d\n", data->turn);
		dprintf(2, "le reste du temps  ==> au plus proche\n");
		dprintf(2, "sol sum = %d\n", sol->sum);
		sol->x = i;
		sol->y = j;
		sol->sum = data->sum;
		dprintf(2, "i = %d\n", i);
		dprintf(2, "j = %d\n", j);
		dprintf(2, "sol->x = %d\n", sol->x);
		dprintf(2, "sol->y = %d\n", sol->y);
	}
}
