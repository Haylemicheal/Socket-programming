#include <stdio.h>
#include "client.h"

 int main(int argc, char const *argv[])
{
   /* code */
   if (argc < 3) {
      fprintf(stderr,"usage %s hostname port\n", argv[0]);
      exit(0);
   }
   
   int portno = atoi(argv[2]);
   int sockfd = socket_(AF_INET, SOCK_STREAM, 0,portno);
   connect_(argv[1]);
   write_msg();
   read_msg();
   return 0;
}