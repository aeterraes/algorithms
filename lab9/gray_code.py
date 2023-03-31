def bincode(x):
    if len(x) == n:
        a.append(x)
        return
    bincode(x + '0')
    revbincode(x + '1')


def revbincode(x):
    if len(x) == n:
        a.append(x)
        return
    bincode(x + '1')
    revbincode(x + '0')


n = int(input())
num = 0
a =  []
bincode("")
for i in range(len(a)):
    print(a[i])