import lindenmayer
from PIL import Image
import math


def set_lsb(n, bit):
    return (n & ~1) | bit


if __name__ == "__main__":
    flag = "utc{h1lb_n0t_d1lb!}"

    source = Image.open("dilbert_orig.bmp")
    w, h = source.size
    assert w == h
    degree = int(math.log2(w))
    print(degree)

    # L System instruction generation
    hilb_rules = {
        "L": "+RF-LFL-FR+",
        "R": "-LF+RFR+FL-"
    }
    hilb_ax = "L"
    hilb = lindenmayer.L(hilb_ax, hilb_rules, degree)

    # Convert instructions to absolute coordinates
    path = lindenmayer.l2coords(hilb.state)

    bs = bin(int.from_bytes(flag.encode("ascii"), "big"))[2:]  # strip 0b...
    bs = bs.zfill(len(bs) + 8 - len(bs)%8)
    print(bs)
    pixels = source.load()
    for i, c in enumerate(bs):
        bit = int(c)
        x, y = path[i]
        r, g, b, a = pixels[x, y]
        r = set_lsb(r, bit)
        g = set_lsb(g, bit)
        b = set_lsb(b, bit)
        pixels[x, y] = (r, g, b, a)
    source.save("dilbert.bmp")
