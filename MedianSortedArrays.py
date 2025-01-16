def findMedianSortedArrays(nums1, nums2):
    # newList = []
    # for i in nums1: newList.append(i)
    # for j in nums2: newList.append(j)
    # newList = sorted(newList)
    # median = 0
    # if len(newList)%2 == 0:
    #     median = (newList[int(len(newList)/2)-1]+newList[int(len(newList)/2)])/2
    #     return median
    # elif len(newList)==0:
    #     pass
    # elif len(newList) == 1:
    #     return newList[0]
    # else:
    #     median = newList[int((len(newList)+1)/2)-1]
    #     return median
    # num1=3, and num2 = 7 ...,.......
    # num1 =3, and num2 = 6 ...,......
    """p = sorted(nums1+nums2)
    nums1, nums2 = p[:len(nums1)], p[len(nums1):]
    req = len(nums1+nums2)
    biggerlist = nums2 if len(nums2)>len(nums1) else nums1
    if req == 1:
        return (nums1+nums2)[0]
    elif req%2==0:
        a9 = nums1[len(nums1)-1:][0]
        a10 = nums2[0]
        if len(nums1) == len(nums2): return (a9+a10)/2
        a = int(req/2)
        n = len(biggerlist)-a-1
        return (biggerlist[n]+biggerlist[n+1])/2
    else:
        a = int((req+1)/2)
        return biggerlist[len(biggerlist)-a if biggerlist==nums2 else len(biggerlist)-a+1]"""
    


a = findMedianSortedArrays([3,4],[1,2])
print(a)


