NAME = stats
SOURCES = main.c ./sources/parser.c ./sources/utilities.c ./sources/stat_output.c ./sources/options_handling.c
INCLUDES = fb_stats.h
LIBFT = libft/libft.a

$(NAME):
	gcc -o stats $(SOURCES) $(LIBFT)

clean:
	rm -f stats 

re: clean $(NAME)
