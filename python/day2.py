with open('02/day2.txt', 'r') as f:
  lines = f.readlines()

entries = [tuple(string.strip().split(' ')) for string in lines]

horiz = 0
depth = 0
aim = 0
for entry in entries:
    action, value = entry
    if action == 'forward':
        horiz += int(value)
        depth += (aim * int(value))
    elif action == 'backward':
        horiz -= int(value)
        depth -= (aim * int(value))
    elif action == 'up':
      aim -= int(value)
    else:
      aim += int(value)

answer = horiz * depth
print(answer)