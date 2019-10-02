#ifndef included_external_libs
    #include <strings.h>

    #include <sys/types.h>
    #include <sys/socket.h>
    #include <netdb.h>
#endif

void setIfFamilyAddressIsIpv4OrIpv6(struct addrinfo *socket_addr, char protocol[]){
    if(strcmp(protocol,"IPV4")==0){
        socket_addr->ai_family = AF_INET;
        return;
    }

    if(strcmp(protocol,"IPV6")==0){
        socket_addr->ai_family = AF_INET6;
        return;
    }

    if(strcmp(protocol,"BOTH")==0){
        socket_addr->ai_family = AF_UNSPEC;
        return;
    }

    socket_addr->ai_family = AF_UNSPEC;
}