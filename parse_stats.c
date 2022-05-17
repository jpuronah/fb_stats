#include <fcntl.h>
#include <stdio.h>
#include "libft/libft.h"

typedef struct	s_player
{
	int		line_index;
	//int		rank;
	char	*name;
	//char	*nation;
	char	*position;
	//char	*squad;
	int		age;
	//char	*born;
	//int		mp;
	//int		starts;
	int			minutes;
	//int		ninetys;
	//int		goals;
	//int		assists;
}				t_player;

t_player	*init_players(void)
{
	t_player	*players;

	if (!(players = (t_player *)ft_memalloc(sizeof(t_player))))
		return (NULL);
	players->age = 0;
	players->name = NULL;
	players->position = NULL;
	return (players);
}

//Rk,Player,Nation,Pos,Squad,Age,Born,MP,Starts,Min,90s,Gls,Ast,G-PK,PK,PKatt,CrdY,CrdR,Gls,Ast,G+A,G-PK,G+A-PK,xG,npxG,xA,npxG+xA,xG,xA,xG+xA,npxG,npxG+xA,Matches

int		skip_column(char *line, int i, int n)
{
	while (n >= 0)
	{
		while (line[i] != ',')
			i++;
		while (line[i] == ',')
			i++;
		n--;
	}
	return (i);
}

int		save_int(char *line, int i, int len, t_player *players)
{
	int		result;
	char	*str;

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

t_player	*parse_stats(char	*line, t_player *player)
{
	int		i;
	int		j;
	int		len;
	char	*str;

	i = 0;
	j = 0;
	len = 0;
	str = NULL;
	printf("%s\n", line);
	if (line[i])
	{
		//	NAME 
		while (line[i] != ',')
			i++;
		if (line[i] == ',' && i < 4)
		{
			j = 0;
			i++;
			while (ft_isalpha(line[i + len]) || line[i + len] == ' ')
				len++;
			//printf("name: %c\n", line[i]);
			//printf("%d\n", len);
			str = ft_strsub(line, i, len);
			//printf("%s\n", str);
			player->name = str;
			str = NULL;
			i = i + len;
		}
	//	printf("test\n");
		//	POSITION
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
			j = 0;
			while (line[i] != ',')
			{
				len = 0;
				while (line[i + len] != ',')
					len++;
				str = ft_strsub(line, i, len);
				player->position = str;
				str = NULL;
				i = i + len;
			}
		}
		//	AGE
		i = skip_column(line, i, 1);
		player->age = save_int(line, i, len, player);
		j = 0;
		printf("%c\n", line[i]);
		i = skip_column(line, i, 3);
		player->minutes = save_int(line, i, len, player);
		i = player->line_index;
	}
	//printf("exit\n");
	return (player);
}

int		main(int ac, char **av)
{
	int		fd;
	int		ret;
	int		nro;
	int		limit;
	char	*line;
	t_player	*players;

	players = init_players();
	if (av[2])
		limit = ft_atoi(av[2]);
	fd = open(av[1], O_RDONLY);
	ret = get_next_line(fd, &line);
	ret = get_next_line(fd, &line);
	nro = 0;
	while (ret > 0 && nro < limit)
	{
		printf("%d\n", limit);
		ret = get_next_line(fd, &line);
		players = parse_stats(line, players);
		nro++;
	}
	printf("%s, %s, %d, %d\n", players->name, players->position, players->age, players->minutes);
	return (0);
}
