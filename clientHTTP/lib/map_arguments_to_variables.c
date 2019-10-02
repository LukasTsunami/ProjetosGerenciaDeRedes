#ifndef included_external_libs
    #include <stdio.h>
    #include <stdlib.h>
    #include <strings.h>
#endif

#ifndef included_structures
   #include "structures.h"
#endif /*included_structures*/

#ifndef included_functions_prototypes
   #include "function_prototypes.h"
#endif /*included_functions_prototypes*/

struct VariablesDTO mapArgumentsToVariables(char *arguments[], int number_of_received_arguments){ 
  char *current_executable = (char*) malloc(sizeof(char) * sizeof(arguments[0]));
  char *http_method = (char*) malloc(sizeof(char) * sizeof(arguments[1]));
  char *hostname = (char*) malloc(sizeof(char) * sizeof(arguments[2]));
  char *port = (char*) malloc(sizeof(char) * sizeof(arguments[3]));
  char *html_file_path_and_filename = (char*) malloc(sizeof(char) * sizeof(arguments[4]));
  char *destination_file_to_save_response_from_request = (char*) malloc(sizeof(char) * sizeof(arguments[5]));

  const int size_of_body_params = getSizeOfBodyParams(arguments, number_of_received_arguments);
  char *body_params = (char*) malloc(sizeof(char) * size_of_body_params);    
  current_executable = copyDynamicString(current_executable, arguments[0]);
  http_method = copyDynamicString(http_method, arguments[1]);
  hostname = copyDynamicString(hostname, arguments[2]);
  port = copyDynamicString(port, arguments[3]);
  html_file_path_and_filename = copyDynamicString(html_file_path_and_filename, arguments[4]);
  destination_file_to_save_response_from_request = copyDynamicString(destination_file_to_save_response_from_request, arguments[5]);
  body_params = checkIfThereAreBodyParams(number_of_received_arguments) ? copyDynamicString(body_params, arguments[6]) : "";

  struct VariablesDTO dto = { 
    current_executable,
    http_method,
    hostname,
    port,
    html_file_path_and_filename,
    destination_file_to_save_response_from_request,
    body_params
  };

  return dto;
}