#include<iostream>
#include<stack>
#include<string>
#include <sstream>
#include <vector>
using namespace std;
bool isdigit(char c) {
    return c >= '0' && c <= '9';
}
int compute(int a,int b,char op){//两个操作数的运算，方便判断运算符
	switch(op){
		case'+':return a+b;
		case'-':return a-b;
		case'*':return a*b;
		case'/':return a/b;
		default:cout<<"ERROR"<<endl;
	}
}
int Priority(char a){//运算符优先级
	if(a=='+'||a=='-')return 1;
	if(a=='*'||a=='/')return 2;
	return 0;
}
int evaluate(string& expression){
	stack<int> values;   // 用于存储操作数
	stack<char> ops;     // 用于存储运算符
	for(int i=0;i<expression.length();i++){
		char ch=expression[i];
		if(isdigit(ch)){//如果是数字，判断多位数字情况
			int val=0;
			while(i<expression.length()&&isdigit(expression[i])){
				val=val*10+(expression[i]-'0');
				i++;
			}
			values.push(val);
			i--;
		}
		else if(ch=='('){
			ops.push(ch);
		}
		else if(ch==')'){//处理括号内的
			while(!ops.empty()&&ops.top()!='('){
				int val2 = values.top(); values.pop();
				int val1 = values.top(); values.pop();
				char op = ops.top(); ops.pop();
				values.push(compute(val1, val2, op));
			}
			ops.pop();//弹出符号
		}
		else{//运算符
			while(!ops.empty()&&Priority(ops.top())>=Priority(ch)){//优先级小就计算前面优先级大的
				int val2 = values.top(); values.pop();
				int val1 = values.top(); values.pop();
				char op = ops.top(); ops.pop();
				values.push(compute(val1, val2, op));
			}
			 ops.push(ch);
		}
	}
	while(!ops.empty()){//计算剩下的
		int val2 = values.top(); values.pop();
		int val1 = values.top(); values.pop();
		char op = ops.top(); ops.pop();
		values.push(compute(val1, val2, op));
	}
	return values.top();  // 返回结果
}
int main(){//主函数运算
	string expression;
	cout<<"请输入表达式 ";
	getline(cin,expression);
	int result = evaluate(expression);
	cout<<"结果"<<result<<endl;
	return 0;
}
