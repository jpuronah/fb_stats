#include "fb_stats.h"

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

void	usage(char *reason)
{
	//printf("Error: ");
	//printf("%s --- ", reason);
	printf("	usage: ./stats <input file> <player index>\n");
	exit(EXIT_FAILURE);
}
int		skip_column(char *line, int i, int n)
{
	if (line[i] == ',' || line[i] == '\\')
		i++;
	while (n >= 0)
	{
		while (line[i] != ',')
			i++;
		while (line[i] == ',')
			i++;
		n--;
	}
	i--;
	return (i);
}

int		save_integer(char *line, int i, int len, t_player *players)
{
	int		result;
	char	*str;

	if (line[i] == ',' || line[i] == '\\')
		i++;
	if (line[i] != ',')
	{
		len = 0;
		while (line[i + len] != ',')
			len++;
		str = ft_strsub(line, i, len);											//Uus ft_atoi jotta saadaan päivät messiin
		result = ft_atoi(str);
		str = NULL;
		players->line_index = i + len;
	}
	return (result);
}

int	ft_is_ext_ascii(int c)
{
	if (c >= 122 )
		return (1);
	else
		return (0);
}

char	*save_char(char *line, int i, int len, t_player *players)
{
	char	*str;
	char	*result;

	if (line[i] == ',' || line[i] == '\\')
		i++;
	if (line[i] != ',' && i < 5)
	{
		len = 0;
		while (line[i + len] != ',' && line[i + len] != '\\')
			len++;
		str = ft_strsub(line, i, len);											//Uus ft_atoi jotta saadaan päivät messiin
		result = str;
		str = NULL;
		players->line_index = i + len;
	}
	return (result);
}

int		save_position(char *line, int i, int len, t_player *player)
{
	char	*str;
	char	*result;

	if (line[i] == '\\')
	{
		while (line[i] != ',')
			i++;
		while (line[i] == ',')
			i++;
		while (line[i] != ',')
			i++;
		while (line[i] == ',')
			i++;
		if (line[i] != ',')
		{
			len = 0;
			while (line[i + len] != ',')
				len++;
			str = ft_strsub(line, i, len);
			player->position = str;
			str = NULL;
			i++;
		}
		player->line_index = i + len;
	}
	return (i);
}