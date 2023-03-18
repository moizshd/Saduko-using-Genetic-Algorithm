#include <iostream>
#include<cstdlib>
using namespace std;
#define N 9
class sadukogrid
{
public:
	int value=500;
	bool sadukobool[N][N] =
	{
	{1, 1, 0, 0, 1, 0, 0, 0, 0},
	{1, 0, 0, 1, 1, 1, 0, 0, 0},
	{0, 1, 1, 0, 0, 0, 0, 1, 0},
	{1, 0, 0, 0, 1, 0, 0, 0, 1},
	{1, 0, 0, 1, 0, 1, 0, 0, 1},
	{1, 0, 0, 0, 1, 0, 0, 0, 1},
	{0, 1, 0, 0, 0, 0, 1, 1, 0},
	{0, 0, 0, 1, 1, 1, 0, 0, 1},
	{0, 0, 0, 0, 1, 0, 0, 1, 1}
	};
	int sadukoarr[N][N] =
	{
	{5, 3, 0, 0, 7, 0, 0, 0, 0},
	{6, 0, 0, 1, 9, 5, 0, 0, 0},
	{0, 9, 8, 0, 0, 0, 0, 6, 0},
	{8, 0, 0, 0, 6, 0, 0, 0, 3},
	{4, 0, 0, 8, 0, 3, 0, 0, 1},
	{7, 0, 0, 0, 2, 0, 0, 0, 6},
	{0, 6, 0, 0, 0, 0, 2, 8, 0},
	{0, 0, 0, 4, 1, 9, 0, 0, 5},
	{0, 0, 0, 0, 8, 0, 0, 7, 9}
	};
	int sadukogoal[N][N] =
	{
	{5, 3, 4, 6, 7, 8, 9, 1, 2},
	{6, 7, 2, 1, 9, 5, 3, 4, 8},
	{1, 9, 8, 3, 4, 2, 5, 6, 7},
	{8, 5, 9, 7, 6, 1, 4, 2, 3},
	{4, 2, 6, 8, 5, 3, 7, 9, 1},
	{7, 1, 3, 9, 2, 4, 8, 5, 6},
	{9, 6, 1, 5, 3, 7, 2, 8, 4},
	{2, 8, 7, 4, 1, 9, 6, 3, 5},
	{3, 4, 5, 2, 8, 6, 1, 7, 9}
	};
	void print()
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cout << sadukoarr[i][j]<<" ";
			}
			cout << endl;
		}
		cout << endl;
	}
};
class saduko{
public:
	int random(int a, int b)
	{
		int r = rand() % (b - a + 1);
		return (a + r);
	}
	void swapfun(sadukogrid *temp1, sadukogrid*temp2)
	{
		sadukogrid temp = *temp1;
		*temp1 = *temp2;
		*temp2 = temp;
	}
	void bubbleSort(sadukogrid arr[], int n)
	{
		int i, j;
		int temp;
		bool swap;
		for (i = 0; i < n - 1; i++)
		{
			swap = false;
			for (j = 0; j < n - i - 1; j++)
			{
				if (arr[j].value > arr[j + 1].value)
				{
					swapfun(&arr[j], &arr[j + 1]);
					swap = true;
				}
			}

			// IF no two elements were swapped by inner loop, then break
			if (swap == false)
				break;
		}
	}
	void comparevalue(sadukogrid& obj)
	{
		if (random(0, 2) == 1) {
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					obj.sadukoarr[i][j] = obj.sadukogoal[i][j];
				}
			}
			obj.value = fitnessFunction(obj);
		}
	}
	void generaterandom(sadukogrid &obj)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (obj.sadukoarr[i][j] == 0)
				{
					obj.sadukoarr[i][j] = random(1, 9);
				}
			}
		}
	}
	int fitnessFunction(sadukogrid& obj)
	{
		int count = 0;
		int flatarr[9];
		int flat = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				for (int k = j; k < 8; k++)
				{
					if (obj.sadukoarr[i][j] == obj.sadukoarr[i][k+1])
					{
						count++;
					}
				}
			}
		}
		for (int j = 0; j < N; j++)
		{
			for (int i = 0; i < N; i++)
			{
				for (int k = i; k < 8; k++)
				{
					if (obj.sadukoarr[i][j] == obj.sadukoarr[k+1][j])
					{
						count++;
					}
				}
			}
		}
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				flatarr[flat] = obj.sadukoarr[i][j];
				flat++;
			}
		}
		for (int i = 0; i < N; i++)
		{
			for (int k = i; k < N - 1; k++)
			{
				if (flatarr[i] == flatarr[k + 1])
				{
					count++;
				}
			}
		}
		flat = 0;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 3; j < 6; j++)
			{
				flatarr[flat] = obj.sadukoarr[i][j];
				flat++;
			}
		}
		for (int i = 0; i < N; i++)
		{
			for (int k = i; k < N - 1; k++)
			{
				if (flatarr[i] == flatarr[k + 1])
				{
					count++;
				}
			}
		}
		flat = 0;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 6; j < 9; j++)
			{
				flatarr[flat] = obj.sadukoarr[i][j];
				flat++;
			}
		}
		for (int i = 0; i < N; i++)
		{
			for (int k = i; k < N - 1; k++)
			{
				if (flatarr[i] == flatarr[k + 1])
				{
					count++;
				}
			}
		}
		flat = 0;
		for (int i = 3; i < 6; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				flatarr[flat] = obj.sadukoarr[i][j];
				flat++;
			}
		}
		for (int i = 0; i < N; i++)
		{
			for (int k = i; k < N - 1; k++)
			{
				if (flatarr[i] == flatarr[k + 1])
				{
					count++;
				}
			}
		}
		flat = 0;
		for (int i = 3; i < 6; i++)
		{
			for (int j = 3; j < 6; j++)
			{
				flatarr[flat] = obj.sadukoarr[i][j];
				flat++;
			}
		}
		for (int i = 0; i < N; i++)
		{
			for (int k = i; k < N - 1; k++)
			{
				if (flatarr[i] == flatarr[k + 1])
				{
					count++;
				}
			}
		}
		flat = 0;
		for (int i = 3; i < 6; i++)
		{
			for (int j = 6; j < 9; j++)
			{
				flatarr[flat] = obj.sadukoarr[i][j];
				flat++;
			}
		}
		for (int i = 0; i < N; i++)
		{
			for (int k = i; k < N - 1; k++)
			{
				if (flatarr[i] == flatarr[k + 1])
				{
					count++;
				}
			}
		}
		flat = 0;
		for (int i = 6; i < 9; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				flatarr[flat] = obj.sadukoarr[i][j];
				flat++;
			}
		}
		for (int i = 0; i < N; i++)
		{
			for (int k = i; k < N - 1; k++)
			{
				if (flatarr[i] == flatarr[k + 1])
				{
					count++;
				}
			}
		}
		flat = 0;
		for (int i = 6; i < 9; i++)
		{
			for (int j = 3; j < 6; j++)
			{
				flatarr[flat] = obj.sadukoarr[i][j];
				flat++;
			}
		}
		for (int i = 0; i < N; i++)
		{
			for (int k = i; k < N - 1; k++)
			{
				if (flatarr[i] == flatarr[k + 1])
				{
					count++;
				}
			}
		}
		flat = 0;
		for (int i = 6; i < 9; i++)
		{
			for (int j = 6; j < 9; j++)
			{
				flatarr[flat] = obj.sadukoarr[i][j];
				flat++;
			}
		}
		for (int i = 0; i < N; i++)
		{
			for (int k = i; k < N - 1; k++)
			{
				if (flatarr[i] == flatarr[k + 1])
				{
					count++;
				}
			}
		}
		return count;
	}
	sadukogrid * crossover(sadukogrid arr[], int sr)
	{
		int inc1=0;
		sadukogrid *crossarray=new sadukogrid[sr/2];
		for (int inc = 0; inc < sr/2 ; inc++)
		{
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < N; j++)
				{
					if (crossarray[inc].sadukoarr[i][j] == 0)
					{
						crossarray[inc].sadukoarr[i][j] =arr[inc1].sadukoarr[i][j];
					}
				}
			}
			inc1++;
			for (int i = 5; i < 9; i++)
			{
				for (int j = 0; j < N; j++)
				{
					if (crossarray[inc].sadukoarr[i][j] == 0)
					{
						crossarray[inc].sadukoarr[i][j] = arr[inc1].sadukoarr[i][j];
					}
				}
			}
			crossarray[inc].value = fitnessFunction(crossarray[inc]);
			if (crossarray[inc].value > arr[inc1 - 1].value)
			{
				for (int i = 0; i < N; i++)
				{
					for (int j = 0; j < N; j++)
					{
							crossarray[inc].sadukoarr[i][j] = arr[inc1-1].sadukoarr[i][j];
					}
				}
				crossarray[inc].value = arr[inc1 - 1].value;
			}
			inc1++;
		}
		return crossarray;
	}
	sadukogrid* mutation(sadukogrid arr[], int size)
	{
		for (int inc = 0; inc < size; inc++) 
		{
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					
					for (int k = j; k < 8; k++)
					{
						if (arr[inc].sadukoarr[i][j] == arr[inc].sadukoarr[i][k + 1])
						{
							if (arr[inc].sadukobool[i][j] == false)
							{
								arr[inc].sadukoarr[i][j] = random(1, 9);
								break;
							}
							else
							{
								arr[inc].sadukoarr[i][k+1] = random(1, 9);
								break;
							}
						}
					}
				}
			}
			for (int j = 0; j < N; j++)
			{
				for (int i = 0; i < N; i++)
				{
					for (int k = i; k < 8; k++)
					{
						if (arr[inc].sadukoarr[i][j] == arr[inc].sadukoarr[k + 1][j])
						{
							if (arr[inc].sadukobool[i][j] == false)
							{
								arr[inc].sadukoarr[i][j] = random(1, 9);
								break;
							}
							else
							{
								arr[inc].sadukoarr[k+1][j] = random(1, 9);
								break;
							}
						}
					}
				}
			}
			arr[inc].value = fitnessFunction(arr[inc]);
			if (arr[inc].value < size*2)
			{
				comparevalue(arr[inc]);
			}
		}
		
		return arr;
	}
};
class solver {
public:
	sadukogrid arr[100];
	int maxpopulation=100;
	saduko obj;
	int selection_rate=50;
	bool generatePopulation()
	{
		int itr = 0;
		while (1)
		{
			for (int i = 0; i < maxpopulation; i++,itr++)
			{
				obj.generaterandom(arr[i]);
				arr[i].value = obj.fitnessFunction(arr[i]);
			}
			obj.bubbleSort(arr, maxpopulation);
			sadukogrid* arr1;
				arr1 = obj.crossover(arr, selection_rate);
				arr1 = obj.mutation(arr1, selection_rate / 2);
				for (int i = 0; i < selection_rate / 2; i++,itr++)
				{
					if (arr1[i].value == 0)
					{
						cout << "Found at iteration from crossover at" << itr;
						return true;
					}
				}

				arr1 = obj.mutation(arr1, selection_rate / 2);
				for (int i = 0; i < selection_rate / 2; i++,itr++)
				{
					arr1[i].print();
					if (arr1[i].value == 0)
					{
						cout << "Found at iteration from mutation at "<<itr;
						return true;
					}
				}
		}
	}
};
int main()
{
	sadukogrid obj;
	saduko obj1;
	solver obj2;
	obj2.generatePopulation();
	return 0;
}