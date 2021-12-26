import numpy as np
import heapq

with open('09/day9.txt', 'r') as f:
  lines = f.readlines()

entries = np.array([list(map(int, list(string.strip()))) for string in lines])
bigy, bigx = entries.shape

def get_neighbors(x, y):
  if x + 1 < bigx:
    yield (x + 1, y)
  
  if x - 1 >= 0:
    yield (x - 1, y)

  if y + 1 < bigy:
    yield (x, y+1)
  
  if y - 1 >= 0:
    yield (x, y-1)


def bfs(coord):
  size = 0
  level = [coord]
  seen = set()
  while level:
    nxt_level = []
    for c in level:
      if c not in seen:
        seen.add(c)
        size += 1
      x, y, = c
      for new_coord in get_neighbors(x, y):
        new_x, new_y = new_coord
        if new_coord not in seen and entries[new_y][new_x] > entries[y][x] and entries[new_y][new_x] != 9:
          nxt_level.append(new_coord)

    level = nxt_level
  return size

agenda = []
for y in range(len(entries)):
  for x in range(len(entries[0])):
    for new_coord in get_neighbors(x, y):
      new_x, new_y = new_coord
      if entries[y][x] >= entries[new_y][new_x]:
        break
    agenda.append((x, y))

results = []
for m in agenda:
  results.append(bfs(m))

heapq.heapify(results)
ans = 1
three_largest = heapq.nlargest(3, results)
for num in three_largest:
  ans *= num

print(ans)
    
