import numpy as np
from numpy.core.numeric import count_nonzero

with open('13/day13.txt', 'r') as f:
  lines = f.readlines()

entries = [line.strip() for line in lines]

coords = [tuple(map(int, entry.split(','))) for entry in filter(lambda entry: ',' in entry, entries)]
commands = [entry.replace('fold along ', '').split('=') for entry in filter(lambda entry: 'fold' in entry, entries)]

max_x = max(coords, key=lambda coord: coord[0])[0]
max_y = max(coords, key=lambda coord: coord[1])[1]

arr = np.zeros((max_x+1, max_y+1))
print(arr.shape)
for coord in coords:
  arr[coord] = 1

for axis, value in commands:
  split = int(value)
  if axis == 'x':
    top_split = split if arr.shape[0] % 2 == 0 else split + 1
    arr1 = arr[0:split, :]
    arr2 = np.flipud(arr[top_split:, :])
  else:
    top_split = split if arr.shape[1] % 2 == 0 else split + 1
    arr1 = arr[:, 0:split]
    arr2 = np.fliplr(arr[:, top_split:])

  arr = arr1 + arr2


print(count_nonzero(arr))
ans = np.array([['.' for _ in range(arr.shape[1])] for _ in range(arr.shape[0])])

for i in range(arr.shape[0]):
  for j in range(arr.shape[1]):
    if arr[i][j] > 0: 
      ans[i][j] = '#'


np.savetxt('13/ans.txt', ans.T, fmt='%s')