#include<iostream>
#include<vector>
using namespace std;

/* �鲢����ĺ��ģ��鲢����������vec��L��M������ģ�M��R������ģ���ô�鲢��һ���������飩*/
void Merge(vector<int> &vec, int L, int M, int R)//���εݹ�ʱ��vecһֱ��������仯��ֻ���±�L��M��R
{
	int LEFT_SIZE = M-L+1;//��߲��ֵĳ��ȣ�����M
	int RIGHT_SIZE = R - M;//�ұ߲��ֵĳ��ȣ�������M

	//�½��������飬����vec��L��M���ֺ�M��R���ִ�ԭ�������ó����������Ž���������
	vector<int> left(LEFT_SIZE);
	vector<int> right(RIGHT_SIZE);
	for (int i = L; i <= M; i++)
	{
		left[i-L] = vec[i];
	}
	for (int i = M+1; i <=R; i++)
	{
		right[i - (M+1)] = vec[i];
	}
	
	//�鲢����������
	int i = 0; int j = 0; int k = L;
	while (i < LEFT_SIZE && j < RIGHT_SIZE)//���αȽ�left�����right����Ԫ�ش�С��С�ķŽ�ԭ����L��R����ǰλ��
	{
		if (left[i] < right[j])
		{
			vec[k] = left[i];
			i++;
			k++;
		}
		else
		{
			vec[k] = right[j];
			j++;
			k++;
		}
	}
	while (i<LEFT_SIZE)//right����Ķ������ˣ�left���黹��Ԫ��û�Ż�vec�������ٱȽ��ˣ�ֱ�Ӷ��Ż�vec����
	{
		vec[k] = left[i];
		i++;
		k++;
	}
	while (j<RIGHT_SIZE)//left����Ķ������ˣ�right���黹��Ԫ��û�Ż�vec��Ҳ�����ڱȽ��ˣ�ֱ�ӷŻ�
	{
		vec[k] = right[j];
		j++;
		k++;
	}

}
/* ǰ��鲢��ǰ���� L��M��M��R����Ԫ��������ģ�����÷���˼�룬����ֱ�������������*/
void MSort(vector<int> &vec, int L, int R)//
{
	if (L == R)
		return;
	else
	{
		int M = (L + R) / 2;
		//һֱϸ�ֵ�left��right��ֻ��һ��Ԫ��ʱ���ŻῪʼִ��Merge
		MSort(vec, L, M);//����vec[M]
		MSort(vec, M+1, R);    //������vec[M]
		Merge(vec, L, M, R); //Merge���ǰ�M����left�εģ��������Ҫһ��
	}
	
}

int main()
{
	vector<int> arr = { 3,6,1,9,5,2,7 };

	MSort(arr, 0, 6);
	//��ӡ
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << " ";

	

	system("pause");
	return 0;
}