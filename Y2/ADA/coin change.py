def coin_change(coins, amount):
    dp = [float('inf') for _ in range(amount + 1)]
    dp[0] = 0

    for coin in coins:
        for i in range(coin, amount + 1):
            dp[i] = min(dp[i], dp[i - coin] + 1)

    return dp[amount] if dp[amount] != float('inf') else -1


def coin_change_recursion(coins, amount):
    memo = {}

    def helper(amount):
        if amount in memo:
            return memo[amount]
        if amount == 0:
            return 0
        if amount < 0:
            return float('inf')

        min_coins = float('inf')
        for coin in coins:
            min_coins = min(min_coins, helper(amount - coin) + 1)

        memo[amount] = min_coins
        return memo[amount]

    result = helper(amount)
    return result if result != float('inf') else -1


test = ([1, 2, 5], 11)
print(coin_change(*test))
print(coin_change_recursion(*test))