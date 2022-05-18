#include "fb_stats.h"

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
		i = skip_column(line, i, 2);
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
