FROM thekidofarcrania/pychall
RUN apt install -y libmpfr-dev libmpc-dev libgmp-dev
RUN pip3 install pycryptodome

COPY src /app
COPY xinetd /etc/xinetd.d/chall

EXPOSE 1337

CMD ["xinetd", "-dontfork"]
