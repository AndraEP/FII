import random


def isFinal(state):
    if state[1] == 0 and state[2] == 0 and state[3] == 2:
        return True
    return False


def transition(state, misMoved, canMoved):
    newState = []
    if state[3] == 1:
        newState = [state[0], state[1] - misMoved, state[2] - canMoved, 2, state[4] + misMoved, state[5] + canMoved]
    elif state[3] == 2:
        newState = [state[0], state[1] + misMoved, state[2] + canMoved, 1, state[4] - misMoved, state[5] - canMoved]
    return newState


def validation(state, misMoved, canMoved):
    newState = transition(state, misMoved, canMoved)
    if newState[1] < 0 or newState[2] < 0 or newState[4] < 0 or newState[5] < 0:
        return False
    elif 0 < newState[1] < newState[2]:
        return False
    elif 0 < newState[4] < newState[5]:
        return False
    elif misMoved + canMoved > newState[0]:
        return False
    else:
        return newState


class generateClass:
    def __init__(self):
        self.possibilities = []

    def initialization(self, barca, misionari, canibali):
        for i in range (0, misionari+1):
            for j in range (0, canibali+1):
                if (i+j) <= barca and (i+j) != 0:
                    self.possibilities.append((i, j))
        print (self.possibilities)

    def returnPairGenerator(self):
        return self.possibilities[random.randint(0, len(self.possibilities)-1)]

    def returnArrayOfPairs(self):
        return self.possibilities


#object creation
global generate
generate = generateClass()


def strategyRandom(state):
    stateList = []
    savedInitialState = state.copy()
    runs = 0
    global max_runs
    max_runs = 10
    while not isFinal(state):
        if runs == max_runs:
            state = savedInitialState.copy()
            runs = 0
            stateList = []
        misMoved, canMoved = generate.returnPairGenerator()
        if validation(state, misMoved, canMoved) is not False and validation(state, misMoved, canMoved) not in stateList:
            newState = validation(state, misMoved, canMoved)
            stateList.append(newState)
            state = newState
            print (state)
        runs += 1
    return state


stateList = []


def strategyBKT(state):
    global stateList
    if isFinal(state):
        print (state)
    for solution in generateBKTMoves(state):
        if solution not in stateList:
            stateList.append(solution)
            strategyBKT(solution)


def generateBKTMoves (state):
    generatedList = []
    pairs = generate.returnArrayOfPairs()
    for pair in pairs:
        if validation(state, pair[0], pair[1]) is not False:
            newState = validation(state, pair[0], pair[1])
            generatedList.append(newState)
    return generatedList


def strategyIDDFS (state, treeDepth):
    for i in range (treeDepth):
        newState = strategyDFS(state, i)
        if newState is not False:
            solution = newState
            break
    return solution


def strategyDFS (state, treeDepth):
    if isFinal(state):
        return state
    if treeDepth == 0:
        return False
    pairs = generate.returnArrayOfPairs()
    for pair in pairs:
        if validation(state, pair[0], pair[1]) is not False:
            newState = validation(state, pair[0], pair[1])
            solution = strategyDFS(newState, treeDepth - 1)
            if solution is not False:
                return solution
    return False


def main():
    misionari = random.randint(3, 15)
    canibali = random.randint(3, 15)
    barca = random.randint(3, 5)

    while misionari < canibali:
        misionari = random.randint(3, 15)
        canibali = random.randint(3, 15)
    state = [barca, misionari, canibali, 1, 0, 0]
    generate.initialization(state[0], state[1], state[2])

    print ("Random: ")
    print(strategyRandom(state))
    print ("\n")

    print("BKT: ")
    strategyBKT(state)
    print("\n")

    print("IDDFS: ")
    print(strategyIDDFS(state, 100))

main()