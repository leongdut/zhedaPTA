//
//1004 �ɼ����� ��20 �֣�
//���� n��>0����ѧ����������ѧ�š��ɼ����ֱ�����ɼ���ߺͳɼ����ѧ����������ѧ�š�
//
//�����ʽ��
//ÿ������������� 1 ��������������ʽΪ
//
//�� 1 �У������� n
//�� 2 �У��� 1 ��ѧ�������� ѧ�� �ɼ�
//�� 3 �У��� 2 ��ѧ�������� ѧ�� �ɼ�
//  ... ... ...
//�� n+1 �У��� n ��ѧ�������� ѧ�� �ɼ�
//����������ѧ�ž�Ϊ������ 10 ���ַ����ַ������ɼ�Ϊ 0 �� 100 ֮���һ�����������ﱣ֤��һ�����������û������ѧ���ĳɼ�����ͬ�ġ�
//
//�����ʽ��
//��ÿ������������� 2 �У��� 1 ���ǳɼ����ѧ����������ѧ�ţ��� 2 ���ǳɼ����ѧ����������ѧ�ţ��ַ������� 1 �ո�
//
//����������
//3
//Joe Math990112 89
//Mike CS991301 100
//Mary EE990830 95
//���������
//Mike CS991301
//Joe Math990112
#include <iostream>
#include <string>
#include <string.h>
using namespace std;
struct Student{
  string name,sno;
  int score;
};
int main(void){
  int n,max1=-1,min1=101,maxnum=0,minnum=0;//������Ҫ��ʼ��
  Student s[1000];
  cin >> n;
  for(int i=0;i<n;i++){
    cin >> s[i].name >> s[i].sno >> s[i].score;
    if(s[i].name.size()>10||s[i].sno.size()>10||(s[i].score<0)||(s[i].score>100)){
      return 0;
    }//ɸ�����ϸ����
    if(s[i].score>max1){
      max1=s[i].score;
      maxnum=i;
    }
    if(s[i].score<min1){
      min1=s[i].score;
      minnum=i;
    }

 }//end for
 cout << s[maxnum].name << " " << s[maxnum].sno << endl;
 cout << s[minnum].name << " " << s[minnum].sno;
 return 0;
}
