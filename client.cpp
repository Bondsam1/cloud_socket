#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
int main(){
    
    //向服务器（特定的IP和端口）发起请求
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));  //每个字节都用0填充
    serv_addr.sin_family = AF_INET;  //使用IPv4地址
    serv_addr.sin_addr.s_addr = inet_addr("118.25.139.122");  //具体的IP地址
    serv_addr.sin_port = htons(39001);  //端口
    
   
    char bufSend[40]={0};
    char buffer[40]={0};

    while(1){
        //创建套接字
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
        printf("Input a sting : \n");
        scanf("%s",bufSend);
        write(sock,bufSend,strlen(bufSend));

        //读取服务器传回的数据
        read(sock, buffer, sizeof(buffer)-1);
       
        printf("Message form server: %s\n", buffer);
        memset(bufSend,0,40);
        memset(buffer,0,40);
        close(sock);
    }
    
   
    return 0;
}