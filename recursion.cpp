#include <iostream>

using namespace std;

int fibonacci(int n){
    int sum = 0;
    if(n == 0)
        return 0;
    else if(n == 1){
        return 1;
    }else{
        return fibonacci(n - 1) + fibonacci(n - 2); 
    }

        

}
int main(){
    int num;
    do{
        cout<<"Num: ";
        cin >> num;
    }while(num <= 0);
    int result = fibonacci(num);
    cout << result;
    return 0;
}