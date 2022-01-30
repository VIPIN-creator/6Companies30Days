 int divide(int dividend, int divisor) {
        int A = dividend, B = divisor, ans = 0, temp, m;
        if(A == INT_MIN && B == -1) return INT_MAX;
        if(A == INT_MAX && B == 1) return INT_MAX;
        if(A == INT_MIN && B == 1) return INT_MIN;
        
        if(B == INT_MAX) return (A == INT_MAX);

        bool neg = (B<0)^(A<0);
        int a = abs(A);
        int b = abs(B);
       if(a == INT_MIN) a = INT_MAX;
        cout << a << endl;
        while(a-b >= 0){
            m = 1; temp = b;
            // cout << temp;
            while((temp << 1) <= (INT_MAX>>1) && (temp << 1) <= a ){
                m<<=1;
                temp<<=1;
            }
            ans += m;
                        cout << temp <<  " ";

            a = a-temp;
        }
        
        if(neg) return (-ans);
        return ans;
        
    }
