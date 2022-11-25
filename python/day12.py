from collections import defaultdict

with open('12/day12.txt', 'r') as f:
  lines = f.readlines()

paths = [tuple(line.strip().split('-')) for line in lines]
graph = defaultdict(list)

for start, end in paths:
  graph[start].append(end)
  graph[end].append(start)

all_paths = []

def dfs(node, seen, path):
  if node == 'end':
    all_paths.append(path)
    return 1

  paths = 0
  for neighbor in graph[node]:
    if seen[neighbor] > 0:
      new_seen = seen.copy()
      if not (neighbor.istitle() or neighbor.isupper()) and neighbor != 'end':
        new_seen[neighbor] -= 1
      new_path = tuple([*path, neighbor])
      paths += dfs(neighbor, new_seen, new_path)

  return paths

start_seen = {k:1 for k in graph.keys()}
s = 'start'
start_seen[s] = 0
path = tuple([s])
for k in graph.keys():
  if k != s:
    seen = start_seen.copy()
    seen[k] = 2
    dfs(s, seen, path)
print(len(set(all_paths)))

# start,A,b,A,end
# start,A,b,end
# start,A,c,A,b,end
# start,A,c,A,end
# start,A,end
# start,b,A,c,A,end
# start,b,A,end
# start,b,end

# start,A,c,A,b,A,end
# start,A,b,A,c,A,end