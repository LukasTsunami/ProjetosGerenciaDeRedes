#ifndef included_external_libs
    #include <strings.h>
#endif

#ifndef included_structures
   #include "structures.h"
#endif /*included_structures*/

#ifndef included_functions_prototypes
   #include "function_prototypes.h"
#endif /*included_functions_prototypes*/


char* getContentLengthString(struct VariablesDTO variables, char *content_length_string){
    content_length_string = strcatInteger(strlen(variables.body_params) + 2, content_length_string, 10);
    return content_length_string;
}