''' 
Given a list of strings. Each string consists of multiple words separated by spaces. Write the following Python functions:
(a) normalize(text): takes a string and returns a normalized string with lowercase words and no punctuation marks.
(b) split words(text): takes a string and returns a list
of words.
(c) count words(word list): takes a list of words and returns a dictionary with words as keys and their occurrences
as values.
(d) sort words(word count): takes a dictionary with words as keys and their occurrences as values, and returns a list of tuples sorted by word occurrence in descending order and by word in alphabetical order for equal occurrences.
(e) get most common words(strings, n): takes a list of strings and an integer n, and returns the n most common words across all the strings, sorted by occurrence in descending order. Use these five functions to find the most common words in the input list of strings.

'''

punctuations = '''!-[]{};:'"\,()<>./?@#$%^&*_~'''

#normalize(text): takes a string and returns a normalized string with lowercase words and no punctuation marks.
def normalize(text):
    normalized_text = text.lower()
    for char in punctuations:
        if char in normalized_text:
            normalized_text = normalized_text.replace(char,"")
    return normalized_text

#split_words(text): takes a string and returns a list of words.
def split_words(text):
    return list(text.split())

#coun_words(word_list): takes a list of words and returns a dictionary with words as keys and their occurrences as values.
def count_words(word_list):
    dict_count = {}
    for word in word_list:
        dict_count[word] = word_list.count(word)
    return dict_count

#sort_words(word_count): takes a dictionary with words as keys and their occurrences as values,
#and returns a list of tuples sorted by word occurrence in descending order and by word in alphabetical order for equal occurrences.
def sort_words(word_count_dict):
    key_sorted_dict = dict(sorted(word_count_dict.items(), key=lambda item:item[0]))
    sorted_tuples = sorted(key_sorted_dict.items(), key=lambda item:item[1], reverse = True)
    return sorted_tuples

# get_most_common_words(string, n): takes a list of strings and an integer n, and returns the n most common words across all the strings,
def get_most_common_words(string, n):
    normalized_text = normalize(string)
    splitted_words_list = split_words(normalized_text)
    words_count_list = count_words(splitted_words_list)
    freq_words_tuples = sort_words(words_count_list)

    common_words_list = list(dict(freq_words_tuples).keys())[:n]
    return common_words_list

#Accepts string and n, no of most common words as input
string = input("Enter a string: ")
n = int(input("Enter no of most common words: "))

#Prints most 'n' common words
print(f"Most {n} common words: {get_most_common_words(string, n)}")

'''

Input/Output:

Enter a string: hai "Hai" hello Hello Hello Hag Hag Ham Ham\
Enter no of most common words: 3
Most 3 common words: ['hello', 'hag', 'hai']

'''