#include<iostream>
#include <vector>
#include <queue>

using namespace std;

char map[20][20];
char tank_look;
pair<int,int>tank_loc; // i,j
int h,w;


void move(char c){
    if(c=='R'){
        tank_look='>';
        if(tank_loc.second+1<w){
            if(map[tank_loc.first][tank_loc.second+1]=='.'){
                tank_loc.second++;
            }
        }
    }else if(c=='L'){
        tank_look='<';
        if(tank_loc.second-1>=0){
            if(map[tank_loc.first][tank_loc.second-1]=='.'){
                tank_loc.second--;
            }
        }
    }else if(c=='U'){
        tank_look='^';
        if(tank_loc.first-1>=0){
            if(map[tank_loc.first-1][tank_loc.second]=='.'){
                tank_loc.first--;
            }
        }
    }else if(c=='D'){
        tank_look='v';
        if(tank_loc.first+1<h){
            if(map[tank_loc.first+1][tank_loc.second]=='.'){
                tank_loc.first++;
            }
        }
    }
}

void shoot(){
    if(tank_look=='v'){
        int i,j;
        i=tank_loc.first;
        j=tank_loc.second;
        while(map[i][j]!='*'&&map[i][j]!='#'&&i<h){
            i++;
        }
        if(map[i][j]=='*')map[i][j]='.';
    }else if(tank_look=='^'){
        int i,j;
        i=tank_loc.first;
        j=tank_loc.second;
        while(map[i][j]!='*'&&map[i][j]!='#'&&i>0){
            i--;
        }
        if(map[i][j]=='*')map[i][j]='.';
    }else if(tank_look=='<'){
        int i,j;
        i=tank_loc.first;
        j=tank_loc.second;
        while(map[i][j]!='*'&&map[i][j]!='#'&&j>0){
            j--;
        }
        if(map[i][j]=='*')map[i][j]='.';
    }else if(tank_look=='>'){
        int i,j;
        i=tank_loc.first;
        j=tank_loc.second;
        while(map[i][j]!='*'&&map[i][j]!='#'&&j<w){
            j++;
        }
        if(map[i][j]=='*')map[i][j]='.';
    }
}

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case) {
        int answer = 0;

        cin>>h>>w;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                char a;
                cin>>a;
                if(a=='>'){
                    tank_look='>';
                    tank_loc={i,j};
                    map[i][j]='.';
                }else if(a=='<'){
                    tank_look='<';
                    tank_loc={i,j};
                    map[i][j]='.';
                }else if(a=='^'){
                    tank_look='^';
                    tank_loc={i,j};
                    map[i][j]='.';
                }else if(a=='v'){
                    tank_look='v';
                    tank_loc={i,j};
                    map[i][j]='.';
                }else{
                    map[i][j]=a;
                }
            }
        }
        int n;
        cin>>n;
        string order;
        cin>>order;
        for(auto i:order){
            if(i=='S'){
                shoot();
            }else{
                move(i);
            }

        }

        cout << '#' << test_case << ' ';
        for(int k=0;k<h;k++){
            for(int j=0;j<w;j++){
                if(k==tank_loc.first&&j==tank_loc.second){
                    cout<<tank_look;
                }else{
                    cout<<map[k][j];
                }
            }cout<<'\n';
        }

//        cout << '#' << test_case << ' ' << answer << '\n';


    }



    return 0;
}

