#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    
    map<pair<string,string>,int>reportdone;
    map<string,vector<string>>reporttarget;
    map<string,int>reportcount;
    for(auto k:report){
        string shooter;
        string target;
        string temp="";
        for(auto i:k){
            if(i==' '){
                shooter=temp;
                temp="";
                continue;
            }
            temp+=i;
        }
        target=temp;
        
        if(reportdone[{shooter,target}]==0){
            reportdone[{shooter,target}]+=1;
            reporttarget[shooter].push_back(target);
            reportcount[target]+=1;
        }
    }
    for(auto id:id_list){
        int temp=0;
        for(auto target:reporttarget[id]){
            if(reportcount[target]>=k){
                temp++;
            }
        }
        answer.push_back(temp);
    }
    
    return answer;
}