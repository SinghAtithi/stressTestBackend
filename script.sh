g++ stressZone/correctCode.cpp -o stressZone/code
g++ stressZone/generator.cpp -o stressZone/gen
g++ stressZone/wrongCode.cpp -o stressZone/brute

# Run the tests
for((i = 1;i<2000; ++i)); do
    ./stressZone/gen $i > stressZone/input_file
    ./stressZone/code < stressZone/input_file > stressZone/myAnswer
    ./stressZone/brute < stressZone/input_file > stressZone/correctAnswer
    cat stressZone/input_file
    diff -Z stressZone/myAnswer stressZone/correctAnswer > /dev/null || break
    echo "Passed test: "  $i
done

# Generate the final output file
echo "WA on the following test:" > stressZone/finalOutput.txt
cat stressZone/input_file >> stressZone/finalOutput.txt
echo "Your answer is:" >> stressZone/finalOutput.txt
cat stressZone/myAnswer >> stressZone/finalOutput.txt
echo "Correct answer is:" >> stressZone/finalOutput.txt
cat stressZone/correctAnswer >> stressZone/finalOutput.txt