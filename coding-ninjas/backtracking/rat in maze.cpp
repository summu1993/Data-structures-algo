//rat in maze- backtracking
/*You are given a N*N maze with a rat placed at maze[0][0]. Find and print all paths that rat can follow to reach its destination i.e. maze[N-1][N-1]. Rat can move in any direc�tion ( left, right, up and down).
Value of every cell in the maze can either be 0 or 1. Cells with value 0 are blocked means rat can�not enter into those cells and those with value 1 are open.
Input Format
The first line of input contains an integer 'N' representing 
the dimension of the maze.
The next N lines of input contain N space-separated 
integers representing the type of the cell.
Output Format :
For each test case, print the path from start position to destination position and only cells that are part of the solution path should be 1, rest all cells should be 0.

Output for every test case will be printed in a separate line.
Note:
You do not need to print anything, it has already been taken care of. Just implement the given function.
Constraints:
0 < N < 11 0 <= Maze[i][j] <=1

Time Limit: 1sec
Sample Input 1 :
3
1 0 1
1 0 1
1 1 1
Sample Output 1 :
1 0 0 1 0 0 1 1 1 
Sample Output 1 Explanation :
Only 1 path is possible

1 0 0
1 0 0
1 1 1
Which is printed from left to right and then top to bottom in one line.

Sample Input 2 :
3
1 0 1
1 1 1
1 1 1
Sample Output 2 :
1 0 0 1 1 1 1 1 1 
1 0 0 1 0 0 1 1 1 
1 0 0 1 1 0 0 1 1 
1 0 0 1 1 1 0 0 1 
Sample Output 2 Explanation :
4 paths are possible which are printed in the required format.*/

#include<bits/stdc++.h>
using namespace std;

void printSolution(int** solution,int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout << solution[i][j] << " ";
		}
	}
	cout<<endl;
}
void mazeHelp(int maze[][20],int n,int** solution,int x,int y){
	if(x == n-1 && y == n-1){
		solution[x][y] =1;
		printSolution(solution,n);
      	solution[x][y] =0;
		return;
	}
	if(x>=n || x<0 || y>=n || y<0 || maze[x][y] ==0 || solution[x][y] ==1) return;
	
	solution[x][y] = 1;
	mazeHelp(maze,n,solution,x-1,y);
	mazeHelp(maze,n,solution,x+1,y);
	mazeHelp(maze,n,solution,x,y-1);
	mazeHelp(maze,n,solution,x,y+1);
	solution[x][y] = 0;
}
void ratInAMaze(int maze[][20], int n){

  int** solution = new int*[n];
  for(int i=0;i<n;i++){
  	solution[i] = new int[n];
  }
  mazeHelp(maze,n,solution,0,0);	
}

// complete solution
#include<bits/stdc++.h>
using namespace std;

void printPathHelper(int** input, int n, int** solution, int x, int y){
	if(x==n-1 && y==n-1) {
		solution[x][y]=1;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<solution[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		return;
	}
	if(x<0 || y<0 || x>=n || y>=0 || input[x][y]==0 || solution[x][y]==1) return;
	solution[x][y]=1;
	printPathHelper(input,n,solution,x-1,y);
	printPathHelper(input,n,solution,x,y-1);
	printPathHelper(input,n,solution,x+1,y);
	printPathHelper(input,n,solution,x,y+1);
	solution[x][y]=0;
}

bool hasPathHelper(int** input, int n, int** solution, int x, int y){
	if(x==n-1 && y==n-1) return true;
	if(x<0 || y<0 || x>=n || y>=0 || input[x][y]==0 || solution[x][y]==1) return false;
	solution[x][y]=1;
	if(hasPathHelper(input,n,solution,x-1,y )) return true;
	if(hasPathHelper(input,n,solution,x+1,y )) return true;
	if(hasPathHelper(input,n,solution,x,y-1 )) return true;
	if(hasPathHelper(input,n,solution,x,y+1 )) return true;
	solution[x][y]=0;
	return false;
}

bool hasPath(int** ar, int n){
	int** solution=new int*[n];
	for(int i=0;i<n;i++){
		solution[i]=new int[n];
		for(int j=0;i<n;j++){
			solution[i][j]=0;
		}
	}
	//return hasPathHelper(ar,n,solution,0,0);
	return printPathHelper(ar,n,solution,0,0);
}

int main(){
	int **ar;
	int n;
	cin>>n;
	ar=new int*[n];
	for(int i=0;i<n;i++){
		ar[i]=new int[n];
		for(int j=0;j<n;j++){
			cin>>ar[i][j];
		}
	}
	cout<<hasPath(ar,n)<<endl;
}
