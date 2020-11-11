blok = None

for sy in range(0, (N // 2 - 1) + 1):
    for sx in range(sy, (N - sy - 2) + 1):
        blok = Read(sy * N + sx)
        x = N - sy - 1
        y = sx
        for i in range(3):
            tblok = Read(y * N + x)
            Write(y * N + x, blok)
            blok = tblok
            x0 = x
            y0 = y
            x = N - y0 - 1
            y = x
        Write(sy * N + sx, blok)
        
        
