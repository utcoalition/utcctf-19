FROM thekidofarcrania/chall

COPY bof.conf /etc/xinetd.d/bof
COPY flag.txt /
COPY flag2.txt /
COPY server /

EXPOSE 1337

CMD ["xinetd", "-dontfork"]
