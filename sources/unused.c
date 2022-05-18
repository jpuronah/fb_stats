/*
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
}*/

/*t_p_lst		*init_p_lst(void)
{
	t_p_lst		*player_list;

	player_list = (t_p_lst *)ft_memalloc(sizeof(t_p_lst) * 550);
	if (player_list == NULL)
		return (NULL);
	player_list->player = NULL;
	player_list->next = NULL;
	player_list->previous = NULL;
	return (player_list);
}*/

/*
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
}*/