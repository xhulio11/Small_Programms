#include<iostream>
#include<cmath>
using namespace std;

// DISCLAIMER
// Approximate solutions only

// Calculating factorial of a int n
long long factorial(int n){

  if(n == 0 || n == 1){
    return 1;
  }
  else{
    return n*factorial(n-1);
  }
}

// Calculating sin(x)
double sin(double x){
   double result = 0;

   for(int i = 0; i < 10; i++){
     // sin x = x − x^2/2! + x^4/4! - x^6/6! + ...
     result = result + pow(-1,i)*(pow(x,2*i+1)/factorial(2*i+1));

   }
   return result;
}

// Calculating cos(x)
double cos(double x){
   double result = 0;

   for(int i = 0; i < 11; i++){
     // cos x = 1 − x + x^3/3! - x^5/5! + ...
     result = result + pow(-1,i)*(pow(x,2*i)/factorial(2*i));

   }
   return result;
}



int main(){
  double x;
  string choice;
  cout<<"Type \"sin\" if you want to find the sin(x) or type \"cos\" to find cos(x):";
  cin>>choice;

  // Controlling if user choose sin, cos or gave wrong input
  if(choice == "sin"){
      cout<<"Give me an x for sin(x): ";
      cin>>x;
      cout<<"The sin("<<x<<") is :"<<sin(x)<< endl;
      // If the user want to continue
      cout<<"\nType \"yes\" if you want to continue and \"no\" or something else otherwise:";
      cin>>choice;
      if(choice == "yes"){
        cout<<endl;
        // Call main() again
        main();
      }
      else {return 0;}
  }
  else if(choice == "cos"){
      cout<<"Give me an x for cos(x): ";
      cin>>x;
      cout<<"The sin("<<x<<") is :"<<cos(x)<< endl;
      // If the user want to continue
      cout<<"\nType \"yes\" if you want to continue and \"no\" or something else otherwise:";
      cin>>choice;
      if(choice == "yes"){
        cout<<endl;
        // Call main() again
        main();
      }
      else {return 0;}
  }
  else{
      // if the input is wrong then call main again.
      cout<<"Wrong Input!!!"<<endl;
      main();
  }

}
