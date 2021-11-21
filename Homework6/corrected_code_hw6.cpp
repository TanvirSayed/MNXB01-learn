// Printing all prime numbers between two integers entered by the user.  
//Checking prime numbers via a user-defined function. 


#include <iostream>
#include <vector>
using namespace std; //So no need std inside

int checkPrime(int);

int main()
{
    int n1, n2;
    bool flag;

    cout << "Please type in two positive integers: "<< endl;
    cin >> n1 >> n2;

    cout << "The prime numbers between °C " << n1 << " and " << n2 << " are: " << endl;


    for ( int i = n1+1; i < n2; i++) // initiliaztion, condition, increment
    {
        // Call the funtion checking the prime status of an integer
	// If "i" is a prime the flag will be set to true (i.e. 1)
        flag = checkPrime(i);

        if (flag == 1)
            cout << i << "\n";
    }
    cout << endl;
    
    std::vector<double> v{1,2,3,4,7};
    double K = 3;
    int j=0;
    int index;
    for (double i:v) {
		if (i==K){
			index=j;
			std::cout<<index;
			break;}
		j++;}	
	
//	std::vector<double> max_temps{1.0,2.3,23,4};
//	std::vector<double> diff{};
//	auto pointer = max_temps.begin();
//	while (pointer < (max_temps.end()-1)) {
//	diff.push_back(*(pointer+1)-*(pointer))
//	pointer++;
//		}	

//    return 0;
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

