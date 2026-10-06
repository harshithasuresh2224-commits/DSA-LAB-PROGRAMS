#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#define SIZE 20
struct stack{
    int top;
    float data[SIZE];
};
typedef struct stack STACK;
void push(STACK *s, float item){
    s->data[++(s->top)]=item;
}
float pop(STACK *s){
    return s->data[(s->top)--];
}
float compute(float op1,char symbol,float op2){
    switch(symbol){
        case '+':return op1+op2;
        case '-':return op1-op2;
        case '*':return op1*op2;
        case '^':return pow(op1,op2);
    }
}
float evalpostfix(STACK *s, char postfix[20]){
    int i;
    char symbol;
    float op1,op2,re;
    for (i=0;postfix[i]!='\0';i++){
        symbol=postfix[i];
        if (isdigit(symbol))
            push(s,symbol-'0');
        else{
            op2=pop(s);
            op1=pop(s);
            re=compute(op1,symbol,op2);
            push(s,re);
        }
    }
    return pop(s);
}
void main(){
    char postfix[20];
    STACK s;
    s.top=-1;
    float ans;
    printf("\n Read postfix expression\n");
    scanf("%s",postfix);
    ans=evalpostfix(&s,postfix);
    printf("\nThe result = %f\n",ans);
    return 0;
}
