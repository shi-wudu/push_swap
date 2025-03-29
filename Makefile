SRCS			=	main.c lifejacket.c movelike.c jagger.c organize.c family.c allts.c sup.c
NAME			=	push_swap

OBJS			=	$(SRCS:%.c=%.o)

CC				=	cc

CFLAGS			= -Wall -Wextra -Werror -g -fsanitize=address

LIBFT_PATH		= ./Libft

LIBFT			= $(LIBFT_PATH)/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	@make -s -C $(LIBFT_PATH)

clean:
	@rm -f $(OBJS)
	
fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_PATH)

re: fclean all

.PHONY:         all clean fclean re