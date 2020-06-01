/**
In a town, there are N people labelled from 1 to N.  There is a rumor that one of these people is secretly the town judge.

If the town judge exists, then:

    The town judge trusts nobody.
    Everybody (except for the town judge) trusts the town judge.
    There is exactly one person that satisfies properties 1 and 2.

You are given trust, an array of pairs trust[i] = [a, b] representing that the person labelled a trusts the person labelled b.

If the town judge exists and can be identified, return the label of the town judge.  Otherwise, return -1.
 */


class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        int judgeT[N+1];
        int peopleTrust[N+1];
        
        for(int i = 0; i < N+1; i++){
            judgeT[i] = 0;
            peopleTrust[i] = 0;
        }
        
        for(int i = 0; i < trust.size(); i++){
            peopleTrust[trust[i][1]]++;
            judgeT[trust[i][0]]++;
        }
        
        for(int i = 1; i < N+1; i++){
            if(peopleTrust[i] == N-1 && judgeT[i] == 0){
                return i;
            }
        }
        return -1;
    }
};
