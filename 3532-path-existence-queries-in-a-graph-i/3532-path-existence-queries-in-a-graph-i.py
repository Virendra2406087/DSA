class Solution:
    def pathExistenceQueries(self, n: int, nums: List[int], maxDiff: int, queries: List[List[int]]) -> List[bool]:
        root=[i for i in range(n)]
        start=0
        for i in range(1,n):
            if nums[i]-nums[i-1]<=maxDiff:
                root[i]=start
            else :
                start=i
        
        ans=[]
        for u,v in queries:
            ans.append(root[u]==root[v])

        return ans
        