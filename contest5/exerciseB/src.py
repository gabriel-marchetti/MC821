m, n = map(int, input().split())

resp = 0
for i in range(1, m+1):
    resp += i * ( pow(i/m, n) - pow((i-1)/m, n) )
print(f"{resp:.9f}")
