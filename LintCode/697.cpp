class Solution {
public:
    /*
     * @param : the given number
     * @return: whether whether there're two integers
     */
    bool checkSumOfSquareNumbers(int num) {
        for (int i = 0; i <= sqrt(num); ++i) {
            int j = sqrt(num - i * i);
            if (i * i + j * j == num)
                return true;
        }
        return false;
    }
};