#include <iostream> 
using namespace std;
#include <stack>
 
char op;

float num1, num2;
float answer;

void showstack(stack <int> s) 
{ 
    while (!s.empty()) 
    { 
        cout << '\t' << s.top(); 
        s.pop(); 
    } 
    cout << '\n'; 
} 

main () 
{
  stack <int> s;

while (1)
    {
 
cout << "\nPlease enter the equation below e.g. 5+5" << endl;
 cin >> num1 >> op >> num2;
 
 
if (op == '-')
	{
	  answer = num1 - num2;
cout << answer;
	s.push(answer);
}
      else if (op == '+')
	{
	  
answer = num1 + num2;
cout << answer;
	s.push(answer);
}
      else if (op == '/')
	{
	  
answer = num1 / num2;
cout << answer;
	s.push(answer);
}
      else if (op == '*')
	{
	  
answer = num1 * num2;
cout << answer;
	s.push(answer);
}

}
}
