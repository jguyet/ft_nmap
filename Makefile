# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/25 15:18:38 by jguyet            #+#    #+#              #
#    Updated: 2017/03/19 04:47:40 by jguyet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

STUDENT		=	jguyet

PROG1		=	ft_nmap

NAMEBASE    =   $(shell basename $(PROG1) .a)

LENGTHNAME	=	`printf "%s" $(NAMEBASE) | wc -c`

MAX_COLS	=	$$(echo "$$(tput cols)-21-$(LENGTHNAME)"|bc)

CC			=	gcc

FLAGS		=	-Wall -Wextra -Werror -ggdb -lpthread

SRCDIR		=

OBJDIR		=	.objs/

INCDIR		=	includes/

LIBFTDIR	=	libft/

INCDIRLIBFT	=	$(LIBFTDIR)/includes/

SRCSPROG1	=	\
				srcs/main.c																	\
				srcs/runnable.c																\
				srcs/test_connection.c														\
				srcs/flags/flags.c															\
				srcs/flags/set_flags_values.c												\
				srcs/flags/flag_ports.c														\
				srcs/flags/flag_scan.c														\
				srcs/utils/get_str_inet_addr.c												\
				srcs/nmap.c																	\
				srcs/utils/check_os.c														\
				srcs/utils/get_current_time_millis.c										\
				srcs/utils/get_protocol.c													\
				srcs/network/protocols/utils/sum.c											\
				srcs/network/socket_protocol_handler.c										\
				srcs/network/socket_receiver.c												\
				srcs/network/socket_sender.c												\
				srcs/network/protocols/protocol_message.c									\
				srcs/network/protocols/protocol_information.c								\
				srcs/network/protocols/headers/ip_protocol_header.c							\
				srcs/network/protocols/headers/icmp_protocol_header.c						\
				srcs/network/protocols/headers/tcp_protocol_header.c						\
				srcs/network/protocols/headers/udp_protocol_header.c						\
				srcs/network/protocols/headers/gre_protocol_header.c						\

DSRCSPROG1	=	$(addprefix $(SRCDIR), $(SRCSPROG1))

OBJSPROG1	=	$(addprefix $(OBJDIR), $(DSRCSPROG1:.c=.o))

.SILENT:

all:
	if test -f $(PROG1) ; then																\
		echo "make: Nothing to be done for \`all\`.";										\
	else																					\
		$(MAKE) -j $(STUDENT);																\
	fi

$(STUDENT):
	make -C $(LIBFTDIR)
	$(MAKE) $(PROG1)

$(PROG1):	$(OBJDIR) $(OBJSPROG1)
	$(CC) $(FLAGS) -o $(PROG1) $(OBJSPROG1) -L $(LIBFTDIR) -lftprintf
	echo "MAKE    [$(PROG1)]"
	echo "\033[38;5;227mAUTHOR  :\033[0m"
	cat auteur

$(OBJDIR):
	mkdir -p $(OBJDIR)
	mkdir -p $(dir $(OBJSPROG1))

$(OBJDIR)%.o : $(SRCDIR)%.c | $(OBJDIR)
	$(CC) $(FLAGS) -MMD -c $< -o $@															\
		-I $(INCDIR) -I $(INCDIRLIBFT)
	printf "\r\033[38;5;117m%s\033[38;5;092m%*.*s\033[0m\033[K"								\
	"MAKE    "$(NAMEBASE)" plz wait ..."	$(MAX_COLS)	$(MAX_COLS)	"[$(@)]"

clean:
	echo -en "\r\033[38;5;101mCLEAN  "														\
		"[\033[0m$(NAMEBASE)\033[38;5;101m]\033[K\033[0m";									\
	rm -rf $(OBJDIR)
	make -C $(LIBFTDIR) clean

fclean:
	echo -en "\r\033[38;5;124mFCLEAN "														\
		"[\033[0m$(NAMEBASE)\033[38;5;124m]\033[K\033[0m";									\
	rm -rf $(PROG1)
	rm -rf $(OBJDIR)
	make -C $(LIBFTDIR) fclean

re:			fclean all

.PHONY: all clean fclean re
