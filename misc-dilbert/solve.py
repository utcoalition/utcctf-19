import lindenmayer
from PIL import Image
import math

if __name__ == "__main__":
    chall = Image.open("dilbert.bmp")
    w, h = chall.size
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
    pixels = chall.load()
    outb = ""
    for i in range(256):
        x,y = path[i]
        outb += str(pixels[x,y][0] & 1)
    
    print(outb)
