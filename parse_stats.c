#include <fcntl.h>
#include <stdio.h>
#include "libft/libft.h"

typedef struct	s_player
{
	//int		rank;
	char	*player;
	//char	*nation;
	char	*position;
	//char	*squad;
	int		age;
	//char	*born;
	//int		mp;
	//int		starts;
	int		minutes;
	//int		ninetys;
	int		goals;
	int		assists;
}				t_player;

//Rk,Player,Nation,Pos,Squad,Age,Born,MP,Starts,Min,90s,Gls,Ast,G-PK,PK,PKatt,CrdY,CrdR,Gls,Ast,G+A,G-PK,G+A-PK,xG,npxG,xA,npxG+xA,xG,xA,xG+xA,npxG,npxG+xA,Matches

void	parse_stats(char	*line)
{
	int		i;

	i = 0;
	printf("%s\n", line);
	while (line[i])
	{
		if (line[i] == ',')
		{
			
		}
	}

}

int		main(int ac, char **av)
{
	int		fd;
	int		ret;
	int		nro;
	int		limit;
	char	*line;

	t_player	**players;
	if (av[2])
		limit = ft_atoi(av[2]);
	fd = open(av[1], O_RDONLY);
	ret = get_next_line(fd, &line);
	nro = 0;
	while (ret > 0 && nro < limit + 1)
	{
		ret = get_next_line(fd, &line);
		parse_stats(line);
		nro++;
	}
	return (0);
}
