def gcd(a, b):
    if b == 0:
        return a
    mod = int(int(a) % int(b))
    return gcd(b, mod)

n = input()
n = int(n)
primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281]
for i in range(n):
    a = input()
    a = int(a)
    num = int(1)
    j = int(0)
    div = int(1)
    while num * primes[j] <= a:
        num = num * int(primes[j])
        div = div * (int(primes[j]) + 1)
        j = j + 1
    cur_gcd = int(gcd(int(div), int(num)))
    num = int(num//cur_gcd)
    div = int(div//cur_gcd)
    print(str(num) + "/" + str(div))