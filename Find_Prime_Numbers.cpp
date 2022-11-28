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

    for(int i = 3; i < n; i++){
        int j = 1;

        // For every prime number that is until now calculated
        // See if it can devide the new number(i) that is being checked.  
        // NOTE: We start from j = 1 (Which means that we take the first prime number to be 2),
        // because 1 can devide any number and it does not define if it is prime or not. 
        for(j ; j < list.size(); j++){
            if(i % list[j] == 0 ){
                break;         
            }
        }
        
        // If we itirated through the whole vector => We din't find any number that can devide (i)
        // So we push it in our list 
        if(j == list.size()){
            list.push_back(i);
        }
        // Finially, we continue to check for the next number. 
    }

    // Print the results
    for(int i : list){
        printf("%d ",i);       
    }
    printf("\n");

}