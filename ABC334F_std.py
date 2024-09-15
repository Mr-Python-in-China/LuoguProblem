N = int(input())
P = [list(map(int, input().split())) for _ in range(N)]
R = [list(map(int, input().split())) for _ in range(N)]
D = [list(map(int, input().split())) for _ in range(N - 1)]
INF = 10**18
dp = [[(INF, 0) for j in range(N)] for i in range(N)]
dp[0][0] = (0, 0)
for i in range(N):
    for j in range(N):
        dist = [[INF for x in range(j + 1)] for y in range(i + 1)]
        dist[i][j] = 0
        for y in range(i, -1, -1):
            for x in range(j, -1, -1):
                if y < i:
                    dist[y][x] = min(dist[y][x], D[y][x] + dist[y + 1][x])
                if x < j:
                    dist[y][x] = min(dist[y][x], R[y][x] + dist[y][x + 1])
                c = max(0, dist[y][x] - dp[y][x][1] + P[y][x] - 1) // P[y][x]
                t = dp[y][x][0] + c + i - y + j - x
                m = dp[y][x][1] + c * P[y][x] - dist[y][x]
                if t < dp[i][j][0] or t == dp[i][j][0] and m > dp[i][j][1]:
                    dp[i][j] = (t, m)
print(dp[N - 1][N - 1][0])