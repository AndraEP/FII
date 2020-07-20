import utils

def function():
    x = 0
    y = 0
    while 1:
        inputs = input()
        if (inputs == "q"):
             return "Program ended."
        else:
            x = int(inputs)
            y = utils.process_item(x)
            print(y)