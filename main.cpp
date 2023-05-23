#include <iostream>
#include <random>
#include <ctime>

using namespace std;

int make_numb(int k, int i, int j, int arr[9][3][3]){
    int numb[9] = {};
    int numb_ok[9] = {};
    for (int ni=0;ni<3;++ni){
        for (int nj=0;nj<3;++nj){
        if (arr[k][ni][nj] != 0){
            numb[arr[k][ni][nj] - 1] = 1;
        }
    }
    }
    int ij = 0;
    for (int ni=0;ni<9;++ni){
        if (numb[0]){
            numb_ok[ij] = numb[ni]}
    } 
    srand(time(0));
	int num = rand() % 9 + 1;
    return num;
}

int main()
{
    int arr_user[9][3][3] = {};

    int arr_pc[9][3][3] = {};
    for (int k=0;k<3;++k){
        for (int i=0;i<3;++i){
            for (int j=0;j<3;++j){
                arr_pc[k][i][j] = make_numb(k, i, j, arr_pc);
            }
        }
    }

    for (int i=0;i<9;++i){
        if (i % 3 == 0){
            cout << "\n";
        }
        for (int k=0;k<3;++k){
            for (int j=0;j<3;++j){
                cout << arr_pc[k][i % 3][j] << " ";
            }
            cout << " ";
        }
        cout << "\n";
    }

    return 0;
}
