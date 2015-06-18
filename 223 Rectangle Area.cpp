class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area=0;
        area=(C-A)*(D-B)+(G-E)*(H-F);
          
        int len=0;
        if(A<E)
        {
            if(C<=E) len=0;
            else if(C>=G) len=G-E;
            else len=C-E;
        }
        else
        {
            if(G<=A) len=0;
            else if(G>=C) len=C-A;
            else len=G-A; 
        }
          
        int height=0;
        if(B<F)
        {
            if(D<=F) height=0;
            else if(D>=H) height=H-F;
            else height=D-F;
        }
        else
        {
            if(H<=B) height=0;
            else if(H>=D) height=D-B;
            else height=H-B; 
        }
        
        return area-height*len;
        
    }
};
