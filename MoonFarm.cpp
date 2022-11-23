#include <bits/stdc++.h>
#include <algorithm>
#include <ctime>
#include <chrono>
#include "solution.h"
#include<stdio.h>
#include <string.h>

using namespace std;
auto start =chrono::steady_clock::now();

vector<int> CreateVector(int size);
vector<vector<int>> CreateMatrix(int n, int m);
void PrintVector(std::vector<int> nums);            
void PrintMatrix(std::vector<std::vector<int>> matrix);

int main(int argc, char * const argv[]){
    // srand(time(nullptr)); //used 123 for Experiments Analysis 
    // int size=4000;
    // vector<int> nums;
    // nums=CreateVector(size);
    //PrintVector(nums);
    // vector<int> nums={2,-11,-3,7,-1,3,-4,5,-1,-5};

    // int n=70,m=70;
    // vector<vector<int>> matrix;    
    // matrix=CreateMatrix(n,m);

    answer ansDPN1,ansBrute,ansDPN2,ansDPN1Mem;
    answerMatrix ansN3,ansN6,ansN4;
    Solution mysolution;                        //Define a solution class

    if (argv[1]!=NULL){
        if(strcmp(argv[1],"1")==0 || strcmp(argv[1],"2")==0 ||strcmp(argv[1],"3a")==0|| strcmp(argv[1],"3b")==0){
            cout<<"enter size(follow by enter) and number"<<endl;
            int arraySize=0; 
            cin>>arraySize; // taking size of vector from user
            int a;
            vector<int> nums;
            for(int i=0 ; i<arraySize ; i++)
            {
                cin>>a;
                nums.push_back(a);
            }

            if(strcmp(argv[1],"1")==0){
                ansBrute=mysolution.maxSubArrayBrute(nums);
                cout<<"Left:"<<ansBrute.l<<' '<<"Right:"<<ansBrute.r<<' '<<"Sum:"<<ansBrute.sum<<endl;
            }
            if(strcmp(argv[1],"2")==0){
                ansDPN2=mysolution.maxSubArrayDPN2(nums);
                cout<<"Left:"<<ansDPN2.l<<' '<<"Right:"<<ansDPN2.r<<' '<<"Sum:"<<ansDPN2.sum<<endl; 
            }
            if(strcmp(argv[1],"3a")==0){
                ansDPN1Mem=mysolution.maxSubArrayMemorization(nums);
                cout<<"Left:"<<ansDPN1Mem.l<<' '<<"Right:"<<ansDPN1Mem.r<<' '<<"Sum:"<<ansDPN1Mem.sum<<endl;
            }
            if(strcmp(argv[1],"3b")==0){
                ansDPN1=mysolution.maxSubArrayBottomUp(nums);
                cout<<"Left:"<<ansDPN1.l<<' '<<"Right:"<<ansDPN1.r<<' '<<"Sum:"<<ansDPN1.sum<<endl;
            }
        }

        if(strcmp(argv[1],"4")==0 || strcmp(argv[1],"5")==0 ||strcmp(argv[1],"6")==0){
            cout<<"Enter matrix size,row(follow by enter) and column (follow by enter)"<<endl;
            int m,n,temp;
            cin>>m>>n;
            vector<vector<int>> matrix;  
            cout<<"Enter each row value"<<endl;              
            for(int i=0; i<m; i++){ 
                vector<int> row;
                for(int j=0; j<n; j++){
                cin>>temp;
                row.push_back(temp);
                }
                matrix.push_back(row);
            }

            if(strcmp(argv[1],"4")==0){
                ansN6=mysolution.maxSubmatrixSumN6(matrix);
                cout<<ansN6.x1<<' '<<ansN6.y1<<' '<<ansN6.x2<<' '<<ansN6.y2<<' '<<ansN6.sum<<endl;
            }
            if(strcmp(argv[1],"5")==0){
                ansN4=mysolution.maxSubmatrixSumN4(matrix);
                cout<<ansN4.x1<<' '<<ansN4.y1<<' '<<ansN4.x2<<' '<<ansN4.y2<<' '<<ansN4.sum<<endl;
            }
            if(strcmp(argv[1],"6")==0){
                ansN3=mysolution.maxSubmatrixSumN3(matrix);
                cout<<ansN3.x1<<' '<<ansN3.y1<<' '<<ansN3.x2<<' '<<ansN3.y2<<' '<<ansN3.sum<<endl;
            }
        }

    }

    //For printing the using time
    cout << "\n";
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;

    return 0;
}

vector<int> CreateVector(int size){
    vector<int> nums(size);
    for (int i = 0; i < size; i++)
    {
        nums[i]=2*rand()-32768 ;
    }
    return nums;
}

vector<vector<int>> CreateMatrix(int n, int m){
    vector<vector<int>> matrix( n , vector<int> (m));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            matrix[i][j]=2*rand()-32768 ;
        }
    }
    return matrix;
}

void PrintVector(std::vector<int> nums){
    int size=nums.size();
    for(int i=0;i<size;i++){
        if(i) putchar(' ');
        std::cout<<nums[i];
    }
    putchar('\n');
    return;
}

void PrintMatrix(std::vector<std::vector<int>> matrix){
    int row=0,col=0;
    row=matrix.size();
    if(row) col=matrix[0].size();
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(j) putchar(' ');
            std::cout<<matrix[i][j];
        }
        putchar('\n');
    }
}