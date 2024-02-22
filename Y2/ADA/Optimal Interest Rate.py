#optimal interest rate
def calculate_profit(rate, a, b, c):
    return a * rate**3 + b * rate**2 + c * rate

def opt(a, b, c):
    optimal_rate = 0.0
    max_profit = 0
    for rate in range(1, 2001):
        p_rate = rate/100
        profit = calculate_profit(p_rate, a, b, c)
        if profit > max_profit:
            optimal_rate = p_rate
            max_profit = profit

    return optimal_rate


inputA = float(input())
inputB = float(input())
inputC = float(input())

print(opt(inputA, inputB, inputC))