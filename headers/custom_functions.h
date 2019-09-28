#include "./constants.h"
#include "./global_variables.h"
#include "./structures.h"
 
char* allocateMemoryForRequestMessage(char* http_method, char *data_to_send, char* hostname, char *html_file_path_and_filename_on_host);
int calculateNewBufferSize();
void cleanBufferOfDestinationFile(char (*buffer)[BUFFSIZ]);
void closeConnection(int socket_identificator);
void configureSocket(struct addrinfo *address_info_configuration_model);
char* copyDynamicString(char* output_str, char* input_str);
char* createRequestMessage(char* http_method, char *data_to_send, char* hostname, char *html_file_path_and_filename_on_host);
void eraseAllPreviousSocketData(struct addrinfo *socket_addr);
void estabilishDataToSend(int socket_identificator, struct VariablesDTO variables);
void forkAndLoopListThoTryToConnect(struct addrinfo *list_of_addresses_infos, int *socket_identificator);
char* formatAsIP(struct sockaddr_in *information_core);
struct VariablesDTO mapArgumentsToVariables(char *arguments[]);
void sendData(struct VariablesDTO variables, int socket_identificator, char (*buffer)[BUFFSIZ]);
void setIfFamilyAddressIsIpv4OrIpv6(struct addrinfo *socket_addr, char protocol[]);
void setThatCallerHandlesOnlyTCP(struct addrinfo *socket_addr);
void validatesIfTheQuantityOfArgumentsPassedIsValid(int how_many_parameters_were_passed);
int getAListOfAllAddressessInfos(struct VariablesDTO variables, struct addrinfo * address_info_configuration_model, struct addrinfo ** list_of_addresses_infos);

char* allocateMemoryForRequestMessage(char* http_method, char *data_to_send, char* hostname, char *html_file_path_and_filename_on_host){
    return malloc(sizeof(char) * ((strlen(html_file_path_and_filename_on_host)) + strlen(hostname) + strlen(http_method) + strlen("  HTTP/1.1\r\nHost: \r\nr\n")));
}

int calculateNewBufferSize(){
    return BUFFSIZ - 1;
}

void cleanBufferOfDestinationFile(char (*buffer)[BUFFSIZ]){
    bzero(buffer, BUFFSIZ);
}

void closeConnection(int socket_identificator){
    shutdown(socket_identificator, SHUT_RDWR);
    close(socket_identificator);
}

void configureSocket(struct addrinfo *address_info_configuration_model){
    const int ACCEPT_ANY_PROTOCOL=0;
    const int NO_EXTRA_BEHAVIORS=0;

    eraseAllPreviousSocketData(address_info_configuration_model);
    setIfFamilyAddressIsIpv4OrIpv6(address_info_configuration_model, "BOTH");
	setThatCallerHandlesOnlyTCP(address_info_configuration_model);
    address_info_configuration_model->ai_flags = NO_EXTRA_BEHAVIORS;
    address_info_configuration_model->ai_protocol = ACCEPT_ANY_PROTOCOL;
}

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

char* createRequestMessage(char* http_method, char *data_to_send, char* hostname, char *html_file_path_and_filename_on_host){ 
    data_to_send = allocateMemoryForRequestMessage(http_method, data_to_send, hostname, html_file_path_and_filename_on_host);
    
    strcpy(data_to_send, http_method);
    strcat(data_to_send, " ");
    strcat(data_to_send, html_file_path_and_filename_on_host);
    strcat(data_to_send, " HTTP/1.1\r\n");
    strcat(data_to_send, "Host: ");
    strcat(data_to_send, hostname);
    strcat(data_to_send, "\r\n\r\n");
    printf("%s",data_to_send);

    return data_to_send;
}

void eraseAllPreviousSocketData(struct addrinfo *socket_addr){
    const int which_byte_to_set_data=0;
    memset(socket_addr, which_byte_to_set_data, sizeof(struct addrinfo));
}

void estabilishDataToSend(int socket_identificator, struct VariablesDTO variables){
    char *data_to_send = createRequestMessage(variables.http_method, data_to_send, variables.hostname, variables.html_file_path_and_filename);
    
    //write on socket communication buffer
    write(socket_identificator, data_to_send, strlen(data_to_send));
}

