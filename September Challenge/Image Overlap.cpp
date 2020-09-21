class Solution {
int lo_helper(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n = A.size(), maxOverlap = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                int currOverlap = 0;
                for (int ii=i; ii<n; ii++) {
                    for (int jj=j; jj<n; jj++) {
                        currOverlap += (A[ii-i][jj-j]*B[ii][jj]);
                    }
                }
                cout<<currOverlap<<endl;
                maxOverlap = max(maxOverlap, currOverlap);
            }
        }
        return maxOverlap;
    }
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int AB = lo_helper(A,B);
        int BA = lo_helper(B,A);
        return max(AB,BA);
    }
};