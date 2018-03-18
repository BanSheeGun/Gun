class Solution {
public:
    /*
     * @param x: An integer
     * @return: The sqrt of x
     */
    int sqrt(int x) {
        if(x == 0) return 0;   
        double result = x; 
        double lastValue;   
        do{   
            lastValue = result;   
            result = result / 2.0 + x / 2.0 / result;   
        } while(abs(result - lastValue) > 1e-4);  
        return (int)result;  
    }
};