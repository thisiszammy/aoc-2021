

fishes = [int(x) for x in input().split(',')]


ctr = 80


while ctr != 0:

    newFish = []
    for i in range(len(fishes)):
        fishes[i]-=1
        if fishes[i] == -1:
            newFish.append(8)
            fishes[i] = 6

    fishes+=newFish
    ctr-=1

print(len(fishes))