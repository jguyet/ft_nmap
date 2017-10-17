/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nmap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 02:45:20 by jguyet            #+#    #+#             */
/*   Updated: 2017/05/24 02:50:31 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NMAP_H
# define FT_NMAP_H

# include <sys/time.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <stdlib.h>
# include <termios.h>
# include <stdio.h>
# include <fcntl.h>
# include <libft.h>
# include <printf.h>
# include <mapft.h>
# include <unistd.h>
# include <netdb.h>

# include "protocol_message.h"

typedef enum                e_proto_enum
{
	IP,
	ICMP,
	UDP,
	TCP,
	GRE,
	MAX_PROTO
}                           t_proto_enum;

# define MAX_PROTOCOLS MAX_PROTO

/*
** Flags
*/
typedef struct				s_flag
{
	BOOLEAN					actif;		/* is actif flag				*/
	char					*name;		/* name of flag					*/
	BOOLEAN					special;	/* has special arguments		*/
	char					*help;		/* text view on --help			*/
	char					*value;		/* arguments					*/
	int						type;		/* type of value				*/
	char					*error;		/* error message				*/
}							t_flag;

struct protocole
{
	t_proto_enum            e_name;
	char					*name;
	size_t                  len;
	int                     proto;
	int                     proto_sock_recv;
	void                    (*prepare_header)();
	void					(*serialize)();
	void                    (*deserialize)();
};

typedef struct				s_protocol_information
{
	int						pid;
	int						ttl;
	int						sequence;
	int						port;
	const struct protocole	*protocol;
	char					*source_ip;
	char					*dest_ip;
}							t_protocol_information;

typedef struct				s_recvfrom
{
	t_message				*message;
	struct sockaddr_in		from;
}							t_recvfrom;

typedef struct				s_scan
{
	BOOLEAN					syn;
	BOOLEAN					null;
	BOOLEAN					fin;
	BOOLEAN					xmas;
	BOOLEAN					ack;
	BOOLEAN					udp;
}							t_scan;

/*
** nmap struct
*/
typedef struct				s_nmap
{
	char					*shost;		/* string hostargs				*/
	int						port;		/* port of connection			*/
	int						sock;		/* socket Protocol			    */
	int                     sock_snd;   /* socket RAW sender            */
	struct sockaddr_in		*addr;		/* sockaddr of destination		*/
	char                    *source_ip;
	char                    *dest_ip;
	int						pid;		/* pid of current program		*/
	int						ttl;		/* time to live  				*/
	int						sequence;	/* sequence id  				*/
	int						received;	/* total received messages  	*/
	int						send;		/* total sended messages  		*/
	int						sweepminsize;
	struct timeval			timeout;	/* timeout						*/
	t_flag					**flags;	/* map of flags					*/
	BOOLEAN					(*launch)();/* pointer of function launch	*/
	const struct protocole	*protocol;
	t_message				*message;
	BOOLEAN					retry;
	int                     socket_type;
	int						*ports;
	int						speedup;
	t_scan					*scans;
}							t_nmap;

# define FLAGS_SIZE			5

# define F_PORT				nmap->flags[0]
# define F_IP				nmap->flags[1]
# define F_FILE				nmap->flags[2]
# define F_SPEEDUP			nmap->flags[3]
# define F_SCAN				nmap->flags[4]

# define MAX_PACKET_SIZE 65535

/*
** Socket connection
*/
BOOLEAN						initialize_socket_sender_connection(t_nmap *nmap);
BOOLEAN						initialize_socket_receiver_connection(t_nmap *nmap);
BOOLEAN						bind_socket_sender(t_nmap *nmap);
BOOLEAN						bind_socket_receiver(t_nmap *nmap);
BOOLEAN						set_on_socket_sender_options(t_nmap *nmap);
BOOLEAN			            set_on_socket_protocol_options(t_nmap *nmap);
BOOLEAN						socket_connection_is_estabilised(int fd);
BOOLEAN						bind_error(void);
BOOLEAN						set_socket_options_error(void);
BOOLEAN						send_message(t_nmap *nmap, t_message *message, t_protocol_information *pi);

/*
** flags manager
*/
BOOLEAN						load_flags(t_nmap *nmap, int argc, char **argv);
BOOLEAN						load_flag_list(t_nmap *nmap);
BOOLEAN						set_flags_values(t_nmap *nmap);
BOOLEAN						print_help(t_nmap *nmap);

