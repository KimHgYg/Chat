#include "Socket.h"

class Socket{

    private:
        SOCKET sockfd, accept_sock;
        WSADATA wsaData;
        SOCKADDR_IN serveraddr, clientaddr;

    public:

    Socket(){
        if(init() != 0){
            cout << "init() error\n";
        }
    }

    ~Socket(){

    }

    int init(){
        int ret;

        //initialize socketaddr_in
        memset(&serveraddr, 0, sizeof(serveraddr));
        serveraddr.sin_family = AF_INET;
        serveraddr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
        serveraddr.sin_port = htons(PORT);

        ret = createServer_socket();

        return ret;
    }

    //Create Socket, listening socket / TCP
    int createServer_socket(){
        
        if(WSAStartup(MAKEWORD(2,2), &wsaData) != 0){
            cout << "WSAStartup() error\n";
            return -1;
        }
    
        if((sockfd = socket(PF_INET, SOCK_STREAM, 0))== INVALID_SOCKET){
            cout << "socket() error \n";
            return -2;
        }

        return 0;
    }
    
    int run_server(){
        int clientaddr_size;

        if(bind(sockfd, (SOCKADDR*)&serveraddr, sizeof(serveraddr)) == SOCKET_ERROR){
            cout << "bind() error\n";
            return -3;
        }

        if(listen(sockfd, QUEUE_SIZE) == SOCKET_ERROR){
            cout << "listen() error\n";
            return -4;
        }
        while(true){
            if((accept_sock = accept(sockfd, (SOCKADDR*)&clientaddr, &clientaddr_size))== INVALID_SOCKET){
                cout << "accept() error\n";
                return -5;
            }
        }

        return 0;
    }

    SOCKET get_server_socket(){
        return sockfd;
    }

    SOCKET get_listening_socket(){
        return accept_sock;
    }

};