
def checkBingo(vboard, board, num):

    for i in range(5):
        for j in range(5):
            if vboard[i][j] == num:
                board[i][j] = 1

            if vboard[j][i] == num:
                board[j][i] = 1


    unMarked = 0

    h_ctr = 0
    v_ctr = 0
    ptMax = 0

    for i in range(5):
        for j in range(5):
            if board[i][j] == 1:
                h_ctr+=1
            else:
                unMarked += vboard[i][j]
            
            if board[j][i] == 1:
                v_ctr+=1


        if h_ctr == 5 or v_ctr == 5:
            ptMax = h_ctr if h_ctr >= v_ctr else v_ctr


        h_ctr = 0
        v_ctr = 0

    
    if(ptMax == 5):
        return unMarked*num

    return 0


nums = list(map(int, input().split(',')))

boards = []
foundBoards = []

inp = "start"
ctr = -1

while True:
    inp = input().strip(" ")

    if inp == "end":
        break
    
    if len(inp) == 0:
        ctr+=1
        boards.append([])        
        foundBoards.append([])
        continue

    row = [int(x) for x in inp.split()]
    boards[ctr].append(row)
    foundBoards[ctr].append([0,0,0,0,0])


ans = 0
iCtr = 0


while ans == 0:


    for i in range(len(boards)):
        ans = checkBingo(boards[i], foundBoards[i], nums[iCtr])
        if ans != 0:
            break
        
    iCtr+=1
    if ans != 0:
        print(ans)
        break