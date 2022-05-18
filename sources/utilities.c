#include "fb_stats.h"

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

void	usage(char *reason)
{
	//printf("Error: ");
	//printf("%s --- ", reason);
	printf("	usage: ./stats <input file> COMMAND\nplayer index, goals, assists, g+a (goals+assists)\n");
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
