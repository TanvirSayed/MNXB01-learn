// Printing all prime numbers between two integers entered by the user.  
//Checking prime numbers via a user-defined function. 


#include <iostream>
using namespace std; //So no need std inside

int checkPrime(int);

int main()
{
    int n1, n2;
    bool flag;

    cout << "Please type in two positive integers: "<< endl;
    cin >> n1 >> n2;

    cout << "The prime numbers between " << n1 << " and " << n2 << " are: " << endl;


    for ( int i = n1+1; i < n2; i++) // initiliaztion, condition, increment
    {
        // Call the funtion checking the prime status of an integer
	// If "i" is a prime the flag will be set to true (i.e. 1)
        flag = checkPrime(i);

        if (flag == 1)
            cout << i << "\n";
    }
    cout << endl;
    return 0;
}


// user-defined function to check prime number
int checkPrime(int n)
{
    bool flag = true;

    for(int j = 2; j <= n/2; j++)
    {
        if (n%j == 0)
        {
            flag = false;           
            break;
        }
    }
    return flag;
}

