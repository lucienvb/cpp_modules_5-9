echo ">> Test case: 0 <<"
./conv 0

echo "\n>> Test case: a <<"
./conv a

echo "\n>> Test case: Z <<"
./conv Z

echo "\n>> Test case: & <<"
./conv '&'

echo "\n>> Test case: 1 <<"
./conv 1

echo "\n>> Test case: -1 <<"
./conv -1

echo "\n>> Test case: 1.0 <<"
./conv 1.0

echo "\n>> Test case: 4.2 <<"
./conv 4.2

echo "\n>> Test case: 1.0f <<"
./conv 1.0f

echo "\n>> Test case: 4.2f <<"
./conv 4.2f

echo "\n>> Test case: 42 <<"
./conv 42

echo "\n>> Test case: -inff <<"
./conv -inff

echo "\n>> Test case: +inff <<"
./conv +inff

echo "\n>> Test case: -inf <<"
./conv -inf

echo "\n>> Test case: +inf <<"
./conv +inf

echo "\n>> Test case: nan <<"
./conv nan

echo "\n>> Test case: 60 <<"
./conv 60

echo "\n>> Test case: -15421543265 <<"
./conv -15421543265

echo "\n>> Test case: 23454236734 <<"
./conv 23454236734

echo "\n>> Test case: 234542367 <<"
./conv 234542367

echo "\n>> Test case: 23454236734.0f <<"
./conv 23454236734.0f

echo "\n>> Test case: 1234123423454236734.0 <<"
./conv 1234123423454236734.0

echo "\n>> Test case: -1234123423454236734.0 <<"
./conv -1234123423454236734.0