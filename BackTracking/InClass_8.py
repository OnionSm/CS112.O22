
def print_(arr_ans):
    for i in range(3):
        print(arr_ans[i], end = " ")
    print()
def Try(arr, arr_ans, i, n, diem):
    for j in range(0, 41, 1):  # Using integers instead of floats for indexing
        arr_ans[i] = j / 4  # Adjusting for float values
        if i == n - 1:
            tong = 0
            for k in range(0, n):
                tong = tong + arr[k] * arr_ans[k]
            if diem in [tong , tong  + 0.05]:
                print_(arr_ans)
        else:
            Try(arr, arr_ans, i + 1, n, diem)  # Incrementing i for recursion
n = 3
arr = [0.2,0.3,0.5]
arr_ans = [0,0,0]
diem = 9.5
Try(arr,arr_ans,0,n,diem)
