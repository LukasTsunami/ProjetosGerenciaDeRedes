#ifndef included_external_libs
    #include <stdio.h>
    #include <stdlib.h>
    #include <strings.h>
#endif

char* copyDynamicString(char* output_str, char* input_str){
    output_str = malloc(sizeof(char) * strlen(input_str));
    if (output_str == NULL) {
        printf("Not enough memory to copy dynamic string");
        const int generic_error_code = 1;
        exit(generic_error_code);
    }
    strcpy(output_str, input_str);
    return output_str;
}
