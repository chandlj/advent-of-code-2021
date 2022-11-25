with open('10/day10.txt', 'r') as f:
  lines = f.readlines()

entries = [list(line.strip()) for line in lines]
openings = set(['(', '<', '[', '{'])
closing_map = {'(': ')', '<': '>', '[': ']', '{': '}'}
errors = []
for entry in entries:
  stack = []
  incomplete = True
  for char in entry:
    if char in openings:
      stack.append(char)
    else:
      opening = stack.pop()
      if closing_map[opening] != char:
        incomplete = False
        break
  if incomplete:
    errors.append([closing_map[opening] for opening in stack][::-1])

scores = []
for err in errors:
  score = 0
  for close in err:
    score *= 5
    if close == ')': score += 1
    elif close == ']': score += 2
    elif close == '}': score += 3
    else: score += 4
  scores.append(score)

scores.sort()
print(scores[len(scores) // 2])

# Part 1
# ans = 0
# for err in errors:
#   if err == ')': ans += 3
#   elif err == ']': ans += 57
#   elif err == '}': ans += 1197
#   else: ans += 25137

