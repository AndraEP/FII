# Ex_3
# Scrieti o functie care returneaza numarul de cuvinte care exista intr-un string. Cuvintele sunt separate de spatii, semne de punctuatie (, ;, ? ! . )

import re
string = "Astazi e frumi afara! Eu vreau o shaorma, poate si o pizza?; shhh.."

#print(string.split())  # split words by space
print(re.split(r"\W+", string))  # split by words
#print(re.findall(r"[\w']", string))  # split by every letter