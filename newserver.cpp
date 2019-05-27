#include<iostream>
#include<string.h>
#include "newserver.h"
using namespace std;
int main(int argc, char const *argv[])
{
	/* code */
    
    char bufer[256];
    Server newserve;
    newserve.socket_(AF_INET, SOCK_STREAM, 0,5001);
    
    newserve.read_msg();
    printf("Message: ");
    scanf("%s",bufer);
    newserve.write_msg(bufer,strlen(bufer));
    newserve.read_msg();
    printf("Message: ");
    scanf("%s",bufer);
    newserve.write_msg(bufer,strlen(bufer));
    newserve.read_msg();
    printf("Message: ");
    scanf("%s",bufer);
    newserve.write_msg(bufer,strlen(bufer));
	return 0;
}