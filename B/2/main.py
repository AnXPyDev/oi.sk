from sys import argv

file = open("./input/" + argv[1], "r").read().split('\n')
del file[0]

words = []

class Word:
    def __init__(self, word, index):
        self.letters = [word[0], word[len(word) - 1]]
        self.index = index
        self.word = word
        self.bestSuccession = []
    def getBestSuccession(self):
        if(self.index == len(words)):
            return
        bestCandidate = [0,0]
        found = False
        for i in range(self.index, len(words)):
            if(len(words[i].bestSuccession) >= bestCandidate[1] and words[i].letters[0] == self.letters[1]):
                bestCandidate = [i, len(words[i].bestSuccession)]
                found = True
        if(found):
            self.bestSuccession = [bestCandidate[0]] + words[bestCandidate[0]].bestSuccession
        print(self.index, self.word, found, self.bestSuccession) 
for i in range(0, len(file) - 1):
    words.append(Word(file[i], i))

for e in range(len(words) - 1, -1, -1):
    words[e].getBestSuccession()

max = 0
for x in words:
    if(len(x.bestSuccession) + 1 > max):
        max = len(x.bestSuccession)

print(max + 1)
