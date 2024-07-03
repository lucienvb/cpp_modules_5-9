echo '"+" should be invalid'
./RPN "+"

echo '\n"-" should be invalid'
./RPN "-"

echo '\n"/" should be invalid'
./RPN "/"

echo '\n"*" should be invalid'
./RPN "*"

echo '\n"+ +" should be invalid'
./RPN "+ +"

echo '\n"1 1 +" = 2'
./RPN "1 1 +"

echo '\n"2 4 * 8 +" = 16'
./RPN "2 4 * 8 +"

echo '\n"2 4 8 + *" = 48'
./RPN "2 4 8 + *"

echo '\n"8 6 9 3 + -1 * / * 7 + 5 +" = -30'
./RPN "8 6 9 3 + -1 * / * 7 + 5 +"

echo '\n"9 3 5 * - -2 -2 -8 * + /" = 6'
./RPN "9 3 5 * - -2 -4 -8 * + /"

echo '\n"9 3 5 * / - -2 -2 -8 * + /" should be invalid'
./RPN "9 3 5 * / - -2 -4 -8 * + /"

echo '\n"1 9 -" = -8'
./RPN "1 9 -"

echo '\n"2 -9 /" = 0'
./RPN "2 -9 /"