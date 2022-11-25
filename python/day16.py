import operator as op
import functools

with open('16/day16.txt', 'r') as f:
  lines = f.readlines()

hex = lines[0].strip()

packet = bin(int('1'+hex, 16))[3:]

parse_header = lambda x: (int(x[:3], 2), int(x[3:6], 2), x[6:])

def parse_literal(packet):
  number = ''
  while packet[0] != '0':
    number += packet[1:5]
    packet = packet[5:]
  number += packet[1:5]
  packet = packet[5:]
  
  return int(number, 2), packet

def checkForEnd(packet):
  if all(char == '0' for char in packet):
    return True
  
  return False


def parse_packet(packet):
  version, type_id, rest = parse_header(packet)

  if type_id == 4:
    return parse_literal(rest)
  else:
    if type_id == 0:
      calc = sum
    elif type_id == 1:
      calc = lambda items: functools.reduce(op.mul, items, 1)
    elif type_id == 2:
      calc = min
    elif type_id == 3:
      calc = max
    elif type_id == 5:
      calc = lambda items: 1 if op.gt(*items) else 0
    elif type_id == 6:
      calc = lambda items: 1 if op.lt(*items) else 0
    else:
      calc = lambda items: 1 if op.eq(*items) else 0

    length_id = rest[0]
    numbers = []
    if length_id == '0':
      length = int(rest[1:16], 2)
      packet = rest[16:length+16]
      while packet:
        number, packet = parse_packet(packet)
        numbers.append(number)
      packet = rest[length+16:]
      
    else:
      length = int(rest[1:12], 2)
      packet = rest[12:]
      for _ in range(length):
        number, packet = parse_packet(packet)
        numbers.append(number)
    
    print(numbers)
    return calc(numbers), packet

print(parse_packet(packet))
