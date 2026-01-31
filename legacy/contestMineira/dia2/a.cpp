#include <bits/stdc++.h>
#include <string>
#include <iostream>
using namespace std;

#define _ ios_base::sync_width_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    int n=0;
    vector<pair<int,int>> alfabeto(26,{0,0});
    vector<pair<char,char>> alfabetoLetra(26);
    alfabetoLetra.f={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    alfabetoLetra.s={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    std::string frase;
    cin>>n;
    cin>>frase;

    for(int i=0; i<n; i++){
        printf("%c", frase[i]);
    }
    
    for(int i=0; i<n; i++){
        //percorrer um elemento
        for(int j=0; j<26; j++){
            if((int)frase[i]==alfabetoLetra[j].f || (int)frase[i]==alfabetoLetra[j].s){
                alfabeto[i].f++;
                alfabeto[i].s++;
                break;
            }   
        }
    }
    int n2=0;
    for(int i=0; i<26; i++){
        n2+=alfabeto[i].f;
    }

    if(n2==26) printf("YES\n");
    else printf("NO\n");
    
    return 0;
}