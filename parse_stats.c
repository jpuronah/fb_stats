#include "fb_stats.h"

t_player	*init_players(void)
{
	t_player	*players;

	if (!(players = (t_player *)ft_memalloc(sizeof(t_player))))
		return (NULL);
	players->age = 0;
	players->name = NULL;
	players->position = NULL;
	players->next = NULL;
	players->previous = NULL;
	players->current = NULL;
	players->line_index = 0;
	players->lst_index = 0;
	return (players);
}

//Rk,Player,Nation,Pos,Squad,Age,Born,MP,Starts,Min,90s,Gls,Ast,G-PK,PK,PKatt,CrdY,CrdR,Gls,Ast,G+A,G-PK,G+A-PK,xG,npxG,xA,npxG+xA,xG,xA,xG+xA,npxG,npxG+xA,Matches

t_player	*parse_stats(char	*line, t_player *player)
{
	int		i;
	int		j;
	int		len;
	char	*str;

	i = 0;

	len = 0;
	str = NULL;
	//printf("%s\n", line);
	if (line[i])
	{
		//	NAME 
		while (line[i] != ',')
			i++;
		player->name = save_char(line, i, len, player);
		i = player->line_index;
		//	POSITION
		i = save_position(line, i, len, player);
		//	AGE
		i = skip_column(line, i, 1);
		player->age = save_integer(line, i, len, player);
		i = player->line_index;
		//	MINUTES
		i = skip_column(line, i, 3);
		player->minutes = save_integer(line, i, len, player);
		i = player->line_index;
		//	GOALS
		//	ASSISTS
		//	GOALS + ASSISTS
		//	GOALS / 90
		//	ASSISTS / 90
		//	(GOALS + ASSISTS) / 90
	}
	return (player);
}

int		main(int ac, char **av)
{
	int				fd;
	int				ret;
	int				player_count;
	int				limit;
	char			*line;
	t_player		*tmp;
	t_player		*players;
	t_list			*player_list;

	player_count = 0;
	players = init_players();
	tmp = init_players();
	player_list = ft_create_elem(tmp);
	/*player_list = (t_list **)malloc(sizeof(t_list) * 550);
	*player_list = ft_lstnew(players, 550);
	player_list->next = players;*/
	if (av[2])
		limit = ft_atoi(av[2]);
	fd = open(av[1], O_RDONLY);
	ret = get_next_line(fd, &line);
	ret = get_next_line(fd, &line);
	while (ret > 0 && player_count < limit)
	{
		//printf("%d\n", limit);
		ret = get_next_line(fd, &line);
		players = parse_stats(line, players);
		player_list->content = players;
		player_list->next = ft_create_elem(tmp);
		printf("%s, %s, %d, %d\n", players->name, players->position, players->age, players->minutes);
		player_count++;
	}
	tmp = NULL;
	ft_lstrev(&player_list);
	tmp = player_list->content;
	printf("%s\n", tmp->name);
	tmp = player_list->next->content;
	printf("%s\n", tmp->name);
	return (0);
}
