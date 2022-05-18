NAME = stats
SOURCES = parse_stats.c parser.c utilities.c
INCLUDES = fb_stats.h
LIBFT = libft/libft.a

$(NAME):
	gcc -o stats $(SOURCES) $(LIBFT)

clean:
	rm -f stats 

re: clean $(NAME)
