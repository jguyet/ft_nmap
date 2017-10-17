# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/25 15:18:38 by jguyet            #+#    #+#              #
#    Updated: 2017/03/19 04:49:16 by jguyet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

NAMEBASE    =   $(shell basename $(NAME) .a)

LENGTHNAME	=	`printf "%s" $(NAMEBASE) | wc -c`

MAX_COLS	=	$$(echo "$$(tput cols)-21-$(LENGTHNAME)"|bc)

CC			=	gcc

FLAGS		=	-Wall -Wextra -Werror

SRCDIR		=	srcs/

OBJDIR		=	.objs/

INCDIR		=	includes/

SRCBASE		=	\
				part1/ft_atoi.c								\
				part1/ft_bzero.c							\
				part1/ft_isalnum.c							\
				part1/ft_isalpha.c							\
				part1/ft_isascii.c							\
				part1/ft_isdigit.c							\
				part1/ft_isprint.c							\
				part1/ft_memccpy.c							\
				part1/ft_memchr.c							\
				part1/ft_memcmp.c							\
				part1/ft_memcpy.c							\
				part1/ft_memmove.c							\
				part1/ft_memset.c							\
				part1/ft_strcat.c							\
				part1/ft_strchr.c							\
				part1/ft_strcmp.c							\
				part1/ft_strcpy.c							\
				part1/ft_strdup.c							\
				part1/ft_strlcat.c							\
				part1/ft_strlen.c							\
				part1/ft_strncat.c							\
				part1/ft_strncmp.c							\
				part1/ft_strncpy.c							\
				part1/ft_strnstr.c							\
				part1/ft_strrchr.c							\
				part1/ft_strstr.c							\
				part1/ft_tolower.c							\
				part1/ft_toupper.c							\
				part2/ft_itoa.c								\
				part2/ft_memalloc.c							\
				part2/ft_memdel.c							\
				part2/ft_putchar.c							\
				part2/ft_putchar_fd.c						\
				part2/ft_putendl.c							\
				part2/ft_putendl_fd.c						\
				part2/ft_putnbr.c							\
				part2/ft_putnbr_fd.c						\
				part2/ft_putstr.c							\
				part2/ft_putstr_fd.c						\
				part2/ft_strclr.c							\
				part2/ft_strdel.c							\
				part2/ft_strequ.c							\
				part2/ft_striter.c							\
				part2/ft_striteri.c							\
				part2/ft_strjoin.c							\
				part2/ft_strmap.c							\
				part2/ft_strmapi.c							\
				part2/ft_strnequ.c							\
				part2/ft_strnew.c							\
				part2/ft_strsplit.c							\
				part2/ft_strsub.c							\
				part2/ft_strtrim.c							\
				bonus/ft_lstadd.c							\
				bonus/ft_lstdel.c							\
				bonus/ft_lstdelone.c						\
				bonus/ft_lstiter.c							\
				bonus/ft_lstmap.c							\
				bonus/ft_lstnew.c							\
				array/ft_qsort.c							\
				array/array_length.c						\
				array/free_array.c							\
				utils/ft_sleep.c							\
				list/ft_lstaddend.c							\
				list/ft_lstsplit.c							\
				list/ft_putlst.c							\
				int/ft_add_end_int.c						\
				int/ft_itoabase.c							\
				int/ft_atoi_base.c							\
				int/ft_litoa.c								\
				int/ft_nbrlen.c								\
				int/ft_convert_double_to_string.c			\
				int/ft_max.c								\
				uint/ft_uitoabase.c							\
				uint/ft_uitoa.c								\
				string/ft_count_char.c						\
				string/ft_lenbychar.c						\
				string/ft_strnchr.c							\
				string/ft_strndup.c							\
				string/ft_strtrim_n.c						\
				string/ft_strtrim_string.c					\
				string/ft_outstring.c						\
				string/ft_dstrjoin.c						\
				string/ft_dstrjoin_char.c					\
				string/ft_split_string.c					\
				string/ft_replace.c							\
				string/ft_strdelandnew.c					\
				string/ft_is_string_printable.c				\
				string/ft_is_string_numeric.c				\
				string/ft_strcontains.c 					\
				printf/add/add_char.c						\
				printf/add/add_int.c						\
				printf/add/add_long.c						\
				printf/add/add_space.c						\
				printf/add/add_string.c						\
				printf/add/add_wchar.c						\
				printf/add/add_zero.c						\
				printf/add/add_conv_string.c				\
				printf/conversions/c.c						\
				printf/conversions/d.c						\
				printf/conversions/o.c						\
				printf/conversions/percent.c				\
				printf/conversions/s.c						\
				printf/conversions/p.c						\
				printf/conversions/u.c						\
				printf/conversions/x.c						\
				printf/conversions/f.c						\
				printf/flags/h.c							\
				printf/flags/hh.c							\
				printf/flags/l.c							\
				printf/flags/ll.c							\
				printf/flags/j.c							\
				printf/flags/z.c							\
				printf/flags/int.c							\
				printf/get/get_char.c						\
				printf/get/get_int.c						\
				printf/get/get_long.c						\
				printf/get/get_float.c						\
				printf/get/get_string.c						\
				printf/sub_flags/sub_flags.c				\
				printf/sub_flags/sub_flags_suite.c			\
				printf/precision/precision.c				\
				printf/precision/precision_left.c			\
				printf/handler.c							\
				printf/ft_printf.c							\
				printf/load_ptr_conv.c						\
				printf/get/get_ptr_function.c				\
				printf/precision/precision_right.c			\
				printf/precision/base/eight.c				\
				printf/precision/base/ten.c					\
				printf/precision/base/sixteen.c				\
				printf/colors/colors.c						\
				map/hashmap.c								\
				map/hashmap_functions.c

SRCS		=	$(addprefix $(SRCDIR), $(SRCBASE))

OBJS		=	$(addprefix $(OBJDIR), $(SRCBASE:.c=.o))

.SILENT:

all:
	if test -f $(NAME) ; then												\
		echo "make: Nothing to be done for \`all\`.";						\
	else																	\
		$(MAKE) -j $(NAME);													\
	fi
$(NAME):	$(OBJDIR) $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)
	echo "MAKE    [$(NAMEBASE)]"

$(OBJDIR):
	mkdir -p $(OBJDIR)
	mkdir -p $(dir $(OBJS))

$(OBJDIR)%.o : $(SRCDIR)%.c | $(OBJDIR)
	$(CC) $(FLAGS) -MMD -c $< -o $@											\
		-I $(INCDIR)
	printf "\r\033[38;5;117m%s\033[38;5;092m%*.*s\033[0m\033[K"							\
	"MAKE    "$(NAMEBASE)" plz wait ..."									\
		$(MAX_COLS) $(MAX_COLS) "[$(@)]"

clean:
	echo -en "\r\033[38;5;101mCLEAN  "										\
		"[\033[0m$(NAMEBASE)\033[38;5;101m]\033[K";							\
	rm -rf $(OBJDIR)

fclean:
	echo -en "\r\033[38;5;124mFCLEAN "										\
		"[\033[0m$(NAMEBASE)\033[38;5;124m]\033[K";							\
	rm -rf $(NAME)
	rm -rf $(OBJDIR)

re:			fclean all

.PHONY:		fclean clean re

-include $(OBJS:.o=.d)

.PHONY: all clean fclean re
