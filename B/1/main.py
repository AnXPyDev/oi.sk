from sys import argv
from copy import copy


file = open("./input/" + argv[1], "r").read().split('\n')


line0 = []


for e in file[0].split(" "):
    line0.append(int(e))

#Tricka
shirts = []

i1 = 0
for j in file[1].split(" "):
    shirts.append([i1 + 1,int(j)])
    i1 += 1

for i in range(0, line0[1]):
    #Prida k pouzitiam prveho tricka 1
    if(file[2 + i] == "Z"):
        shirts[0][1] += 1
    elif(file[2 + i] == "L"):
        e = 0
        minimum = shirts[0][1]
        #Vpocita minimalne pocet pouziti
        for x in shirts:
            if(x[1] < minimum):
                minimum = x[1]
        #Posune prve tricko s min hodnotou do predu a prida k jeho pouzitiam 1
        for o in shirts:
            if (o[1] == minimum):
                temp = copy(shirts[e])
                del shirts[e]
                shirts = [temp] + shirts
                shirts[0][1] += 1
                break   
            e += 1

    print(shirts[0][0])
            

