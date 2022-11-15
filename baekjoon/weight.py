n = int(input())
compareLst = []
for i in range(n):
    data = tuple(map(int,input().split()))
    compareLst.append(data)

rankLst = []
def findRank(target):
    rank = 1
    for item in compareLst:
        if item[0] < target[0] and item[1] < target[1]:
            continue
        elif item[0] > target[0] and item[1] > target[1]:
            rank+=1
        else:
            continue
    
    print(f"{rank} ", end="")

for i in compareLst:
    findRank(i)