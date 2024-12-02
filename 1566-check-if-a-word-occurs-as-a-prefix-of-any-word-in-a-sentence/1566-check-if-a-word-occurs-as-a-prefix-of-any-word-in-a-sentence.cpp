class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int ss=sentence.size(), ws=searchWord.size();
        int wc=1;
        for(int i=0;i<ss;i++)
        {
            if(sentence[i]!=searchWord[0])
            {
                while(i<ss and sentence[i]!=' ' ) i++;

                if(i==ss) return -1;

                wc++;
            }

            if(sentence[i]==searchWord[0])
            {
                int j=0;
                for(;j<ws;j++,i++)
                {
                    if(sentence[i]!=searchWord[j])
                        break;
                }
                i--;
                if(j==ws)
                    return wc;
            }

        }


        return -1;
        
    }
};