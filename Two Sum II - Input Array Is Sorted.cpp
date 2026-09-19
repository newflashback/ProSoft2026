class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        //https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/
        // Т.к. массив отсортирован, мы можем применить два указателя 
        int low = 0; //указывает на меньший элемент суммы
        int high = numbers.size() - 1; //указывает на больший
        //цикл, по определению low < high, иначе такой пары не существует 
        while(low < high){ 
            int s = numbers[low] + numbers[high]; // считаем сумму
            if(s == target){ //если нашли
                return {low + 1, high + 1};
            }
            else{
                if(s > target){ 
                    /*если наша сумма больше требуемой, нужно уменьшить, 
                    учитывая что low уже указывает на наименьший 
                    возможный элемент, сдвинем влево high */
                    high--;
                }
                else{
                    /*Если сумма меньше требуемой, сдвинем low вправо, чтобы ее увеличить*/
                    low++;
                }
            }
        }
        //Цикл работает за O(n)
        //По условию пара всегда есть, заглушка
        return {};
    }
};