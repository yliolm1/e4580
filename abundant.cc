#include <iostream>
#include <cmath>
#include <cstdlib>

#include <errno.h> // we will include errnos, cmath, cstdlib due to strtol, square-rooting and error-checking
using namespace std;

int sum(int o){
int altogether = 0;
for (int n = 1; n <= sqrt(o); n++){ // this sum function takes a number and tries to trace smaller divisors
if (o%n == 0){ // check that there won't be any abundance - should be always zero when looking for needed numbers
if (o/n != n){ // check that we won't add the same number twice if division equals the given divisor

altogether += n; 
altogether += (o/n); // add the small divisor and the result of the said division

}
else { altogether += n;} // just add the divisor if the requirement above is not fulfilled

}
}
altogether -= o; // we won't need the number in the sum - just its factors/divisors
return altogether;


}

int main(int argc, char* argv[])
{
if (argc != 2){return -1;}

char* p;
errno = 0;
int k = strtol(argv[1], &p, 10);
if (*p != '\0' || errno != 0) return -1; //check that we have only 2 arguments, only int digits and nothing more

int l = 0; // appearance counter given by the user


for (int m = 1; m < 1000000; m++){ // 1000000 will be the overall maximum this program could reach

if ((sum(m) > m)){ // see if the means of abundance are met - the number should be smaller than the sum of its divisors
l++;
cout << m << endl;
if (l == k){return 0;} // see if we match the appearance count given by the user
}
}
return 0;
}

