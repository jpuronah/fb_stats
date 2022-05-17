#ifndef		FB_STATS_H
# define	FB_STATS_H

#include <fcntl.h>
#include <stdio.h>
#include "libft/libft.h"

/*typedef struct	s_list
{
	t_player		*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;*/

typedef struct	s_player
{
	int		line_index;
	int		lst_index;
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
	void		*next;
	void		*previous;
	void		*current;
}				t_player;

int		save_position(char *line, int i, int len, t_player *player);
char	*save_char(char *line, int i, int len, t_player *players);
int		ft_is_ext_ascii(int c);
int		save_integer(char *line, int i, int len, t_player *players);
int		skip_column(char *line, int i, int n);

#endif