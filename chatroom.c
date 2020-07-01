#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#include "ThreadAPI.c"

#define PORT 8080 



pthread_t ptid[10];
int server_fd;  


int main(int argc, char const *argv[]) 
{ 
    
    struct sockaddr_in address; 
    int opt = 1; 
    int addrlen = sizeof(address); 
    
    //char *hello = "Hello from server"; 
       
    // Creating socket file descriptor 
    printf("Creating socket file\n");
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) 
    { 
        perror("socket failed"); 
        exit(EXIT_FAILURE); 
    } 
       
    // Forcefully attaching socket to the port 8080 
    printf("Attaching socket to the port 8080\n");
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, 
                                                  &opt, sizeof(opt))) 
    { 
        perror("setsockopt"); 
        exit(EXIT_FAILURE); 
    } 
    address.sin_family = AF_INET; 
    address.sin_addr.s_addr = INADDR_ANY; 
    address.sin_port = htons( PORT ); 
       
    // Forcefully attaching socket to the port 8080 
    if (bind(server_fd, (struct sockaddr *)&address,  
                                 sizeof(address))<0) 
    { 
        perror("bind socket to port 8080  failed\n"); 
        exit(EXIT_FAILURE); 
    } 
    printf("listening to a connection\n");
    if (listen(server_fd, 3) < 0) 
    { 
        perror("listen"); 
        exit(EXIT_FAILURE); 
    } 
    printf("Accepting a connection from client\n");
    while (1){
        user_obj* user= malloc(sizeof (user_obj));
        if ((user->new_socket = accept(server_fd, (struct sockaddr *)&address,  
                       (socklen_t*)&addrlen))<0) 
        { 
            perror("accept"); 
            exit(EXIT_FAILURE); 
        } 
        arrayOfUser[numOfUser]=user->new_socket;
        printf("Thread id %d is created\n",numOfUser); 
        pthread_create(&ptid[numOfUser++], NULL, &functionForlistening, user); 
    }
    printf("Client received\nClient address is %d\n",address.sin_addr.s_addr);
    while(1);
    return 0;
} 
