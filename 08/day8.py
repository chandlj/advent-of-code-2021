with open('08/day8_test.txt', 'r') as f:
  lines = f.readlines()

entries = [tuple(map(lambda string: string.split(), line.strip().split(' | '))) for line in lines]
for entry in entries:
  mapping = {num:'' for num in range(1, 10)}
  encoded = entry[0]
  encoded.sort(key=len)
  print(encoded)
  one = encoded.pop(0)
  seven = encoded.pop(0)
  four = encoded.pop(0)
  eight = encoded.pop()
  mapping[1] = one
  mapping[7] = seven
  mapping[4] = four
  mapping[8] = eight
  eight
  for x in encoded:
    if len(set(eight) - set(x)) == 1: print(x)
    # print(eight, x)
# ans = 0
# for entry in entries:
#   for digit in entry:
#     if len(digit) in [2, 3, 4, 7]:
#       ans += 1

# print(ans)