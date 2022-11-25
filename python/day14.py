from collections import Counter

with open('14/day14.txt', 'r') as f:
  lines = f.readlines()

entries = [line.strip() for line in lines if line != '\n']

polymer = entries[0]
rules = dict(tuple(rule.split(' -> ')) for rule in entries[1:])

for _ in range(40):
  new_p = ''
  for i in range(len(polymer) - 1):
    char = rules[polymer[i:i+2]]
    new_p += f'{polymer[i]}{char}'
  new_p += polymer[-1]
  polymer = new_p

counts = Counter(polymer)
common = counts.most_common()
ans = common[0][1] - common[-1][1]
print(ans)