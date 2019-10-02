#ifndef included_external_libs
    #include <sys/types.h>
    #include <sys/socket.h>
    #include <netdb.h>
#endif
 
#ifndef included_functions_prototypes
   #include "function_prototypes.h"
#endif /*included_functions_prototypes*/

void configureSocket(struct addrinfo *address_info_configuration_model){
    const int ACCEPT_ANY_PROTOCOL=0;
    const int NO_EXTRA_BEHAVIORS=0;

    eraseAllPreviousSocketData(address_info_configuration_model);
    setIfFamilyAddressIsIpv4OrIpv6(address_info_configuration_model, "BOTH");
	setThatCallerHandlesOnlyTCP(address_info_configuration_model);
    address_info_configuration_model->ai_flags = NO_EXTRA_BEHAVIORS;
    address_info_configuration_model->ai_protocol = ACCEPT_ANY_PROTOCOL;
}