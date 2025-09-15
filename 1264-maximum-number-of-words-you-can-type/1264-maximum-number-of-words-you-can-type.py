class Solution(object):
    def canBeTypedWords(self, text, brokenLetters):
        broken = dict()
        for b in brokenLetters:
            broken[b] = True
        
        words = text.split()
        count = 0
        for w in words:
            typed = True
            for c in w:
                if c in brokenLetters:
                    typed = False
                    break
            count = count + typed
        
        return count
        