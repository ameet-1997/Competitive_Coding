def read_robot(name):
  l = map(int, raw_input().split())
  return [l[:3], l[3:]]

def robo_sub(a, b): return [a[0]-b[0],a[1]-b[1],a[2]-b[2]]
def robo_add(a, b): return [a[0]+b[0],a[1]+b[1],a[2]+b[2]]

def next_position(robot):
  for i in range(3):
    if robot[0][i] <> robot[1][i]:
      p = robot[0][:]
      p[i] += (1 if robot[0][i] < robot[1][i] else -1)
      return p
  return robot[0]

def finished(robot):
  return robot[0] == robot[1]

def format_bot(robot):
  return '(%d %d %d)' % (robot[0], robot[1], robot[2])

def print_bots(*robots):
  print ' '.join(map(format_bot, robots))

robots = map(read_robot, range(2))
print_bots(robots[0][0], robots[1][0])

polite_bot = 0
while sum(map(finished, robots)) < 2:
  nobots = map(next_position, robots)
  if (nobots[0] == robots[1][0] and nobots[1] == robots[0][0] or
      nobots[0] == nobots[1] and (finished(robots[0]) or finished(robots[1]))):
    axis = robo_sub(robots[0][0], robots[1][0])
    nobots[polite_bot] = robo_add(robots[polite_bot][0], axis[1:] + axis[:1])
    polite_bot = 1 - polite_bot
  elif nobots[0] == nobots[1]:
    nobots[polite_bot] = robots[polite_bot][0]
    polite_bot = 1 - polite_bot

  robots[0][0] = nobots[0]
  robots[1][0] = nobots[1]
  print_bots(*nobots)