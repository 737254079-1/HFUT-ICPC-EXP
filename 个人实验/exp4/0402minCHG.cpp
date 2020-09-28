//����С�޸Ĵ��� 
#include <iostream> 
#include <utility> 
#include <vector> 
#include <algorithm> 
using namespace std;
 
int dis[1000][1000];

int min(int a, int b, int c)
{
	int temp;
	if(a > b)
		temp = b;
	else 
		temp = a;
	
	if(temp > c)
		return c;
	else 
		return temp;
}
 
void print(int L1, int L2)
{
	for(int i = 0; i < L1 + 1; i++)
    {
    	for(int j = 0; j < L2 + 1; j++)
    	{
    		cout << dis[i][j] << "\t";
		}
		cout << "\n";
	}
	
}

void getEditDis(string S11, string S22)
{
	int i, j ;
	
    string S1 = "0" + S11;//string�±��Ǵ�0��ʼ�ģ������۱��Ǵ�1��ʼ�� 
    string S2 = "0" + S22;//��Ҫ��ǰ��Ӹ�0��ֹ��һ���ֱ����� 
		
    int L1 = S1.length();
    int L2 = S2.length();

	for(i = 0; i <= L1; i++) 
		dis[i][0] = i ;
	for(j = 0; j <= L2; j++) 
		dis[0][j] = j ;
 
	for(i = 1; i <= L1; i++)
	{
		for(j = 1; j <= L2; j++)
		{
			
			if(S1[i] == S2[j])//��������һ���ַ���� 
			{
				//cout << S1[i] << "  " << S2[j] << endl; 
				dis[i][j] = dis[i - 1][j - 1] ;//���޸ģ��̳�  
			}
			else 
			{
				//cout << S1[i] << "  " << S2[j] << endl; 
				dis[i][j] = dis[i - 1][j - 1] + 1 ;//�޸� +1 
			}
			//״̬ת�Ʒ��� �Ƚ��޸� ɾ�� ������ԵĴ��� 
			dis[i][j] = min( dis[i][j], dis[i - 1][j] + 1, dis[i][j - 1] + 1 ) ;
			
			if(dis[i][j] == dis[i - 1][j] + 1)//ɾ�� 
			{
				
			}
			else if(dis[i][j] == dis[i][j - 1] + 1)//���� 
			{
				
			}
			else if(dis[i][j] == dis[i - 1][j - 1] + 1)//�޸� 
			{
				
			} 
			else//δ�Ķ� 
			{
				
			} 
			
		}
	}

	print(L1, L2);	
	cout << "��̱༭�����ǣ�" << dis[L1][L2];
}

int main()
{
//	string S1, S2;
//	cin >> S1;
//	cin >> S2;

    string S1 = "sfdxbqw";
    string S2 = "gfdgw";

	getEditDis(S1, S2);
}

