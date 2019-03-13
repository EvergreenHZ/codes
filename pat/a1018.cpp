#include "stdio.h"
#include "math.h"
#include "string.h"
#include "iostream"
//#include "stdlib.h"
#include "vector"
#include "set"
#include "map"
//#include "stack"
#include "queue"
#include "algorithm"
using namespace std;

const int MAXV = 510;//最大顶点数
const int INF = 1000000000;//无穷大

//n为顶点数，m为边数，Cmax为最大容量，Sp为问题站点
//G为邻接矩阵，weight为点权，d[]记录最短距离
//mindNeed记录最少携带数目，minRemain记录最少带回的数目
int n, m , Cmax, Sp, numPath = 0, G[MAXV][MAXV], weight[MAXV];
int d[MAXV], minNeed = INF, minRemain = INF;
bool vis[MAXV] = {false};//vis[i] == true 表示顶点i已访问，初始均为false
vector<int> pre[MAXV];//前驱
vector<int> tempPath, path;//临时路径及最优路径

void Dijkstra(int s){//s为起点
    fill(d, d + MAXV, INF);
    d[s] = 0;
    for (int i = 0; i < n; i++) {//循环n次
        int u = -1, MIN = INF;//u使d[u]最小，MIN存放该最小的d[u]
        for (int j = 0; j <= n; j++) {//找到未访问的顶点中d[]最小的
            if (vis[j] == false && d[j] < MIN) {
                u = j;
                MIN = d[j];
            }
            
        }
        //找不到小于INF的d[u]，说明剩下的顶点和起点s不连通
        if (u == -1) return;
        vis[u] = true;//标记u已访问
        for (int v = 0; v <= n; v++) {
            //如果v未访问&& u能到达v
            if (vis[v] == false && G[u][v] != INF) {
                if (d[u] + G[u][v] < d[v]) {
                    d[v] = d[u] + G[u][v];//优化d[v]
                    pre[v].clear();
                    pre[v].push_back(u);
                }else if (d[u] + G[u][v] == d[v]){
                    pre[v].push_back(u);
                }
            }
        }
    }
}
void DFS(int v){
    if(v == 0){//递归边界,叶子结点
        tempPath.push_back(v);
        //路径tempPath上需要携带数目、需要带回的数目
        int need = 0, remain = 0;
        for (int i = tempPath.size() - 1; i >= 0 ; i--) {
            int id = tempPath[i];//当前结点编号id
            if (weight[id] > 0) {//点权大于0，说明需要带走一部分自行车
                remain += weight[id];
            }else{//点权不超过0，需要补给
                if (remain > abs(weight[id])) {//当前持有量足够补给
                    remain -= abs(weight[id]);
                }else{
                    need += abs(weight[id]) - remain;//不够的部分从PBMC携带
                    remain = 0;//当前持有的自行车都用来补给
                }
            }
        }
        if (need < minNeed){//需要从PBMC携带的自行车数目更少
            minNeed = need;//优化minNeed
            minRemain = remain;//覆盖minRemain
            path = tempPath;//覆盖最优路径path
        }else if(need == minNeed && remain < minRemain){
            //携带数目相同，带回数目变少
            minRemain = remain;//优化minRemain
            path = tempPath;//覆盖最优路径path
        }
        tempPath.pop_back();
        return;
    }
    tempPath.push_back(v);
    for (int i = 0; i < pre[v].size(); i++) {
        DFS(pre[v][i]);
    }
    tempPath.pop_back();
}

int main(){
    scanf("%d%d%d%d", &Cmax, &n, &Sp, &m);
    int u, v;
    fill(G[0], G[0] + MAXV * MAXV, INF);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &weight[i]);
        weight[i] -= Cmax / 2;//点权减去答案的一半
    }
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &u, &v);
        scanf("%d", &G[u][v]);
        G[v][u] = G[u][v];
    }
    Dijkstra(0);//Dijkstra算法入口
    DFS(Sp);
    printf("%d ", minNeed);
    for (int i = path.size() - 1; i >= 0; i--) {
        printf("%d", path[i]);
        if (i > 0) {
            printf("->");
        }
    }
    printf(" %d\n", minRemain);
    return 0;
}
