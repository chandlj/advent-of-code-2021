import numpy as np

with open('07/day7.txt', 'r') as f:
  entries = list(map(int, f.readline().strip().split(',')))

global_min = float('inf')
for i, target in enumerate(range(1, max(entries) // 2)):
  # target = round(np.mean(entries))
  fuel = 0
  for entry in entries:
    n = abs(entry - target)
    fuel += int(n + ((n*(n+1)) / 2))
  
  if fuel < global_min:
    global_min = fuel

print(global_min)