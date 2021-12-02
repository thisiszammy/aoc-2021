command = ""

xAxis = 0
yAxis = 0
inputs = ["",0]
while(inputs[0] != "endcommand"):
    inputs = list(map(str, input().split()))

    if(inputs[0] == "forward"):
        xAxis+=int(inputs[1])
    elif(inputs[0] == "down"):
        yAxis+=int(inputs[1])
    else:
        yAxis-=int(inputs[1])

print(str(xAxis*yAxis))