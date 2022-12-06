set -e
g++ correctCode.cpp -o code
g++ generator.cpp -o gen
g++ wrongCode.cpp -o brute
for((i = 1;i<2000 ; ++i)); do
    ./gen $i > input_file
    ./code < input_file > myAnswer
    ./brute < input_file > correctAnswer
    cat input_file
    diff -Z myAnswer correctAnswer > /dev/null || break
    echo "Passed test: "  $i
done
echo "WA on the following test:" > finalOutput.txt
cat input_file >> finalOutput.txt
echo "Your answer is:" >> finalOutput.txt
cat myAnswer >> finalOutput.txt
echo "Correct answer is:" >> finalOutput.txt
cat correctAnswer >> finalOutput.txt