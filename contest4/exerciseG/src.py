zero_zero = []
one_one = []
one_one.append(0)
zero_zero.append(0)

for i in range(1, 1001):
    one_one.append(zero_zero[i-1] + one_one[i-1])
    increment = 1 if i % 2 == 0 else 0
    zero_zero.append(zero_zero[i-1] + one_one[i-1] + increment)

#print("zero_zero:\t", end='')
#print( zero_zero[:5])
#print("one_one:\t", end='')
#print( one_one[:5])
while(True):
    try:
        n = int(input())
        print(zero_zero[n])
    except EOFError:
        break
