#define included_functions_prototypes 1

char* allocateMemoryForRequestMessage(struct VariablesDTO VariablesDTO, char *data_to_send, int number_of_received_arguments);
int calculateNewBufferSize();
int checkIfThereAreBodyParams(int number_of_received_arguments);
void cleanBufferOfDestinationFile(char (*buffer)[BUFFSIZ]);
void closeConnection(int socket_identificator);
void configureSocket(struct addrinfo *address_info_configuration_model);
char* copyDynamicString(char* output_str, char* input_str);
char* createRequestMessage(struct VariablesDTO variables, char *data_to_send, int number_of_received_arguments);
void eraseAllPreviousSocketData(struct addrinfo *socket_addr);
void estabilishDataToSend(int socket_identificator, struct VariablesDTO variables, int number_of_received_arguments);
void forkAndLoopListThoTryToConnect(struct addrinfo *list_of_addresses_infos, int *socket_identificator);
char* formatAsIP(struct sockaddr_in *information_core);
char* getContentLengthString(struct VariablesDTO variables, char *content_length_string);
int getSizeOfBodyParams(char *arguments[], int number_of_received_arguments);
int getSizeOfBodyParamsByVariable(struct VariablesDTO variables, int number_of_received_arguments);
struct VariablesDTO mapArgumentsToVariables(char *arguments[], int number_of_received_arguments);
void sendData(struct VariablesDTO variables, int socket_identificator, char (*buffer)[BUFFSIZ]);
void setIfFamilyAddressIsIpv4OrIpv6(struct addrinfo *socket_addr, char protocol[]);
void setThatCallerHandlesOnlyTCP(struct addrinfo *socket_addr);
char* strcatInteger(int value, char* result, int base);
void validatesIfTheQuantityOfArgumentsPassedIsValid(int how_many_parameters_were_passed);
int getAListOfAllAddressessInfos(struct VariablesDTO variables, struct addrinfo * address_info_configuration_model, struct addrinfo ** list_of_addresses_infos);
