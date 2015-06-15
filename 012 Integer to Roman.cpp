class Solution {
public:
    string intToRoman(int num) {
        vector<int> radix={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        vector<string> base={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        
        string roman;
        for(int i=0;i<13;i++)
        {
            int digit=num/radix[i];
            num%=radix[i];
            while(digit--) roman+=base[i];
        }
        return roman;
    }
};
