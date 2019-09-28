#include "./libs.h"
#include "./custom_functions.h"

int main(int argc, char *argv[])
{ 
    int socket_identificator, destination_file_identificator, number_of_received_arguments=argc, answer_status_code;
    const int THROWS_ERROR_CODE=1, PROGRAM_SUCCESSFULL_EXECUTED_CODE=0;
    char buffer[BUFFSIZ], *data_to_send;
    struct addrinfo address_info_configuration_model;
    struct addrinfo *list_of_addresses_infos;
    
    validatesIfTheQuantityOfArgumentsPassedIsValid(number_of_received_arguments);
    
    struct VariablesDTO variables = mapArgumentsToVariables(argv);

    configureSocket(&address_info_configuration_model);

    getAListOfAllAddressessInfos(variables, &address_info_configuration_model, &list_of_addresses_infos);
    
    forkAndLoopListThoTryToConnect(list_of_addresses_infos, &socket_identificator);
    
    socket_identificator = *global_variable_to_get_socket_identificator_from_blocking_function_fork_and_loop_list_tho_try_to_connect;

    estabilishDataToSend(socket_identificator, variables);

    sendData(variables, socket_identificator, &buffer, destination_file_identificator);

    closeConnection(socket_identificator);
    
	return(PROGRAM_SUCCESSFULL_EXECUTED_CODE);
}
