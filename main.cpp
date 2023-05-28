#include <iostream>
#include <random>
#include <ctime>

using namespace std;

void print(int arr[9][9], int us_arr[9][9]) {
    for (int i = 0; i < 9; ++i) {
        if (i % 3 == 0) {
            cout << "\n";
        }
        for (int j = 0; j < 9; ++j) {
            if (j % 3 == 0) {
                cout << "  ";
            }
            if (arr[i][j] != 0 and arr[i][j] == us_arr[i][j]) {
                cout << " " << arr[i][j] << " ";
            }
            else if (arr[i][j] != 0) {
                cout << " " << arr[i][j] << " ";
            }
            else {
                cout << " " << "_" << " ";
            }
        }
        cout << "\n";
    }
    cout << "\n";
}

int cheak(int arr[9][9]) {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (arr[i][j] == 0) {
                return 1;
            }
        }
    }
    for (int i = 0; i < 9; ++i) {
        int k[9] = {};
        for (int j = 0; j < 9; ++j) {
             if (k[arr[i][j] - 1] != 0) {
                return 1;
             }
             k[arr[i][j] - 1] = 1;
        }
    }
    //for (int o = 0; o < 9; ++o) {
     //   int k[9] = {};
    //    for (int i = 0; i < 3; ++i) {
     //       for (int j = 0; j < 3; ++j) {
      //          if (k[arr[i + o][j] - 1] != 0) {
   //                 return 1;
  //              }
   //             k[arr[i][j] - 1] = 1;
     //       }
     //  }
   //}
    return 0;
}

int main()
{
    //генерация поля
    srand(time(0));
    int arr[9][9] = {};
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            arr[i][j] = ((j + i * 3 + i / 3) % (9) + 1);
        }
    }
    for (int k=0; k < 2; ++k) {
        int a1 = rand() % 3;
        int b1 = (a1 + 1) % 3;
        int b2 = (a1 + 2) % 3;
        int me = 0;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 9; ++j) {
                me = arr[i + (b1 * 3)][j];
                arr[i + (b1 * 3)][j] = arr[i + (b2 * 3)][j];
                arr[i + (b2 * 3)][j] = me;
            }
        }
    }
    for (int k=0; k < 2; ++k) {
        int a1 = rand() % 3;
        int b1 = (a1 + 1) % 3;
        int b2 = (a1 + 2) % 3;
        int me = 0;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 3; ++j) {
                me = arr[i][j + (b1 * 3)];
                arr[i][j + (b1 * 3)] = arr[i][j + (b2 * 3)];
                arr[i][j + (b2 * 3)] = me;
            }
        }
    }
    for (int k=0; k < 2; ++k) {
        for (int n = 0; n < 3; ++n) {
            int a1 = rand() % 3;
            int b1 = (a1 + 1) % 3;
            int b2 = (a1 + 2) % 3;
            int me = 0;
            for (int j = 0; j < 9; ++j) {
                me = arr[n * 3 + b1][j];
                arr[n * 3 + b1][j] = arr[n * 3 + b2][j];
                arr[n * 3 + b2][j] = me;
            }
        }
    }
    for (int k=0; k < 2; ++k) {
        for (int n = 0; n < 3; ++n) {
            int a1 = rand() % 3;
            int b1 = (a1 + 1) % 3;
            int b2 = (a1 + 2) % 3;
            int me = 0;
            for (int j = 0; j < 9; ++j) {
                me = arr[j][n * 3 + b1];
                arr[j][n * 3 + b1] = arr[j][n * 3 + b2];
                arr[j][n * 3 + b2] = me;
            }
        }
    }

    int pc_arr[9][9] = {};
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            pc_arr[i][j] = arr[i][j];
        }
    }

    int k = 60;
    int n;
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 7; ++j) {
            n = rand() % 9;
            if (arr[i][n] != 0) {
                k -= 1;
                arr[i][n] = 0;
            }
        }
    }

    int us_arr[9][9] = {};
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            us_arr[i][j] = arr[i][j];
        }
    }


    
    cout << "numbers with dots are unchangeable\n";
    cout << "example: \xf9\9\xf9\n\n";
    cout << "x = 1 and y = 1 is up left corner and x = 9 and y = 9 is down right corner\n\n";
    cout << "good luck! enjoy!\n";

    //print(pc_arr, us_arr);
    print(arr, us_arr);

    while (cheak(arr)) {
        cout << "\n\n";
        int n, m, l;
        cout << "please, enter y x number\n";
        cin >> n >> m >> l;
        if (n > 0 && n < 10 && n > 0 && n < 10 && n > 0 && n < 10 && us_arr[n - 1][m - 1] == 0) {
            arr[n - 1][m - 1] = l;
        }
        else {
            cout << "uncorrect numbers\n";
        }
        print(arr, us_arr);
    }
    cout << "\n\n good job!!";
    return 0;
}
