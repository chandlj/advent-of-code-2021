from collections import Counter
import numpy as np
from typing import List

# with open('day3.txt', 'r') as f:
#   lines = f.readlines()

# entries = np.array([list(string.replace('\n', '')) for string in lines])

# gamma = ''
# epsilon = ''
# for i in range(len(entries[0])):
#   (most, _), (least, _) = Counter(entries[:, i]).most_common()
#   gamma += most
#   epsilon += least

# gamma = gamma[::-1]
# epsilon = epsilon[::-1]
# gamma_num = 0
# epsilon_num = 0
# for i in range(len(gamma)):
#   x = int(gamma[i])
#   y = int(epsilon[i])
#   gamma_num += (2 ** i) * x
#   epsilon_num += (2 ** i) * y

# print(gamma_num * epsilon_num)

with open('03/day3.txt', 'r') as f:
  lines = f.readlines()

filtered = [list(line.strip())[::-1] for line in lines]
N = len(filtered[0])

def getMostCommon(entries: List[List[str]]):
  ones = 0
  zeroes = 0
  for entry in entries:
    digit = entry[-1]
    if digit == '1': ones += 1
    else: zeroes += 1

  return ('1', '0') if ones >= zeroes else ('0', '1')

entries = filtered.copy()
oxygen = ''
for _ in range(N):
  most, least = getMostCommon(entries)
  oxygen += most
  entries = [item[:-1] for item in filter(lambda num: True if num[-1] == most else False, entries)]
  if len(entries) == 1:
    for entry in entries[0][::-1]:
      oxygen += entry
    break

entries = filtered.copy()
co2 = ''
for _ in range(N):
  most, least = getMostCommon(entries)
  co2 += least
  entries = [item[:-1] for item in filter(lambda num: True if num[-1] == least else False, entries)]
  if len(entries) == 1:
    for entry in entries[0][::-1]:
      co2 += entry
    break

oxygen = oxygen[::-1]
co2 = co2[::-1]
num1 = 0
num2 = 0
for i in range(len(oxygen)):
  x = int(oxygen[i])
  y = int(co2[i])
  num1 += (2 ** i) * x
  num2 += (2 ** i) * y

print(num1 * num2)



