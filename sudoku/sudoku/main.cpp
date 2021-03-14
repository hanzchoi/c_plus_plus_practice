//  Created by Hanz Choi on 3/5/21.

#include <iostream>
using namespace std;

bool isItSudoku(int *arr);
bool fCheck(int *arr);



int main() {
    int VALID_SOLUTION[9][9] = {
        {9, 1, 6, 8, 4, 3, 5, 2, 7},
        {8, 4, 2, 7, 5, 6, 9, 3, 1},
        {7, 5, 3, 2, 9, 1, 8, 6, 4},
        {3, 6, 4, 9, 2, 7, 1, 8, 5},
        {2, 8, 1, 5, 6, 4, 7, 9, 3},
        {5, 9, 7, 1, 3, 8, 2, 4, 6},
        {6, 7, 8, 4, 1, 9, 3, 5, 2},
        {4, 2, 9, 3, 7, 5, 6, 1, 8},
        {1, 3, 5, 6, 8, 2, 4, 7, 9}
        
    };
    
    int allCheck[3]={0,0,0};
    
    int col[9][9];
    
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            col[i][j] = VALID_SOLUTION[j][i];
        }
        cout<< endl;
    }
    
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cout << col[i][j] << " ";
        }
        cout<< endl;
    }
    

    //int row[9] = {9, 1, 6, 8, 4, 3, 5, 2, 7};
    //int checkerBox[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
//
//    for(int i=0; i<9; i++){
//        if(checkerBox[row[i]-1] == 0){
//            cout << checkerBox[row[i]-1] << endl;
//
//            checkerBox[row[i]-1]++;
//        }
//    }
//
//    cout << isItSudoku(checkerBox) << endl;
    cout << fCheck(allCheck);
    return 0;
}

bool isItSudoku(int *box){
    bool check = true;
    for(int i=0; i < 9; i++){
        if(box[i] != 1){
            check=false;
            break;
        }
    }
    
    return check;
}


bool fCheck(int *allCheck){
    for(int i=0; i<3; i++){
        if(allCheck[i] == 0){
            return false;
        }
    }
    return true;
}

