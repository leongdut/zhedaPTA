//1002 写出这个数 （20 分）
//读入一个正整数 n，计算其各位数字之和，用汉语拼音写出和的每一位数字。
//
//输入格式：
//每个测试输入包含 1 个测试用例，即给出自然数 n 的值。这里保证 n 小于 10
//​100
//​​ 。
//
//输出格式：
//在一行内输出 n 的各位数字之和的每一位，拼音数字间有 1 空格，但一行中最后一个拼音数字后没有空格。
//
//输入样例：
//1234567890987654321123456789
//输出样例：
//yi san wu
#include<stdio.h>
int main()
{
  char shu[10][10]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
  char n;//输入数，每次输入一次就操作一次
  int sum=0;//输入数求和
  int num1,num2,num3;
  int i=0;
  while((n=getchar())!='\n'&&i<101){ //监听输入 注意：赋值语句需要加括号
    if(n<'0'||n>'9'){ //排除监听的特殊情况
      return 0;
    }
    sum+=(n-'0');
    i++;
  }
  num1=sum/100; //百位
  num2=(sum/10)%10; //十位
  num3=sum%10;  //个位

  if(num1==0&&num2==0){
    printf("%s",shu[num3]);
  }
  else if(num1==0&&num2!=0){
    printf("%s %s",shu[num2],shu[num3]);
  }else{
    printf("%s %s %s",shu[num1],shu[num2],shu[num3]);
  }
  return 0;
}
