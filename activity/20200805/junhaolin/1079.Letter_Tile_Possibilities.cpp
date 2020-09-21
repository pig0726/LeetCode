class Solution {
public:
    int numTilePossibilities(string tiles) {
        map<char,int> mp;
        for (int i=0; i<tiles.size(); i++)
            mp[tiles[i]]++;
        
        return count(mp);
    }
    
    int count(map<char,int> mp){
        int sum = 0;
        if (!isEmpty(mp)) {
            for(const auto & [key, value] : mp) { 
                if (value > 0) {
                    mp[key]--;
                    sum ++;
                    sum += count(mp);
                    mp[key]++;
                }
            }
        }    
        return sum;
    }
    
    bool isEmpty(map<char,int> mp) {
        int sum = 0;
        for(const auto & [key, value] : mp)   
            sum += value;
        return sum == 0 ? true : false;
    }
};
