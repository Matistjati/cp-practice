#!/usr/bin/env python3
import sys
import math

EPS = 1e-9

def simplex(A, b, c):
    # Solve: maximize c^T x s.t. A x <= b, x >= 0
    # Assumes b[i] >= 0 for all i (initial basic feasible solution exists: x=0, slacks=b)
    m = len(b)
    n = len(c)
    # tableau T: (m+1) x (n+m+1)
    cols = n + m + 1
    rows = m + 1
    T = [[0.0]*cols for _ in range(rows)]
    # fill constraints
    for i in range(m):
        for j in range(n):
            T[i][j] = A[i][j]
        T[i][n + i] = 1.0   # slack var
        T[i][-1] = b[i]
    # objective row (we store as -c for maximizing)
    for j in range(n):
        T[m][j] = -c[j]
    T[m][-1] = 0.0

    basis = [n + i for i in range(m)]  # basic variable index for each constraint row

    def pivot(r, col):
        inv = 1.0 / T[r][col]
        # normalize pivot row
        for j in range(cols):
            T[r][j] *= inv
        # eliminate column from other rows
        for i in range(rows):
            if i == r:
                continue
            fac = T[i][col]
            if abs(fac) > 0:
                for j in range(cols):
                    T[i][j] -= fac * T[r][j]
        basis[r] = col

    while True:
        # choose entering column (most negative coefficient in objective row)
        enter = -1
        val = -EPS
        for j in range(cols - 1):
            if T[m][j] < val:
                val = T[m][j]
                enter = j
        if enter == -1:
            break  # optimal

        # choose leaving row by min ratio
        leave = -1
        best = 1e300
        for i in range(m):
            a = T[i][enter]
            if a > EPS:
                ratio = T[i][-1] / a
                if ratio < best - 1e-15 or (abs(ratio - best) < 1e-15 and basis[i] > basis[leave] if leave != -1 else True):
                    best = ratio
                    leave = i
        if leave == -1:
            return float('inf'), None  # unbounded
        pivot(leave, enter)

    # extract solution (only original n vars)
    x = [0.0]*n
    for i in range(m):
        if basis[i] < n:
            x[basis[i]] = T[i][-1]
    opt = T[m][-1]
    return opt, x

def main():
    data = sys.stdin.read().strip().split()
    if not data:
        return
    it = iter(data)
    M = int(next(it)); N = int(next(it))
    x = [float(next(it)) for _ in range(N)]
    A = []
    b = []
    for _ in range(M):
        t = float(next(it))
        b.append(t)
        row = []
        for j in range(N):
            row.append(float(next(it)))
        A.append(row)
    # maximize sum_j x_j * p_j
    opt, sol = simplex(A, b, x)
    if opt == float('inf'):
        # problem unbounded -> we could print a large number or handle it.
        # Here we print a large integer placeholder (problem instances usually bounded).
        print("INF")
    else:
        # Floor the result, careful with floating rounding
        ans = math.floor(opt + 1e-9)
        print(ans)

if __name__ == "__main__":
    main()
