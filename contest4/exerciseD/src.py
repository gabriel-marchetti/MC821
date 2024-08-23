test_cases = int(input())
for i in range(test_cases):
    N = int(input())
    P = input()
    P = [int(x) for x in P]

    MOD = 0
    power = len(P) - 1
    for i in range(len(P)):
        MOD += (P[i]%N) * pow(10, power, N)
        MOD %= N
        power -= 1
    print(MOD)
