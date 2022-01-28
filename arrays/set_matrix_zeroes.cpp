// given a mtrix modify entire row and col of the element having value equal to 0

#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

// brtue force:  T: O(n*m) + O(m+n)  S: O(1) 
// additional m+n as we are traversing the entire col and row for the elements having value equal to 0
void setZeroesBrute(vector<vector<int>> &matrix){

    int rows = matrix.size();
    int cols = matrix[0].size();

    for(int i=0; i<rows; i++){ 
        for(int j=0; j<cols; j++){

            if(matrix[i][j] == 0){

                for(int row=0; row<rows; row++){
                    if(matrix[row][j] != 0)
                        matrix[row][j] = INT_MIN+1;
                }

                for(int col=0; col<cols; col++){
                    if(matrix[i][col] != 0)
                        matrix[i][col] = INT_MIN+1;
                }

            }

        }
    }

    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(matrix[i][j] == INT_MIN+1)
                matrix[i][j] = 0;
        }
    }

}

// T: O(m^n)  S: O(m+n)
// create two dummy arrays to mark the pos of 0 elements
void setZeroesBetter(vector<vector<int>> &matrix){

    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<int> dummy_row(rows, 1);
    vector<int> dummy_col(cols, 1);

    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){

            if(matrix[i][j] == 0){ // if the element is 0: mark the row and col in dummy vectors as 0
                dummy_row[i]=0;
                dummy_col[j]=0;
            }

        }
    }

    // traverse the array again, if either of the dummy vectors is 0 at a pos: make the element 0
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){

            if(dummy_col[j]==0 || dummy_row[i]==0)
                matrix[i][j]=0;

        }
    }

}

int main(void){


}