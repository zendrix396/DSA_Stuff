def req(nums):
    if nums == sorted(nums):
        return True
    else:
        for i in range(len(nums)):
            newlist = nums[:i] + nums[i+1:]
            if newlist == sorted(newlist):
                return True
        else:
            return False
a = req([1,2,9,5,3])
print(a)