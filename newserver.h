#include <cstdio>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

class Server{
public:
	int sockfd, newsockfd, portno;
	int read_var = 0,write_var=0;
	int n, pid,size_;
	char * input;
	char buffer[256];
	void accept_(){
		struct sockaddr_in  cli_addr;
		socklen_t clilen;
		
	    clilen = sizeof(cli_addr);
		newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
      
       if (newsockfd < 0) {
         perror("ERROR on accept");
         exit(1);
        }

	}
	void doprocessing(){
	   int pid = fork();
	   bzero(buffer,256);
	   if (pid < 0) {
	         perror("ERROR on fork");
	         exit(1);
	      }
	      
	      if (pid == 0) {
	         
	        close(sockfd);
	         if(read_var==1) {
	         n = read(newsockfd,buffer,255);
	         if (n < 0) {
	           perror("ERROR reading from socket");
	           exit(1);
	        }
	        printf("Here is the message: %s\n",buffer);

	        exit(0);
	         }
          else if(write_var==1) {
	            n = write(newsockfd,input,size_);
	            if (n < 0) {
	                perror("ERROR writing to socket");
	                exit(1);
	              }
	              exit(0);
	        }
	   
	      }
	      
        read_var = 0;
	    write_var = 0;
	  }
    void read_msg () {
	   read_var = 1;
	   doprocessing();
	   
	}
	    
    void write_msg (char * inp,int size) {
	   
	  write_var = 1;
	  input = inp;
	  size_ = size;
	  doprocessing();
	  
	}

	void listen_(){
	 listen(sockfd,5);

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

   void socket_(int family,int s_type,int protocol,int port){
		sockfd = socket(family,s_type, protocol);
		if (sockfd < 0) {
	      perror("ERROR opening socket");
	      exit(1);
	   }
	   portno = port;
	   bind_();
	   listen_();
	   accept_();
	   }

};

