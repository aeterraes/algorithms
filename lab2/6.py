def merge(left, right):
    it1, it2 = 0, 0
    res = []
    l, r = len(left), len(right)
    while it1 < l and it2 < r:
        if left[it1] <= right[it2]:
            res.append(left[it1])
            it1 += 1
        else:
            res.append(right[it2])
            it2 += 1
    res.extend(left[it1:])
    res.extend(right[it2:])
    return res

def merge_sort(a):
    n = len(a)
    if n == 1:
        return a
    left = merge_sort(a[:(n // 2)])
    right = merge_sort(a[(n // 2):])
    res = merge(left, right)
    return res

n = int(input())
a = list(map(int, input().split()))
b = merge_sort(a)
for i in range(n):
    print(b[i], end=' ')
