class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices) == 1:
            return 0
        max_profit = 0
        left_idx = 0
        for right_idx in range(1, len(prices)):
            current_profit = prices[right_idx] - prices[left_idx]
            if current_profit <= 0:
                left_idx = right_idx
            max_profit = max(max_profit, current_profit)
        return max_profit