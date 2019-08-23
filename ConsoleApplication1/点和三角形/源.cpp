#include<iostream>
#include<math.h>
using namespace std;

/*��*/
class point_float
{
public:
	point_float(float _x,float _y):x(_x),y(_y){}
	float x;
	float y;
};
/*�㷨*/
/*˼·�������*/
#define ABS_FLOAT_0 0.0001//�����˼ά��0.0001������0
/*��3�������������*/
float GetS(const point_float a, const point_float b, const point_float c)
{
	float AB_x,AB_y ,BC_x,BC_y,CA_x,CA_y;
	AB_x = fabs(b.x - a.x);
	AB_y = fabs(b.y - a.y);

	BC_x = fabs(c.x - b.x);
	BC_y = fabs(c.y -b.y);

	CA_x = fabs(c.x - a.x);
	CA_y = fabs(c.y - a.y);

	float S;
	S = ((BC_y + CA_y)*AB_x - CA_x*CA_y - BC_x*BC_y)/2.0f;
	return S;
}
int main()
{
	/*����һ��������*/
	point_float A(0, 0);
	point_float B(1, 0);
	point_float C(0, 1);

	/*����һ����*/
	point_float P(0, 1.1);

	/*��������ABC���*/
	float S_ABC = GetS(A, B, C);
	/*��������ABP��BCP��CAP���*/
	float S_ABP = GetS(A, B, P);
	float S_BCP = GetS(B, C, P);
	float S_CAP = GetS(C, A, P);

	float SS = S_ABP + S_BCP + S_CAP;//��P��Ϊ֧�������С�����������
	cout << S_ABC <<" "<<SS<< endl; //
	if (fabs(SS - S_ABC) < ABS_FLOAT_0)//���������<0.0001ʱ��ΪP��������ABC��
	{
		cout << "true" << endl;
		//return true;
	}
		
	else
	{
		cout << "false" << endl;
		//return false;
	}
		
	system("pause");
	return 0;
}