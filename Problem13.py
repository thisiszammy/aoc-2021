def getFuelRequirement(crabs, pos):
    fuel = 0
    for i in crabs:
        fuel += abs(pos-i)
    
    return fuel


crabs = [int(x) for x in input().split(",")]

fuel = -1

for i in crabs:
    estFuel = getFuelRequirement(crabs, i)
    if estFuel < fuel or fuel == -1:
        fuel = estFuel

print(fuel)

