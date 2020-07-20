from copy import copy, deepcopy


def initial_state(checkers_board, first, second):
    for i in range(1, len(checkers_board[1]) - 1):
        checkers_board[1][i] = first
    for j in range(1, len(checkers_board[4]) - 1):
        checkers_board[4][j] = second


def final_state(checkers_board, first, second):
    contor = 0
    contor_first = 0
    contor_second = 0
    for i in range(1, len(checkers_board[1]) - 1):
        if checkers_board[1][i] == second:
            contor_second += 1
        if checkers_board[4][i] == first:
            contor_first += 1
    for k in range(1, len(checkers_board) - 1):
        for i in range(1, len(checkers_board[k]) - 1):
            if checkers_board[k][i] == first and checkers_board[k + 1][i] == second:
                contor += 1
        if contor == 4:
            return True
    if contor_first == 4:
        return True
    if contor_second == 4:
        return True
    return False


def intermediate_state(board, row_moving, col_moving, current_pos_row, current_pos_col, player):
    board[current_pos_row][current_pos_col] = 0
    board[row_moving][col_moving] = player


def show_board(board):
    for row in range(1, 5):
        for col in range(1, 5):
            print(board[row][col], end="  ")
        print()


def get_possible_moves(checkers_board, player):
    moves = []
    for row in range(1, 5):
        for col in range(1, 5):
            if checkers_board[row][col] == player:
                for r in range(row - 1, row + 2):
                    for c in range(col - 1, col + 2):
                        if checkers_board[r][c] == 0:
                            # print(row, col, "->", r, c)
                            move = (row, col, r, c)
                            moves.append(move)
    return moves


def evaluate_state(board):
    value = 0
    for row in range(1, 5):
        for col in range(1, 5):
            if board[row][col] == first_player:
                value = value - row
                # we subtract how much each piece has advanced
            if board[row][col] == second_player:
                value = value + (5 - row)
                # we add how much each piece has advanced
    return value


checkers_board = [
    [-1, -1, -1, -1, -1, -1],
    [-1, 0, 0, 0, 0, -1],
    [-1, 0, 0, 0, 0, -1],
    [-1, 0, 0, 0, 0, -1],
    [-1, 0, 0, 0, 0, -1],
    [-1, -1, -1, -1, -1, -1]
]

first_player = 1
second_player = 2
initial_state(checkers_board, first_player, second_player)

current_player = first_player

while not final_state(checkers_board, first_player, second_player):
    if current_player == first_player:
        show_board(checkers_board)
        possible_moves = get_possible_moves(checkers_board, current_player)
        print(f"Player {current_player}, is your turn.")
        moveStr = input()
        if moveStr == "q":
            print("Game ended.")
            break
        if moveStr != "q" and len(moveStr) == 4:
            actual_row = int(moveStr[0])
            actual_col = int(moveStr[1])
            wanted_row = int(moveStr[2])
            wanted_col = int(moveStr[3])
            pos = (actual_row, actual_col, wanted_row, wanted_col)
            if pos in possible_moves:
                intermediate_state(checkers_board, wanted_row, wanted_col, actual_row, actual_col, current_player)
        current_player = second_player

    else:
        possible_moves_computer_first = get_possible_moves(checkers_board, current_player)
        remember_move = possible_moves_computer_first[0]

        max_final = 0
        for i in range(0, len(possible_moves_computer_first)):
            copy_board_comp_first = deepcopy(checkers_board)
            intermediate_state(copy_board_comp_first, possible_moves_computer_first[i][2],
                               possible_moves_computer_first[i][3],
                               possible_moves_computer_first[i][0], possible_moves_computer_first[i][1], current_player)
            possible_moves_human_first = get_possible_moves(copy_board_comp_first, first_player)

            min_final = 10
            for j in range(0, len(possible_moves_human_first)):
                copy_board_human_first = deepcopy(copy_board_comp_first)
                intermediate_state(copy_board_human_first, possible_moves_human_first[j][2],
                                   possible_moves_human_first[j][3],
                                   possible_moves_human_first[j][0], possible_moves_human_first[j][1], first_player)
                possible_moves_computer_second = get_possible_moves(copy_board_human_first, current_player)

                max = -10
                # second level computer
                for k in range(0, len(possible_moves_computer_second)):
                    second_board_comp = deepcopy(copy_board_human_first)
                    intermediate_state(second_board_comp, possible_moves_computer_second[k][2],
                                       possible_moves_computer_second[k][3],
                                       possible_moves_computer_second[k][0], possible_moves_computer_second[k][1],
                                       current_player)
                    possible_moves_human_second = get_possible_moves(second_board_comp, first_player)

                    min = 10
                    # second level human
                    for l in range(0, len(possible_moves_human_second)):
                        second_board_human = deepcopy(second_board_comp)
                        intermediate_state(second_board_human, possible_moves_human_second[l][2],
                                           possible_moves_human_second[l][3],
                                           possible_moves_human_second[l][0], possible_moves_human_second[l][1],
                                           first_player)
                        min2 = evaluate_state(second_board_human)

                        if min2 < min:
                            min = min2

                    if min > max:
                        max = min

                if max < min_final:
                    min_final = max

            # remember the move, first one if many with the same result
            if min_final > max_final:
                max_final = min_final
                remember_move = possible_moves_computer_first[i]

        # do that move
        print(remember_move)
        intermediate_state(checkers_board, remember_move[2], remember_move[3], remember_move[0], remember_move[1],
                           current_player)
        show_board(checkers_board)
        print("PC before\n")
        current_player = first_player
