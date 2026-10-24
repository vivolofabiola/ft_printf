NAME 			= libftprintf
CC				= cc
CFLAGS 			= -Wall -Wextra -Werror
INCLUDES 		= .
HEADERS			= ft_printf.h

LIBFT_DIR		= libft
LIBFT 			= $(LIBFT_DIR)/libft.a

SRCS			= ft_printf.c \
				ft_printf_utils.c \
				ft_printf_chars.c \
				ft_printf_hex.c \
				ft_printf_numbers.c \
		
OBJS			= $(SRC:.c=.o)
AR				= ar rcs
RM				= rm -f

all: $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $@

clean:
	@make -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
