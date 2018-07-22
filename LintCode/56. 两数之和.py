class Solution:
    """
    @param numbers: An array of Integer
    @param target: target = numbers[index1] + numbers[index2]
    @return: [index1, index2] (index1 < index2)
    """
    def twoSum(self, numbers, target):
        # write your code here
        d = {}
        for i in range(len(numbers)):
            differ = target - numbers[i] 
            if differ in d:
                return [d[differ], i]
            d[numbers[i]] = i
        return []