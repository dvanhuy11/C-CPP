#include <stdio.h>
#include "stackchar.h"
#include "stackfloat.h"
#include "dslkchar.h"
int doUT(char c)
{
	switch(c){
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
		case '%':
			return 2;
		default: 
			return 0;
	}
}
node* postfix(char bt[], int n){
	stack* s=NULL;
	stack* top=NULL;
	node* output=NULL;
	for(int i=0;i<n;i++){
		showList(s);
		showList(output);
		switch(bt[i]){
			case '(':
				push(s,bt[i]);
				break;
			case ')':
				top = pop(s);
				while(top->info!='('){
					insertLast(output,top->info);
					top = pop(s);
				}
				break;
			case '+':
			case '-':
			case '*':
			case '/':
				if(isEmpty(s)){
					push(s,bt[i]);
				}else{
					while(s!=NULL&&doUT(s->info)>=doUT(bt[i])){
						top = pop (s);
						insertLast(output,top->info);
					}
					push(s,bt[i]);
				}
				break;
			default:
				insertLast(output,bt[i]);
		}
	}
	while(s!=NULL){
		showList(s);
		showList(output);
		top=pop(s);
		insertLast(output,top->info);
	}
	return output;
}
float tinhtoan(float a, float b, char toantu){
	switch(toantu){
		case'+':
		    return a+b;
		case'-':
		 	return a-b;
		case '*':
			return a*b;
		case '/':
			return a/b; 
	} 
} 
float gtribt(node* p){
	stackf* s=NULL;
	node* i=p;
	while(i!=NULL){
		switch(i->info){
			case '+':
			case '-':
		 	case '*':
		 	case '/':
		 		if(s!=NULL){
		 			stackf* pa=pop(s);
		 			stackf* pb=pop(s);
		 			float kq=tinhtoan(pb->info,pa->info,i->info);
		 			push(s,kq);
		 			free(pa);
		 			free(pb);
				}
				break;
			default:
				float t=atof(&i->info);
				push(s,t);
		}
		 i=i->next;
	}
	return pop(s)->info;
}
int main(){
	char bieuthuc[18]="1*2+3*((4-5)+6)/7";
	int n=17;
	node* p=NULL;
	p=postfix(bieuthuc,n);
	showList(p);
	printf("\nGia tri bieu thuc: %0.2f",gtribt(p));
	float x=1*2+3*((4-5)+6)/7;
	printf("\nGia tri dung la: %0.2f",x);
	return 0;
}
