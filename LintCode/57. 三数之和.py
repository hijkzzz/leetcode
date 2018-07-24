class Solution:
    """
    @param numbers: Give an array numbers of n integer
    @return: Find all unique triplets in the array which gives the sum of zero.
    """
    def threeSum(self, numbers):
        # write your code here
        numbers.sort()
        r = []
        
        for i in range(len(numbers)):
            j = i + 1
            k = len(numbers) - 1
            while j < k:
                total = numbers[i] + numbers[j] + numbers[k]
                seq =  [numbers[i], numbers[j], numbers[k]]
                if total == 0 and seq not in r:
                    r.append(seq)
                if total > 0:
                    k -= 1
                else:
                    j += 1

        return r