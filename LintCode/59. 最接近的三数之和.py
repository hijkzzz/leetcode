class Solution:
    """
    @param numbers: Give an array numbers of n integer
    @param target: An integer
    @return: return the sum of the three integers, the sum closest target.
    """
    def threeSumClosest(self, numbers, target):
        # write your code here
        numbers.sort()
        minn = float('inf')
        r = None
        
        for i in range(len(numbers)):
            j = i + 1
            k = len(numbers) - 1
            while j < k:
                total = numbers[i] + numbers[j] + numbers[k]
                
                if abs(total - target) < minn:
                    minn = abs(total - target)
                    r = total

                if total > target:
                    k -= 1
                else:
                    j += 1

        return r