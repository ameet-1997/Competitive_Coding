test = 0
test = int(raw_input()) 

for i in range(test):
	s = raw_input()
	s = s.strip().split()
	# print(s)
	for j in range(len(s)):
		s[j] = s[j].lower()
	# print(s)
	if len(s) > 1:
		for j in range(len(s)-1):
			print(s[j][0:1].upper()+"."),
	print(s[-1].capitalize())
