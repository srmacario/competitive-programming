k = int(input())
pr = []
fat = []
for i in range(1,1001):
    cnt = 0
    for j in range (2, i+1):
        if i%j == 0:
            cnt += 1
    if cnt == 1:
        pr.append(int(i))

for p in pr:
    while (k%p) == 0:
        k/=p
        fat.append(int(p))
    
fat.sort(reverse = True)
cnt = 0
ans = 1
for f in fat:
    for i in range(1,f):
        ans *= pr[cnt]
    cnt += 1
print(ans)