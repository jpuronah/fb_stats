#include "fb_stats.h"

void	ft_goals_per_90(t_player *player_list)
{
	double		ref;
	char		*leader;
	t_player	*head;

	ref = 0;
	leader = NULL;
	head = NULL;
	head = player_list;
	//printf("%s\n", player_list->name);
	//printf("%f\n", (double)player_list->minutes / (double)player_list->goals);
	while (player_list->next != NULL)
	{
		if (player_list->goals > 0 && player_list->minutes > 1000 && (player_list->minutes / player_list->goals) > ref)
		{
			ref = player_list->minutes;
			leader = player_list->name;
		}
		else if (player_list->next != NULL)
			player_list = player_list->next;
		else if (player_list->next == NULL)
			break ;
	}
	player_list = head;
	while (player_list->next != NULL)
	{
		if (player_list->goals > 0 && player_list->minutes > 1000 && (player_list->minutes / player_list->goals) < ref)
		{
			ref = player_list->minutes;
			leader = player_list->name;
		}
		if (player_list->next != NULL)
			player_list = player_list->next;
		if (player_list->next == NULL)
			break ;
	}
	printf("%s, %f\n", leader, ref);
}

void	ft_most_mins(t_player *player_list)
{
	int		ref;
	char	*leader;

	ref = 0;
	leader = NULL;
	while (player_list->next != NULL)
	{
		if (player_list->minutes > ref)
		{
			ref = player_list->minutes;
			leader = player_list->name;
		}
		if (player_list->next != NULL)
			player_list = player_list->next;
		if (player_list->next == NULL)
			break ;
	}
	printf("%s, %d\n", leader, ref);
}

void	ft_goals(t_player *player_list)
{
	int		ref;
	char	*leader;

	ref = 0;
	leader = NULL;
	while (player_list->next != NULL)
	{
		if (player_list->goals > ref)
		{
			ref = player_list->goals;
			leader = player_list->name;
		}
		if (player_list->next != NULL)
			player_list = player_list->next;
		if (player_list->next == NULL)
			break ;
	}
	printf("%s, %d\n", leader, ref);
}

void	ft_assists(t_player *player_list)
{
	int		ref;
	char	*leader;

	ref = 0;
	leader = NULL;
	while (player_list->next != NULL)
	{
		if (player_list->assists > ref)
		{
			ref = player_list->assists;
			leader = player_list->name;
		}
		if (player_list->next != NULL)
			player_list = player_list->next;
		if (player_list->next == NULL)
			break ;
	}
	printf("%s, %d\n", leader, ref);
}