class Solution {
void dfs(vector<vector<int>>& g, vector<vector<int>>& ans, std::vector<int>& path, int u, int n){
    path.push_back(u);
    if(u == n){
        //если путь заканчивается в нужной вершине, кладем в ответ
        ans.push_back(path);
    }
    else {
        //перебираем ее соседей
        for(int v : g[u]){
            dfs(g, ans, path, v, n);
        }
    }
    //выходим из вершины
    path.pop_back();
    return;
}
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        //https://leetcode.com/problems/all-paths-from-source-to-target/description/
        int n = graph.size() - 1;
        std::vector<std::vector<int>> ans;
        //текущий путь
        std::vector<int> path;
        //Пройдемся DFS по всем путям в графе, начинающимся в 0, заканч. в  n - 1
        dfs(graph, ans, path, 0, n);
        //Такой мод DFS завершится, т.к. граф ациклический, visited не нужен 
        /*Сложность решения O(n * 2^n) из за копирования векторов, 
        память O(n) на стек рекурсии и path, без учета итогового ответа*/
        return ans;
    }
};