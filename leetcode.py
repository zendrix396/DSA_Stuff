def removeDuplicates(nums) -> int:
    res = []
    for i in nums:
        if i not in res:
            res.append(i)
    return len(res)

a = removeDuplicates([0,0,1,1,1,2,2,3,3,4])
print(a)