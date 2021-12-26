import numpy as np

with open('05/day5.txt', 'r') as f:
  lines = f.readlines()

entries = [list(map(lambda num: tuple(map(int, num.split(','))), line.strip().replace(' -> ', ' ').split())) for line in lines]

max_x = max(x for entry in entries for x, _ in entry)
max_y = max(y for entry in entries for _, y in entry)

arr = np.zeros((max_y+1, max_x+1))

for entry in entries:
  (x1, y1), (x2, y2) = entry
  if x1 == x2:
    for y in range(min(y1, y2), max(y1, y2) + 1):
      arr[y, x1] += 1
  elif y1 == y2:
    for x in range(min(x1, x2), max(x1, x2) + 1):
      arr[y1, x] += 1
  else:
    if x1 < x2:
      for i, x in enumerate(range(x1, x2 + 1)):
        if y1 < y2:
          arr[y1 + i, x] += 1
        else:
          arr[y1 - i, x] += 1
    else:
      for i, x in enumerate(range(x2, x1 + 1)):
        if y1 < y2:
          arr[y2 - i, x] += 1
        else:
          arr[y2 + i, x] += 1


ans = 0
for elem in arr.flatten():
  if elem > 1: ans += 1

print(ans)
