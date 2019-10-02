#ifndef included_external_libs
    #include <stdio.h>
    #include <stdlib.h>
    #include <strings.h>

    #include <sys/types.h>
    #include <sys/socket.h>
    #include <netdb.h>

    #include <netinet/in.h>
    #include <netinet/tcp.h>
#endif

#ifndef included_global_variables
   #include "global_variables.h"
#endif /*included_global_variables*/

#ifndef included_constants
   #include "constants.h"
#endif /*included_constants*/

#ifndef included_functions_prototypes
   #include "function_prototypes.h"
#endif /*included_functions_prototypes*/


void forkAndLoopListThoTryToConnect(struct addrinfo *list_of_addresses_infos, int *socket_identificator){
    struct addrinfo *pointer_to_walk_along_address_infos;
    struct sockaddr_in *information_core;
    int OPTLEN = 1, UNCONNECTED_SOCKET = -1;

    for(pointer_to_walk_along_address_infos = list_of_addresses_infos; pointer_to_walk_along_address_infos != NULL; pointer_to_walk_along_address_infos = pointer_to_walk_along_address_infos->ai_next)
    {
        information_core = (struct sockaddr_in *) pointer_to_walk_along_address_infos->ai_addr;
        printf("------------------------\n");
        printf("Address: %s\n", formatAsIP(information_core));
        
        int socket_identificator = socket(pointer_to_walk_along_address_infos->ai_family, pointer_to_walk_along_address_infos->ai_socktype, IPPROTO_TCP);

        setsockopt(socket_identificator, IPPROTO_TCP, TCP_NODELAY, (const char *) &OPTLEN, sizeof(int));
        
        global_variable_to_get_socket_identificator_from_blocking_function_fork_and_loop_list_tho_try_to_connect = &socket_identificator;

        if(socket_identificator == UNCONNECTED_SOCKET)
            continue;
        if(connect(socket_identificator, pointer_to_walk_along_address_infos->ai_addr, pointer_to_walk_along_address_infos->ai_addrlen) != -1)
            break;
        close(socket_identificator);

    }

    if (pointer_to_walk_along_address_infos == NULL)
    {
        fprintf(stderr, "It was not possible to estabilish connection\n");
        exit(EXIT_FAILURE);
    }

    freeaddrinfo(list_of_addresses_infos);
}
