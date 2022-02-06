#include <iostream>

int stepPerms(int n) { //uses recursion
    if(n < 2) { //base case
        return 1;
    }
    if(n == 2) { //base case
        return 2;
    }
    else { //adds the number of ways from the previous 3 steps
        return stepPerms(n-1) + stepPerms(n-2) + stepPerms(n-3);
    }
}

int table[10000];
int memoization(int n) { //faster/efficient recursion
    if(n < 2) {
        return 1;
    }
    if(n == 2) {
        return 2;
    }
    else if(table[n] != 0) {
        return table[n];
    }
    else {
        int temp = memoization(n-1) + memoization(n-2) + memoization(n-3);
        table[n] = temp;
        return temp;
    }
}

int main() {
    
    for(int i = 0; i <= 10; i++) {
        //When I set i < 100, my output started slowing down at 34 so I terminated the process.
        std::cout << "Steps: " << i << "\t" << "Ways: " << stepPerms(i) << std::endl;
    }
    
    for(int i = 0; i < 10000; i++) {
        table[i] = 0;
    }
    for (int i = 0; i <= 100; i++) {
        //Memoization runs much faster and can produce results for all 100 numbers
        //Some results after 36 become negative because they pass the maximum number an int can hold
        std::cout << i << " :  " << memoization(i) << std::endl;
    }

    return 0;
}

/**
 * First, I wrote out all the possible sequences of 2, 3, 4 and 6 steps on paper.
 * Then, I counted the number of ways Davis can climb each of these steps and created a table.
 * The table looked like:
 * 1    2   3   4   5   6
 * 1    2   4   7   13  24
 * I couldn't find the pattern right away so I originally thought I had to
 * count the number of times a number shifted in a sequence
 * (EX: 1 2 1 1 -> 1 1 2 1, the 2 can be shifted 4 times) but that wasn't correct.
 * 
 * Then, I thought about how I could get the number of ways to climb 7 steps
 * without writing out all the possible combinations.
 * 
 * After trying different variations of adding, subtracting, and dividing the numbers on the chart,
 * I thought about how the possible sequences I wrote out look similiar and thought that the
 * number of ways to climb 6 (n-1) steps probably affects the number of ways for the 7th (nth) step.
 * 
 * I ended up realizing that the pattern was to add the 3 previous ways to get
 * the number of ways for the nth step.
 * 
 * So, to get the number of ways to climb 6 steps, you can do 13 + 7 + 4 = 24,
 * so for 7 steps, you have to add 7 + 13 + 24 = 44.
 */