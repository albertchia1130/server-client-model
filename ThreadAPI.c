#include <pthread.h>

int valread;
int numOfUser=0;
int arrayOfUser[100];
typedef struct {
    int new_socket;
    char username[20];
}user_obj;
void EchoToAllUser(char buffer[]);

void* functionForlistening(void* arg) 
{
    user_obj* user_id = arg;
    printf("Enter thread\n");
    
    char buffer[1024]={0};
    while(1){
        //need to fix a big where if the client program exit,
        //the thread will loop indefinitely.
        valread = read( user_id->new_socket, buffer, 1024);
        EchoToAllUser(buffer);
        printf("user  :%s\n",buffer ); 
        bzero (buffer, sizeof(buffer));
        //send(new_socket , hello , strlen(hello) , 0 ); 
        //printf("Hello message sent\n");
    }        
}

void EchoToAllUser(char buffer[]){
  for(int i=0;i<numOfUser;i++){
    write(arrayOfUser[i], buffer, 1024);
  }



}

