class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        for (auto & letter : letters) 
            if (letter > target) 
                return letter;
               
        return letters.front();
    }
};
