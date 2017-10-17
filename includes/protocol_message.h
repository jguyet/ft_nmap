/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protocol_message.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 21:38:45 by jguyet            #+#    #+#             */
/*   Updated: 2017/09/12 21:38:47 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOCOL_MESSAGE_H
# define PROTOCOL_MESSAGE_H

/*
** INTERNET PROTOCOL IP
*/
# define PROT_INTERNET_IPV4 AF_INET
# define PROT_INTERNET_IPV6 AF_INET6

/*
** Fluxs types
*/
# define BINARY_SOCK_FLUX   SOCK_STREAM
# define INTERNAL_SOCK_FLUX SOCK_RAW
# define SMALL_SOCK_FLUX	SOCK_DGRAM

/*
** SOCK PROTOCOL
*/
# ifndef IPPROTO_GRE
#  define IPPROTO_GRE	47
# endif

# define DEFAULT_PROTOCOL   0
# define ICMP_PROTOCOL      IPPROTO_ICMP
# define TCP_PROTOCOL       IPPROTO_TCP
# define UDP_PROTOCOL       IPPROTO_UDP
# define GRE_PROTOCOL       IPPROTO_GRE

/*
** setsockopt options :
*/
# define EPROTONOSUPPORT    93
# define EAFNOSUPPORT       97

# define SOL_TCP            6
# define SOL_IP             0

/*
** ICMP MESSAGE TYPES
*/
# define ICMP_ECHOREPLY		0	/* Echo Reply			    */
# define ICMP_DEST_UNREACH	3	/* Destination Unreachable	*/
# define ICMP_SOURCE_QUENCH	4	/* Source Quench			*/
# define ICMP_REDIRECT		5	/* Redirect (change route)	*/
# define ICMP_ECHO			8	/* Echo Request				*/
# define ICMP_TIME_EXCEEDED	11	/* Time Exceeded			*/
# define ICMP_PARAMETERPROB	12	/* Parameter Problem		*/
# define ICMP_TIMESTAMP		13	/* Timestamp Request		*/
# define ICMP_TIMESTAMPREPLY 14	/* Timestamp Reply			*/
# define ICMP_INFO_REQUEST	15	/* Information Request		*/
# define ICMP_INFO_REPLY	16	/* Information Reply		*/
# define ICMP_ADDRESS		17	/* Address Mask Request		*/
# define ICMP_ADDRESSREPLY	18	/* Address Mask Reply		*/
# define NR_ICMP_TYPES		18
/* UNREACH codes */
# define ICMP_UNREACH_NET	            0	/* bad net */
# define ICMP_UNREACH_HOST	            1	/* bad host */
# define ICMP_UNREACH_PROTOCOL	        2	/* bad protocol */
# define ICMP_UNREACH_PORT	            3	/* bad port */
# define ICMP_UNREACH_NEEDFRAG	        4	/* IP_DF caused drop */
# define ICMP_UNREACH_SRCFAIL	        5	/* src route failed */
# define ICMP_UNREACH_NET_UNKNOWN       6	/* unknown net */
# define ICMP_UNREACH_HOST_UNKNOWN      7	/* unknown host */
# define ICMP_UNREACH_ISOLATED	        8	/* src host isolated */
# define ICMP_UNREACH_NET_PROHIB	    9	/* net denied */
# define ICMP_UNREACH_HOST_PROHIB       10	/* host denied */
# define ICMP_UNREACH_TOSNET	        11	/* bad tos for net */
# define ICMP_UNREACH_TOSHOST	        12	/* bad tos for host */
# define ICMP_UNREACH_FILTER_PROHIB     13	/* admin prohib */
# define ICMP_UNREACH_HOST_PRECEDENCE   14	/* host prec vio. */
# define ICMP_UNREACH_PRECEDENCE_CUTOFF 15	/* prec cutoff */

# define ICMP_MINLEN		28

/*
** Changes the default value set by the TCP/IP service provider in the
** TTL field of the IP header in outgoing datagrams.
** IP_TTL support is not required;
** to check whether IP_TTL is supported,
** use getsockopt to get current options.
** If getsockopt fails, IP_TTL is not supported.
*/
# define TCP_IP_PACKET_HEADER_SERVICE IP_TTL

