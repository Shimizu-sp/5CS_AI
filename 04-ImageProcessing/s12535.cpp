#include<opencv2/core.hpp>
#include<opencv2/highgui.hpp>
int main(){
int x[2][2] = {
		{ -1, 1 },
		{ -1, 0 },
	
	};

	int y[2][2] = {
		{ 0, 1 },
		{ -1, 1 },
	
	};

	int i, j;
	int sum = 0;
	double B;

	for (i = 0; i<3; i++){
		for (j = 0; j<3; j++){
			sum += x[i][j] * y[i][j];
		}
	}

	B = (125.0 / (1.5 * 1.5))*sum;

	printf("C=%lf\n", B);
	printf("C=%.2lf\n", B);

	return 0;
}