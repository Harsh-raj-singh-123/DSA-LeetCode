class Solution {
int gcdodd(int n){
    int sumodd  = 0;
    int i = 1;
    while(n > 0){
        sumodd = sumodd + i;
        i+=2;
        n--;
    }
    return sumodd;
}

int gcdeven(int n){
    int sumeven  = 0;
    int i = 2;
    while(n > 0){
        sumeven = sumeven + i;
        i+=2;
        n--;
    }
    return sumeven;
}

int gcd(int x, int y){
    if(y == 0) return x;
    if(x == 0) return y;
    return gcd(y, x%y);
}

public:
    int gcdOfOddEvenSums(int n) {
        int x = gcdodd(n);
        int y = gcdeven(n);
        int z = gcd(x, y);
        return z;
    }
};