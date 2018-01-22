test = 0
test = int(raw_input())


for tester in range(test) :
	digits,k = raw_input().split()

	digits = int(digits)
	k = int(k)	

 	number = str(raw_input())	#number is the given number

 	product = 1

 	for i in range(k) :		#initial product of the first k digits
 		product = product*int(number[i])

 	max_product = product

 	i = k

 	while i < digits :

 		if int(number[i-k]) == 0 :
 			product = 1
 			for j in range(i-k+1,i+1) :
 				product = product*int(number[j])
 			i = i + 1

 		else :
			product = product/int(number[i-k])
	 		product = product*int(number[i])
	 		i = i + 1

 		if product > max_product :
 			max_product = product


 	print(str(max_product))


