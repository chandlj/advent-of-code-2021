import numpy as np

with open("11/day11.txt", 'r') as f:
  lines = f.readlines()

entries = np.array([list(map(int, *line.split())) for line in lines])
Y, X = entries.shape
N = len(entries.flatten())

STEPS = 100

def isValidCoord(coord):
  x, y = coord
  if 0 <= x < X and 0 <= y < Y: return True
  return False

def get_neighbors(x, y, seen):
  for neighbor in [(xprime, yprime) for xprime in range(x-1, x+2) for yprime in range(y-1, y+2)]:
    if isValidCoord(neighbor) and neighbor not in seen:
      yield neighbor

def flash_coord(entries, coord, seen):
  flashes = 1
  seen.add(coord)
  entries[coord] = 0
  for neighbor in get_neighbors(*coord, seen):
    entries[neighbor] += 1
    if entries[neighbor] > 9:
      flashes += flash_coord(entries, neighbor, seen)
  return flashes

# flashes = 0
done = False
steps = 0
while not done:
  seen = set()
  steps += 1
  for coord in [(x, y) for x in range(X) for y in range(Y)]:
    entries[coord] += 1
  for coord in [(x, y) for x in range(X) for y in range(Y)]:
    if entries[coord] > 9 and coord not in seen:
      if flash_coord(entries, coord, seen) == N:
        done = True

print(steps)