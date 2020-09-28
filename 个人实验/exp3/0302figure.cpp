#include <iostream> 
#include <utility> 
#include <vector> 
#include <algorithm> 
#include<bits/stdc++.h>

using namespace std;

const int maxn = 1010;
int n;
double esp = 1e-8;

template<class Ty1, class Ty2> //�������أ����������AB 
inline const pair<Ty1, Ty2> operator-(const pair<Ty1, Ty2>&p1, const pair<Ty1, Ty2>&p2)
{
    pair<Ty1, Ty2> ret;
    ret.first = p1.first - p2.first;
    ret.second = p1.second - p2.second;
    return ret;
}

typedef pair<double, double> POINT;
 
POINT p[maxn];

int sgn(double x)//�ж����� 
{
    if (fabs(x) < esp) 
	{
        return 0;
    }
    else {
        return x > 0 ? 1 :- 1;
    }
}

double CP(POINT A, POINT B) //���������ָ����ʵ��������
							   //��������е��������ʽ��һ���ģ��õ�ʱ��Ҫע�⣩ 
{
    return A.first * B.second - A.second * B.first;
}

bool intersec(POINT A1, POINT B1, POINT A2 , POINT B2)//�ж����ο����ཻ
{
	//�ж�����A1B1,A2B2�Ƿ��ཻ 
	double C1, C2, C3, C4;
	 
    C1 = CP(A2 - A1, B1 - A1);
	C2 = CP(B1 - A1, B2 - A1);
	 
    C3 = CP(A1 - A2, B2 - A2);
	C4 = CP(B2 - A2, B1 - A2);
    
    if (sgn(C1 * C2) >= 0 && sgn(C3 * C4) >= 0)//������� 
	{
        return true;
    }
    return false;
}

bool segInter() //�ж����޷Ƿ����� 
{
    //����ÿһ���߶�
	//��������ֱ������������
	//������Ƿ���ʣ�µ������߶��н���
	 
    for (int i = 2; i < n - 1; i++) 
	{
        for (int j = 1; j < i; j++)
        {
            if (intersec(p[i], p[i + 1], p[j - 1], p[j])) 
			{
                return true;
            }
        }
    }
    
    //���һ�������Ƚ�
	 
    for (int i = 1; i < n - 2; i++) 
	{
        if (intersec(p[n - 1], p[0], p[i], p[i + 1])) 
		{
            return true;
        }
    }
    return false;
}

double Area() 
{
    double S = 0;
    for (int i = 1; i < n - 1; i++) 
	{
        S += CP(p[i] - p[0], p[i + 1] - p[0]);
    }
    return fabs(S) * 0.5;
}

void sleep1(int k)
{
	for(int i = 0; i < k; i++)
	{
		
	}
}
int main() 
{
    int num = 0;
    int flag[400] = {0};
	double area[400] = {0};
	
    while((cin >> n) && (n != 0)) 
	{
        double a, b;
        for (int i = 0; i < n; i++) 
		{
            cin >> a >> b;
            p[i] = POINT(a, b);
        }
        if (n < 3) 
		{
			flag[num] = -1;
			num++;
            continue;
        }
        if(segInter()) 
		{
			flag[num] = -1;
			num++;
            continue;
        }
        else 
		{
			flag[num] = 1;
		    area[num] = Area();
		    num++;
        }
    }
    
    for(int i = 0 ; i < 400 ; i++)
    {
    	if(flag[i] == -1)
    		cout << "Figure " << i + 1 << ": Impossible" << "\n";
    	if(flag[i] == 1)
    	    cout << "Figure " << i + 1 << ": " << setprecision(2) << area[i] << "\n";
	}
	
    return 0;
}
/*
5 
0 0.6 
0 1 
0.5 0.5 
1 1 
1 0 
4 
0 0 
0 1 
1 0 
1 3
5 
0 0 
0 1 
0.5 0.5 
1 1 
1 0
0 
*/



