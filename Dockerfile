FROM debian

RUN apt-get update 

RUN apt-get install gcc -y
RUN apt-get install nano -y

COPY . /usr/local/httprequests

WORKDIR /usr/local/httprequests


