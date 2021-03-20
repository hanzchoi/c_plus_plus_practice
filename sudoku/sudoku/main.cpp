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
    
    int columnRe[9][9];
    int littleBox[9][9];
    int checkerBox[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
           
    
    // TO MAKE COL
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            columnRe[i][j] = VALID_SOLUTION[j][i];
        }
        cout<< endl;
    }
    
    //ROW CHECK
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            checkerBox[VALID_SOLUTION[i][j]-1]++;
        }
        // we can check and return false right away
        if(!isItSudoku(checkerBox)){
            allCheck[0]=1;
            break;
        }
        
        std::fill_n(checkerBox, 9, 0);
    }
    // this shows that youre unsure
    std::fill_n(checkerBox, 9, 0);

    //COL CHECK
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            checkerBox[columnRe[i][j]-1]++;
        }
        
        if(!isItSudoku(checkerBox)){
            allCheck[0]=1;
            break;
        }
        
        std::fill_n(checkerBox, 9, 0);
    }
    
    std::fill_n(checkerBox, 9, 0);
    
    int row=0;
    int column=0;
    //
    
    //Make LittleBox
    for(int I=0; I<6; I+=3){
        for(int J=0; J<6; J+=3){
            for(int i=I; i<I+3; i++){
                for(int j=J; j<J+3; j++){
                    littleBox[i][j] = VALID_SOLUTION[i][j];
                }
            }
        }
    }
    
    cout << "test" << endl;
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cout << littleBox[i][j] << ", ";
        }
        cout << endl;
    }

    
    cout << allCheck[0] << ", " << allCheck[1]  << ", " << allCheck[2] << endl;

//    cout << isItSudoku(checkerBox) << endl;
    //cout << fCheck(allCheck);
    return 0;
}

//make it similiar to fcheck
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



//make the function and impolemnt short circuiting
