
def maxProfit(prices):
    """
    :type prices: List[int]
    :rtype: int
    """
    min_p = prices[0]
    profit = 0
    for i in prices:
        if i < min_p:
            min_p = i
        elif min_p == -1:
            min_p = i
        elif i > min_p:
            print(i, min_p)
            profit += i - min_p
            min_p = -1


    return profit

#test
prices = [1,2,3,4,5]
print(maxProfit(prices))
