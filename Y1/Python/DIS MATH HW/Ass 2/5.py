import math

def sieve(num):
    max_prime = int(num/2)+1
    prime = [True for i in range(max_prime)]
    list_prime = []
    for index, isprime in enumerate(prime):
        if index == 0 or index == 1:
            prime[index] = False
        elif isprime:
            for i in range((index)**2,max_prime,index):

                prime[i] = False

    for index,i in enumerate(prime):
        if i :
            list_prime.append(index)

    return list_prime

print(sieve(32505779))