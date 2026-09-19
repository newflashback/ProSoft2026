class Solution {
public:
    int uniquePaths(int m, int n) {
        //https://leetcode.com/problems/unique-paths/description/
        //ДП: будем хранить в ячейке - количество путей в нее
        //Индексация идет с 1
        vector<vector<int>> dp(m + 1, std::vector<int>(n + 1));
        // База ДП - в начальную клетку 1 путь
        dp[1][1] = 1;
        // В клетки первого столбца можно попасть только из верхней клетки
        for(int i = 2; i < m + 1; i++){
            dp[i][1] = dp[i - 1][1];
        }
        // В клетки первой строки можно попасть только из левой клетки 
        for(int i = 2; i < n + 1; i++){
            dp[1][i] = dp[1][i - 1]; 
        }
        // База и крайние случаи готовы, заполняем таблицу
        for(int i = 2; i < m + 1; i++){
            for(int j = 2; j < n + 1; j++){
                //В клетку можно попасть либо слева либо сверху 
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        // Сложность O(n^2), память O(n^2)
        return dp[m][n];
    }
};