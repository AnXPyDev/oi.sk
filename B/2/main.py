from sys import argv

file = open("./input/" + argv[1], "r").read().split('\n')

words = []
numberOfWords = int(file[0])

class Word:
    def __init__(self, word, index):
        self.letters = [word[0], word[len(word) - 1]]
        self.index = index
        self.word = word
        self.bestSuccession = []
    def getBestSuccession(self):
        found = False
        if(self.index != len(words) - 1):
            bestCandidate = [0,0]
            for i in range(self.index + 1, len(words)):
                if(len(words[i].bestSuccession) >= bestCandidate[1] and words[i].letters[0] == self.letters[1]):
                    bestCandidate = [i, len(words[i].bestSuccession)]
                    found = True
            if(found):
                self.bestSuccession = [bestCandidate[0]] + words[bestCandidate[0]].bestSuccession
        print(self.index, self.word, found, self.bestSuccession) 

for i in range(0, numberOfWords):
    words.append(Word(file[i + 1], i))

for e in range(len(words) - 1, -1, -1):
    words[e].getBestSuccession()

max = 0
for x in words:
    if(len(x.bestSuccession) + 1 > max):
        max = len(x.bestSuccession)

print(max + 1)
