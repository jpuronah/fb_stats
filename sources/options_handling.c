#include "fb_stats.h"

void	output_stats(char	*av2, t_player *head)
{
	if (ft_strcmp(av2, "mins") == 0)
		ft_most_mins(head);
	else if (ft_strcmp(av2, "goals") == 0)
		ft_goals(head);
	else if (ft_strcmp(av2, "g10") == 0)
		ft_goals_top_10(head, 1000, 0);
	else if (ft_strcmp(av2, "a10") == 0)
		ft_assists_top_10(head, 1000, 0);
	else if (ft_strcmp(av2, "assists") == 0)
		ft_assists(head);
	else if (ft_strcmp(av2, "ga") == 0)
		ft_goals_and_assists(head);
	else if (ft_strcmp(av2, "gamin") == 0)
		ft_goals_and_assists_min(head);
	else if (ft_strcmp(av2, "gmin") == 0)
		ft_goals_min(head);
	else if (ft_strcmp(av2, "amin") == 0)
		ft_assists_min(head);
	else if (ft_strcmp(av2, "agegamin") == 0)
		ft_age_goals_and_assists_min(head);
	exit(EXIT_SUCCESS);
}

char	*output_type(char	*av2)
{
	if (ft_strcmp(av2, "mins") == 0)
		return ("mins");
	else if (ft_strcmp(av2, "goals") == 0)
		return ("goals");
	else if (ft_strcmp(av2, "g10") == 0)
		return ("g10");
	else if (ft_strcmp(av2, "a10") == 0)
		return ("a10");
	else if (ft_strcmp(av2, "assists") == 0)
		return ("assists");
	else if (ft_strcmp(av2, "ga") == 0)
		return ("ga");
	else if (ft_strcmp(av2, "gamin") == 0)
		return ("gamin");
	else if (ft_strcmp(av2, "gmin") == 0)
		return ("gmin");
	else if (ft_strcmp(av2, "amin") == 0)
		return ("amin");
	else if (ft_strcmp(av2, "agegamin") == 0)
		return ("agegamin");
	else
		return (NULL);
}
