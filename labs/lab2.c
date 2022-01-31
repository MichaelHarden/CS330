#include <stdio.h>
#include <math.h>

/***
 * cubeOfOdd prints the cube of all non-negitave odd integers, which fall in
 * the range falling in the range, (0, n)
 * 
 * This goal is achieved by looping through each number in the range 0 to n.
 * If the number is divisable by 2 and positive, its value is printed.
 * 
 * parameters:
 *      int n: a non-negitive integer as upper bound to the range.
 */
void cubeOfOdd(int n) {
    int num;
    for (num=1 ; num<n ; num++) {
        // check if the current num is positive and odd .
        if ((num % 2) == 1) { 
            int cube = num*num*num;
            printf("%d \n",cube);
        }
    }
}

/***
 * introToCS330 prints "UAB CS 330" when n is divisible by both 3 and 7. If it
 * is only divisable by 7, "UAB" is printed, If only divisable by 3, "CS" is 
 * printed. If none of the above conditions are met, n is checked to be a 
 * prime number. If it is, "Go Blazers" is printed. If none of these cases are
 * met, the cube of n is printed.
 * 
 * parameters:
 *      int n: a positive integer key value. This value is used for tests 
 *   listed above
 */
void introToCS330(int n) {
    //checking if divisible by 3 and 7
    if (((n % 7) == 0) && ((n % 3) == 0)) {
        printf("UAB CS 330\n");
    }
    // checking if divisible by 7
    else if((n % 7) == 0) {
        printf("UAB\n");
    }
    //checking if divisible by 3
    else if((n % 3) == 0) {
        printf("CS\n");
    }
    else {
        // starts by assuming n is primve
        int isPrime = 1;
        int i;
        // if n is not prime, all the prime factors must come in pairs. These
        // pairs start at the square root. For each pair, the first number must
        // be at or bellow the square root and its partner must be at or above
        // the square root. Because of this principal we only have to check the
        // values in the range of [2 : ceiling(square_root(n))]
        for (i=2 ; i <= (int) ceil(sqrt(n)) ; i++) {
            // if n is divisible by i, then it is not prime
            if((n%i) == 0) {
                isPrime = 0;
                break;
            }
        }
        if (isPrime) {
            printf("Go Blazers\n");
        } else {
            printf("%d\n", n*n*n);
        }

    }
}

/***
 * printHello prints a string of each number, i, in the range [0 : n]. However, if
 * n is a power of 2, "HELLO" is printed in the place of i.
 * 
 * We can check whether i is a power of 2 by checking the bit representation of i.
 * Since binary is a power two number system a numeber containing only a single 1 
 * in the binary string, then it is a power of 2.
 * 
 * Examples: (type int)
 *   5  ->  0000 0000 0000 0101 : contains two 1's. Not a power of 2
 *   32 ->  0000 0000 0010 0000 : contains only one 1. Is a power of 2
 *  173 ->  0000 0000 1010 1101 : contains five 1's. Not a power of 2
 * 
 * This computation is done by checking each bit and keeping track of the 
 * number of 1's in the binary string.
 * 
 * parameters:
 *      int n: an integer which is used for upper range of the process 
 *   described above. 
 */
void printHello(int n) {
    
    
    unsigned int i;
    for(i=0 ; i <= n ; i++) {

        unsigned int num = i;
        unsigned int setBits = 0;
        // counts number of 1's in the bit representation of the current number
        while (num != 0) {
            setBits += num & 1;
            num >>= 1;
        }
        if (setBits == 1) {
            printf("HELLO");
        } else {
            printf("%d", i);
        }
    }
    printf("\n");
}

/**
 * paintGallons finds the number of gallons of paint needed to paint a room.
 * This calculation is done by finding the area of all four walls and the
 * ceiling, taking their sum, and dividing this sum by 400. The number 400 is
 * chosen because, one gallon will provide enough paint for 400 square feet of
 * wall.
 * 
 * parameters:
 *      float lenght: lenght of the room in feet
 *      float width: width of the room in feet
 *      float height: height of the room in feet
 * 
 * return:
 *      int: the number of gallons needed
 */
int paintGallons(float length, float width, float height) {
    float paint_area = ((length * height) * 2)
                        + ((width * height) * 2)
                        + (length * width);
                    
    // the ceiling function is used to prevent from being short by a fraction 
    // of a gallon.
    int gallons_needed = (int) ceil(paint_area/400);
    return gallons_needed;
}

/**
 * grader calculates if a student has a passing grade. The rubic used is as
 * follows. If the students attendance score is 20 or less, he fails. If either
 * the exams average or average home work is 70 or below, he fails. The student
 * also must have at least an average homework or average exam schore that is
 * greater than 85.
 * 
 * parameters:
 *      float avg_exam: the average score for the exames
 *      float avg_hw: the average score for homework
 *      float attendance: the attendance score
 */
void grader (float avg_exam, float avg_hw, int attendance) {
    if ((attendance > 20) && (avg_exam > 70) && (avg_hw > 70)) {
        if ((avg_exam > 85) || (avg_hw > 85)) {
            printf("PASS\n");
        }
    }
    else {
        printf("FAIL\n");
    }
}

int main(int argc, char const *argv[])
{
    //// TEST CASES FROM ASSIGNMENT DOC
    
    // cubeOfOdd(5);
    // cubeOfOdd(3);
    // cubeOfOdd(8);

    // introToCS330(3);
    // introToCS330(70);
    // introToCS330(4);
    // introToCS330(17);
    // introToCS330(42);

    // printHello(3);
    // printHello(7);
    // printHello(10);
    // printHello(1);

    // printf("%d", paintGallons(10.0, 12.0, 8.0));
   
    // grader(72.0, 88.0, 22);
    // grader(66.0, 100.0, 24);
    // grader(100.0, 90.0, 18);

    int num;
    printf("Enter an number for the function you would like to run\n \t1) cubeOfOdd()\n \t2) introToCS330()\n \t3) printHello()\n \t4) paintGallons()\n \t5) grader()\n");
    scanf("%d", &num);
    if (num == 1) {
        printf("Enter integer: "); 
        scanf("%d", &num);
        cubeOfOdd(num);
    } else if (num == 2) {
        printf("Enter integer: ");
        scanf("%d", &num);
        introToCS330(num);
    } else if (num == 3) {
        printf("Enter integer: ");
        scanf("%d", &num);
        printHello(num);
    } else if (num == 4) {
        float len, wid, high;
        printf("Enter lenght float: ");
        scanf("%f", &len);

        printf("Enter width float: ");
        scanf("%f", &wid);

        printf("Enter height float: ");
        scanf("%f", &high);
        printf("%d\n", paintGallons(len, wid, high));
    } else if (num == 5) {
        float att, exam, hw; 
        printf("Enter average exam float parameter: ");
        scanf("%f", &exam);

        printf("Enter average homework float parameter: ");
        scanf("%f", &hw);
        printf("Enter attendance float parameter: ");
        scanf("%f", &att);

        grader (exam, hw, att);
    } else {
        printf("Out of bounds value");
    }

    return 0;
}
