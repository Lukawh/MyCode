#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

int main()
{
    int prime_test, n;

    //Ask the user to enter number until he gives an appripriate one.
    while(true) {
        cout<<"Please, enter number to work with!"<<endl;
        cin>>prime_test;

        //If number is invalid, do the cycle again.
        if(prime_test<=1) {
            cout<<"Invalid number! Please enter number higher than 1!"<<endl;
            continue;
        }
        //Continue with the program otherwise.
        break;
    }

    n = sqrt(prime_test);
    ++n;
    bool * sieve = (bool*) calloc(n, sizeof(bool));

    //0 and 1 are always not prime.
    sieve[0] = true;
    sieve[1] = true;

    //Work with each number in the sieve.
    for(int i = 2; i<n; i++) {
        //If it is not prime, move to another one.
        if(sieve[i]) {
            continue;
        }
        //Mark all multiples of current number as not prime.
        for(int j = i*2; j<n; j+=i) {
            //Make sure we do not get out of bounds.
            if(j<n) {
                sieve[j] = true;
            }
        }
    }


    //Print all prime numbers (Or use them in any other manner)
    for(int i = 2; i<n; i++) {
        if(!sieve[i] && !(prime_test%i)) {
            cout<<"Number "<<prime_test<<" is not a prime number."<<endl;
            cout<<"Its divisor is "<<i<<", which implies that its divisor is also "<<prime_test/i<<endl;
            return 0;
        }
    }

    cout<<"Number "<<prime_test<<" is a prime number."<<endl;
    return 0;
}
