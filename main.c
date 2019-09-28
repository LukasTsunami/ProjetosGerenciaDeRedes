#include "./libs.h"
#include "./constants.h"
#include "./functions.h"

void loopListTryingToConnect(struct addrinfo *list_of_addresses_infos, int *socket_identificator){
    struct addrinfo *pointer_to_walk_along_address_infos;
    struct sockaddr_in *information_core;
    int OPTLEN = 1, UNCONNECTED_SOCKET = -1;

    for(pointer_to_walk_along_address_infos = list_of_addresses_infos; pointer_to_walk_along_address_infos != NULL; pointer_to_walk_along_address_infos = pointer_to_walk_along_address_infos->ai_next)
    {
        information_core = (struct sockaddr_in *) pointer_to_walk_along_address_infos->ai_addr;
        printf("------------------------\n");
        printf("Address: %s\n", formatAsIP(information_core));
        
        int aux = socket(pointer_to_walk_along_address_infos->ai_family, pointer_to_walk_along_address_infos->ai_socktype, IPPROTO_TCP);
        
        socket_identificator = &aux;

        setsockopt(*socket_identificator, IPPROTO_TCP, TCP_NODELAY, (const char *) &OPTLEN, sizeof(int));
        
        if(*socket_identificator == UNCONNECTED_SOCKET)
            continue;
        if(connect(*socket_identificator, pointer_to_walk_along_address_infos->ai_addr, pointer_to_walk_along_address_infos->ai_addrlen) != -1)
            break;
        close(*socket_identificator);

    }

    if (pointer_to_walk_along_address_infos == NULL)
    {
        fprintf(stderr, "It was not possible to estabilish connection\n");
        exit(EXIT_FAILURE);
    }

    freeaddrinfo(list_of_addresses_infos);
}

int main(int argc, char *argv[])
{ 
    int socket_identificator, destination_file_identificator, number_of_received_arguments=argc, answer_status_code;
    const int THROWS_ERROR_CODE=1, PROGRAM_SUCCESSFULL_EXECUTED_CODE=0;
    char buffer[BUFFSIZ],*data_to_send;
    struct addrinfo address_info_configuration_model;
    struct addrinfo *list_of_addresses_infos;
    
    validatesIfTheQuantityOfArgumentsPassedIsValid(number_of_received_arguments);
    
    struct VariablesDTO variables = mapArgumentsToVariables(argv);

    configureSocket(&address_info_configuration_model);

    getAListOfAllAddressessInfos(variables.hostname, variables.port, &address_info_configuration_model, &list_of_addresses_infos);
    
    loopListTryingToConnect(list_of_addresses_infos, &socket_identificator);

    data_to_send = estabilishDataToSend(variables.http_method, data_to_send, variables.hostname, variables.html_file_path_and_filename);
    write(socket_identificator, data_to_send, strlen(data_to_send));
    bzero(buffer, BUFFSIZ);
    destination_file_identificator = open(variables.destination_file_to_save_response_from_request, O_WRONLY | O_APPEND | O_CREAT, FILE_PERMISSIONS);

    while( read(socket_identificator, buffer, calculateNewBufferSize() != 0))
    {
        write(destination_file_identificator, buffer, strlen(buffer));
        bzero(buffer, BUFFSIZ);
    }

    shutdown(socket_identificator, SHUT_RDWR);
    close(socket_identificator);
    
	return(PROGRAM_SUCCESSFULL_EXECUTED_CODE);
}
