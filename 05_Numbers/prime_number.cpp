
#include <iostream>
#include <math.h>
#include <string.h>
#include <sys/time.h>

using namespace std;

long getCurrentTime(); 
bool isPrime(int);
bool listPrimeNumbers(int number);
int make_prime_list(int prime_list[], int number);
bool isPrime2(const int);

int main(int argc, char**argv) {

    int number = 123;
    cout<<number<<" is " << (isPrime(number) ? "" : "not") <<" prime number" <<endl;
    listPrimeNumbers(number);

    const int max = 10;
    int prime_list[max];
    make_prime_list(prime_list, max);
    for (int i=0; i<max; i++) {
	cout <<prime_list[i]<<" ";
    }
    cout <<endl;

    //对比两种算法的速度
    int max_number = 2147483647;
    long time1 = getCurrentTime();
    cout <<max_number <<" is " << (isPrime(max_number) ? "" : "not ") << " prime number" <<endl;
    long time2 = getCurrentTime();
    cout<<"algorithm1 cost " <<(time2-time1) <<endl;

    long time3 = getCurrentTime();
    cout <<max_number <<" is " <<(isPrime(max_number) ? "" : "not ") << " prime number" <<endl;
    long time4 = getCurrentTime();
    cout<<"algorithm 2 cost " <<(time4-time3) <<endl;

    return 0;
}

//判断nubmer是否是素数
//方法1: 遍历(2, sqrt(number)]内的所有元素, 判断元素能不能被number整除, 能整除那么number就不是素数
bool isPrime(int number) {

    for (int i=2; i<sqrt(number); i++) {
        if ((number % i) == 0) {
            return false;
        }
    }

    return true;
}

bool isPrime2(const int number) {
    int prime_list[number/2];
    int count = make_prime_list(prime_list, number);
    
    return prime_list[count] == number; 
}

//构造素数序列prime_list[]的前number个
int make_prime_list(int prime_list[], int number) {
    int i, j, count;
    prime_list[0] = 2;
    prime_list[1] = 3;

    for (int i=5, count = 2; count < number; i+=2) {
        int flag = true;
        for (j=1; prime_list[j] * prime_list[j] <= i; ++j) {
            if (i%prime_list[j] == 0) {
                flag = false;
                break;
            }
        }
        if (flag) {
            prime_list[count++] = i;
        }
    }

    cout <<"make_prime_list return count " <<count <<endl;

    return count;
}

//列举出2~number之间所有的素数
bool listPrimeNumbers(int number) {
    const int max = number;
    bool is_prime[max];
    int prime_list[max/2];

    int index = 0;
    memset(is_prime, true, sizeof(is_prime));
    memset(prime_list, -1, sizeof(prime_list));

    for (int i=2; i<=max; i++) {
        if (is_prime[i]) {
            prime_list[index++] = i;
            for (int j=i*2; j<=max; j+=i) {
                is_prime[j]=false;
            }
        }
    } 

    for (int i=0; prime_list[i] <= max && prime_list[i] != -1; i++) {
    	cout <<prime_list[i]<<" ";
    }
    cout<<endl;
}


long getCurrentTime()  
{  
   struct timeval tv;  
   gettimeofday(&tv,NULL);  
   return tv.tv_sec * 1000 + tv.tv_usec / 1000;  
} 
