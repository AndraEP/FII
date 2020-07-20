# Ex_4
# Write a function that receives two strings as parameters and returns the number of occurrences of the first character string in the second.

string1 = input("First string: ")
string2 = input("Second string: ")

def ex4 (string1, string2):
    string1 = string1.lower()
    string2 = string2.lower()
    count = 0
    for i in range (0, len(string2)):
        if string1[0] == string2[i]:
            count += 1
    return count

print(ex4(string1, string2))