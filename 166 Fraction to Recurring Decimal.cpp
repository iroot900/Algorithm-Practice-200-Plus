class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
       long nume= (long) numerator;
       long deno= (long) denominator;
       
       int sign=0;
       if(nume<0) {nume=-nume; ++sign;}
       if(deno<0) {deno=-deno; ++sign;}
        
        long digit=0, remainder=0;
        string result;
        digit=nume/deno;
        remainder=nume%deno;
        result+=to_string(digit);
        if(remainder==0) 
        {
            if((sign&1)&&result!="0") {result.insert(0,"-"); return result;}
            else return result;
        }
        result.push_back('.');
        unordered_map<int,int> pos;
        
        while(remainder!=0)
        {
            if(pos.find(remainder)!=pos.end()) 
            {
                result.insert(pos[remainder],"(");
                result.push_back(')');
                if((sign&1)&&result!="0") {result.insert(0,"-"); return result;}
                else return result;
            }
            pos[remainder]=(int)result.size();
            digit=remainder*10/deno;
            remainder=remainder*10%deno;
            result.push_back('0'+digit);
        }
        if((sign&1)&&result!="0") {result.insert(0,"-"); return result;}
        else return result;
    }
};
