fishes = [int(x) for x in input().split(",")]

vals = [0 for i in range(9)]

for i in fishes:
    vals[i]+=1


ctr = 256

while ctr > 0:
    tempZero = vals[0]
    vals[0] = vals[1]
    vals[1] = vals[2]
    vals[2] = vals[3]
    vals[3] = vals[4]
    vals[4] = vals[5]
    vals[5] = vals[6]
    vals[6] = vals[7] + tempZero
    vals[7] = vals[8]
    vals[8] = tempZero


    ctr-=1


print(sum(vals))