/*
** unsigned typedef
*/
typedef	unsigned char		u_char;
typedef	unsigned short		u_short;
typedef	unsigned int		u_int;
typedef	unsigned long		u_long;


#ifdef __unix__
	#if BYTE_ORDER == BIG_ENDIAN
		#define htons(n) (n)
	#else
		#define htons(n) (((((unsigned short)(n) & 0xFF)) << 8) | (((unsigned short)(n) & 0xFF00) >> 8))
	#endif
#endif

#define CKSUM(x) \
    (x = (x >> 16) + (x & 0xffff), (~(x + (x >> 16)) & 0xffff))

/*
** ICMP message HEADER
*/
struct icmphdr
{
	u_char					type;		/* message type		*/
	u_char					code;		/* type sub-code	*/
	u_short					checksum;	/* sum of msglength	*/
	union
	{
		struct
		{
			u_short			id;			/* current processid*/
			u_short			sequence;	/* sequence id		*/
		}					echo;		/* echo datagram	*/
		unsigned int		gateway;	/* gateway address	*/
	}						un;			/* union			*/
};

struct udphdr
{
	u_int16_t	source;
	u_int16_t	dest;
	u_int16_t	len;
	u_int16_t	check;
	u_int16_t	seq;
	u_int16_t	ttl;
	char		tv[16];
};

struct tcphdr
{
	u_int16_t source;
	u_int16_t dest;
	u_int32_t seq;
	u_int32_t ack_seq;
# if __BYTE_ORDER == __LITTLE_ENDIAN
	u_int16_t res1:4;
	u_int16_t doff:4;
	u_int16_t fin:1;
	u_int16_t syn:1;
	u_int16_t rst:1;
	u_int16_t psh:1;
	u_int16_t ack:1;
	u_int16_t urg:1;
	u_int16_t res2:2;
# elif __BYTE_ORDER == __BIG_ENDIAN
	u_int16_t doff:4;
	u_int16_t res1:4;
	u_int16_t res2:2;
	u_int16_t urg:1;
	u_int16_t ack:1;
	u_int16_t psh:1;
	u_int16_t rst:1;
	u_int16_t syn:1;
	u_int16_t fin:1;
# else
#  error "Adjust your <bits/endian.h> defines"
# endif
	u_int16_t window;
	u_int16_t check;
	u_int16_t urg_ptr;
};

struct pseudoheader
{
	u_int32_t				src;			/*source ip address 32bits*/
	u_int32_t				dst;			/*destination ip address 32bits*/
	u_char					zero;			/*0 8bits				*/
	u_char					protocol;       /* IP Protocol 8bits	*/
	u_int16_t				tcp_length;		/* total length 16bits  */
};

struct grehdr
{
    u_short                 flags;          /* 0x2001           */
    u_short                 proto;          /* dest port        */
    u_short                 length;         /*                  */
    u_short                 callid;         /* pid + sequenceId */
};

struct iphdr
{
# if BYTE_ORDER == LITTLE_ENDIAN
	u_char                  hl:4,			/* header length */
			                version:4;		/* version */
# endif
# if BYTE_ORDER == BIG_ENDIAN
	u_char                 	version:4,		/* version */
			                hl:4;			/* header length */
# endif
	u_char                  service;		/* type of service */
	u_short                 len;			/* total length */
	u_short                 pid;			/* identification */
	u_short                 off;			/* fragment offset field */
# define	                IP_DF 0x4000	/* dont fragment flag */
# define	                IP_MF 0x2000	/* more fragments flag */
	u_char                  ttl;			/* time to live */
	u_char                  protocol;		/* protocol */
	u_short                 checksum;		/* checksum */
	struct in_addr          src;		    /* source and dest address */
	struct in_addr          dest;	        /* source and dest address */
};

/*
** icmp message struct
*/
# define IPHDR_SIZE 		sizeof(struct iphdr)

typedef struct				s_message
{
//# ifdef __linux__
	struct iphdr			ip_header;
//# endif
	struct icmphdr			icmp_header;				/* header of message send 	*/
    struct udphdr           udp_header;
    struct tcphdr           tcp_header;
	struct pseudoheader		pseudoheader;
    struct grehdr           gre_header;
    void                    *data;
    int                     len;
    int                     packet_len;
    BOOLEAN                 (*serialize)();
	void                    (*tostring)();
}							t_message;

#endif
