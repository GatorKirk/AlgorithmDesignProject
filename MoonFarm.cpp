#include <bits/stdc++.h>
#include "solution.h"
using namespace std;



int main(){

    vector<int> nums={-2,11,-3,7};

    vector<vector<int> > matrix = { { 0, -2, -7, 0 },
                                    { 9, 2, -6, 2 },
                                    { -4, 1, -4, 1 },
                                    { -1, 8, 0, -2 } };
    //vector<vector<int>> matrix1={};
    //vector<vector<int>> ansmatrix;
    answer ansDPN1,ansBrute,ansDPN2;
    answerMatrix ansN3,ansN6,ansN4;
    Solution mysolution;                        //Define a solution class

    ansBrute=mysolution.maxSubArrayBrute(nums);
    cout<<ansBrute.l<<' '<<ansBrute.r<<' '<<ansBrute.sum<<endl;

    ansDPN2=mysolution.maxSubArrayDPN2(nums);
    cout<<ansDPN2.l<<' '<<ansDPN2.r<<' '<<ansDPN2.sum; 
    
    ansDPN1=mysolution.maxSubArrayBottomUp(nums);
    cout<<ansDPN1.l<<' '<<ansDPN1.r<<' '<<ansDPN1.sum<<endl;

    ansN6=mysolution.maxSubmatrixSumN6(matrix);
    cout<<ansN6.x1<<' '<<ansN6.y1<<' '<<ansN6.x2<<' '<<ansN6.y2<<' '<<ansN6.sum<<endl;
    ansN3=mysolution.maxSubmatrixSumN3(matrix);
    cout<<ansN3.x1<<' '<<ansN3.y1<<' '<<ansN3.x2<<' '<<ansN3.y2<<' '<<ansN3.sum<<endl;
    ansN4=mysolution.maxSubmatrixSumN4(matrix);
    cout<<ansN4.x1<<' '<<ansN4.y1<<' '<<ansN4.x2<<' '<<ansN4.y2<<' '<<ansN4.sum<<endl;
    return 0;
}

