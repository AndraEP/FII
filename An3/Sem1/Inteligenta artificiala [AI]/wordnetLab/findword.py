from nltk.corpus import wordnet

file = open('testFile.txt', 'r')
original_text = file.read().split()
final_text = ""
syns_list = []

for original_word in original_text:
    word = ""
    length = len(original_word)
    if original_word[length - 1] in ["!", ",", ".", "?"]:
        word = original_word[length - 1]
        original_word = original_word[:length - 1]

    syns = wordnet.synsets(original_word)
    if len(syns) > 0:
        for elem in syns:
            if '.n.' in str(elem):
                hypern = syns[0].hypernyms()
                if len(hypern) > 0:
                    syns_list.append(syns[0])
                    lemms_string = str(hypern[0].lemmas()[0]).split('.')[0]
                    if len(word) == 1:
                        final_text += lemms_string[7:] + word + " "
                    else:
                        final_text += lemms_string[7:] + " "
                elif len(word) == 1:
                    final_text += original_word + word + " "
                else:
                    final_text += original_word + " "
                break
            elif len(word) == 1:
                final_text += original_word + word + " "
            else:
                final_text += original_word + " "
            break
    elif len(word) == 1:
        final_text += original_word + word + " "
    else:
        final_text += original_word + " "
    if word in ['!', '.', '?']:
        max_distance = 0
        for syn in syns_list:
            for syn2 in syns_list:
                if syn != syn2:
                    distance = syn.shortest_path_distance(syn2)
                    if max_distance < distance:
                        max_distance = distance
        final_text += str(max_distance) + '\n'
        syns_list = []

file.close()
file = open('testFile.txt', 'a')
file.write("\n" + final_text)
file.close()
