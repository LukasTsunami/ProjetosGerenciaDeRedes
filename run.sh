 #!/bin/sh

#Compile program and create executable "exe"
gcc -o exe main.c

#recreate destination file
echo "" > output/response_from_executed_request.txt

#execution:

#    1GET 2HOST 3PORT 4SOURCE 5DESTINATION
./exe $1 $2 $3 $4 $5 $6
 
#./exe GET 10.132.20.22 80 /aulas/gr/readme.txt output/response_from_executed_request.txt

#./exe GET indoorweb.com.br 80 / output/response_from_executed_request.txt
#./exe GET e70af7ad.ngrok.io 80 / output/response_from_executed_request.txt
#./exe POST 87335d4c.ngrok.io 80 / output/response_from_executed_request.txt
#./exe GET https://devnaestrada.com.br/ 80 2019/09/27/entrevista-carla-vieira.html output/response_from_executed_request.txt
#./exe HEAD 10.132.20.22 80 /aulas/gr/readme.txt output/response_from_executed_request.txt


