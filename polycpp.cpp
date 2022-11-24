#include<bits/stdc++.h>
using namespace std;
struct node{
    int coef;
    node *next;
};
class ll{
    node * hn1,*hn2;
    int n1,n2;
    node *ln1,*ln2;
    public:ll(){
        hn1=NULL;
        ln1=NULL;
        hn2=NULL;
        ln2=NULL;
    }
    void poly(){
            cout<<"Enter the value of polynomial 1 :"<<endl;
        cout<<"Enter the order of polynomial:";
        cin>>n1;
        for(int j=n1;j>=0;j--){
            node *nn_1=new node;
            cout<<"Enter coefficient of x^"<<j<<":";
            cin>>nn_1->coef;
            nn_1->next=NULL;
            if(hn1==NULL){
                hn1=nn_1;
                ln1=nn_1;
            }
            else{
                ln1->next=nn_1;
                ln1=nn_1;
            }
        }
        cout<<"Enter the value of polynomial 2:"<<endl;
        cout<<"Enter order of polynomial:";
        cin>>n2;
        for(int j=n2;j>=0;j--){
            node *nn_2=new node;
            cout<<"Enter coefficient of x^"<<j<<":";
            cin>>nn_2->coef;
            nn_2->next=NULL;
            if(hn2==NULL){
                hn2=nn_2;
                ln2=nn_2;
            }
            else{
                ln2->next=nn_2;
                ln2=nn_2;
            }
        }
        if(n1==n2){
            node *cn1=hn1,*cn2=hn2;
            while(cn1!=NULL && cn2!=NULL){
                cn1->coef+=cn2->coef;
                cn1=cn1->next;
                cn2=cn2->next;
            }
        }
        else if(n1>n2){
            node *cn1=hn1,*cn2=hn2;
            int l=n1;
            while(l!=n2){
                cn1=cn1->next;
                l--;
            }
            while(cn1!=NULL && cn2!=NULL){
                cn1->coef+=cn2->coef;
                cn1=cn1->next;
                cn2=cn2->next;
            }
        }
        else{
            node *cn1=hn1,*cn2=hn2;
            int l=n2;
            while(l!=n1){
                cn2=cn2->next;
                l--;
            }
            while(cn1!=NULL && cn2!=NULL){
                cn1->coef+=cn2->coef;
                cn1=cn1->next;
                cn2=cn2->next;
            }
        }
        node *c=hn1;
        cout<<"Addition is :"<<endl;
        int x=n1;
        while(c!=NULL && x!=-1){
            x--;
            if(c->coef<0)
            cout<<c->coef<<"x^"<<x+1;
            else
            cout<<"+"<<c->coef<<"x^"<<x+1;
            c=c->next;
        }
    }
};
int main(){
    ll a;
    a.poly();
}