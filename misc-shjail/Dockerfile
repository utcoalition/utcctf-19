FROM thekidofarcrania/chall

RUN useradd jail && \
    useradd jail_pwn && \
    mkdir -p /home/jail/jaildir
WORKDIR /home/jail

COPY jail .
COPY xinetd /etc/xinetd.d/chall
COPY flag.txt jaildir/
COPY hello jaildir/

RUN chown root:jail_pwn jaildir/flag.txt && \
    chmod 440 jaildir/flag.txt && \
    chmod o-r /tmp && \
    chown root:jail_pwn jail && \
    chmod g+s jail

EXPOSE 1337

CMD ["xinetd", "-dontfork"]
