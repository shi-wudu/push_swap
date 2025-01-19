SRCS			=	

NAME			=	push_swap.a

OBJS			=	$(SRCS:.c=.o)

CC				=	cc

CFLAGS			= -Wall -Wextra -Werror

LIBFT_PATH		= ./Libft

LIBFT			= $(LIBFT_PATH)/libft.a

OBJS			= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
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