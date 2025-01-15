class Solution {
public:
    int bits(int n){
        int count = 0;
        while(n) count += n & 1, n >>= 1;
        return count;
    }

    int minimizeXor(int num1, int num2) {
        int res = num1;
        int a = bits(res);
        int b = bits(num2);
        if(b == 31) return (1 << 31) - 1;
        int msb = 31;
        
        for(int i = 0; i <= msb && a != b; i++){
            if(a > b && ((1 << i) & res)){
                res &= ~(1 << i);
                a--;
            } else if(a < b && !((1 << i) & res)){
                res |= (1 << i);
                a++;
            }
        }
        return res;
    }
};