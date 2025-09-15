class Solution(object):
    def canBeTypedWords(self, text, brokenLetters):
        broken = set(brokenLetters)
        
        words = text.split()
        count = 0
        for w in words:
            typed = True
            for c in w:
                if c in broken:
                    typed = False
                    break
            count = count + typed
        
        return count
        