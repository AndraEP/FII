# Ex_2
# Write a function that calculates how many vowels are in a string.

string = "This is a random string"
# string = input("Type in a string: ")

def ex2(string):
    count = 0
    check = {i: 0 for i in "aeiouAEIOU"}
    for char in string:
        if char in check:
            count += 1
    return count


print(ex2(string))
print(*map(string.lower().count, "aeiouAEIOU"))
