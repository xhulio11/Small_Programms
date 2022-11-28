#include <stdio.h>
#include <vector>
using namespace std;


int main(){
    int n; 
    printf("Give me the upper bound to calculate prime numbers: ");
    scanf("%d",&n);
    
    // This list will contain all the prime numbers
    // It is going to be expanded while prime numbers are calculated
    vector <int> list;
    
    // We push 1 (this is a prime number that can devide any number)
    // We push 2 (this prime number is the first which can be divided with 1 and itself) 
    list.push_back(1);
    list.push_back(2);


    /*-----------------------------------LOGIC OF CALCULATION---------------------------------------------------
        If a prime number can devide a new number, that means that the new number is not prime.
        There is no need to calculate if anyone of the previous numbers that exist can devide 
        the new number to be checked. That is because every non-prime number (for example 14 or 16 etc)
        can be devided from a previous number which is prime. So if the non-prime number (14) can
        devide a number (for example 28) that means that a previous prime number can do it too (for example 2 or 7).
    -----------------------------------------------------------------------------------------------------------
    */

   // We itirate through all the numbers that are to be checked. 
    for(int i = 3; i < n; i++){
        int j = 1;
        
        /*
        1) For every prime number that has been until now calculated
        2) See if it can devide the new number(i) that is being checked.
        3) NOTE: We start from j = 1 (Which means that we take the first prime number to be 2),
           because 1 can devide any number and it does not define if it is prime or not. 
        */
        for(j ; j < list.size(); j++){
            if(i % list[j] == 0 ){
                break;         
            }
        }
       
        /*
        If we itirated through the whole vector it means that we did not find any number that can devide (i)
        So we push it in our list 
        */
        if(j == list.size()){
            list.push_back(i);
        }
        
        // Finally, we continue to check for the next number. 
    }

    // Print the results
    for(int i : list){
        printf("%d ",i);       
    }
    printf("\n");

}
