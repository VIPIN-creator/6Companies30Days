 bool winnerOfGame(string colors) {
        int cnta = 0,  cntb = 0, ans1 = 0, ans2 = 0;
        for(auto c : colors){
            if(c == 'A'){
                cnta++;
                ans2 += max(0, cntb-2);
                cntb = 0;
            }
            else {
                cntb++;
                ans1 += max(cnta-2, 0);
                cnta = 0;
            }
        }
        ans2 += max(0, cntb-2);
        ans1 += max(cnta-2, 0);
        
        return ans1 > ans2;
    }
