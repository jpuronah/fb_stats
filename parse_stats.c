#include <fcntl.h>
#include <stdio.h>
#include "libft/libft.h"

typedef struct	s_player
{
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

//Rk,Player,Nation,Pos,Squad,Age,Born,MP,Starts,Min,90s,Gls,Ast,G-PK,PK,PKatt,CrdY,CrdR,Gls,Ast,G+A,G-PK,G+A-PK,xG,npxG,xA,npxG+xA,xG,xA,xG+xA,npxG,npxG+xA,Matches

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
		while (line[i] != ',')
			i++;
		while (line[i] == ',')
			i++;
		while (line[i] != ',')
			i++;
		i++;
		j = 0;
		//printf("test\n");
		//printf("%c\n", line[i]);
		/*printf("%c", line[i - 1]);
		printf("%c", line[i]);
		printf("%c", line[i + 1]);
		printf("%c", line[i + 2]);
		printf("%c\n", line[i + 3]);*/
		if (line[i] != ',')
		{
			//printf("%c\n", str[j]);
			len = 0;
			while (line[i + len] != ',')
				len++;
			str = ft_strsub(line, i, len);											//Uus ft_atoi jotta saadaan päivät messiin
			player->age = ft_atoi(str);
			//printf("%c\n", line[i]);
			str = NULL;
			i = i + len;
		}
		printf("%c\n", line[i]);
		i = skip_column(line, i, n);


	}
	//printf("exit\n");
	return (player);
}

int		skip_colum(linem, 1, n)
{
	
}

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
	printf("%s, %s, %d\n", players->name, players->position, players->age);
	return (0);
}
