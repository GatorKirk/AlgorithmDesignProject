#include <bits/stdc++.h>

void PrintVector(std::vector<int> nums);            
void PrintMatrix(std::vector<std::vector<int>> matrix);

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