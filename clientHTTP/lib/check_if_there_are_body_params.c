int checkIfThereAreBodyParams(int number_of_received_arguments){
  // Always is one more than the number of parameters you passed
  // 'Cause the first one is the executable
  return number_of_received_arguments == 7;
}