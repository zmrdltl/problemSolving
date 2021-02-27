while True:
	line = int(input())
	if line == 0:
		break

	post = [] 
	for i in range(line):
		post.append(input())

	index = 0
	for line in post:
		isPresent = False  
		for char in range(index, len(line)):
			if line[char] == ' ':
				index = char
				isPresent = True
				break
			if isPresent == False:
				if index < len(line):
					index = len(line)
	print (index+1)
