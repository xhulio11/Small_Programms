#include <stdio.h>
#include <vector>
using namespace std;


int main(){
    // This list will contain all the prime numbers
    // It is going to be expanded while prime numbers are calculated
    vector <int> list;
    
    // We push 1 (this prime number can divide every number)
    // We push 2 (this prime number is the first which can be divided with 1 and itself) 
    list.push_back(1);
    list.push_back(2);

    for(int i = 3; i < 10000; i++){
        int j = 0;

        // For every prime number that is until now calculated
        // See if it can devide the new number(i) that is being checked.  
        for(j = 0; j < list.size(); j++){
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