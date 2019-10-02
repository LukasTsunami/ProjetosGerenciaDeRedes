#ifndef included_external_libs
    #include <sys/types.h>
    #include <sys/socket.h>
    #include <netdb.h>

    #include <arpa/inet.h>
    #include <netinet/in.h>
    #include <netinet/tcp.h>
#endif

char* formatAsIP(struct sockaddr_in *information_core){
  return inet_ntoa((struct in_addr) information_core->sin_addr);
}