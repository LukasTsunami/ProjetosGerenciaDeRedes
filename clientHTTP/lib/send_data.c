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

#ifndef included_structures
   #include "structures.h"
#endif /*included_structures*/

#ifndef included_functions_prototypes
   #include "function_prototypes.h"
#endif /*included_functions_prototypes*/

void sendData(struct VariablesDTO variables, int socket_identificator, char (*buffer)[BUFFSIZ]){
    cleanBufferOfDestinationFile(buffer);

    int destination_file_identificator = open(variables.destination_file_to_save_response_from_request, O_WRONLY | O_APPEND | O_CREAT, FILE_PERMISSIONS);
    while( read(socket_identificator, buffer, calculateNewBufferSize() != 0))
    {
        write(destination_file_identificator, buffer, strlen(*buffer));
        cleanBufferOfDestinationFile(buffer);
    }
}
