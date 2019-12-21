FROM thekidofarcrania/py2chall

COPY xinetd /etc/xinetd.d/chall
COPY add_rotate_xor.py /server.py

EXPOSE 1337

CMD ["xinetd", "-dontfork"]
