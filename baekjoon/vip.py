# memoization
# def rule(lst, k, n):
#     if k==0:
#         lst[k][n-1] = n
#         return n
#     if lst[k][n-1] != -1:
#         return lst[k][n]

#     sum = 0
#     for i in range(1,n+1):
#         # print(k-1, " ", i)
#         sum += rule(lst, k-1, i)
        
#     return sum

# def sumLst(lst, k, n):
#     sum = 0
#     for i in lst[k]:
#         for j in range(n):
#             sum+=lst[k][j]
#     return sum

def rule(lst, k, n):
    for i in range(k+1):
        for j in range(n):
            if i==0:
                lst[i][j] = j+1
            else :
                sum = 0
                for t in range(j+1):
                    sum+=lst[i-1][t]
                lst[i][j] = sum

    
    return lst[k][n-1]

t = int(input())

for i in range(t):
    k = int(input())
    n = int(input())
    
    lst =[[-1 for _ in range(n)] for _ in range(k+1)]
    # print(lst)
    print(rule(lst, k, n))
    # for i in lst:
    #     print(lst)