void forkAndLoopListThoTryToConnect(struct addrinfo *list_of_addresses_infos, int *socket_identificator){
    struct addrinfo *pointer_to_walk_along_address_infos;
    struct sockaddr_in *information_core;
    int OPTLEN = 1, UNCONNECTED_SOCKET = -1;

    for(pointer_to_walk_along_address_infos = list_of_addresses_infos; pointer_to_walk_along_address_infos != NULL; pointer_to_walk_along_address_infos = pointer_to_walk_along_address_infos->ai_next)
    {
        information_core = (struct sockaddr_in *) pointer_to_walk_along_address_infos->ai_addr;
        printf("------------------------\n");
        printf("Address: %s\n", formatAsIP(information_core));
        
        int socket_identificator = socket(pointer_to_walk_along_address_infos->ai_family, pointer_to_walk_along_address_infos->ai_socktype, IPPROTO_TCP);

        setsockopt(socket_identificator, IPPROTO_TCP, TCP_NODELAY, (const char *) &OPTLEN, sizeof(int));
        
        global_variable_to_get_socket_identificator_from_blocking_function_fork_and_loop_list_tho_try_to_connect = &socket_identificator;

        if(socket_identificator == UNCONNECTED_SOCKET)
            continue;
        if(connect(socket_identificator, pointer_to_walk_along_address_infos->ai_addr, pointer_to_walk_along_address_infos->ai_addrlen) != -1)
            break;
        close(socket_identificator);

    }

    if (pointer_to_walk_along_address_infos == NULL)
    {
        fprintf(stderr, "It was not possible to estabilish connection\n");
        exit(EXIT_FAILURE);
    }

    freeaddrinfo(list_of_addresses_infos);
}

char* formatAsIP(struct sockaddr_in *information_core){
  return inet_ntoa((struct in_addr) information_core->sin_addr);
}

struct VariablesDTO mapArgumentsToVariables(char *arguments[]){ 
  char *current_executable = (char*) malloc(sizeof(char) * sizeof(arguments[0]));
  char *http_method = (char*) malloc(sizeof(char) * sizeof(arguments[1]));
  char *hostname = (char*) malloc(sizeof(char) * sizeof(arguments[2]));
  char *port = (char*) malloc(sizeof(char) * sizeof(arguments[3]));
  char *html_file_path_and_filename = (char*) malloc(sizeof(char) * sizeof(arguments[4]));
  char *destination_file_to_save_response_from_request = (char*) malloc(sizeof(char) * sizeof(arguments[5]));
  
  current_executable = copyDynamicString(current_executable, arguments[0]);
  http_method = copyDynamicString(http_method, arguments[1]);
  hostname = copyDynamicString(hostname, arguments[2]);
  port = copyDynamicString(port, arguments[3]);
  html_file_path_and_filename = copyDynamicString(html_file_path_and_filename, arguments[4]);
  destination_file_to_save_response_from_request = copyDynamicString(destination_file_to_save_response_from_request, arguments[5]);

  struct VariablesDTO dto = { 
    current_executable,
    http_method,
    hostname,
    port,
    html_file_path_and_filename,
    destination_file_to_save_response_from_request
  };

  return dto;
}

int getAListOfAllAddressessInfos(struct VariablesDTO variables, struct addrinfo * address_info_configuration_model, struct addrinfo ** list_of_addresses_infos){    
    int answer_status_code = -1; 
    
    if( (answer_status_code = getaddrinfo(variables.hostname, variables.port, address_info_configuration_model, list_of_addresses_infos)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(answer_status_code));
    }

    return answer_status_code;
}

void sendData(struct VariablesDTO variables, int socket_identificator, char (*buffer)[BUFFSIZ]){
    cleanBufferOfDestinationFile(buffer);

    int destination_file_identificator = open(variables.destination_file_to_save_response_from_request, O_WRONLY | O_APPEND | O_CREAT, FILE_PERMISSIONS);
    while( read(socket_identificator, buffer, calculateNewBufferSize() != 0))
    {
        write(destination_file_identificator, buffer, strlen(*buffer));
        cleanBufferOfDestinationFile(buffer);
    }
}

void setIfFamilyAddressIsIpv4OrIpv6(struct addrinfo *socket_addr, char protocol[]){
    if(strcmp(protocol,"IPV4")==0){
        socket_addr->ai_family = AF_INET;
        return;
    }

    if(strcmp(protocol,"IPV6")==0){
        socket_addr->ai_family = AF_INET6;
        return;
    }

    if(strcmp(protocol,"BOTH")==0){
        socket_addr->ai_family = AF_UNSPEC;
        return;
    }

    socket_addr->ai_family = AF_UNSPEC;
}

void setThatCallerHandlesOnlyTCP(struct addrinfo *socket_addr){
    socket_addr->ai_socktype = SOCK_STREAM;
} 

void validatesIfTheQuantityOfArgumentsPassedIsValid(int how_many_parameters_were_passed){
  // 6 params => { 0 = argc, 1 = http_method, 2 = hostname, 3 = port, 4 = source_path, 5 = destination_path }
  const int expected_parameters = 6;
  if(how_many_parameters_were_passed!=expected_parameters){
        printf("\n------------------------------------------------------\n");
        printf("\n\tWrong number of parameters passed\n");
        printf("\n\tPlease provide this order of parameters:\n");
        
        printf("\n\t|\t0 - executable\t\t|");
        printf("\n\t|\t1 - http_method\t\t|");
        printf("\n\t|\t2 - hostname\t\t|");
        printf("\n\t|\t3 - port\t\t|");
        printf("\n\t|\t4 - source_path\t\t|");
        printf("\n\t|\t5 - destination_path\t|");
        printf("\n\n------------------------------------------------------\n");
        exit(ERROR);
    }
}
