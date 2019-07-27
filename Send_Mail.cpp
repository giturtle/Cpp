

int main(){
    int n;
    long long a[21] = {0,0,1};
    
    for (int i = 3; i < 21; i++){
        a[i] = (i - 1)*(a[i - 1] + a[i - 2]);
    }
    
    while (cin >> n){
        cout << a[n] << endl;
    }
    return 0;
}
