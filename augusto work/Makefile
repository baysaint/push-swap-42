# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aude-la <aude-la@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/08 14:04:24 by aude-la           #+#    #+#              #
#    Updated: 2026/11/05 12:44:24 by aude-la          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC = utils_lists.c ft_printf.c csdiu.c utils_libft.c sa_sb_ss_pa_pb.c \
ra_rb_rr.c rra_rrb_rrr.c

OBJS = $(SRC:%.c=%.o)

CC = cc
CFLAGS = -Werror -Wall -Wextra
INC_DIR = .
CPPFLAGS = -I$(INC_DIR)
RM = rm -f

NAME = push_swap_lib.a


all: $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
