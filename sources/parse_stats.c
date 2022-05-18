#include "fb_stats.h"

void	show_data(t_player *data)
{
	printf("%s (", data->name);
	printf("%d), ", data->age);
	printf("%s, ", data->position);
	printf("%d min.\n", data->minutes);
}

void	ft_print_player_list(t_player *player_list, int limit)
{
	int		count;

	count = 0;
	/*while (player_list->previous != NULL)
	{
		show_data(player_list->previous);
		if (player_list->previous != NULL)
			player_list = player_list->previous;
		if (player_list->previous == NULL)
			break ;
	}*/
	while (player_list->next != NULL)
	{
		if (limit == count)
			show_data(player_list->next);
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
	player->name = NULL;
	player->position = NULL;
	player->next = NULL;
	player->previous = NULL;
	player->current = NULL;
	player->line_index = 0;
	player->lst_index = 0;
	return (player);
}

t_player	*ft_create_player(t_player *player)
{
	t_player	*tmp;

	if (!(tmp = (t_player *)malloc(sizeof(t_player))))
		return (NULL);
	player->age = 0;
	player->name = NULL;
	player->position = NULL;
	player->next = NULL;
	player->previous = NULL;
	player->current = NULL;
	player->line_index = 0;
	player->lst_index = 0;
	return (tmp);
}

size_t	ft_playercount(t_player *lst)
{
	size_t i;

	i = 0;
	
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i - 1);
}

int		main(int ac, char **av)
{
	int				fd;
	int				ret;
	char			*line;

	int				player_count;
	int				limit;
	t_player		*players;
	t_player		*players2;
	t_player		*tmp;
	t_player		*head;

	if (ac != 3)
		usage("wrong number of arguments");
	head = NULL;
	player_count = 0;
	players = init_player();
	players2 = NULL;
	tmp = init_player();
	if (av[2])
		limit = ft_atoi(av[2]);
	fd = open(av[1], O_RDONLY);
	ret = get_next_line(fd, &line);
	ret = get_next_line(fd, &line);
	head = players;
	while (ret > 0)
	{
		if (players->previous == NULL)
		{
			ret = get_next_line(fd, &line);
			players = parse_stats(line, players);
			head = players;
			players2 = init_player();
			players->next = players2;
			players2->previous = players;
		}
		if (players2->previous != NULL)
		{
			ret = get_next_line(fd, &line);
			players2 = parse_stats(line, players2);
			tmp = players;
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
		//player_count++;
	}
	if (limit == 0)
	{
		printf("%s (", head->name);
		printf("%d), ", head->age);
		printf("%s, ", head->position);
		printf("%d min.\n", head->minutes);
		exit(EXIT_SUCCESS);
	}
	ft_print_player_list(head, limit);
	return (0);
}
