FROM nakatt/doxygen

RUN apk update && apk add dos2unix

ADD compile.sh /usr/local/bin/compile.sh
RUN chmod 777 /usr/local/bin/compile.sh
RUN dos2unix /usr/local/bin/compile.sh

ENTRYPOINT ["/usr/local/bin/compile.sh"]
#ENTRYPOINT [""]