#ifndef included_external_libs
    #include <stdio.h>
    #include <stdlib.h>
    #include <strings.h>

    #include <sys/types.h>
    #include <sys/socket.h>
    #include <netdb.h>
#endif

#ifndef included_structures
   #include "structures.h"
#endif /*included_structures*/

#ifndef included_functions_prototypes
   #include "function_prototypes.h"
#endif /*included_functions_prototypes*/

void estabilishDataToSend(int socket_identificator, struct VariablesDTO variables, int number_of_received_arguments){
    char *data_to_send = createRequestMessage(variables, data_to_send, number_of_received_arguments);
    
    //write on socket communication buffer
    write(socket_identificator, data_to_send, strlen(data_to_send));
}