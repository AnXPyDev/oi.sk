n = 7
k = 600
stanky = [200, 100, 200, 300, 200, 200, 100]

vysledok_d = 0
vysledok_l = 0

l = 0
r = n - 1

potrebne_k = sum(stanky)

if potrebne_k < k:
    vysledok_d = n
    vysledok_l = 0
else:
    while l <= n:
        while potrebne_k < k:
            r += 1
            potrebne_k += stanky[r]
        while potrebne_k > k:
            r -= 1
            potrebne_k -= stanky[r]
        d = r - l
        if d > vysledok_d:
            vysledok_d = d
            vysledok_l = l
        l += 1
    
        
print(vysledok_d, vysledok_l + 1)
