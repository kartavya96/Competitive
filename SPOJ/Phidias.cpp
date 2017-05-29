#include <iostream>
#include <cstring>
using namespace std;
 
int T,W,H,N,w,h,best[620][620];
 
int main() {
  cin >> T;
  while (T--) {
    memset(best,0x3f,sizeof(best));
    cin >> W >> H >> N;
    while (N--) 
    { 
    	cin >> w >> h; 
    	best[w][h]=0; 
    }
    for (int i=0; i<=W; i++) 
    {
    	for (int j=0; j<=H; j++) 
    	{
    		best[i][j] = min( best[i][j], i*j );
   			for (int k=1; k<i; k++) 
    			best[i][j] = min( best[i][j], best[k][j] + best[i-k][j] );
    		for (int k=1; k<j; k++)
    			best[i][j] = min( best[i][j], best[i][k] + best[i][j-k] );
    		cout<<best[i][j]<<" ";
    	}
    	cout<<endl;
    }
    cout << best[W][H] << endl;
  }
  return 0;
}