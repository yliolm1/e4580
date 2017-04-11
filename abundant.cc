#include <iostream>
#include <cmath>
#include <cstdlib>

#include <errno.h>
using namespace std;

int sum(int o){
int altogether = 0;
for (int n = 1; n <= sqrt(o); n++){
if (o%n == 0){
if (o/n != n){

altogether += n;
altogether += (o/n);

}
else { altogether += n;}

}
}
altogether -= o;
return altogether;


}

int main(int argc, char* argv[])
{
if (argc != 2){return -1;}

char* p;
errno = 0;
int k = strtol(argv[1], &p, 10);
if (*p != '\0' || errno != 0) return -1;

int l = 0;


for (int m = 1; m < 1000000; m++){

if ((sum(m) > m)){
l++;
cout << m << endl;
if (l == k){return 0;}
}
}
return 0;
}

