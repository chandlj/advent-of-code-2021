with open('01/day1.txt', 'r') as f:
  lines = f.readlines()

entries = [int(string.strip()) for string in lines]

answer = 0
for i in range(1, len(entries)):
  if entries[i] > entries[i-1]:
    answer += 1

print(answer)

answer = 0
for i in range(4, len(entries)):
  if sum(entries[i-3:i]) > sum(entries[i-4:i-1]):
    answer += 1

print(answer)