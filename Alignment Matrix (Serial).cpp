#include <iostream>
using namespace std;

int main()
{
    int n  ;
    cout << "Enter length of string : ";
    cin >> n;
    char str1[n] ;
    char str2[n];
    cout<<"Enter string 1: " ;
    cin>>str1 ;
    cout<<"Enter string 2: " ;
    cin>>str2 ;
    n+=1 ;
    //matrix creation
    int am[n][n] ;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            am[i][j]=0 ;
        }
    }
    //match and mismatch penalty
    int reward = 2 ;
    int penalty = -1 ;
    //hit condition then am[i-1][j-1] + reward = am[i][j]
    // miss condition then calculate 3 things c1=am[i-1][j-1] + penalty | c2=am[i-1][j] + penalty | c3=am[i][j-1] + penalty
    //compare c1,c3,c3 and set am[i][j] to the highest value 
    //(c1 > c2) ? (c1 > c3 ? c1 : c3) : (c2 > c3 ? c2 : c3)
    
    // matrix updation using above scores

        for(int i=1;i<n;i++){
            for(int j=1;j<n;j++){
                if(str1[i]==str2[j]){
                    // hit condition
                    am[i][j] = am[i-1][j-1] + reward ;
                }
                else{
                    // miss condition
                    int c1,c2,c3,max ;
                    c1=am[i-1][j-1] + penalty ;
                    c2=am[i-1][j] + penalty ;
                    c3=am[i][j-1] + penalty ;
                    max = (c1 > c2) ? (c1 > c3 ? c1 : c3) : (c2 > c3 ? c2 : c3) ;
                    am[i][j] = max  ;
                
                }
            }
        }
    
    
    
    //matrix printing
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
        {
            cout << am[i][j] << "  ";
            if(j == n - 1)
                cout << endl;
        }
    return 0;
}