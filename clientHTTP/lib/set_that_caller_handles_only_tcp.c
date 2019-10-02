#ifndef included_external_libs
    #include <sys/types.h>
    #include <sys/socket.h>
    #include <netdb.h>
#endif

#ifndef included_constants
   #include "constants.h"
#endif /*included_constants*/

void setThatCallerHandlesOnlyTCP(struct addrinfo *socket_addr){
    socket_addr->ai_socktype = SOCK_STREAM;
} 