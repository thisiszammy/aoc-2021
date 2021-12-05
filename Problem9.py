def getMapBounds(coords):
    vMax = -1
    for i in range(len(coords)):
        tMax = max(coords[i][0] + coords[i][1])
        if  tMax > vMax:
            vMax=tMax

    return vMax

coords = []
x = "start"

while True:
    inp = input()

    if inp == "end":
        break

    x = inp.split("->")
        
    coords.append([[int(a) for a in x[0].split(",")], [int (b) for b in x[1].split(",")]])


mapBounds = getMapBounds(coords)
gMap = [[0 for i in range(mapBounds+1)] for j in range(mapBounds+1)]
ctr = 0


for i in range(len(coords)):
    sCoord = coords[i]

    if sCoord[0][0] == sCoord[1][0]:
        
        if sCoord[1][1] > sCoord[0][1]:
            for j in range(sCoord[0][1], sCoord[1][1]+1):
                
                gMap[sCoord[0][0]][j]+=1
                if gMap[sCoord[0][0]][j] == 2:
                    ctr+=1

        elif sCoord[0][1] > sCoord[1][1]:
            for j in range(sCoord[1][1], sCoord[0][1]+1):

                gMap[sCoord[0][0]][j]+=1
                if gMap[sCoord[0][0]][j] == 2:
                    ctr+=1
        else:
            gMap[sCoord[0][0]][sCoord[0][1]]+=1
            if gMap[sCoord[0][0]][sCoord[0][1]] == 2:
                ctr+=1

    elif sCoord[0][1] == sCoord[1][1]:
        
        if sCoord[1][0] > sCoord[0][0]:
            for j in range(sCoord[0][0], sCoord[1][0]+1):
                
                gMap[j][sCoord[0][1]]+=1
                if gMap[j][sCoord[0][1]] == 2:
                    ctr+=1
        
        elif sCoord[0][0] > sCoord[1][0]:
            for j in range(sCoord[1][0], sCoord[0][0]+1):

                gMap[j][sCoord[0][1]]+=1
                if gMap[j][sCoord[0][1]] == 2:
                    ctr+=1
        else:
            gMap[sCoord[0][0]][sCoord[0][1]]+=1
            if gMap[sCoord[0][0]][sCoord[0][1]] == 2:
                ctr+=1

print(ctr)


        