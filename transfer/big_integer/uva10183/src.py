while(True):
    enters = input().split()
    a = int(enters[0])
    b = int(enters[1])
    if( a == 0 and b == 0):
        break
    counter = 0
    fib_1 = 1
    fib_2 = 2

    if(a == fib_1 or a == fib_2):
        counter += 1
    if(b == fib_1 or b == fib_2):
        counter += 1

    while(True):
        if(fib_2 > b):
            break
        if(fib_2 > a and fib_2 < b):
            counter += 1
        copy_fib = fib_2
        fib_2 = fib_1 + fib_2
        fib_1 = copy_fib
    print(counter)
