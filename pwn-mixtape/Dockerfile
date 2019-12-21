FROM thekidofarcrania/chall

COPY pwnable /pwnable
COPY xinetd /etc/xinetd.d/chall
COPY flag.txt /

EXPOSE 1337

CMD ["xinetd", "-dontfork"]
