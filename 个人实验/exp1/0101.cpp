# include <algorithm>
# include <vector>
# include <list>
# include <iostream>

using namespace std;

void vectorTest()
{
    vector<int> vec1;
    cout << "Vector*********************************************" << endl;
    cout << "����10�����������vector" << endl;

    for (int i = 0; i < 10; ++i)
	{
        vec1.push_back(rand());
    }

    vector<int>::iterator it;
    for (it = vec1.begin(); it != vec1.end(); ++it)
	{
        cout << *it << ' ';
    }
	cout << "\n";
	
    cout << "\nͷ�����������" << endl;

    vec1.insert(vec1.begin(), rand());

    for (it = vec1.begin(); it != vec1.end(); ++it)
	{
        cout << *it << ' ';
    }
	cout << "\n";
	
    cout << "\nfind����ĳ�������" << endl;

    int x = rand();
    it = find(vec1.begin(), vec1.end(), x);

    if (*it == x)
	{ 
        cout << *it << endl;
    }
    else
	{   
        vec1.push_back(x);
    }

    for (it = vec1.begin(); it != vec1.end(); ++it)
	{
        cout << *it << ' ';
    }
	cout << "\n";
	
    cout << "\n��sort����" << endl;

    sort(vec1.begin(), vec1.end());

    for (it = vec1.begin(); it != vec1.end(); ++it)
	{
        cout << *it << ' ';
    }
	cout << "\n";
	
    cout << "\nɾ��vectorβ��Ԫ��" << endl;

    vec1.pop_back();

    for (it = vec1.begin(); it != vec1.end(); ++it)
	{
        cout << *it << ' ';
    }
	cout << "\n";
	
    cout << "\n��vector���" << endl;

    vec1.erase(vec1.begin(), vec1.end());

    for (it = vec1.begin(); it != vec1.end(); ++it)
	{
        cout << *it << ' ';
    }
    cout << "\n";
    
    cout << "Vector*********************************************" << endl;
}

void listTest()
{
    list<int> list1;
    
    cout << "\nList***********************************************" << endl;
    cout << "����10�����������list" << endl;

    for (int i = 0; i < 10; ++i){
        list1.push_back(rand());
    }

    list<int>::iterator it;
    for (it = list1.begin(); it != list1.end(); ++it){
        cout << *it << ' ';
    }
	cout << "\n";
	
    cout << "\nͷ�����������" << endl;

    list1.push_front(rand());

    for (it = list1.begin(); it != list1.end(); ++it){
        cout << *it << ' ';
    }
	cout << "\n";
	
    cout << "\nfind����ĳ�������" << endl;

    int x = rand();
    it = find(list1.begin(), list1.end(), x);

    if (*it == x)
	{ 
        cout << *it << endl;
    }
    else
	{   
        list1.push_back(x);
    }

    for (it = list1.begin(); it != list1.end(); ++it)
	{
        cout << *it << ' ';
    }
	cout << "\n";
	
    cout << "\n��sort����" << endl;

    list1.sort();
    
    for (it = list1.begin(); it != list1.end(); ++it)
	{
        cout << *it << ' ';
    }
	cout << "\n";
	
    cout << "\nɾ��β��Ԫ��" << endl;

    // ɾ��listβ��Ԫ��
    list1.pop_back();

    for (it = list1.begin(); it != list1.end(); ++it){
        cout << *it << ' ';
    }
	cout << "\n";
	
    cout << "\n��list���" << endl;

    //���
    list1.erase(list1.begin(), list1.end());

    for (it = list1.begin(); it != list1.end(); ++it){
        cout << *it << ' ';
    }
	cout << "\n";
	
    cout << "\nList***********************************************" << endl;
}

int main(int argc, char *argv[]){
    //cout << "Vector*********************************************" << endl;
    vectorTest();
    //cout << "Vector*********************************************" << endl;
    //cout << "List*********************************************" << endl;
    listTest();
    //cout << "List*********************************************" << endl;l;

    return 0;
}
