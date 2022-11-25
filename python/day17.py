import re

with open('17/day17.txt', 'r') as f:
  line = f.read()

x_range, y_range = re.findall('(-?\d+)..(-?\d+)', line)

map_int = lambda tupl: tuple([*map(int, tupl)])
x_range = map_int(x_range)
y_range = map_int(y_range)

checkTarget = lambda x, y: x_range[0] <= x <= x_range[1] and y_range[0] <= y <= y_range[1]
inBounds = lambda x, y: x <= x_range[1] and y >= y_range[0]

def simulate(vx, vy):
  x, y, max_y = 0, 0, 0
  hitTarget = False
  while not hitTarget and inBounds(x, y):
    x += vx
    y += vy
    max_y = max(max_y, y)
    vx -= 1 if vx > 0 else 0
    vy -= 1

    hitTarget = checkTarget(x, y)

  return max_y if hitTarget else None

velos = []
for vx in range(1000):
  for vy in range(-1000, 1000):
    if simulate(vx, vy) is not None:
      velos.append((vx, vy))

print(len(set(velos)))


