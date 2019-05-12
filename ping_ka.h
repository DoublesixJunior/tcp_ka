#ifndef __PING_KA_H__
#define __PING_KA_H__


#include <stdio.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <arpa/inet.h> 
#include <netdb.h> 
#include <unistd.h> 
#include <string.h> 
#include <stdlib.h> 
#include <netinet/ip_icmp.h> 
#include <time.h> 
#include <fcntl.h> 
#include <signal.h> 
#include <time.h>
#include <pthread.h>

// Define the Packet Constants 
// ping packet size 
#define PING_PKT_S 64 
   
// Automatic port number 
#define PORT_NO 0  
  
// Automatic port number 
#define PING_SLEEP_RATE 1000000

// Gives the timeout delay for receiving packets 
// in seconds 
#define RECV_TIMEOUT 1  

//
#define printerr(fmt,...) do { fprintf(stderr, fmt, ## __VA_ARGS__); fflush(stderr); return -1;} while(0)
  
// ping packet structure 
struct ping_pkt 
{ 
    struct icmphdr hdr; 
    char msg[PING_PKT_S-sizeof(struct icmphdr)]; 
}; 


typedef void (*taskentry)(void);

void intHandler(int dummy) ;
char *dns_lookup(char *addr_host, struct sockaddr_in *addr_con) ;
char* reverse_dns_lookup(char *ip_addr) ;
void send_ping(int ping_sockfd, struct sockaddr_in *ping_addr, char *ping_dom, char *ping_ip, char *rev_host) ;

unsigned int start_task( 
    unsigned char    *pucThreadName,
    unsigned short   priority,
    unsigned int     stackSize,
    unsigned int     option,
    taskentry        taskname,
    unsigned int     taskpara
);

#endif