/*Problem description
Chef loves circular cakes. He divides them into smaller pieces and sells them. You are to help him in this work.

Today Chef has cooked the brand new circular cake. To split the cake Chef can make several (possibly, zero) cuts. Each cut should be a straight line going from the center of the cake to its border. Also, the angle between any two cuts should have positive integer value (Chef measure all the angles in degrees). Chef consider two pieces of cake equal if the appropriate angles are equal.


The picture contains two distinct pieces, and two cuts. Red part on the image shows one piece. The appropriate angle is AOB.

Chef gives to you an integer N, denoting the number of pieces Chef wants to make. You need to answer the following questions:

Is it possible to make exactly N equal pieces from the whole cake?
Is it possible to make exactly N pieces from the whole cake?
Is it possible to make exactly N pieces from the whole cake, in such a way that no two of them are equal?

Input
First line contains a single integer T denoting the number of test cases. Each of the following T lines contain a single integer N denoting the number of pieces Chef wants to make.

Output
For each test case, output one line containing 3 space separated characters. Above, we defined the 3 questions that Chef will ask. Output 'y' for yes or 'n' for no (quotes for clarity) for each of those questions. Answers for 3 questions (in the order above) must be space separated on the same line.

Constraints
1 = T = 10000
1 = N = 10000
Example
Input:
2
4
7

Output:
y y y
n y y
 

Explanation
Example case 1.
Is it possible to make N equal pieces?
Yes, you can cut 4 pieces each with 90 degrees angle.
Is it possible to make N pieces?
Yes, you can cut 4 pieces each with 90 degrees angle.
Is it possible to make N pieces, such that no two of them are equal?
Yes, you can cut 4 pieces with angles 88, 89, 91, 92.*/


#include <iostream>
using namespace std;

int main() {
	long long t;
	cin>>t;

	while(t--){

		long long n;
		cin>>n;

		if(!(360%n))
			cout<<"y ";
		else
			cout<<"n ";

		if(n<=360)
			cout<<"y ";
		else
			cout<<"n ";

		if(n*(n+1)/2 <= 360)
			cout<<"y ";
		else
			cout<<"n ";

		cout<<endl;
	 }
	return 0;
}

	
	
	
