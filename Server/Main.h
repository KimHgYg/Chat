#ifndef SERVER_MAIN_H
#define SERVER_MAIN_H

#include<iostream>
#include<winSock2.h>
#include<stdlib.h>
#include<string.h>
#include<stdexcept>

#include<thread>
#include<chrono>

using namespace std;

#define IP "127.0.0.1"
#define PORT 9000

#define BUF_SIZE 4096
#define QUEUE_SIZE 10


void ErrorHandling(string message);

#endif