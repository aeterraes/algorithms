def insertion_sort(a, n):
    for i in range(1, n):
        j = i - 1
        ok = 0
        while j >= 0 and a[j] > a[j + 1]:
            a[j], a[j + 1] = a[j + 1], a[j]
            j -= 1
            ok = 1
        if ok:
            cur(a, n)

def cur(a, n):
    for i in range(n):
        print(a[i], end=' ')
    print()

n = int(input())
a = list(map(int, input().split()))
insertion_sort(a, n)