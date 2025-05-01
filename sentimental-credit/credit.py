def main():

    number = input("Enter: ")
    length = len(number)

    if length == 15 and int(number[:2]) in [34, 37] and verify(number, length):
        print("AMEX")

    elif length == 13 and int(number[:1]) == 4 and verify(number, length):
        print("VISA")

    elif length == 16 and int(number[:2]) in [51, 52, 53, 54, 55] and verify(number, length):
        print("MASTERCARD")

    elif length == 16 and int(number[:1]) == 4 and verify(number, length):
        print("VISA")

    else:
        print("INVALID")


def verify(num, len):
    list1 = []
    list2 = []
    sum1 = 0
    sum2 = 0
    for n in range(-1, ((len+1)*-1), -1):

        if abs(n) % 2 == 1:
            list1.append(int(num[n]))
        else:
            list2.append(int(num[n]))

    for n in list2:
        n *= 2
        if n >= 10:
            sum2 += int((n/10)) + (n % 10)
        else:
            sum2 += n
    sum1 += sum(list1)

    if (sum1+sum2) % 10 == 0:
        return True

main()
