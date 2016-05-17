echo "Test invalide"

echo "\n"
cat ./exemple/false.exemple
./fillit ./exemple/false.exemple
echo "\n"
cat ./exemple/false2.exemple
./fillit ./exemple/false2.exemple
echo "\n"
cat ./exemple/false3.exemple
./fillit ./exemple/false3.exemple
echo "\n"
cat ./exemple/false4.exemple
./fillit ./exemple/false4.exemple
echo "\n"
cat ./exemple/false5.exemple
./fillit ./exemple/false5.exemple
echo "\n"

echo "Test valide"
./PcsGen.py 1 > test
time ./fillit test
./PcsGen.py 4 > test
time ./fillit test
./PcsGen.py 8 > test
time ./fillit test
./PcsGen.py 9 > test
time ./fillit test
./PcsGen.py 10 > test
time ./fillit test
