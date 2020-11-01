class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        int i=0,j=0,n=nums.size();
        for(i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                j=1;
                break;
            }
        }
        if(!j)
        {
            nums.push_back(0);
            n++;
        }    
        i=0,j=0;
        while(i<n)
       {
            if(nums[i] == i)
                   i++;
            else if(nums[i] < n && nums[i]>=0)
           {
               j = nums[nums[i]];
                if(j == nums[i])
                {
                    i++;
                }
                else
                {
                nums[nums[i]] = nums[i];
                nums[i] = j;
                    if(nums[i] == i)
                   i++;
                }
               
                
           }
            else
            {
                i++;
            }
       }
        for(i=1;i<n;i++)
        {
            if(nums[i] != i)
            {
                return i;
            }
        }
        return i;
    }
};
