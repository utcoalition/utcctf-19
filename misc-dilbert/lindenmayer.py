def l2coords(string):
    coords = [(0, 0)]
    heading = 0
    for c in string:
        if c == "F":
            prev = coords[-1]
            if heading == 0:
                coords.append((prev[0] + 1, prev[1]))
            elif heading == 1:
                coords.append((prev[0], prev[1] + 1))
            elif heading == 2:
                coords.append((prev[0] - 1, prev[1]))
            elif heading == 3:
                coords.append((prev[0], prev[1] - 1))
        if c == "+":
            heading += 1
            heading %= 4
        if c == "-":
            heading -= 1
            heading %= 4
    return coords

class L():
    def __init__(self, axiom: str, rules: dict, degree: int):
        self.state = axiom
        self.rules = rules
        self.degree = degree
        for i in range(degree):
            self.advance()

    def advance(self):
        new = ""
        for c in self.state:
            if c in self.rules:
                new += self.rules[c]
            else:
                new += c
        self.state = new
