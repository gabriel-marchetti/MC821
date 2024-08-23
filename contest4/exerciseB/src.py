while(True):
    try:
        enters = input().split()
        number_str = enters[0]
        power = int(enters[1])

        digits = []
        decimal_digits = 0
        for i in range(len(number_str)):
            if(number_str[i] != '.'):
                digits.append(number_str[i])
                continue
            decimal_digits = len(number_str) - i - 1

        decimal_digits *= power
        digits.reverse()
        number_with_no_decimals = 0
        base = 1
        for i in range(len(digits)):
            number_with_no_decimals += int(digits[i]) * base
            base *= 10

        number_with_no_decimals = pow(number_with_no_decimals, power)
        final_num = [int(x) for x in str(number_with_no_decimals)]

        place_of_dot = len(final_num) - decimal_digits
        dotFirst = False
        if(place_of_dot > 0):
            final_num.insert(place_of_dot, '.')
        else:
            final_num.reverse()
            for i in range(abs(place_of_dot)):
                final_num.append(0)
            dotFirst = True
            final_num.reverse()

        while(final_num[len(final_num) - 1] == 0):
            final_num.pop()
        if(dotFirst):
            print('.', end='')
        for i in range(len(final_num)):
            print(final_num[i], end='')
        print()
        
    except EOFError:
        break
