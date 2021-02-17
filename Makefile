# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: nicky <nicky@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2021/02/16 10:24:22 by nicky         #+#    #+#                  #
#    Updated: 2021/02/16 10:26:53 by nicky         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
OBJ_FILES = ft_printf.o \
			print_char.o \
			print_int.o \
			print_plus_minus.o \
			print_x.o \
			parser.o \
			puts.o \
			get_len.o \



HEADER_FILE = ft_printf.h
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a
cc = gcc

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ_FILES)
	cp $< $@
	ar -crs $@ $(OBJ_FILES)

%.o: %.c $(HEADER_FILE)
	$(CC) -c $(CFLAGS) -o $@ $<

$(LIBFT):
	make -C libft

clean:
	make fclean -C libft
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(LIBFT)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re