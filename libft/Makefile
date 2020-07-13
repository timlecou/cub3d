# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: timlecou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/21 13:17:02 by timlecou          #+#    #+#              #
#    Updated: 2020/06/16 17:00:43 by timlecou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c\
	ft_isdigit.c ft_isprint.c ft_itoa.c ft_memccpy.c ft_memchr.c ft_memcmp.c\
	ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c\
	ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c\
	ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c\
	ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c\
	ft_tolower.c ft_toupper.c ft_strndup.c ft_lstsize.c ft_lstadd_front.c\
	ft_lstadd_back.c ft_lstnew.c ft_lstlast.c ft_lstdelone.c ft_lstclear.c\
	ft_lstiter.c ft_lstmap.c pf_fill_op.c pf_ft_print_c.c pf_ft_print_d.c\
	pf_ft_print_p.c pf_ft_print_per.c pf_ft_print_s.c pf_ft_print_u.c\
	pf_ft_print_x.c pf_print_conversion.c pf_utilities_1.c pf_utilities_2.c\
	pf_utilities_3.c pf_utilities_p.c pf_utilities_u.c pf_utilities_x.c\
	ft_printf.c ft_strcmp.c

OBJ = $(SRCS:.c=.o)

FLAGS = -Werror -Wall -Wextra

%.o: %.c
	gcc -c $(FLAGS) $< -o $@

all : $(OBJ)
	gcc -c $(SRCS) $(FLAGS)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(NAME) : $(OBJ)
	gcc -c $(SRCS) $(FLAGS)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
