// C++ program to check if a given credit
// card is valid or not.
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define eb emplace_back
#define deb(x) cout << #x << "=" << x << endl;
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl;
#define deb3(x, y, z) cout << #x << "=" << x << "," << #y << "=" << y << ","<<#z<<"="<<z<<endl;
ll toint(const string &s) {stringstream ss; ss << s; ll x; ss >> x; return x;}
string tostring ( ll number ){stringstream ss; ss<< number; return ss.str();}
#define  fastIO  ios_base::sync_with_stdio(0); cin.tie(0);

ll fast_power(ll a,ll x)
  {
      if(x==0) return 1;
      else if(x==1) return a;
      else { ll R = fast_power(a,x>>1);
      if(!(x&1)) return R*R;
      else return R*a*R; }
  }

// Return this number if it is a single digit, otherwise,
// return the sum of the two digits
int getDigit(ll number)
{
if (number < 9)
  return number;
return number / 10 + number % 10;
}

// Return the number of digits in d
int getSize(ll d)
{
string num = to_string(d);
return num.length();
}

// Return the first k number of digits from
// number. If the number of digits in number
// is less than k, return number.
long getPrefix(ll number, int k)
{
if (getSize(number) > k)
{
  string num = to_string(number);
 // cout<<stol(num.substr(0,k))<<" "<<num<<" ";
  return stol(num.substr(0, k));
}
return number;
}

// Return true if the digit d is a prefix for number
bool prefixMatched(ll number, int d)
{
  //cout<<number<<" ";
return getPrefix(number, getSize(d)) == d;
}

// Get the result from Step 2
int sumOfDoubleEvenPlace(ll number)
{
int sum = 0;
string num = to_string(number) ;
for (int i = getSize(number) - 2; i >= 0; i -= 2){
  sum += getDigit(int(num[i] - '0') * 2);
}

return sum;
}

// Return sum of odd-place digits in number
int sumOfOddPlace(ll number)
{
  int sum = 0;
  string num = to_string(number) ;
  for (int i = getSize(number)-1; i >= 0; i -= 2){
    sum += num[i] - '0';
  }
  return sum;
}

// Return true if the card number is valid
bool isValid(ll number)
{
return (getSize(number) >= 13 &&
    getSize(number) <= 16)&&(prefixMatched(number, 4) ||
  prefixMatched(number, 5) ||
  prefixMatched(number, 37) ||
  prefixMatched(number, 6))&& (sumOfDoubleEvenPlace(number) +
  sumOfOddPlace(number)) % 10==0;
}

// Driver Code
int main()
{
long long int number;
cin>>number;
cout << number << " is " <<  (isValid(number) ? "valid" : "invalid");
return 0;
}
