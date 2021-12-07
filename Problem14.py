def getFuelRequirement(crabs, pos):
    fuel = 0
    for i in crabs:
        subCap = abs(pos-i)
        fuel += int(int(subCap*(subCap+1))/2)
    
    return fuel


crabs = [int(x) for x in input().split(",")]

fuel = -1
farthestPoint = max(crabs)
nearestPoint = min(crabs)

for i in range(nearestPoint, farthestPoint+1):
    estFuel = getFuelRequirement(crabs, i)
    if estFuel < fuel or fuel == -1:
        fuel = estFuel

print(fuel)

