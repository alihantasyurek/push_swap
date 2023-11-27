NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c \
       stack_init.c \
       push_swap_utils.c \
	   swap.c \
	   rotate.c \
	   reverse_rotate.c \
	   sort_stacks.c \
	   push.c \
	   init_nodes_a.c \
	   init_nodes_b.c \
	   handle_errors.c \
	   functions.c

LIBFT_PATH = libft
LIBFT_ARCHIVE = $(LIBFT_PATH)/libft.a

all: $(NAME)

$(NAME) : $(SRCS) $(LIBFT_ARCHIVE)
	$(CC) $(CFLAGS) $(SRCS) $(LIBFT_ARCHIVE) -o $(NAME) 

$(LIBFT_ARCHIVE) : 
	make -C $(LIBFT_PATH)

clean:
	make -C $(LIBFT_PATH) clean

fclean: 
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean

re: fclean all
