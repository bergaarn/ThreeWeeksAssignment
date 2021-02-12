#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <arpa/inet.h>

using namespace std;

int main()
{
    int socketID;
    int portNo = 1700;
    struct sockaddr_in serverAddr;
    char buffer[256];

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(portNo);
    inet_aton("13.53.76.30", (struct in_addr*) &serverAddr.sin_addr.s_addr);

    socketID = socket(AF_INET, SOCK_STREAM, 0);
    connect(socketID, (struct sockaddr*) &serverAddr, sizeof(serverAddr));
    recv(socketID, buffer, 256, 0);
    cout << buffer << endl;
    close(socketID);
    
    return 0;
}