int				   			*load_ports_flags(char *ports);
int							tab_length(int *tab);
void        				load_flag_scan(t_scan *scans, char *value);

/*
** nmap.c
*/
t_nmap						*singleton_nmap(void);
void						destruct_nmap(t_nmap *nmap);
BOOLEAN						process_nmaproute(t_nmap *nmap);
BOOLEAN						process_three_request(t_nmap *nmap);
BOOLEAN						sendto_message(t_nmap *nmap);

/*
** Messages
*/
t_message					*new_message(size_t size);
BOOLEAN						serialize_message(t_message *message, t_protocol_information *pi);
void						destruct_message(t_message *packet);
t_message					*deserialize_message(t_protocol_information *pi, void *ptr, int ptr_size);
void			            tostring(t_message *message);

/*
** Handler
*/
t_recvfrom					*handle_message(t_nmap *nmap, t_protocol_information *pi, int packet_size);
char                        *process_received_message(t_nmap *nmap, struct sockaddr_in *addr);

/*
** Utils
*/
unsigned short				checksum(void *b, int len);
long						get_current_time_millis();
char						*get_hostname_ipv4(struct in_addr *addr);
char						*get_hostname_ipv6(struct in6_addr *addr);
struct sockaddr_in			*get_sockaddr_in_ipv4(char *host);
char						*get_hostname_by_in_addr(const struct in_addr *addr);
const struct protocole    	*get_protocol(t_proto_enum e);
const struct protocole    	*get_protocol_by_name(char *name);
int                         get_count_of_host_ipv4(char *host, int ai_protocol);
struct	sockaddr_in	        **get_all_sockaddr_in_ipv4(char *host, int ai_protocol);

/*
** struct protocol information
*/
t_protocol_information		*new_protocol_information(void);
void						destruct_protocol_information(t_protocol_information *p);
void						protocol_information_set_dest_ip(t_protocol_information *p, char *ip);
void                    	protocol_information_set_source_ip(t_protocol_information *p, char *ip);
/*
** prococol headers
*/
void		                prepare_iphdr(t_message *message, t_protocol_information *pi);
void                        prepare_icmp_header(t_message *message, t_protocol_information *pi);
void		                prepare_udp_header(t_message *message, t_protocol_information *pi);
void		                prepare_tcp_header(t_message *message, t_protocol_information *pi);
void		                prepare_gre_header(t_message *message, t_protocol_information *pi);

void					    serialize_ip_header(t_message *message, t_protocol_information *pi);
void					    serialize_icmp_header(t_message *message, t_protocol_information *pi);
void					    serialize_udp_header(t_message *message, t_protocol_information *pi);
void					    serialize_tcp_header(t_message *message, t_protocol_information *pi);
void					    serialize_gre_header(t_message *message, t_protocol_information *pi);

void		                deserialize_icmp_header(t_message *message, t_protocol_information *pi);
void		                deserialize_udp_header(t_message *message, t_protocol_information *pi);
void		                deserialize_tcp_header(t_message *message, t_protocol_information *pi);
void		                deserialize_gre_header(t_message *message, t_protocol_information *pi);

void		                add_tcp_options(t_message *message, t_protocol_information *pi);

static const struct protocole protos[MAX_PROTOCOLS] = {
	{
		IP,
		"ip",
		sizeof(struct iphdr),
		DEFAULT_PROTOCOL,
		DEFAULT_PROTOCOL,
		prepare_iphdr,
		serialize_ip_header,
		NULL

	},
	{
		ICMP,
		"icmp",
		sizeof(struct icmphdr),
		ICMP_PROTOCOL,
		ICMP_PROTOCOL,
		prepare_icmp_header,
		serialize_icmp_header,
		deserialize_icmp_header
	},
	{
		UDP,
		"udp",
		sizeof(struct udphdr),
		UDP_PROTOCOL,
		ICMP_PROTOCOL,
		prepare_udp_header,
		serialize_udp_header,
		deserialize_udp_header
	},
	{
		TCP,
		"tcp",
		sizeof(struct tcphdr),
		TCP_PROTOCOL,
		ICMP_PROTOCOL,
		prepare_tcp_header,
		serialize_tcp_header,
		deserialize_tcp_header
	},
	{
		GRE,
		"gre",
		sizeof(struct grehdr),
		GRE_PROTOCOL,
		ICMP_PROTOCOL,
		prepare_gre_header,
		serialize_gre_header,
		deserialize_gre_header
	}
};

BOOLEAN					test_connection(t_nmap *nmap);

#endif
