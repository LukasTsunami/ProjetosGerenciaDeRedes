#ifndef included_external_libs
    #include <stdio.h>
#endif

#ifndef included_structures
   #include "structures.h"
#endif /*included_structures*/

#ifndef included_functions_prototypes
   #include "function_prototypes.h"
#endif /*included_functions_prototypes*/

int getSizeOfBodyParamsByVariable(struct VariablesDTO variables, int number_of_received_arguments){
  const int MININUM_BODY_PARAMS_LENGTH = 5;
  return checkIfThereAreBodyParams(number_of_received_arguments) ? sizeof(variables.body_params) : MININUM_BODY_PARAMS_LENGTH;
}
