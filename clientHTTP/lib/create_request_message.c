#ifndef included_external_libs
    #include <stdlib.h>
    #include <strings.h>
#endif

#ifndef included_constants
   #include "constants.h"
#endif /*included_constants*/

#ifndef included_functions_prototypes
   #include "function_prototypes.h"
#endif /*included_functions_prototypes*/

char* createRequestMessage(struct VariablesDTO variables, char *data_to_send, int number_of_received_arguments){ 
    data_to_send = allocateMemoryForRequestMessage(variables, data_to_send, number_of_received_arguments);
    
    if ( (strcmp(variables.http_method, "POST")==0) || (strcmp(variables.http_method, "PUT")==0) ) {
        strcpy(data_to_send, variables.http_method);
        strcat(data_to_send, " ");
        strcat(data_to_send, variables.html_file_path_and_filename);
        strcat(data_to_send, " HTTP/1.1\r\n");
        strcat(data_to_send, "Host: ");
        strcat(data_to_send, variables.hostname);
        strcat(data_to_send, "\r\n");
        strcat(data_to_send, "Content-Type: application/octet-stream\r\n");
        strcat(data_to_send, "Content-Length: ");
        char* content_length_string = malloc(sizeof(char) * (strlen(variables.body_params)) - 10);
        content_length_string = getContentLengthString(variables, content_length_string);
        
        strcat(data_to_send, (char *) content_length_string);
        strcat(data_to_send, "\r\n");
        strcat(data_to_send, "\r\n\n"); 
        strcat(data_to_send, variables.body_params);
        strcat(data_to_send, "\r\n"); 
    
    } else if ( (strcmp(variables.http_method, "GET")==0) || (strcmp(variables.http_method, "HEAD")==0) ){
        strcpy(data_to_send, variables.http_method);
        strcat(data_to_send, " ");
        strcat(data_to_send, variables.html_file_path_and_filename);
        strcat(data_to_send, " HTTP/1.1\r\n");
        strcat(data_to_send, "Host: ");
        strcat(data_to_send, variables.hostname);
        strcat(data_to_send, "\r\n\r\n"); 
    }
    printf("%s",data_to_send);
    return data_to_send;
}