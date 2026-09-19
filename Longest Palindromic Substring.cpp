class Solution {
public:
    string longestPalindrome(string s) {
        //https://leetcode.com/problems/longest-palindromic-substring/description/
        int n = s.length();
        // ДП, смысл "Является ли подстрока s(i, j) палиндромом?"
        vector<vector<bool>> dp(n, std::vector<bool>(n));
        //База односимвольная строка - палиндром
        for(int i = 0; i < n; i++){
            dp[i][i] = true;
        }

        int start = 0; // начало макс палиндрома
        int end = 0; // конец макс палиндрома
        int max_len = 1; // длина макс палиндрома
        for(int i = n - 1; i > -1; i--){
            for(int j = i + 1; j < n; j++){
                /* пытаемся расширить палиндром: если символы на концах совпадают, 
                и длина 2, если длина больше, смотрим чтобы это подстрока была палиндромом*/
                if (s[i] == s[j] && (j - i < 3 || dp[i + 1][j - 1])){
                        dp[i][j] = true;
                        if(j - i + 1 >= max_len){
                            // вычисляем индексы наибольшего подпалиндрома
                            start = i;
                            end = j;
                            max_len = j - i + 1;
                        }
                    
                }
            }
        }
        // Сложность O(n^2), память O(n^2)
        return s.substr(start, end - start + 1);
    }
};