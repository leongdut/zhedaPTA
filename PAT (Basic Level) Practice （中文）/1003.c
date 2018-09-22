//1003 我要通过！ （20 分）
//“答案正确”是自动判题系统给出的最令人欢喜的回复。本题属于 PAT 的“答案正确”大派送 —— 只要读入的字符串满足下列条件，系统就输出“答案正确”，否则输出“答案错误”。
//
//得到“答案正确”的条件是：
//
//字符串中必须仅有 P、 A、 T这三种字符，不可以包含其它字符；
//任意形如 xPATx 的字符串都可以获得“答案正确”，其中 x 或者是空字符串，或者是仅由字母 A 组成的字符串；
//如果 aPbTc 是正确的，那么 aPbATca 也是正确的，其中 a、 b、 c 均或者是空字符串，或者是仅由字母 A 组成的字符串。
//现在就请你为 PAT 写一个自动裁判程序，判定哪些字符串是可以获得“答案正确”的。
//
//输入格式：
//每个测试输入包含 1 个测试用例。第 1 行给出一个正整数 n (<10)，是需要检测的字符串个数。接下来每个字符串占一行，字符串长度不超过 100，且不包含空格。
//
//输出格式：
//每个字符串的检测结果占一行，如果该字符串可以获得“答案正确”，则输出 YES，否则输出 NO。
//
//输入样例：
//8
//PAT
//PAAT
//AAPATAA
//AAPAATAAAA
//xPATx
//PT
//Whatever
//APAAATAA
//输出样例：
//YES
//YES
//YES
//YES
//NO
//NO
//NO
//NO

#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;
//时间复杂度O（n^2）
//空间复杂度O（1）
int main(){
  int i=0,j=0;
  int n;//记录输入字符串个数；
  char c[101];//开辟存储空间，要求输入的字符串长度不超过100；
  if(scanf("%d",&n)!=1){
    return 0;
  }
  for(i=0;i<n;i++){

    bool result=1;
    int count1=0,count2=0,count3=0;
    int countP=0,countT=0;
    if(scanf("%s",c)!=1){ //c++编译在此处输入有一个返回值，不能直接用scanf，特别是在循环中，非常容易在用户输入非法字符的时候造成死循环。
      return 0;
    }
    //此处开始筛掉字符串含有除P,A,T以外字符的字符串
    for(j=0;j<(int)(strlen(c));j++){
         if(c[j]!='P'&&c[j]!='A'&&c[j]!='T'){
             result=0;
             break;
         }
         if(c[j]=='P'){
             countP++;
             if(countP==2){ //筛掉P字符重复出现的字符串
                result=0;
                break;
           }
         }
         if(c[j]=='T'){  //筛掉T字符重复出现的字符串
             countT++;
             if(countT==2){
               result=0;
               break;
             }
         }
    }//end for

    if(result==1){
      string s=c;

      count1=s.find("P");//寻找P的下标第一次出现的位置
      count2=s.find("A");//寻找A的下标第一次出现的位置
      count3=s.find("T");//寻找T的下标第一次出现的位置
      if(count1==-1||count2==-1||count3==-1){
        result=0;
      }
      else{//核心判断，前面两处A的个数乘机是否等于最后一处A的个数
        result=((int)(count1*(count3-count1-1))==(int)(strlen(c)-count3-1))?1:0;
      }
    }
    if(result){
      printf("YES\n"); //一次输入的字符串经过检验合格
    }
    else{
      printf("NO\n"); //一次输入的字符串经过检验不合格
    }
  }//end for
  return 0;
}
