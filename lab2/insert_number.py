n = int(input())
a = list(map(int, input().split()))
k, p = map(int, input().split())
for i in range(p - 1):
    print(a[i], end=' ')
print(k, end=' ')
for i in range(p - 1, n):
    print(a[i], end=' ')
