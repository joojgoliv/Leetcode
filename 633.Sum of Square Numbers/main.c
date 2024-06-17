#include <stdio.h>
#include <stdbool.h>
#include <math.h>
int a, b, sum;

/*
Takes the square root of c and put in a, after this the program tests a with all possible combinations of b that 
cant pass the value of c, if it passes than we subtract 1 of the value of a and test it with possible values of b
Note that if mathematically if we pass the value of c in a^2 + b^2 and decrease by 1 a and a = b we cant ever find the 
a value that can be equal to c therefore the loop breaks, to not consume more processing.
*/
bool judgeSquareSum(int c) {
    if(c<0){
        return false;
    }else{
        a = sqrt(c);
        if(a*a == c){
            return true;
        }else{
            b = 1;
            while(1){
                sum = (a*a)+(b*b);
                if(sum == c) return true;
                if(sum<c) {
                  b++;
                }else{
                    a--;
                    if(a == b|| a < b) return false;
                    b=1;
                }
            }
        }
    }
}

int main(){
    int input;
    printf("Chose the number: ");
  scanf("%d", &input);
    if(judgeSquareSum(input) == true){
        printf("True");
        printf("\na = %d, b = %d", a, b);
    }else{
        printf("False");
    }

    return 0;
}