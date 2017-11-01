class Solution {
public:
    /*
     * @param A: an integer array
     * @return: 
     */
    void sortIntegers(vector<int> &A) {
        for (int i = 0; i < (int)A.size(); ++i)
            for (int j = i + 1; j < (int)A.size(); ++j)
                if (A[i] > A[j])
                    swap(A[i], A[j]);
    }
};