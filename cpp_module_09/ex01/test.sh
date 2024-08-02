# 42 test cases
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
./RPN "7 7 * 7 -"
./RPN "1 2 * 2 / 2 * 2 4 - +"
./RPN "(1 + 1)"

# Basic operations
./RPN "2 3 +"           # 5
./RPN "9 4 -"          # 5
./RPN "6 3 /"           # 2
./RPN "5 3 *"           # 15

# Mixed operations
./RPN "5 1 2 + 4 * + 3 -"      # 14
./RPN "2 3 4 * +"              # 14
./RPN "2 3 + 4 *"              # 20
./RPN "2 3 4 + *"              # 14

# Handling of zero and negatives
./RPN "0 3 +"           # 3
./RPN "5 0 -"           # 5
./RPN "0 5 -"           # -5
./RPN "0 3 *"           # 0
./RPN "3 0 *"           # 0
./RPN "6 3 0 /"         # Error (division by zero)
./RPN "-2 -3 *"         # 6

# Order of operations without parentheses
./RPN "5 1 2 + 4 * + 3 -"      # 14
./RPN "3 5 8 * 7 + *"          # 141
./RPN "4 2 + 3 5 1 - * +"      # 18

# Complex expressions
./RPN "8 4 1 1 + - / 3 * 2 1 1 + + -"  # 8
./RPN "9 3 / 2 * 5 +"                   # 11

# More edge cases
./RPN ""                # Error (empty input)
./RPN "4 2 +"           # 6
./RPN "4 2 3 +"         # Error (too many operands)
./RPN "+"               # Error (missing operands)
./RPN "4 2 + +"         # Error (too many operators)
./RPN "4 2 3"           # Error (not enough operators)
./RPN "5 5 +"           # 10

# Parentheses and invalid characters
./RPN "(1 2 +)"         # Error (invalid characters/parentheses)
./RPN "2 3 4 a +"       # Error (invalid characters)

