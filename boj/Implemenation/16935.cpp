#include <bits/stdc++.h>
using namespace std;
int n, m, r, arr[101][101];
void calculateOne(){
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n / 2; j++){
            swap(arr[j][i], arr[n-j+1][i]);
        }
    }
}

void calculateTwo(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m / 2; j++){
            swap(arr[i][j],arr[i][m-j+1]);
        }
    }
}
//오른쪽 90도 회전
void calculateThree(){
    int tmp[101][101];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            tmp[i][j] = arr[i][j];
        }
    }
    memset(arr,0,sizeof(arr));
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            arr[i][j] = tmp[n-j+1][i];
        }
    }
    swap(n,m);
}

//왼쪽 90도 회전
void calculateFour(){
    int tmp[101][101];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            tmp[i][j] = arr[i][j];
        }
    }
    memset(arr,0,sizeof(arr));
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            arr[i][j] = tmp[j][m-i+1];
        }
    }
    swap(n,m);
}

void calculateFive(){
    vector <int> a,b,c,d;
    for(int i = 1; i <= n/2; i++){
        for(int j = 1; j <= m/2; j++){
            a.push_back(arr[i][j]);
        }
    }

    for(int i = 1; i <= n/2; i++){
        for(int j = m/2+1; j <= m; j++){
            b.push_back(arr[i][j]);
        }
    }
    
    for(int i = n/2+1; i <= n; i++){
        for(int j = m/2+1; j <= m; j++){
            c.push_back(arr[i][j]);
        }
    }

    for(int i = n/2+1; i <= n; i++){
        for(int j = 1; j <= m/2; j++){
            d.push_back(arr[i][j]);
        }
    }

    //===========================================
    int piv = 0;
    for(int i = 1; i <= n/2; i++){
        for(int j = 1; j <= m/2; j++){
            arr[i][j] = d[piv++];
        }
    }

    piv = 0;
    for(int i = 1; i <= n/2; i++){
        for(int j = m/2+1; j <= m; j++){
            arr[i][j] = a[piv++];
        }
    }
    piv = 0;
    for(int i = n/2+1; i <= n; i++){
        for(int j = m/2+1; j <= m; j++){
            arr[i][j] = b[piv++];
        }
    }
    piv = 0;
    for(int i = n/2+1; i <= n; i++){
        for(int j = 1; j <= m/2; j++){
            arr[i][j] = c[piv++];
        }
    }

}

void calculateSix(){
    vector <int> a,b,c,d;
    for(int i = 1; i <= n/2; i++){
        for(int j = 1; j <= m/2; j++){
            a.push_back(arr[i][j]);
        }
    }

    for(int i = 1; i <= n/2; i++){
        for(int j = m/2+1; j <= m; j++){
            b.push_back(arr[i][j]);
        }
    }
    
    for(int i = n/2+1; i <= n; i++){
        for(int j = m/2+1; j <= m; j++){
            c.push_back(arr[i][j]);
        }
    }

    for(int i = n/2+1; i <= n; i++){
        for(int j = 1; j <= m/2; j++){
            d.push_back(arr[i][j]);
        }
    }   
    
    //===========================================

    int piv = 0;
    for(int i = 1; i <= n/2; i++){
        for(int j = 1; j <= m/2; j++){
            arr[i][j] = b[piv++];
        }
    }

    piv = 0;
    for(int i = 1; i <= n/2; i++){
        for(int j = m/2+1; j <= m; j++){
            arr[i][j] = c[piv++];
        }
    }
    piv = 0;
    for(int i = n/2+1; i <= n; i++){
        for(int j = m/2+1; j <= m; j++){
            arr[i][j] = d[piv++];
        }
    }
    piv = 0;
    for(int i = n/2+1; i <= n; i++){
        for(int j = 1; j <= m/2; j++){
            arr[i][j] = a[piv++];
        }
    }
}

void print(){
    for(int i = 1; i <= 100; i++){
        int flag = 0;
        for(int j = 1; j <= 100; j++){
            if(arr[i][j]) cout << arr[i][j] << ' ', flag = 1;
        }
        if(flag) cout << '\n';
    }
}

int main(){
    cin >> n >> m >> r;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> arr[i][j];
    while(r--){
        int op;
        cin >> op;
        switch (op){
        case 1:
            calculateOne();
            break;
        case 2:
            calculateTwo();
            break;
        case 3:
            calculateThree();
            break;
        case 4:
            calculateFour();
            break;
        case 5:
            calculateFive();
            break;
        case 6:
            calculateSix();
            break;    
        }
    }
    print();
}