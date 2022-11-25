import numpy as np

with open('04/day4.txt', 'r') as f:
  lines = f.readlines()

numbers = lines[0].strip().split(',')
boards = [lines[i:i+5] for i in range(2, len(lines), 6)]

for board in boards:
  for i in range(len(board)):
    board[i] = board[i].strip().split()

boards = [np.array(board) for board in boards]
N = len(boards)

chosen = set()

def checkBoard(board):
  for line in board:
    if all(item in chosen for item in line): return True
  
  for line in board.T:
    if all(item in chosen for item in line): return True

  # for i in range(len(board)):
  #   rowTrue = True
  #   colTrue = True
  #   for j in range(len(board)):
  #     if board[i][j] not in chosen: rowTrue = False
  #     if board[j][i] not in chosen: colTrue = False

  #   if rowTrue: return True
  #   if colTrue: return True

  return False

def runSim(boards, chosen):
  for num in numbers:
    chosen.add(num)
    nxt = []
    if len(boards) == 1:
      if checkBoard(boards[0]): return boards[0], int(num)
      else:
        continue
    else:
      for board in boards:
        if not checkBoard(board):
          nxt.append(board)
      
      boards = nxt

winner, num = runSim(boards, chosen)

print(num * sum([int(element) for element in winner.flatten() if element not in chosen]))


