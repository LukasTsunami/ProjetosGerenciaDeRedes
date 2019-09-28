char* allocate_memory_for_request_message(char* http_method, char *data_to_send, char* hostname, char *SOURCE_URI);
int calculateNewBufferSize();
void configureSocket(struct addrinfo *address_info_configuration_model);
char* copyDynamicString(char* output_str, char* input_str);
void eraseAllPreviousSocketData(struct addrinfo *socket_addr);
char* estabilishDataToSend(char* http_method, char *data_to_send, char* hostname, char *SOURCE_URI);
void setIfFamilyAddressIsIpv4OrIpv6(struct addrinfo *socket_addr, char protocol[]);
void setThatCallerHandlesOnlyTCP(struct addrinfo *socket_addr);
void validates_if_the_quantity_of_paramaters_passed_is_valid(int how_many_parameters_were_passed);
int test_if_hostname_exists(char* hostname, char* port, struct addrinfo * address_info_configuration_model, struct addrinfo ** target_gotten_address_informations);

char* allocate_memory_for_request_message(char* http_method, char *data_to_send, char* hostname, char *SOURCE_URI){
    return malloc(sizeof(char) * ((strlen(SOURCE_URI)) + strlen(hostname) + strlen(http_method) + strlen("  HTTP/1.1\r\nHost: \r\nr\n")));
}

int calculateNewBufferSize(){
    return BUFFSIZ - 1;
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

void eraseAllPreviousSocketData(struct addrinfo *socket_addr){
    const int which_byte_to_set_data=0;
    memset(socket_addr, which_byte_to_set_data, sizeof(struct addrinfo));
}

char* estabilishDataToSend(char* http_method, char *data_to_send, char* hostname, char *SOURCE_URI){ 
    data_to_send = allocate_memory_for_request_message(http_method, data_to_send, hostname, SOURCE_URI);
    
    strcpy(data_to_send, http_method);
    strcat(data_to_send, " ");
    strcat(data_to_send, SOURCE_URI);
    strcat(data_to_send, " HTTP/1.1\r\n");
    strcat(data_to_send, "Host: ");
    strcat(data_to_send, hostname);
    strcat(data_to_send, "\r\n\r\n");
    printf("%s",data_to_send);
    
    return data_to_send;
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

void validates_if_the_quantity_of_paramaters_passed_is_valid(int how_many_parameters_were_passed){
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

int test_if_hostname_exists(char* hostname, char* port, struct addrinfo * address_info_configuration_model, struct addrinfo ** target_gotten_address_informations){    
    int answer_status_code = -1; 
    
    if( (answer_status_code = getaddrinfo(hostname, port, address_info_configuration_model, target_gotten_address_informations)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(answer_status_code));
    }

    return answer_status_code;
}