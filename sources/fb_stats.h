#ifndef		FB_STATS_H
# define	FB_STATS_H

#include <fcntl.h>
#include <stdio.h>
#include "../libft/libft.h"

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
	int			goals;
	int		assists;
	struct	s_player		*next;
	struct	s_player		*previous;
	struct	s_player		*current;
}				t_player;

/*typedef struct	s_p_lst
{
	t_player		*player;
	struct s_list	*next;
	struct s_list	*previous;
}				t_p_lst;*/

int			save_position(char *line, int i, int len, t_player *player);
char		*save_char(char *line, int i, int len, t_player *players);
int			ft_is_ext_ascii(int c);
int			save_integer(char *line, int i, int len, t_player *players);
int			skip_column(char *line, int i, int n);
t_player	*parse_stats(char	*line, t_player *player);
void		usage(char *reason);
size_t		ft_playercount(t_player *lst);
void	ft_assists(t_player *player_list);
void	ft_goals(t_player *player_list);
void	ft_most_mins(t_player *player_list);
void	ft_goals_per_90(t_player *player_list);
void	ft_goals_and_assists(t_player *player_list);
void	ft_goals_and_assists_min(t_player *player_list);
void	ft_age_goals_and_assists_min(t_player *player_list);
void	ft_goals_top_10(t_player *player_list);
void	output_stats(char	*av2, t_player *head);
char	*output_type(char	*av2);

#endif