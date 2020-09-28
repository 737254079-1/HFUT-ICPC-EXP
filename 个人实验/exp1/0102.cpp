# include <vector>
# include <algorithm>
# include <iostream>

using namespace std;
vector<int> vector2;

void print()
{
	vector<int>::iterator it;
    for (it = vector2.begin(); it != vector2.end(); it++)
	{
        cout << (*it) << ' ';
    }
    cout << "\n";  
} 
    
void vectorTest2()
{
	int max, min;

	vector<int>::iterator it;
    cout << "����10�����������vector��" << endl;

    for (int i = 0; i < 10; i++){
        vector2.push_back(rand());
    }

	print();

    cout << "\n�����㷨sort��������" << endl;

    sort(vector2.begin(), vector2.end());
    
	print();

    cout << "\n�����㷨sort��������" << endl;

    sort(vector2.begin(), vector2.end(), greater<int>());

	print();

    cout << "\n�����㷨find����ĳ���������" << endl;

    int x = rand();
    it = find(vector2.begin(), vector2.end(), x);

    if (*it == x)
	{  
        cout << *it << endl;
    }
    else
	{   
        vector2.push_back(x);
    }

	print();
	
    cout << "\n�ҳ������е���СԪ�غ����Ԫ�أ�" << endl;

    max = *max_element(vector2.begin(), vector2.end());

    cout << "\n���Ԫ�أ�" << max << endl;

    min = *min_element(vector2.begin(), vector2.end());

    cout << "\n��СԪ�أ�" << min << endl;
}

int main(){
    vectorTest2();
    return 0;
}
