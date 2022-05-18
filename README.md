# fb_stats

Football data project

No clear end goal, maybe a game or maybe just data visualization

usage: ./stats <input file> COMMAND

Command list:

'number' (player index), mins, goals, 
assists, ga (goals+assists), 
gamin (minutes / goals+assists), 
agegamin ((age / 20) * (minutes / goals+assists))


  Example:
  ```
  $>git clone < URL >
  $>cd < DIR >
  $>make stats
  $>gcc -o stats ./sources/parse_stats.c ./sources/parser.c ./sources/utilities.c libft/libft.a
  $>./stats EPL_player_stats 300
  $>Harry Maguire (29), DF, 2425 min.
  $>
  $>./stats EPL_player_stats 238
  $>Phil Jones (30), DF, 163 min.
