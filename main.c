#include "./headers/libs.h"
#include "./headers/custom_functions.h"

int main(int number_of_received_arguments, char *arguments[])
{
    int socket_identificator;
    char buffer[BUFFSIZ];
    struct addrinfo address_info_configuration_model, *list_of_addresses_infos;

    //Manage Received Aruments
    validatesIfTheQuantityOfArgumentsPassedIsValid(number_of_received_arguments);
    
    struct VariablesDTO variables = mapArgumentsToVariables(arguments, number_of_received_arguments);
    //Before Connect
    configureSocket(&address_info_configuration_model);
    getAListOfAllAddressessInfos(variables, &address_info_configuration_model, &list_of_addresses_infos);
    forkAndLoopListThoTryToConnect(list_of_addresses_infos, &socket_identificator);
    socket_identificator = *global_variable_to_get_socket_identificator_from_blocking_function_fork_and_loop_list_tho_try_to_connect;

    //After Connect
    estabilishDataToSend(socket_identificator, variables, number_of_received_arguments);
    sendData(variables, socket_identificator, &buffer);
    closeConnection(socket_identificator);
    
	return(PROGRAM_SUCCESSFULL_EXECUTED_CODE);
}

