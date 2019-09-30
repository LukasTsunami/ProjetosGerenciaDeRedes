# This project make Http 1.1 requests (without TLS) using raw C language

## HTTP METHODS IMPLEMENTED:

- GET
- HEAD
- POST
- PUT

# There are some ways of running this project:

## Choose one of those scripts:

### First:

- gcc -o exe main.c
- echo "" > output/response_from_executed_request.txt
- ./exe GET HOSTNAME PORT / output/response_from_executed_request.txt

#### Example:

- ./exe GET indoorweb.com.br 80 / output/response_from_executed_request.txt

#### Example2:

- ./exe POST 10.132.20.22 80 /aulas/gr/readme.txt output/response_from_executed_request.txt

---

### Second:

- chmod +x run.sh
- ./run.sh

---

## With Docker:

- docker-compose up --build
- docker-compose run --rm httprequests /bin/bash
- After that, run one of those **scripts** before

- docker-compose run --rm httprequests /bin/bash ./run.sh POST 95f61387.ngrok.io 80 / output/response_from_executed_request.txt "nome=lucas@tsunami&girl=julia"

- docker-compose run --rm httprequests /bin/bash ./run.sh PUT 847e22f8.ngrok.io 80 / output/response_from_executed_request.txt "nome=lucas&email=lucas@tsunami1234567891012"

## How to test server?:

- enter into server folder
- run node index.js
- download ngrok to expose localhost
  - ./ngrok http 8081
- After this, change ./run.sh with the ngrok URL

## Where will be stored my http responses?

- output/response_from_executed_request.txt file
