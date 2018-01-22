test=0
n=1
product=1
test=int(raw_input())
while test:
    n=int(raw_input())
    for i in range(1,n+1):
        product=product*i
    print(product)
    product=1
    test=test-1   