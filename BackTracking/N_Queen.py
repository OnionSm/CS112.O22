import sys

def print_ans(arr):
    for i in range(N):
        for j in range(N):
            print(arr[i][j], end = " ")
        print()
    print()

def Try(col, i, line_1, line_2,arr, count):
    for j in range(N):
        if col[j] == 0 and line_1[i-j+N-1] == 0 and line_2[i+j] == 0:
            col[j] = line_1[i-j+N-1] = line_2[i+j] = 1
            arr[i][j] = 1
            if i == N-1:
                count[0] += 1
                print_ans(arr)
            else:
                Try(col, i+1, line_1, line_2,arr, count)
            arr[i][j] = 0
            col[j] = line_1[i - j + N - 1] = line_2[i + j] = 0
N = int(sys.stdin.readline())
arr = [[0 for i in range(N)] for j in range(N)]
print_ans(arr)
col = [0] * N
line_1 = [0] * (2*N-1)
line_2 = [0] * (2*N-1)
count = [0]
Try(col, 0, line_1, line_2,arr, count)
print("Số cách sắp xếp bàn cờ : {}".format(count[0]))
