#/bin/sh

#Compile program and create executable "exe"
gcc -o exe get.c

#recreate destination file
echo "" > response_from_executed_request.txt

#execution:

#./exe GET 10.132.20.22 80 /aulas/gr/readme.txt response_from_executed_request.txt

./exe GET indoorweb.com.br 80 / response_from_executed_request.txt
#./exe HEAD 10.132.20.22 80 /aulas/gr/readme.txt response_from_executed_request.txt

