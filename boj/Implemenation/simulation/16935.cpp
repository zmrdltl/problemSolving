#include <bits/stdc++.h>
using namespace std;
int n, m, r, arr[101][101];

void one(){
    for(int j = 0; j < m; j++){
        for(int i = 0; i < n/2; i++){
            swap(arr[n-1-i][j], arr[i][j]);
        }
    }    
}
void two(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m/2; j++){
            swap(arr[i][m-1-j], arr[i][j]);
        }
    }
}
void three(){
    int tmp[101][101];
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            tmp[i][j] = arr[n-1-j][i];
        }
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            arr[i][j] = tmp[i][j];
        }
    }
    swap(n,m);
}
void four(){
    int tmp[101][101];
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            tmp[i][j] = arr[j][m-1-i];
        }
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            arr[i][j] = tmp[i][j];
        }
    }
    swap(n,m);
}
void five(){
    int tmp[101][101];
    //1 -> 2
    for(int i = 0; i < n/2; i++){
        for(int j = m/2; j < m; j++){
            tmp[i][j] = arr[i][j-m/2];
        }
    }
    //2 -> 3
    for(int i = n/2; i < n; i++){
        for(int j = m/2; j < m; j++){
            tmp[i][j] = arr[i - n/2][j];
        }
    }
    //3 -> 4
    for(int i = n/2; i < n; i++){
        for(int j = 0; j < m/2; j++){
            tmp[i][j] = arr[i][j+m/2];
        }
    }
    for(int i = 0; i < n/2; i++){
        for(int j = 0; j < m/2; j++){
            tmp[i][j] = arr[i + n/2][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            arr[i][j] = tmp[i][j];
        }
    }
}
void six(){
    int tmp[101][101];
    //1->4
    for(int i = n/2; i < n; i++){
        for(int j = 0; j < m/2; j++){
            tmp[i][j] = arr[i - n/2][j];
        }
    }
    //4->3
    for(int i = n/2; i < n; i++){
        for(int j = m/2; j < m; j++){
            tmp[i][j] = arr[i][j-m/2];
        }
    }
    //3->2
    for(int i = 0; i < n/2; i++){
        for(int j = m/2; j < m; j++){
            tmp[i][j] = arr[n/2+i][j];
        }
    }
    for(int i = 0; i < n/2; i++){
        for(int j = 0; j < m/2; j++){
            tmp[i][j] = arr[i][j+m/2];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            arr[i][j] = tmp[i][j];
        }
    }
}

int main(){
    cin >> n >> m >> r;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }
    while(r--){
        int x;
        cin >> x;
        switch(x){
            case 1:
                one();
                break;
            case 2:
                two();
                break;
            case 3:
                three();
                break;
            case 4:
                four();
                break;
            case 5:
                five();
                break;
            case 6:
                six();
                break;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
}