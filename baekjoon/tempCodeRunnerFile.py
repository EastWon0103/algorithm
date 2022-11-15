from queue import PriorityQueue


n = int(input())
pq = PriorityQueue(maxsize=n)
for i in range(n):
    item = int(input())
    pq.put(item)

for i in range(n):
    print(pq.get())
