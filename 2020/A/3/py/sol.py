n = 7
k = 600
a = [200, 100, 200, 300, 200, 200, 100]

vysledok_d = 0
vysledok_l = 0

l = 0
r = n - 1
p = sum(a)

if p < k:
    vysledok_d = n
    vysledok_l = 0
elif k < min(a):
    vysledok_d = 0
    vysledok_l = 0
else:
    while l <= n:
        while p < k and r > l + 1:
            r += 1
            p += a[r]
        while p > k and r + 1 < n:
            p -= a[r]
            r -= 1
        d = r - l
        if d > vysledok_d:
            vysledok_d = d
            vysledok_l = l
        potrebne_k 
        l += 1
    
        
print(vysledok_d, vysledok_l + 1)
