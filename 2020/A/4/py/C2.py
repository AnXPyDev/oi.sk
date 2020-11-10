for y in range(N):
    for x in range(N):
        Write(N * N + y * N + x, Read(x * N + (N - y - 1)))

for i in range(N * N):
    Write(i, Read(N * N + i))
        
