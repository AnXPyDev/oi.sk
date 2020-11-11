N = 5

m = [i for i in range(1, N * N + 1)]

def Read(i):
    return m[i]

def Write(i, b):
    m[i] = b

def pm():
    for y in range(N):
        for x in range(N):
            print(Read(y * N + x), end = " ")
        print("", end = "\n")


pm()
        
blok = None

for sy in range(0, (N // 2 - 1) + 1):
    for sx in range(sy, (N - sy - 2) + 1):
        y = sy
        x = sx
        for i in range(5):
            tblok = Read(y * N + x)
            Write(y * N + x, blok)
            blok = tblok
            x0 = x
            y0 = y
            x = N - y0 - 1
            y = x0

pm()
