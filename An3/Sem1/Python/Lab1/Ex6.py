# Ex_6
# Write a function that converts a string of characters written in UpperCamelCase into lowercase_with_underscores.


#string = "UpperCamelCase"
#is_first = True
#result = ""

#for c in string:
 #   if is_first:
  #      is_first = False
   #     result += c.lower()
   # else:
    #    if c == c.lower():
     #       result += c
      #  else:
       #     result += f"_{c.lower()}"
        #    result += "_{}"
#print(result)

string = "UpperCamelCase"


def ex_6(string):
    aux = string
    aux = aux.replace(string[0], string[0].lower())
    for i in range(1, len(string)):
        if string[i].isupper():
            aux = aux.replace(string[i], "_"+string[i].lower())
    print(aux)


ex_6(string)