NAME = stats
SOURCES = ./sources/parse_stats.c ./sources/parser.c ./sources/utilities.c
INCLUDES = fb_stats.h
LIBFT = libft/libft.a

$(NAME):
	gcc -o stats $(SOURCES) $(LIBFT)

clean:
	rm -f stats 

re: clean $(NAME)
