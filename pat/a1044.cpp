#include<iostream>
#include<vector>
using namespace std;
int m;

struct node{
        node(int f, int t){
                from = f;
                to = t;
        }
        int from;
        int to;
};

void binaryFind(vector<int>&vec, int from, int &to, int& tmpSum){
        int left, right;
        left = from ;
        right = vec.size()-1;

        while(left < right){
                int mid = (left+right)/2;
                if( (vec[mid]-vec[from-1])>=m ){
                        right = mid;
                }else{
                        left = mid+1;
                }
        }
        to = right;
        tmpSum = vec[to] - vec[from-1];
}

int main(){
        int n,i,t;
        cin>>n>>m;
        vector<int> vec(n+1,0);
        for(i=1; i<=n; i++){
                cin>>vec[i];
                vec[i] += vec[i-1];
        }
        vector<node> result;
        int tmpSum, best = -1;
        for(i=1; i<=n; i++){
                int from,to;
                from = i;
                binaryFind(vec, from, to, tmpSum);
                if(best==-1 || (tmpSum<best && tmpSum>=m )){
                        result.clear();
                        result.push_back(node(from,to));
                        best = tmpSum;
                }else if(best!=-1 && best==tmpSum){
                        result.push_back(node(from,to));
                }
        }
        for(i=0; i<result.size(); i++){
                printf("%d-%d\n",result[i].from, result[i].to);
        }
        return 0;
}
