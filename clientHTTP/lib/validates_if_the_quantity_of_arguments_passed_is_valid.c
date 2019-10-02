#ifndef included_external_libs
    #include <stdio.h>
    #include <stdlib.h>
#endif

void validatesIfTheQuantityOfArgumentsPassedIsValid(int how_many_parameters_were_passed){
  // 6 params => { 0 = argc, 1 = http_method, 2 = hostname, 3 = port, 4 = source_path, 5 = destination_path }
  const int expected_parameters = 6;
  if(how_many_parameters_were_passed<expected_parameters){
        printf("\n------------------------------------------------------\n");
        printf("\n\tWrong number of parameters passed\n");
        printf("\n\tPlease provide this order of parameters:\n");
        
        printf("\n\t|\t0 - executable\t\t|");
        printf("\n\t|\t1 - http_method\t\t|");
        printf("\n\t|\t2 - hostname\t\t|");
        printf("\n\t|\t3 - port\t\t|");
        printf("\n\t|\t4 - source_path\t\t|");
        printf("\n\t|\t5 - destination_path\t|");
        printf("\n\n|--------OPTIONAL--------|\n");
        printf("\n\t|\t6 - Body Params/Querystring\t|");
        printf("\n\n------------------------------------------------------\n");
        exit(ERROR);
    }
}