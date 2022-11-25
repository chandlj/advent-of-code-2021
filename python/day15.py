with open('15/day15.txt', 'r') as f:
  lines = f.readlines()

grid = [list(map(int, [*line.strip()])) for line in lines]
memo = [[float('inf') for _ in range(len(grid[0]))] for _ in range(len(grid))]

for row in range(len(grid) - 1, -1, -1):
  for col in range(len(grid[0]) - 1, -1, -1):
    if (row + 1) < len(grid) and (col + 1) < len(grid[0]):
      bottom = memo[(row+1)][col]
      right = memo[row][(col+1)]
      path = min(bottom, right)
    elif (col + 1) < len(grid[0]):
      path = memo[row][(col+1)]
    elif (row + 1) < len(grid):
      path = memo[(row+1)][col]
    else:
      path = 0

    memo[row][col] = grid[row][col] + path

ans = memo[0][0] - grid[0][0]
print(ans)
