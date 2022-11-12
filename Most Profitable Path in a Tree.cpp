#define ll long long
class Solution {
public:
    int mx = INT_MIN;
    bool path(vector<int>& res , vector<vector<int>>& adj , int par , int u , int bob){
        
        for(auto v: adj[u]){
            if (v == par){
                continue;
            }
            
            res.push_back(v);
            if(v == bob){
                return true;
            }
            
            if(path(res , adj , u , v , bob)){
                return true;
            }
            
            res.pop_back();
            
        }
        
        return false;
    }
    
    void dfs(vector<int>& orders , vector<vector<int>>& adj , int u , int par , int sum , vector<int>& amount){
        
        bool flag=  false;
        for(auto v: adj[u]){
        if(v == par){
            continue;
        }
            
            int sum1 = sum;
            flag = true;    
            if(orders[v] == 2){
               sum1 += 0;
            }
            
            else if(orders[v] == 1){
                sum1 += amount[v]/2;
            }
            
            
            else{
                sum1 += amount[v];
            }
            
            // cout<<v<<" "<<sum1<<"\n";
            dfs(orders , adj , v , u , sum1 , amount);
        
            
        }
        
        
        
        if(!flag){
            
            mx = max(mx , sum);
        }
        
        
        
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int size = edges.size();
        
        size += 1;
        
        vector<vector<int>> adj(size);
        
        for(int i = 0 ; i<edges.size() ; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> res;
        res.push_back(0);
        path(res , adj , -1 , 0 , bob);
        
        vector<int> orders(size , 0);
  // for(int i = 0 ; i<res.size() ; i++){
  //     cout<<res[i]<<" ";
  // }
        
      //  cout<<"\n";
        for(int i = res.size()/2 ; i<res.size() ; i++){
                
            orders[res[i]] = 2;
        
        }
        

        
        if(res.size()%2 == 1){
            orders[res[res.size()/2]] = 1;
        }
        
        
//   for(int i = 0 ; i<size ; i++){
//       cout<<orders[i]<<" ";
//   }
//         cout<<"\n";
        
        
        mx = INT_MIN;
        dfs(orders ,adj , 0 , -1 , amount[0] , amount);
            
            return mx;
    }
};
