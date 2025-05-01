def main():

    number = input("Enter: ")
    length = len(number)

    if length == 15 and number[:2] in ["34", "37"] and verify(number):
        print("AMEX")

    elif length == 13 and number[0] == "4" and verify(number):
        print("VISA")

    elif length == 16 and number[:2] in ["51", "52", "53", "54", "55"] and verify(number):
        print("MASTERCARD")

    elif length == 16 and number[0] == "4" and verify(number):
        print("VISA")

    else:
        print("INVALID")


def verify(num):
    sum1, sum2 = 0, 0
    for i, digit in enumerate(reversed(num)):
        n = int(digit)

        if i % 2 == 0:
            sum1 += n
        else:
            n *= 2
            sum2 += n // 10 + n % 10
            
    return (sum1 + sum2) % 10 == 0


main()
