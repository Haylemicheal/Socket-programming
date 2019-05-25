#include <stdio.h>
#include "server.h"
int main(int argc, char const *argv[])
{
	/* code */
    int n;
    char buffer[256];
    bzero(buffer,256);
    int sockfd = socket_(AF_INET, SOCK_STREAM, 0,5001);
	bind_();
	listen_();
    int sock = accept_();
    
	return 0;
}