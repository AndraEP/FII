import numpy as np
import csv
import keras
from keras.layers import Dense
from gensim.models import Word2Vec, KeyedVectors

with open("data.txt") as csv_file:
    csv_reader = csv.reader(csv_file, delimiter=',')
    get_array = np.array(list(csv_reader)[1:])
all_words = [line.split() for line in get_array[:, 0]]
print(all_words)
model = Word2Vec(all_words, min_count=1)
model.save("word2vec.model")

list = ['school', 'computer', 'lights', 'camera', 'keyboard', 'work', 'projects', 'car', 'speed', 'friends']
for i in list:
    print(model.wv.most_similar(positive=i, topn=1))

model.wv.save("wordvect.kv")
key_vect = KeyedVectors.load("wordvect.kv")
key_word = [key_vect[word] for sentence in get_array[:, 0] for word in sentence.split()]
key_arr = [get_array[i, 1] for (i, sentence) in enumerate(get_array[:, 0]) for word in sentence.split()]
training_data = np.array(key_word)
train_labels = np.array(key_arr)

rn_model = keras.models.Sequential()
rn_model.add(Dense(20, activation='relu', input_shape=(100,)))
rn_model.add(Dense(10, activation='relu'))
rn_model.add(Dense(1, activation='sigmoid'))
rn_model.compile(loss='binary_crossentropy', optimizer='adam')
rn_model.fit(training_data, train_labels, validation_split=0.0, epochs=4, batch_size=600, verbose=2)
rn_model.save("model.h5")
new_model = keras.models.load_model("model.h5")
print(new_model.predict(np.array([key_vect['summer']])))
