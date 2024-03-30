import sys
def print_ans(arr):
    for i in range(N):
        print(arr[i], end = "")
    print()
def Try(arr, i):
    for j in range(2):
        arr[i-1] = j
        if i == N:
            print_ans(arr)
        else:
            Try(arr,i+1)
N = int(sys.stdin.readline())
arr = [0] * N
Try(arr,1)
