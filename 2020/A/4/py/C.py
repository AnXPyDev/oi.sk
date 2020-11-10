posledny_blok = None
blok = None

for zaciatok_y in range(N // 2):
    for zaciatok_x in range(zaciatok_y, N - (zaciatok_y + 1)):
        pozicia = zaciatok_y * N + zaciatok_x
        for i in range(5):
            blok = Read(pozicia)
            Write(pozicia, posledny_blok)
            posledny_blok = blok
            y = pozicia // N
            x = pozicia - y * N
            pozicia += (2*N - ((N+1) * (y+1))) + (N-1) * x
