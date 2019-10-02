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

int getAListOfAllAddressessInfos(struct VariablesDTO variables, struct addrinfo * address_info_configuration_model, struct addrinfo ** list_of_addresses_infos){    
    int answer_status_code = -1; 
    
    if( (answer_status_code = getaddrinfo(variables.hostname, variables.port, address_info_configuration_model, list_of_addresses_infos)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(answer_status_code));
    }

    return answer_status_code;
}