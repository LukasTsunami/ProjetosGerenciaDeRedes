#/bin/sh

#Compile program and create executable "exe"
gcc -o exe main.c

#recreate destination file
echo "" > output/response_from_executed_request.txt

#execution:

#./exe GET 10.132.20.22 80 /aulas/gr/readme.txt output/response_from_executed_request.txt

./exe GET indoorweb.com.br 80 / output/response_from_executed_request.txt
#./exe HEAD 10.132.20.22 80 /aulas/gr/readme.txt output/response_from_executed_request.txt

