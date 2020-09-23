class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int i,j,k,n = gas.size();
        if(!n)
            return -1;
        if(n==1)
        {
            if(gas[0] >= cost[0])
                return 0;
            else
                return -1;
        }
        int start = 0,end = 1;
        int g = gas[0]-cost[0];
        while(start!=end)
        {
            while(g<0 && start!=end)
            {
                g = g - (gas[start]-cost[start]);
                start = (start+1)%n;
                if(start == 0)
                    return -1;
            }
            g += gas[end]-cost[end];
            end = (end+1)%n;
        }
        if(g<0)
            return -1;
        return start;
    }
};
