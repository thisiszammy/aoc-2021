command = ""

aim = 0
position = 0
depth = 0
inputs = ["",0]
while(inputs[0] != "endcommand"):
    inputs = list(map(str, input().split()))

    if(inputs[0] == "down"):
        aim+=int(inputs[1])
    elif(inputs[0] == "up"):
        aim-=int(inputs[1])
    else:
        position += int(inputs[1])
        depth += aim * int(inputs[1])


print(str(position*depth))