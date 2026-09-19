class Solution {
public:
    int longestValidParentheses(string s) {
        //https://leetcode.com/problems/longest-valid-parentheses/description/
        /*Будем обрабатывать ПСП с помощью стека, храним 
        в нем индексы, которые ломают последовательность*/
        stack<int> indices;
        indices.push(-1); // -1 храним на случай если есть ПСП с началом в 0
        int len = 0; //ответ 
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == '(') {
                //незакрытая ( нарушает логику ПСП, закидываем в стек ее индекс
                indices.push(i);
            }
            else {
                //пробуем для '(' найти пару ')'
                indices.pop();
                if(indices.empty()) {
                    //нет пары для ')'
                    indices.push(i);
                }
                else {
                    //ПСП лежит между i и последней некорректной скобкой
                    len = std::max(len, i - indices.top());
                }
            }
        } 
        //Сложность O(n) по времени, O(n) по памяти
        return len;
    }
};