# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/13 15:08:13 by rkochhan          #+#    #+#              #
#    Updated: 2021/09/14 08:57:49 by rkochhan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

LIBFT	= libft
LIBS	= -L $(LIBFT) -lft
INCLUDE	= -I $(LIBFT) -I include

CC		= clang
CFLAGS	= -Wall -Werror -Wextra
CDEBUG	= $(CFLAGS) -fsanitize=address -g -D PS_DEBUG=1

SRC		= push_swap.c \
			op_push.c \
			op_swap.c \
			op_rotate.c \
			op_reverse_rotate.c \
			parse_args.c \
			utils.c \
			stack.c \
			dlst.c

OBJ		= $(SRC:.c=.o)


.c.o:
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $(<:.c=.o)

$(NAME): $(OBJ)
	@ make -s -C $(LIBFT)
	@ $(CC) $(CFLAGS) $(OBJ) $(INCLUDE) $(LIBS) -o $(NAME)
	@ echo "Made $(value NAME)"

all: $(NAME)

debug:
	@ make -s -C $(LIBFT)
	@ $(CC) $(CDEBUG) $(SRC) $(INCLUDE) $(LIBS) -o $(NAME)
	@ echo "Made $(value NAME) for debug"

clean:
	@ make -s clean -C $(LIBFT)
	@ rm -rf $(OBJ)

fclean: clean
	@ make -s fclean -C $(LIBFT)
	@ rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re