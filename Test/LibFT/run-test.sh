echo " -------------------------------------------------------------------------- "
echo " CHECKING NORMINETTE"
echo " -------------------------------------------------------------------------- "

norminette "$1"

echo " -------------------------------------------------------------------------- "
echo " PREPARING FILES AND FOLDERS..."
echo " -------------------------------------------------------------------------- "

rm -rf "$HOME/goinfre/RUN_TEST"
mkdir -p "$HOME/goinfre/RUN_TEST"
mkdir -p "$HOME/goinfre/RUN_TEST/PROJECT"
mkdir -p "$HOME/goinfre/RUN_TEST/RESULTS"
cp -r "$1" "$HOME/goinfre/RUN_TEST/PROJECT"
cd "$HOME/goinfre/RUN_TEST/PROJECT/$1" || exit
git clone --quiet https://github.com/Tripouille/libftTester
cd ..
git clone --quiet https://github.com/alelievr/libft-unit-test

echo " -------------------------------------------------------------------------- "
echo " EXECUTING TEST 1 / 2 - TRIPOUILLE"
echo " -------------------------------------------------------------------------- "

cd "$1/libftTester" || exit
make

echo " -------------------------------------------------------------------------- "
echo " EXECUTING TEST 2 / 3 - LIBFT-UNIT-TEST CHECK"
echo " -------------------------------------------------------------------------- "

cd ..
cd ..
cd libft-unit-test || exit
make f

echo " -------------------------------------------------------------------------- "
echo " EXECUTING TEST 2 / 3 - LIBFT-UNIT-TEST BENCHMARK"
echo " -------------------------------------------------------------------------- "

make b

echo " -------------------------------------------------------------------------- "
echo " TEST ENDED"
echo " -------------------------------------------------------------------------- "
