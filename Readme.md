# There are some ways of running this project:

## Choose one of those scripts:

### First:

- gcc -o exe main.c
- echo "" > output/response_from_executed_request.txt
- ./exe GET HOSTNAME PORT / output/response_from_executed_request.txt

#### Example:

- ./exe GET indoorweb.com.br 80 / output/response_from_executed_request.txt

#### Example2:

- ./exe GET 10.132.20.22 80 /aulas/gr/readme.txt output/response_from_executed_request.txt

---

### Second:

- ./run.sh

---

# With Docker:

- docker stop projetosgerenciaderedes_httprequests_1 && docker rm projetosgerenciaderedes_httprequests_1 && docker volume rm projetosgerenciaderedes_ger-redes && docker-compose up --build && docker-compose run --rm httprequests /bin/bash
- After that, run one of those scripts before

# Where will be stored my http responses?

- output/response_from_executed_request.txt file
