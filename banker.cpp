#include <iostream>
#include <fstream>


int main() {

	std::ifstream file("data.txt");
	
	int n; // Number of Processes
	file >> n; // Read Number of Processes
	
	int m; // Number of Resources
	file >> m; // Read Number of Resources
	
	// Allocated Resources
	int alloc[n][m];
	for (int row = 0; row < n; row++){
		for (int col = 0; col < m; col++)
			file >> alloc[row][col];
	}
	
	// Max Resources
	int max[n][m];
	for (int row = 0; row < n; row++){
		for (int col = 0; col < m; col++)
			file >> max[row][col];
	}
	
	// Available Resources
	int avail[m];
	for (int col = 0; col < m; col++)
		file >> avail[col];
	
	
	
	int f[n], ans[n], ind = 0;
	int k;
	for (k = 0; k < n; k++) {
		f[k] = 0;
	}
	
	int need[n][m];
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++)
		need[i][j] = max[i][j] - alloc[i][j];
	}
	
	int y = 0;
	for (k = 0; k < 5; k++) {
		for (i = 0; i < n; i++) {
		if (f[i] == 0) {
		
			int flag = 0;
			for (j = 0; j < m; j++) {
			if (need[i][j] > avail[j]){
				flag = 1;
				break;
			}
			}
	
			if (flag == 0) {
			ans[ind++] = i;
			for (y = 0; y < m; y++)
				avail[y] += alloc[i][y];
			f[i] = 1;
			}
		}
		}
	}
	
	int flag = 1;
	
	// Check whether sequence is safe
	for(int i = 0; i < n; i++)
	{
			if(f[i] == 0)
		{
			flag = 0;
			std::cout << "The System is not in a Safe State";
			break;
		}
	}
	// Print out sequence if safe
	if(flag == 1)
	{
		std::cout << "The System is in a Safe State" << std::endl;
	    std::cout << "The Safe Sequence Is:" << std::endl;
		for (i=0; i < n-1; i++)
			std::cout << "P" << ans[i] << " > ";
		std::cout << "P" << ans[n - 1] << std::endl;
	}
	
	return (0);
}