#ifndef included_external_libs
    #include <strings.h>
    #include <stdlib.h>
#endif

#ifndef included_structures
   #include "structures.h"
#endif /*included_structures*/

#ifndef included_functions_prototypes
   #include "function_prototypes.h"
#endif /*included_functions_prototypes*/

char* allocateMemoryForRequestMessage(struct VariablesDTO variables, char *data_to_send, int number_of_received_arguments){
    int size_of_body_params = getSizeOfBodyParamsByVariable(variables, number_of_received_arguments);
    return malloc(sizeof(char) * ((strlen(variables.html_file_path_and_filename)) + strlen(variables.port) + size_of_body_params + strlen(variables.hostname) + strlen(variables.http_method) + strlen("  HTTP/1.1\r\nHost: \r\nr\n")));
}