import sys

def print_ans(arr):
    for i in range(K):
        print(arr[i], end = "")
    print()

def Try(arr, i, arr_choose, count):
    for j in range(N):
        if arr_choose[j] == 0:
            arr_choose[j] = 1
            arr[i-1] = j
            if i == K:
                count[0] += 1
                print_ans(arr)
            else:
                Try(arr, i+1, arr_choose, count)
            arr_choose[j] = 0

N, K = map(int, sys.stdin.readline().split())
arr = [0] * 100
arr_choose = [0] * 100
count = [0]
Try(arr, 1, arr_choose, count)
print("Số hoán vị:", count[0])