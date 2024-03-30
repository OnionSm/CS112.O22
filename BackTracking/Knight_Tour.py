def check_pos(i,j):
    if i<0 or j < 0 or i >= N or j >= N:
        return False
    return True
def print_ans(arr):
    for i in range(N):
        for j in range(N):
            print(arr[i][j], end = " ")
        print()
    print()
def Try(step, i, j, board, I, J):
    for k in range(8):
        next_pos_i = i + I[k]
        next_pos_j = j + J[k]
        if check_pos(next_pos_i,next_pos_j) and board[next_pos_i][next_pos_j] == 0:
            board[next_pos_i][next_pos_j] = step + 1
            if step == N*N -1:
                print_ans(board)
                return
            else:
                Try(step+1, next_pos_i, next_pos_j, board, I, J)
            board[next_pos_i][next_pos_j] = 0

N = int(input())
I = [-2,-1,1,2,2,1,-1,-2]
J = [1,2,2,1,-1,-2,-2,-1]
board = [[0 for i in range(N)] for j in range(N)]
Try(0, 3, 3, board, I, J)