'''
Given a list of words, find all pairs of unique indices such that each pair forms unique palindrome.
For example, given the following words: ["code", "edoc", "da","d"] Return [[0, 1], [1, 0], [2,3]]
'''

def is_palindrome(word):
    return word == word[::-1]

def palindrome_pairs(words):
    pairs = []
    
    for i, word1 in enumerate(words):
        for j, word2 in enumerate(words):
            if i == j:
                continue
            if is_palindrome(word1+word2):
                pairs.append([i,j])
    return pairs

words = ["code", "edoc", "da","d"]
print(palindrome_pairs(words))


''' 
Output:
[[0, 1], [1, 0], [2, 3]]
'''       