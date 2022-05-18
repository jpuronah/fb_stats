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

void	top10(t_player *head, t_player *head2, int count, int ref, int offset, char *leader)
{
	while (head->next != NULL)
	{
		count++;
		if (ref - head->goals == 1 + offset)
		{
			ref = head->goals;
			leader = head->name;
			count++;
			offset = 0;
			printf("%d, %d\n", ref, head->goals);
		}
		if (ref - head->goals > 1 + offset)
			offset++;
		if (head->next != NULL)
			head = head->next;
		if (head->next == NULL && count < 10)
			top10(head2, head2, count, ref, offset, leader);
		if (head->next == NULL)
			break ;
	}
}

void	ft_goals_top_10(t_player *player_list)
{
	int			ref;
	int			count;
	int			offset;
	char		*leader;
	t_player	*head;
	t_player	*head2;

	ref = 0;
	count = 0;
	offset = 0;
	leader = NULL;
	head = player_list;
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
	printf("%d, %d\n", ref, head->goals);
	top10(head, head2, count, ref, offset, leader);
}

void	ft_goals(t_player *player_list)
{
	int			ref;
	char		*leader;

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

void	ft_goals_and_assists(t_player *player_list)
{
	int		ref;
	char	*leader;

	ref = 0;
	leader = NULL;
	while (player_list->next != NULL)
	{
		if ((player_list->assists + player_list->goals) > ref)
		{
			ref = player_list->assists + player_list->goals;
			leader = player_list->name;
		}
		if (player_list->next != NULL)
			player_list = player_list->next;
		if (player_list->next == NULL)
			break ;
	}
	printf("%s, %d\n", leader, ref);
}

void	ft_age_goals_and_assists_min(t_player *player_list)
{
	int		ref;
	int		result;
	char	*leader;

	ref = 500000;
	result = 0;
	leader = NULL;
	while (player_list->next != NULL)
	{
		if ((player_list->assists + player_list->goals) > 0 && player_list->minutes > 480)
		{
			if (((player_list->age * 2) *  (player_list->minutes / (player_list->assists + player_list->goals))) < ref)
			{
				ref = (player_list->age) * (player_list->minutes / (player_list->assists + player_list->goals));
				result = ref / 20;
				leader = player_list->name;
			}
		}
		if (player_list->next != NULL)
			player_list = player_list->next;
		if (player_list->next == NULL)
			break ;
	}
	printf("%s, %d\n", leader, result);
}

void	ft_goals_and_assists_min(t_player *player_list)
{
	int		ref;
	char	*leader;

	ref = 5000;
	leader = NULL;
	while (player_list->next != NULL)
	{
		if ((player_list->assists + player_list->goals) > 0 && player_list->minutes > 480)
		{
			if ((player_list->minutes / (player_list->assists + player_list->goals)) < ref)
			{
				ref = player_list->minutes / (player_list->assists + player_list->goals);
				leader = player_list->name;
			}
		}
		if (player_list->next != NULL)
			player_list = player_list->next;
		if (player_list->next == NULL)
			break ;
	}
	printf("%s, %d\n", leader, ref);
}