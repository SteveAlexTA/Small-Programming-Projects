#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
long long brightestArea(vector<vector<int>>& matrix, int m, int n, int k) 
{
    long long max_sum = 0;
    for (int i = k; i < m-k; i++) {
        for (int j = k; j < n-k; j++) {
            int center = matrix[i][j];
            long long sum_square = 0;
            bool isMaxCenter = true;
            for (int dx = -k; dx <= k; dx++) {
                for (int dy = -k; dy <= k; dy++) {
                    int nx = i+dx;
                    int ny = j+dy;
                    int spot = matrix[nx][ny];
                    sum_square+=spot;
                    if(!(dx==0&&dy==0)&&spot>=center) isMaxCenter = false;
                }
                if (isMaxCenter==false) break;
            }
            if(isMaxCenter==true) max_sum = max(max_sum,sum_square);
        }
    }
    return max_sum;
}
int main() {
    int m,n,k; cin >> m >> n >> k;
	vector<vector<int> > matrix(m, vector<int>(n));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> matrix[i][j];
		}
	} 
	cout << brightestArea(matrix,m,n,k) << endl;
}