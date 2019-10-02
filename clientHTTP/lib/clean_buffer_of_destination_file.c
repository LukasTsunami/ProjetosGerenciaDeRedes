#include <strings.h>

#ifndef included_constants
    #include <constants.h>
#endif /*included_constants*/

void cleanBufferOfDestinationFile(char (*buffer)[BUFFSIZ]){
    bzero(buffer, BUFFSIZ);
}