#include<algorithm>
#include<vector>
#include<list>
#include<iostream>
#include<vector>

using namespace std;
 
int maze[4][6] = { {1, 1, 0, 0, 0, 0},
                   {0, 1, 1, 1, 0, 0},
                   {1, 1, 0, 1, 0, 0},
                   {0, 1, 1, 1, 0, 0} };
vector<pair<int, int> > path;
 
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};//�� �� �� ��
 
void printvector(vector<pair<int, int> > path)
{
    vector<pair<int , int > >::iterator it;
    for(it = path.begin();it != path.end(); it++)
    {
        cout << "("<< it->first << "," << it->second << ")" << " -> ";
    }
    cout << "(3,3)" << endl;
}
 
void search(vector<pair<int, int> > tpath, int x, int y)
{
    if(x < 0 || y < 0 || x > 5 || y > 3)//Խ�緵��
        return;
 
    if(x == 3 && y == 3)
    {
        path = tpath; //����ҵ��˳���,���¼��·��
        printvector(path);//ÿ��·������ӡ 
        return;
    }
 
    for(int ix = 0; ix < 4; ix++)//�ĸ���������
    {
        if(maze[x+dir[ix][0]][ y+dir[ix][1]] == 1)
        {
            tpath.push_back(make_pair(x, y));
            
            maze[x][y] = -1;//�߹��ı�־ 
            
            search(tpath, x+dir[ix][0], y+dir[ix][1]);
            tpath.pop_back();//ɾ�����һ��Ԫ��
        }
    }
}
int main()
{
    vector<pair<int, int> > tpath;
    search(tpath, 0, 0);//�ӿ�ʼ������
}

