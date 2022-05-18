#include "fb_stats.h"

void	show_data(t_player *data)
{
	printf("%s (", data->name);
	printf("%d), ", data->age);
	printf("%s, ", data->position);
	printf("%d min., ", data->minutes);
	printf("goals: %d, ", data->goals);
	printf("assists: %d \n", data->assists);
}

void	ft_print_player_list(t_player *player_list, int limit)
{
	int		count;

	count = 0;
	while (player_list->next != NULL)
	{
		if (limit == count)
			show_data(player_list);
		if (player_list->next != NULL)
			player_list = player_list->next;
		if (player_list->next == NULL)
			break ;
		count++;
	}
}

t_player	*init_player(void)
{
	t_player	*player;

	if (!(player = (t_player *)ft_memalloc(sizeof(t_player))))
		return (NULL);
	player->age = 0;
	player->goals = 0;
	player->assists = 0;
	player->name = NULL;
	player->position = NULL;
	player->next = NULL;
	player->previous = NULL;
	player->current = NULL;
	player->line_index = 0;
	player->lst_index = 0;
	return (player);
}

void	init_everything(int	*limit, int *player_count, char **arg2, t_player **head,
		t_player **players, t_player **players2, t_player **tmp)
{
	*arg2 = NULL;
	*head = NULL;
	*limit = -1;
	*player_count = 0;
	*players = init_player();
	*players2 = NULL;
	*tmp = init_player();
}

void	output_stats(char	*av2, t_player *head)
{
	if (ft_strcmp(av2, "mins") == 0)
		ft_most_mins(head);
	else if (ft_strcmp(av2, "goals") == 0)
		ft_goals(head);
	else if (ft_strcmp(av2, "g10") == 0)
		ft_goals_top_10(head);
	else if (ft_strcmp(av2, "assists") == 0)
		ft_assists(head);
	else if (ft_strcmp(av2, "ga") == 0)
		ft_goals_and_assists(head);
	else if (ft_strcmp(av2, "gamin") == 0)
		ft_goals_and_assists_min(head);
	else if (ft_strcmp(av2, "agegamin") == 0)
		ft_age_goals_and_assists_min(head);
}

char	*output_type(char	*av2)
{
	if (ft_strcmp(av2, "mins") == 0)
		return ("mins");
	else if (ft_strcmp(av2, "goals") == 0)
		return ("goals");
	else if (ft_strcmp(av2, "g10") == 0)
		return ("g10");
	else if (ft_strcmp(av2, "assists") == 0)
		return ("assists");
	else if (ft_strcmp(av2, "ga") == 0)
		return ("ga");
	else if (ft_strcmp(av2, "gamin") == 0)
		return ("gamin");
	else if (ft_strcmp(av2, "agegamin") == 0)
		return ("agegamin");
	else
		return (NULL);
}

int		main(int ac, char **av)
{
	int				fd;
	int				ret;
	char			*line;

	int				player_count;
	int				limit;
	char			*arg2;
	t_player		*players;
	t_player		*players2;
	t_player		*tmp;
	t_player		*head;

	if (ac != 3)
		usage("wrong number of arguments");
	init_everything(&limit, &player_count, &arg2, 
					&head, &players, &players2, &tmp);
	arg2 = output_type(av[2]);
	if (arg2 == NULL)
		limit = ft_atoi(av[2]);
	fd = open(av[1], O_RDONLY);
	ret = get_next_line(fd, &line);
	free(line);
	ret = get_next_line(fd, &line);
	head = players;
	while (ret > 0)
	{
		if (players->previous == NULL)
		{
			ret = get_next_line(fd, &line);
			players = parse_stats(line, players);
			free(line);
			head = players;
			players2 = init_player();
			players->next = players2;
			players2->previous = players;
		}
		if (players2->previous != NULL)
		{
			ret = get_next_line(fd, &line);
			players2 = parse_stats(line, players2);
			tmp = init_player();
			players2->next = tmp;
			tmp->previous = players2;
		}
		if (tmp->previous != NULL)
		{
			ret = get_next_line(fd, &line);
			tmp = parse_stats(line, tmp);
			players = init_player();
			tmp->next = players;
			players->previous = tmp;
		}
		if (players->previous != NULL)
		{
			ret = get_next_line(fd, &line);
			players = parse_stats(line, players);
			players2 = init_player();
			players->next = players2;
			players2->previous = players;
		}
		//free(line);
		player_count++;
	}
	if (arg2 != NULL)
		output_stats(arg2, head);
	ft_print_player_list(head, limit);
	return (0);
}
