words1 = ["amazon","apple","facebook","google","leetcode"]
words2= ["lo","eo"]

res= []
for p in words1:
    listp = list(p)
    print(f"listp: {listp}")
    newlistt = []
    for k in words2:
        newlist = list(k)
        print(f"newlist: {newlist}")
        for i in newlist:
            if i in listp:
                newlistt.append(i)
                listp.remove(i)
        
    newlistt = "".join(sorted(newlistt))
    newlist = "".join(sorted(newlist))
    if newlist == newlistt:
        res.append(p)
print(res)

        
        


            
    

