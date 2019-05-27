#include<iostream>
#include "newclient.h"
int main(int argc, char const *argv[])
{
   /* code */
   if (argc < 3) {
      fprintf(stderr,"usage %s hostname port\n", argv[0]);
      exit(0);
   }
   
   int portno = atoi(argv[2]);
   Client newclient;
   char bufer[256];

    newclient.socket_(AF_INET, SOCK_STREAM, 0,portno);
   
    newclient.connect_(argv[1]);
    newclient.read_msg();
    printf("Message: ");
    scanf("%s",bufer);
    newclient.write_msg(bufer);
    newclient.read_msg();
    printf("Message: ");
    scanf("%s",bufer);
    newclient.write_msg(bufer);
    newclient.read_msg();
    printf("Message: ");
    scanf("%s",bufer);
    newclient.write_msg(bufer);
   
    
    
   return 0;
}