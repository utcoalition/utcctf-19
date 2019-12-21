FROM thekidofarcrania/pychall

COPY xinetd /etc/xinetd.d/chall
COPY flag.txt /
COPY server.py /
RUN chmod o+r /server.py
RUN chmod o+r /flag.txt

EXPOSE 1337

CMD ["xinetd", "-dontfork"]
