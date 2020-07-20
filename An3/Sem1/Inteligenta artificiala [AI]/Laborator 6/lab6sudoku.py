import numpy as np
import queue


class SudokuSolver:

    def __init__(self):
        self.NUM_OF_VARS = 81
        self.var_domain = {}  # dict of integer-> set() <=> variable -> domain
        self.assignment = [None] * self.NUM_OF_VARS
        self.number_of_guesses = 0

    # initializes assignment and var_domain
    def load_sudoku_data(self, puzzle_num):
        fname = 'puz-' + puzzle_num + '.txt'
        with open(fname) as f:
            content = f.readlines()

        content = [x.strip() for x in content]
        for i in range(0, len(content)):
            line = content[i]
            variables = line.split(' ')
            for j in range(0, len(variables)):
                value = variables[j]
                self.assignment[9 * i + j] = int(value) if value is not '-' else None

        for i in range(0, len(self.assignment)):
            var = self.assignment[i]
            if var is None:
                self.load_domain_values(i, self.assignment)

    def reset_state(self):
        self.number_of_guesses = 0
        self.var_domain = {}
        self.assignment = [None] * self.NUM_OF_VARS

    # Entry point for search
    def backtracking_search(self):
        puzzle_num = ['001', '002', '010', '015', '025', '026', '048', '051', '062', '076', '081', '082', '090', '095',
                      '099', '100']
        puzzle_index = 3

        self.load_sudoku_data(puzzle_num[puzzle_index])
        print
        "Initial Domain", self.var_domain
        self.number_of_guesses = 0
        solution = self.backtrack_recursive_with_inference(self.assignment)
        print
        "Puzzle ", puzzle_num[puzzle_index], "\nSolution"
        if solution is False:
            print
            False
        else:
            print
            np.reshape(solution, (9, 9))
        print
        "Number of guesses AC3: ", self.number_of_guesses

    #        self.reset_state()
    #
    #        self.load_sudoku_data(puzzle_num[puzzle_index])
    #        self.number_of_guesses = 0
    #        solution = self.backtrack_recursive(self.assignment)
    #        print "Puzzle ",puzzle_num[puzzle_index], "\nSolution"
    #        if solution is False:
    #            print False
    #        else:
    #            print np.reshape(solution, (9,9))
    #        print "Number of guesses", self.number_of_guesses

    # Entry point for search
    def backtracking_search_for_all(self):
        puzzle_num = ['001', '002', '010', '015', '025', '026', '048', '051', '062', '076', '081', '082', '090', '095',
                      '099', '100']
        for puzzle_index in range(0, len(puzzle_num)):
            # puzzle_index = 4
            self.load_sudoku_data(puzzle_num[puzzle_index])
            solution = self.backtrack_recursive(self.assignment)
            print
            "Puzzle ", puzzle_num[puzzle_index], "\nSolution"
            if solution is False:
                print
                False
            else:
                print
                np.reshape(solution, (9, 9))
            print
            "Number of guesses:", self.number_of_guesses
            self.reset_state()

            self.load_sudoku_data(puzzle_num[puzzle_index])
            self.backtrack_recursive_mrv(self.assignment)
            print
            "Number of guesses with MRV:", self.number_of_guesses
            self.reset_state()

            self.load_sudoku_data(puzzle_num[puzzle_index])
            self.backtrack_recursive_with_inference(self.assignment)
            print
            "Number of guesses with AC3:", self.number_of_guesses
            self.reset_state()

    # Recursive backtracking function
    def backtrack_recursive(self, assignment):
        if self.is_assignment_complete(assignment) is True:
            return assignment

        # Get next unassigned variable -either default or using mrv
        var = self.select_unassigned_variable(assignment)

        # Which value to assign to the variable first? - How to decide order?
        values = self.order_domain_values(var, assignment)
        if len(values) > 0:
            self.number_of_guesses += len(values) - 1

        for value in values:
            if (self.is_consistent_assigment(value, var, assignment)):
                assignment[var] = value
                result = self.backtrack_recursive(assignment)
                if (result is not False):
                    return result
                assignment[var] = None
        return False

    # Recursive backtracking function
    def backtrack_recursive_mrv(self, assignment):
        if self.is_assignment_complete(assignment) is True:
            return assignment

        # Get next unassigned variable -either default or using mrv
        var = self.select_unassigned_variable_mrv(assignment)

        # Which value to assign to the variable first? - How to decide order?
        values = self.order_domain_values(var, assignment)

        if len(values) > 0:
            self.number_of_guesses += len(values) - 1

        for value in values:
            if (self.is_consistent_assigment(value, var, assignment)):
                assignment[var] = value
                result = self.backtrack_recursive_mrv(assignment)
                if (result is not False):
                    return result
                assignment[var] = None
        return False

    # Recursive backtracking function
    def backtrack_recursive_with_inference(self, assignment):
        if self.is_assignment_complete(assignment) is True:
            return assignment

        # Get next unassigned variable -either default or using mrv
        var = self.select_unassigned_variable(assignment)

        # Which value to assign to the variable first? - How to decide order?
        values = self.order_domain_values(var, assignment)

        if len(values) > 0:
            self.number_of_guesses += len(values) - 1

        for value in values:
            inferences = []
            if (self.is_consistent_assigment(value, var, assignment)):
                assignment[var] = value
                inferences = self.get_inferences(var, value, assignment)
                # print "Inferences",inferences
                if (inferences is not False):
                    self.add_inferences_to_assignment(assignment, inferences)
                    # print np.reshape(assignment,(9,9))
                    result = self.backtrack_recursive_with_inference(assignment)
                    if (result is not False):
                        return result
            self.remove_value_and_inferences_from_assignment(var, value, inferences, assignment)

        return False

    # returns the least constraining value for var - in this case does not matter, return first value
    def order_domain_values(self, var, assignment):
        if var in self.var_domain:
            values = self.var_domain[var]
            return sorted(list(values))

    # Have all variables been assignned?
    def is_assignment_complete(self, assignment):
        if sum(x is None for x in assignment) is 0:
            return True
        return False

    # Use MRV here
    def select_unassigned_variable_mrv(self, assignment):
        min_domain = 9
        mrv_var = None
        for k, v in self.var_domain.iteritems():
            if (len(v) <= min_domain and assignment[k] is None):
                mrv_var = k
                min_domain = len(v)
                if (min_domain is 1):
                    return mrv_var

        return mrv_var

    # returns the first unassigned variable
    def select_unassigned_variable(self, assignment):
        for k, v in self.var_domain.iteritems():
            if assignment[k] is None:
                return k

    # Check if var can be assigned to variable - any constraint violated?
    def is_consistent_assigment(self, value, var, assignment):
        unavailable_values = self.get_unavailable_values(var, assignment)
        return value not in unavailable_values

    def load_domain_values(self, var, assignment):
        unavailable_values = self.get_unavailable_values(var, assignment)
        universal_set = set(np.arange(1, 10))
        self.var_domain[var] = universal_set.difference(unavailable_values)

        # Returns all pre-existing values in the row, box and column of var

    def get_unavailable_values(self, var, assignment):
        (i, j) = var / 9, var % 9
        row_values = [assignment[9 * i + k] for k in range(0, 9)]
        col_values = [assignment[j + 9 * k] for k in range(0, 9)]
        box_row, box_col = 3 * int(i / 3), 3 * int(j / 3)
        box_top_left = 9 * box_row + box_col
        box_values = []
        for row in range(0, 3):
            for col in range(0, 3):
                box_values.append(assignment[box_top_left + col + 9 * row])
        sets = [set(row_values), set(col_values), set(box_values)]
        unavailable_values = set.union(*sets)  # Note this has None too but none will never be assigned
        if None in unavailable_values:
            unavailable_values.remove(None)
        return unavailable_values

    def arc_consistency_ac3(self, assignment):
        q = queue.Queue()

        # Initially all the arcs are in CSP
        for var in range(0, len(assignment)):
            value = assignment[var]
            if value is None:
                neighbors = self.get_neighbors(var, assignment)
                for n in neighbors:
                    q.put((var, n))
                    # print "arc",var,'->',n

        while not q.empty():
            (var_i, var_j) = q.get()
            if (self.revise(var_i, var_j)):
                if (len(self.var_domain[var_i]) is 0):
                    return False
                neighbors = self.get_neighbors(var_i, assignment)
                for i in range(0, len(neighbors)):
                    var_k = neighbors[i]
                    if (var_k is not var_j):
                        q.put((var_k, var_i))
        return True

    # returns true if and only if we revise the domain of  var_i
    def revise(self, var_i, var_j):
        revised = False
        removed = set()
        # print "Arc",var_i,"->",var_j
        for d in self.var_domain[var_i]:
            v = self.var_domain[var_j]
            if d in self.var_domain[var_j]:
                v = self.var_domain[var_j] - set([d])
            if len(v) is 0:
                # self.var_domain[var_i].remove(d)
                # print "Arc",var_i,"->",var_j
                # print var_j, "has no value in domain", self.var_domain[var_j] ,"except", d
                removed.add(d)
                revised = True
        if (len(removed) > 0):
            self.var_domain[var_i] = self.var_domain[var_i] - removed
            # print "Removed", removed , "from domain of", var_i,"=>",self.var_domain[var_i]
        return revised

    def get_neighbors(self, var, assignment):

        (i, j) = var / 9, var % 9
        row_vars = [9 * i + k for k in range(0, 9) if assignment[9 * i + k] is None and (9 * i + k) is not var]
        col_vars = [j + 9 * k for k in range(0, 9) if assignment[j + 9 * k] is None and (j + 9 * k) is not var]
        box_row, box_col = 3 * int(i / 3), 3 * int(j / 3)
        box_top_left = 9 * box_row + box_col
        box_vars = []
        for row in range(0, 3):
            for col in range(0, 3):
                if (assignment[box_top_left + col + 9 * row] is None and box_top_left + col + 9 * row is not var):
                    box_vars.append(box_top_left + col + 9 * row)
        neighbors = row_vars
        neighbors.extend(col_vars)
        neighbors.extend(box_vars)
        sorted_neighbours_list = sorted(list(set(neighbors)))
        return sorted_neighbours_list

    # Use different inference methods, e.g arc consistency  - as of now update domain
    def get_inferences(self, var, value, assignment):
        result = self.arc_consistency_ac3(assignment)
        if (result is False):
            return result
        inferences = []
        for var in range(0, len(assignment)):
            value = assignment[var]
            if value is None and len(self.var_domain[var]) is 1:
                inferred_value = list(self.var_domain[var])[0]
                inferences.append((var, inferred_value))
        return inferences

    # Add the list of variable inferences, to assignment
    def add_inferences_to_assignment(self, assignment, inferences):
        # print "Adding inferences to assignment"
        for p in range(0, len(inferences)):
            (var, value) = inferences[p]
            assignment[var] = value

    def remove_value_and_inferences_from_assignment(self, var, value, inferences, assignment):
        assignment[var] = None

        if (inferences is not False):
            for p in range(0, len(inferences)):
                (var, value) = inferences[p]
                assignment[var] = None


if __name__ == "__main__":
    csp = SudokuSolver()
    csp.backtracking_search_for_all()