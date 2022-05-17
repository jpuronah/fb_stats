#include "fb_stats.h"

void	show_data(t_player *data)
{
	printf("Showdata\n");
	printf("%s (", data->name);
	printf("%d), ", data->age);
	printf("%s, ", data->position);
	printf("%d min.\n", data->minutes);
}

void	ft_print_player_list(t_player *player_list)
{
	t_player		*data;

	data = NULL;
	while (player_list->name != NULL)
	{
		show_data(player_list);
		if (player_list->next != NULL)
			player_list = player_list->next;
		if (player_list->next == NULL)
			break ;
	}
	ft_putchar('\n');
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

void	ft_list_push_front(t_player **begin_list, void *data)
{
	t_player	*tmp;

	if (*begin_list)
	{
		tmp = ft_create_player(data);
		tmp->next = *begin_list;
		*begin_list = tmp;
	}
	else
		*begin_list = ft_create_player(data);
}

t_p_lst		*init_p_lst(void)
{
	t_p_lst		*player_list;

	player_list = (t_p_lst *)ft_memalloc(sizeof(t_p_lst) * 550);
	if (player_list == NULL)
		return (NULL);
	player_list->player = NULL;
	player_list->next = NULL;
	player_list->previous = NULL;
	return (player_list);
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
	return (i);
}

int		main(int ac, char **av)
{
	int				fd;
	int				ret;
	char			*line;

	int				player_count;
	int				limit;
	t_player		*player;
	t_player		*tmp;
	t_player		**head;
	t_p_lst			*player_list;

	head = NULL;
	player_count = 0;
	player = init_player();
	tmp = init_player();
	if (av[2])
		limit = ft_atoi(av[2]);
	fd = open(av[1], O_RDONLY);
	ret = get_next_line(fd, &line);
	ret = get_next_line(fd, &line);
	printf("TEST\n");
	while (ret > 0 && player_count < limit)
	{
		player_list = init_p_lst();
		ret = get_next_line(fd, &line);
		player = parse_stats(line, player);
		player_list->player = player;
		tmp = init_player();
		player_list->next = tmp;
		player = player_list->next;
		//free(line);
		//printf("%s, %s, %d, %d\n", player->name, player->position, player->age, player->minutes);
		//printf("%s, %s, %d, %d\n", tmp->name, tmp->position, tmp->age, tmp->minutes);
		player_count++;
	}
	printf("%zu\n", ft_playercount(player));

	//ft_print_player_list(*head);
	//ft_print_player_list(player_list);
	ft_putstr("\n");
	return (0);
}
