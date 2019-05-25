#include <stdio.h>
#include <stdlib.h>

#include <netdb.h>
#include <netinet/in.h>

#include <string.h>


void doprocessing (int sock);
int n, pid;
int sockfd, newsockfd, portno, clilen;


int socket_(int family,int s_type,int protocol,int port){
	sockfd = socket(family,s_type, protocol);
	if (sockfd < 0) {
      perror("ERROR opening socket");
      exit(1);
   }
   portno = port;
   return sockfd;
   }

 void bind_(){
 	struct sockaddr_in serv_addr;
 	bzero((char *) &serv_addr, sizeof(serv_addr));
   serv_addr.sin_family = AF_INET;
   serv_addr.sin_addr.s_addr = INADDR_ANY;
   serv_addr.sin_port = htons(portno);
 	if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
      perror("ERROR on binding");
      exit(1);
   }


 }
 void listen_(){
 listen(sockfd,5);

}

int accept_(){
	struct sockaddr_in  cli_addr;
    clilen = sizeof(cli_addr);
	newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
      
      if (newsockfd < 0) {
         perror("ERROR on accept");
         exit(1);
      }
      
      /* Create child process */
      pid = fork();
      
      if (pid < 0) {
         perror("ERROR on fork");
         exit(1);
      }
      
      if (pid == 0) {
         /* This is the client process */
         close(sockfd);
         doprocessing (newsockfd);
         exit(0);
      }
      else {
         close(newsockfd);
      }
     return newsockfd;
}

void doprocessing (int sock) {
   int n;
   char buffer[256];
   bzero(buffer,256);
   n = read(sock,buffer,255);
   
   if (n < 0) {
      perror("ERROR reading from socket");
      exit(1);
   }
    printf("Here is the message: %s\n",buffer);
    n = write(sock,"I got your message",18);
   if (n < 0) {
      perror("ERROR writing to socket");
      exit(1);
   }
   //send_msg (sock,char * msg)
}
void send_msg (int sock,char * msg) {
	
	printf("Enter the message");
    scanf("%s",msg);
   n = write(sock,msg,18);
   
   if (n < 0) {
      perror("ERROR writing to socket");
      exit(1);
   }
   
}
