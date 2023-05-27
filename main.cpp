#include <iostream>
#include <random>
#include <ctime>

using namespace std;


int main()
{
    int arr_user[9][9] = {};
    
    
    srand(time(0));
    int arr_pc[9][9] = {};
    for (int i=0;i<9;++i){
        for (int j=0;j<9;++j){
            arr_pc[i][j] = ((j + i*3 + i/3) % (9) + 1);
        }
    }
    for (int k;k<2;++k){
        int a1 = rand() % 3;
        int b1 = (a1 + 1) % 3;
        int b2 = (a1 + 2) % 3;
        int me = 0;
        for (int i=0;i<3;++i){
            for (int j=0;j<9;++j){
                me = arr_pc[i + (b1 * 3)][j];
                arr_pc[i + (b1 * 3)][j] = arr_pc[i + (b2 * 3)][j];
                arr_pc[i + (b2 * 3)][j] = me;
            }
        }
    }
    
    for (int k;k<2;++k){
        int a1 = rand() % 3;
        int b1 = (a1 + 1) % 3;
        int b2 = (a1 + 2) % 3;
        int me = 0;
        for (int i=0;i<9;++i){
            for (int j=0;j<3;++j){
                me = arr_pc[i][j + (b1 * 3)];
                arr_pc[i][j + (b1 * 3)] = arr_pc[i][j + (b2 * 3)];
                arr_pc[i][j + (b2 * 3)] = me;
            }
        }
    }
    
    for (int k;k<2;++k){
        for (int n=0;n<3;++n){
            int a1 = rand() % 3;
            int b1 = (a1 + 1) % 3;
            int b2 = (a1 + 2) % 3;
            int me = 0;
            for (int j=0;j<9;++j){
                me = arr_pc[n * 3 + b1][j];
                arr_pc[n * 3 + b1][j] = arr_pc[n * 3 + b2][j];
                arr_pc[n * 3 + b2][j] = me;
            }
        }
    }
    
    for (int k;k<2;++k){
        for (int n=0;n<3;++n){
            int a1 = rand() % 3;
            int b1 = (a1 + 1) % 3;
            int b2 = (a1 + 2) % 3;
            int me = 0;
            for (int j=0;j<9;++j){
                me = arr_pc[j][n * 3 + b1];
                arr_pc[j][n * 3 + b1] = arr_pc[j][n * 3 + b2];
                arr_pc[j][n * 3 + b2] = me;
            }
        }
    }
    
    
    
    
    
    
    for (int i=0;i<9;++i){
        if (i % 3 == 0){
            cout << "\n";
        }
        for (int j=0;j<9;++j){
            if (j % 3 == 0){
                cout << "  ";
            }
            cout << arr_pc[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";

    return 0;
}
