def initial_state(checkers_board, first, second):
    # global checkers_board
    for i in range(1, len(checkers_board[1]) - 1):
        checkers_board[1][i] = first
    for j in range(1, len(checkers_board[4]) - 1):
        checkers_board[4][j] = second
    # return checkers_board


def final_state(checkers_board, first, second):
    # for elem_here in checkers_board:
    #     print(elem_here)
    # print('\n')

    # checkers_board = [
    #     [-1, -1, -1, -1, -1, -1],
    #     [-1, 2, 2, 2, 0, -1],
    #     [-1, 0, 0, 2, 0, -1],
    #     [-1, 0, 0, 0, 0, -1],
    #     [-1, 1, 1, 1, 1, -1],
    #     [-1, -1, -1, -1, -1, -1]
    # ]

    # for elem in checkers_board:
    #     print(elem)
    # print('\n')

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
    # for elem_f in checkers_board:
    #     print(elem_f)
    # print('\n')


def show_board(checkers_board):
    for row in range(1, 5):
        for col in range(1, 5):
            print(checkers_board[row][col], end="  ")
        print()


def get_possible_moves(checkers_board, player):
    moves = []
    for row in range(1, 5):
        for col in range(1, 5):
            if checkers_board[row][col] == player:
                for r in range(row-1, row+2):
                    for c in range(col-1, col+2):
                        if checkers_board[r][c] == 0:
                            # print(row, col, "->", r, c)
                            move = (row, col, r, c)
                            moves.append(move)
    return moves


def evaluate_state(checkers_board):
    value = 0
    for row in range(1, 5):
        for col in range(1, 5):
            if checkers_board[row][col] == first_player:
                value = value - row
                # we subtract how much each piece has advanced
            if checkers_board[row][col] == second_player:
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

# for elem_i in checkers_board:
#     print(elem_i)
# print('\n')

first_player = 1
second_player = 2
initial_state(checkers_board, first_player, second_player)

# print(final_state(checkers_board, first_player, second_player))

current_player = first_player

while not final_state(checkers_board, first_player, second_player):
    if current_player == first_player:
        show_board(checkers_board)
        possible_moves = get_possible_moves(checkers_board, current_player)
        # print(f"Possible moves for Player {current_player}: {possible_moves}")
        print(f"Player {current_player}, is your turn.")
        moveStr = input()
        # move = int(moveStr)
        # print(move*2)
        # TODO: check if the move is valid, 4 digits number, each digit from {1,2,3,4}
    else:
        possible_moves = get_possible_moves(checkers_board, current_player)
        print(f"Possible moves for Player{current_player}: {possible_moves}")
        print(f"The evaluation of current state is: {evaluate_state(checkers_board)}")
    if current_player == first_player:
        current_player = second_player
    else:
        current_player = first_player