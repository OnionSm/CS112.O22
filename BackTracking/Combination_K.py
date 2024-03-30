import sys
def print_ans(arr):
    for i in range(K):
        print(arr[i+1], end = "")
    print()
def Try(arr, i):
    for j in range(arr[i-1]+1,N-K+i+1):
        arr[i] = j
        if i == K:
            print_ans(arr)
        else:
            Try(arr,i+1)
N, K = map(int,sys.stdin.readline().split())
arr = [0] * 100
Try(arr,1)

