#include "Main.h"

int main(){
    
    SOCKET sockfd, accept_sock;
    WSADATA wsaData;
    SOCKADDR_IN serveraddr, clientaddr;

    if(WSAStartup(MAKEWORD(2,2), &wsaData) != 0)
        ErrorHandling("WSAStartup() Error");
    
    sockfd = socket(PF_INET, SOCK_STREAM, 0);

    if(sockfd == INVALID_SOCKET)
        ErrorHandling("socket() error");

    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
    serveraddr.sin_port = htons(PORT);

}