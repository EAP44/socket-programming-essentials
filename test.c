#include <stdio.h>
// #include <string>
#include <stdlib.h>
#include <unistd.h>
#include <Sys/socket.h>


int main (){
    int ss ,cs;
    struct  sockaddr_in sa;
    char msg[255];

    ss = socket(AF_INIET,SOCK_STREAM,0);
    if (SS <0){
        perror('error socket!!!!')
    }

    sa.sin_family = AF_INET;
    sa.sin_port = 3000;
    sa.sin_saddr = INADDR_ANY; 

    bind(ss,(struct socketaddr*)& sa,sizeof(sa));

    listen(ss,5);

    cs = accept(ss,0,0);

    while(1){

    }


    
}