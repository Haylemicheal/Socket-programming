
#include <cstdio>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

class Client{
public:
   int sockfd, portno,n;
   char buffer[256];
   int socket_(int family,int s_type,int protocol,int port){
     
      /* Create a socket point */
      sockfd = socket(family, s_type, 0);
      
      if (sockfd < 0) {
         perror("ERROR opening socket");
         exit(1);
      }
    portno = port;
      
    return sockfd;
   }

   void connect_(char const * argv){
   	struct sockaddr_in serv_addr;
   	struct hostent *server;
   	server = gethostbyname(argv);
      
      if (server == NULL) {
         fprintf(stderr,"ERROR, no such host\n");
         exit(0);
      }
       bzero((char *) &serv_addr, sizeof(serv_addr));
      serv_addr.sin_family = AF_INET;

      bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
      serv_addr.sin_port = htons(portno);
      
      /* Now connect to the server */
      if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
         perror("ERROR connecting");
         exit(1);
      }
      
   }
   void write_msg(char * bufer){
   	 //printf("Please enter the message: ");
      //bzero(buffer,256);
      //fgets(buffer,255,stdin);
      
      /* Send message to the server */
      n = write(sockfd, bufer, strlen(bufer));
      
      if (n < 0) {
         perror("ERROR writing to socket");
         exit(1);
      }
      
   }
   void read_msg(){
   	/* Now read server response */
      bzero(buffer,256);
      n = read(sockfd, buffer, 255);
      
      if (n < 0) {
         perror("ERROR reading from socket");
         exit(1);
      }
      
      printf("%s \n",buffer);
      
   }
};

