#include<algorithm>
#include<vector>
#include<list>
#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int x[9] = {-1, -1, -1, -1, -1, -1, -1, -1, -1}, sum = 0;//x[i]���±��ʾqueen����������i��ʾqueen�������� 
 
int count;

void printMethod()//ͼ�λ���ӡ���� 
{
	cout << "\n���ǵ�" << sum << "�ַ���!\n" ;
	for(int i = 1; i < 9; i++)
	{
		for(int j = 1; j < 9; j++)
		{
			if(j == x[i])
			{
				cout << "Q" << "  ";
			}
			else 
			{
				cout << "x" << "  ";
			}
			//cout << "\n";
		}
		cout << "\n";
	}
	cout << "\n" << "------------------------" << "\n";
}
 
void dfs(int num)
{
	if(num >= 8)//������� 
	{
		sum++;
		printMethod();
		return;
	} 
	else
	{
		for(int j = 1;j <= 8; j++)
		{
			x[num + 1] = j;//ÿһ�ж���һ�ſ����ҳ�������λ�� 
			
			bool flag = true;

			for(int g = num;g > 0; g--)//���ǰ���Ѿ����õ�i-1��
			{
				if( x[g] == x[num + 1] 
				|| (abs(x[num + 1] - x[g]) == abs(num + 1 - g)) )  //��ͬһ��/�ڶԽ����� 
				flag = false; 
			} 
			
			if( flag )//�ж��Ƿ�������� 
				dfs(num + 1);  
		} 
	} 
} 

int main()
{
	dfs(0);
	cout << sum;
	//printMethod();
}


