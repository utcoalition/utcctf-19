FROM thekidofarcrania/chall

RUN mkdir /app
COPY xinetd /etc/xinetd.d/chall
COPY login /app
COPY flag.txt /

EXPOSE 1337

CMD ["xinetd", "-dontfork"]
