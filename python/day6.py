import heapq

with open('06/day6_test.txt', 'r') as f:
  lines = f.readlines()

fish = [int(num) for num in lines[0].split(',')]
heapq.heapify(fish)

total_fish = 0
days = 256
while days > 0:
  f = fish[0]
  f += 1
  to_add = 0
  for i in range(len(fish)):
    fish[i] -= f
    if fish[i] == -1:
      fish[i] = 6
      to_add += 1

  for _ in range(to_add):
    heapq.heappush(fish, 8)

  heapq.heapify(fish)

  days -= f

print(len(fish))

  


# nxt = []
# for day in range(256):
#   print(day)
#   for f in fish:
#     f -= 1
#     if f < 0:
#       nxt.append(6)
#       nxt.append(8)
#     else:
#       nxt.append(f)

#   fish = nxt
#   nxt = []

# print(len(fish))
