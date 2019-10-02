#ifndef included_external_libs
    #include <stdio.h>
    #include <stdlib.h>
    #include <strings.h>

    #include <sys/types.h>
    #include <sys/socket.h>
    #include <netdb.h>
#endif

#ifndef included_constants
   #include "constants.h"
#endif /*included_constants*/

#ifndef included_functions_prototypes
   #include "function_prototypes.h"
#endif /*included_functions_prototypes*/

void eraseAllPreviousSocketData(struct addrinfo *socket_addr){
    const int which_byte_to_set_data=0;
    memset(socket_addr, which_byte_to_set_data, sizeof(struct addrinfo));
}