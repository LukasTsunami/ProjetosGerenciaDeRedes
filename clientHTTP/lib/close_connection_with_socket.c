#ifndef included_external_libs
    #include <sys/types.h>
    #include <sys/socket.h>
    #include <netdb.h>
    #include <unistd.h>
#endif
 
void closeConnectionWithSocket(int socket_identificator){
    shutdown(socket_identificator, SHUT_RDWR);
    close(socket_identificator);
}