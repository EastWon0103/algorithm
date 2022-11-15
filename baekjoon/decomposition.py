data = int(input())

def decomposit(d, target):
    sum = d
    for i in list(str(d)):
        sum+=int(i)
    
    if target==sum:
        return True
    return False

result = 0
for i in range(0,data):
    if decomposit(i, data):
        result = i
        break


print(result)