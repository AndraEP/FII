import sys
import datetime
import random


# def calc(arg1, arg2, arg3, arg4):
#     if globaly_dict[arg2] is not None:
#         sum = globaly_dict.get(arg2)(int(arg1), int(arg3))
#         print(sum)
#     file = open(arg4, "w")
#     file.write(str(datetime.datetime.now().replace(microsecond=0)) + " " + arg1 + arg2 + arg3 + " = " + str(sum))
#
# globaly_dict = {
#     "+": lambda a, b: a + b,
#     "*": lambda a, b: a * b,
#     "/": lambda a, b: a / b,
#     "%": lambda a, b: a % b,
#     "^": lambda a, b: a ** b,
# }
#
# arg1 = sys.argv[1]
# arg2 = sys.argv[2]
# arg3 = sys.argv[3]
# arg4 = sys.argv[4]
# calc(arg1, arg2, arg3, arg4)


# def lottery (max_nr, draw_size, num_players):
#     list_winning = []
#     while len(list_winning) < draw_size:
#         number = random.randint(1, max_nr)
#         if number < max_nr and number not in list_winning:
#             list_winning.append(number)
#
#     players_list = []
#     for i in range(0, num_players):
#         playeri = []
#         while len(playeri) < draw_size:
#             player_number = random.randint(1, max_nr)
#             if player_number < max_nr and player_number not in playeri:
#                 playeri.append(player_number)
#         players_list.append(playeri)
#
#     print(list_winning)
#     for i in range(0, len(players_list)):
#         contor = 0
#         guessed_playeri = []
#         for j in range(0, len(players_list[i])):
#             if players_list[i][j] in list_winning:
#                 contor += 1
#                 guessed_playeri.append(players_list[i][j])
#         print(contor, guessed_playeri)
#
# if int(sys.argv[1]) in range(1, 50) and int(sys.argv[2]) in range(3, 11) and int(sys.argv[3]) in range(2, 11):
#     arg1 = int(sys.argv[1])
#     arg2 = int(sys.argv[2])
#     arg3 = int(sys.argv[3])
#     lottery(arg1, arg2, arg3)
# else:
#     exit(1)
#
#

# def matches (file1, file2, file3):
#     result = []
#     f1 = open(file1, "r")
#     data_f1 = f1.read().split("\n")
#     f2 = open(file2, "r")
#     data_f2 = f2.read().split("\n")
#     f3 = open(file3, "r")
#     data_f3 = f3.read().split("\n")
#     while data_f1 and data_f2 and data_f3:
#         match = []
#         number1 = random.randint(0, len(data_f1)-1)
#         number2 = random.randint(0, len(data_f2)-1)
#         number3 = random.randint(0, len(data_f3)-1)
#         match.append(data_f1[number1])
#         match.append(data_f2[number2])
#         match.append(data_f3[number3])
#         result.append(match)
#         data_f1.remove(data_f1[number1])
#         data_f2.remove(data_f2[number2])
#         data_f3.remove(data_f3[number3])
#     print(result)
#
# file1 = "D:\\Work\\Python\\lab10\\file1.txt"
# file2 = "D:\\Work\\Python\\lab10\\file2.txt"
# file3 = "D:\\Work\\Python\\lab10\\file3.txt"
# matches(file1, file2, file3)


# def santa (string):
#     date_to_be = datetime.datetime.strptime(string, '%Y-%m-%d %H:%M:%S')
#     actual_date = datetime.datetime.now().replace(microsecond=0)
#     time_remained = date_to_be - actual_date
#     print(time_remained)
#     print(time_remained.total_seconds())
#
# santa("2019-12-25 03:33:33")


