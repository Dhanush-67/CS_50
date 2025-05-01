from cs50 import get_float

while True:
    amount = get_float("Enter: ")
    if amount >= 0:
        amount *= 100
        break

coins = 0

for n in [25, 10, 5, 1]:
    if amount >= n:
        coins += int(amount/n)
        amount -= int(amount/n)*n

print(int(coins))
