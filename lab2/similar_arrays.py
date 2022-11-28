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
k = int(input())
b = list(map(int, input().split()))
a1 = merge_sort(a)
b1 = merge_sort(b)
a2 = []
a2.append(a1[0])
b2 = []
b2.append(b1[0])
for i in range(1, n):
    if a1[i - 1] != a1[i]:
        a2.append(a1[i])
for i in range(1, k):
    if b1[i - 1] != b1[i]:
        b2.append(b1[i])
if len(a2) != len(b2):
    print("NO")
else:
    flag = True
    for i in range(len(a2)):
        if (a2[i] != b2[i]):
            flag = False
            break
    if flag:
        print("YES")
    else:
        print("NO")
