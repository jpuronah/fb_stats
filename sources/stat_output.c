#include "fb_stats.h"

void	ft_goals_per_mins(t_player *player_list)
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

t_top10	*init_top10(void)
{
	t_top10		*gtop10;

	gtop10 = (t_top10 *)malloc(sizeof(t_top10) * 11);
	gtop10->player = NULL;
	/*gtop10->goals = 0;
	gtop10->name = NULL;
	gtop10->next = NULL;*/
	return (gtop10);
}

void	make_list(char *leader, int ref, int count)
{
	t_top10		*list;
	t_top10		*head;
	t_player	*player;

	list = init_top10();
	head = list;
	player = list->player;
}

void	ft_goals_top_10(t_player *player_list, int max, int count)
{
	int			ref;
	char		*leader;
	t_player	*head;

	ref = 0;
	leader = NULL;
	head = player_list;
	while (player_list->next != NULL)
	{
		if (player_list->goals > ref && player_list->goals < max)
		{
			ref = player_list->goals;
			leader = player_list->name;
		}
		if (player_list->next != NULL)
			player_list = player_list->next;
		if (player_list->next == NULL)
			break ;
	}
	if (count == 0)
		printf("Top 10 Goalscorers\n");
	if (leader && ref && count++ < 10)
	{
		printf("%s\n  Goals: %d\n", leader, ref);
	}
	if (ref > 1 && count < 10)
		ft_goals_top_10(head, ref, count);
}

void	ft_assists_top_10(t_player *player_list, int max, int count)
{
	int			ref;
	char		*leader;
	t_player	*head;

	ref = 0;
	leader = NULL;
	head = player_list;
	while (player_list->next != NULL)
	{
		if (player_list->assists > ref && player_list->assists < max)
		{
			ref = player_list->assists;
			leader = player_list->name;
		}
		if (player_list->next != NULL)
			player_list = player_list->next;
		if (player_list->next == NULL)
			break ;
	}
	if (count == 0)
		printf("Top 10 Assists\n");
	if (leader && ref && count++ < 10)
	{
		printf("%s\n  Assists: %d\n", leader, ref);
	}
	if (ref > 1 && count < 10)
		ft_assists_top_10(head, ref, count);
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

void	ft_goals_min(t_player *player_list)
{
	int		ref;
	char	*leader;

	ref = 5000;
	leader = NULL;
	while (player_list->next != NULL)
	{
		if ((player_list->goals) > 0 && player_list->minutes > 480)
		{
			if ((player_list->minutes / (player_list->goals)) < ref)
			{
				ref = player_list->minutes / (player_list->goals);
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

void	ft_assists_min(t_player *player_list)
{
	int		ref;
	char	*leader;

	ref = 5000;
	leader = NULL;
	while (player_list->next != NULL)
	{
		if ((player_list->assists) > 0 && player_list->minutes > 480)
		{
			if ((player_list->minutes / (player_list->assists)) < ref)
			{
				ref = player_list->minutes / (player_list->assists);
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
