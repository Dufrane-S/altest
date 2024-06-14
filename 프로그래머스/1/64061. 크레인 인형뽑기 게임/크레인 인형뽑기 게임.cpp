#include <string>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> tong;
    for(auto m:moves){
        m-=1;
        for(int i=0;i<board.size();i++){
            if(board[i][m]){
                if(!tong.empty()&&tong.top()==board[i][m]){
                    answer+=2;
                    tong.pop();
                }else{
                    tong.push(board[i][m]);
                }
                board[i][m]=0;
                
                break;
            }
        }
    }
    while(!tong.empty()){
        cout<<tong.top()<<" ";tong.pop();
    }
    return answer;
}