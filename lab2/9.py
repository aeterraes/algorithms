def quicksort(a, l, r):
    if l < r:
        p = partition(a, l, r)
        quicksort(a, l, p)
        quicksort(a, p + 1, r)

def partition(a, l, r):
    p = a[(l + r) // 2]
    i = l
    j = r
    while i <= j:
        while a[i] < p:
            i += 1
        while a[j] > p:
            j -= 1
        if i >= j:
            break
        a[i], a[j] = a[j], a[i]
        i += 1
        j -= 1
    return j
def p(a, n):
    for i in range(n):
        print(a[i], end=' ')
        
n = int(input())
a = list(map(int, input().split()))
quicksort(a, 0, n - 1)
p(a, n)