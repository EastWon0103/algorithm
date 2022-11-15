n = int(input())
aLst = list(map(int, input().split()))
t = int(input())
targetLst = list(map(int, input().split()))

aLst.sort()
#1 2 3 4 5
def find(low, high,target):
    mid = int((low+high)/2)
    if(aLst[mid] == target):
        return 1

    if(low>=high):
        return 0
    
    if aLst[mid] < target:
        return find(mid+1,high, target)
    else:
        return find(low,mid-1, target)



for i in targetLst:
    result = find(0,n-1, i)
    print(result)
    