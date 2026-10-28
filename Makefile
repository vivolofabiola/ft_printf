NAME        = libftprintf.a
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
INCLUDES    = .
HEADERS     = ft_printf.h

LIBFT_DIR   = libft
LIBFT       = $(LIBFT_DIR)/libft.a

SRCS        = ft_printf.c \
              ft_printf_utils.c \
              ft_print_chars.c \
              ft_print_hex.c \
              ft_print_numbers.c

OBJS        = $(SRCS:.c=.o)
AR          = ar rcs
RM          = rm -f

all: $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJS)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $@

clean:
	@make -C $(LIBFT_DIR) clean
	$(RM) $(OBJS)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
