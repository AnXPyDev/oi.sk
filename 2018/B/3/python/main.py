from sys import argv
file = open("./input/" + argv[1], "r").read().split('\n')

numOfWords = int(file[0])
abc = "abcdefghijklmnopqrstuvwxyz"
def move(list, indexOld, indexNew):
    return list[0:indexNew] + list[indexOld] + list[indexNew:indexOld] + list[indexOld + 1:]

lastWord = file[numOfWords]
for word in reversed(file[1:numOfWords]):
    minL = min(len(word), len(lastWord))
    for i in range(minL):
        if(not lastWord[i] == word[i]):
            if(abc.index(word[i]) > abc.index(lastWord[i])):
                abc = move(abc, abc.index(word[i]), abc.index(lastWord[i]))
            break
    lastWord = word
print(abc)



