#include<iostream>
#include<time.h>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

template <class T>
struct node
{
    T data;
    node *next;
    node *prev;
};
template <class T>

class list
{
    private:
        node<T> *beg;
        node<T> *end;
        int length;
    public:
        list()
        {
            beg=NULL;
            end=NULL;
            length=0;
        }
        
        bool is_empty()
        {
            return beg==NULL;
        }
        
        void add(T data, int pos)
        {
            if(is_empty()&&pos==1)
            {
                beg = new node<T>();
                beg->data=data;
                beg->next=NULL;
                beg->prev=NULL;
                end=beg;
                length++;
            }
          
            else
            {
                bool added=false;
                if(!is_empty())
                {
                    if(pos==1)
                    {
                        added=true;
                        node<T>* p=beg;
                        beg=new node<T>();
                        beg->data=data;
                        beg->next=p;
                        beg->prev=NULL;
                        p->prev=beg;
                        length++;
                   }
                    if(pos==length+1&&!added)
                    {
                        added = true;
                        node<T> *p=end;
                        end=new node<T>();
                        end->data=data;
                        end->next=NULL;
                        end->prev=p;
                        p->next=end;
                        length++;
                    }
                    if(pos>1&&pos<length+1&&!added)
                    {
                        added=true;
                        node<T> *p=beg;
                        int counter=1;
                        while(counter<pos)
                        {
                            p=p->next;
                            counter++;
                        }
                        node<T> *s=p->prev;
                        node<T> *z=new node<T>();
                        z->data=data;
                        z->next=p;
                        z->prev=s;
                        s->next=z;
                        p->prev=z;
                        length++;
                    }
                }
            }
        }
        
        void remove(int pos)
        {
            if(pos==1)
            {
                if(beg==end)
                {
                    delete beg;
                    beg=NULL;
                    end=NULL;
                }
                else
                {
                    beg=beg->next;
                    delete beg->prev;
                    beg->prev=NULL;
                }
                length--;
            }
          
            if(pos==length&&length!=1)
            {
                end=end->prev;
                delete end->next;
                end->next=NULL;
                length--;
            }
          
            if(pos>1&&pos<length)
            {
                int counter=1;
                node<T> *p=beg;
                while(counter<pos)
                {
                    counter++;
                    p=p->next;
                }
                node<T> *s=p->next;
                node<T> *z=p->prev;
                s->prev=z;
                z->next=s;
                delete p;
                length--;
            }
        }
        
        node<T> * get_beg()
        {
            return beg;
        }
        
        node<T> * get_end()
        {
            return end;
        }
        
        int get_length()
        {
            return length;
        }
        
        void reverse()
        {
            node<T> *p=beg;
            node<T> *r=end;
            T swap;
            for (int i=0;i<length/2;i++)
            {
                swap=p->data;
                p->data=r->data;
                r->data=swap;
                p=p->next;
                r=r->prev;
            }
        }
        
        void print()
        {
            node<T> *p=beg;
            while(p!=NULL)
            {
                cout<<p->data<<"     ";
                p=p->next;
            }
            cout<<endl;
        }
        
        void printel(int a)
        {
            int br=1;
            node<T> *p=beg;
            while(br<a)
            {
                p=p->next;
                br++;
            }
            cout<<p->data<<"     "<<endl;
        }
        
        void sort()
        {
            node<T> *p=beg;
            node<T> *q=p->next;
            int swap;
            for(int i=0;i<length-1;i++){
                p=beg;
                q=p->next;
                for (int j=0;j<length-1;j++)
                {
                    if(p->data<q->data)
                    {
                        swap=p->data;
                        p->data=q->data;
                        q->data=swap;
                    }
                    p=p->next;
                    q=q->next;
                }
            }
        }
        
        void poker()
        {
            int br=0,br1=0,flag=0,f=0,g=0;
            node<T> *p=beg;
            node<T> *q=p->next;
            node<T> *x=end;
            for(int i=0;i<3;i++)
            {
                if (p->data==q->data)
                    {
                        br++;
                    }
                else 
                {
                    if(br>0)
                    {
                        p=p->next;
                        q=q->next;
                        break;
                    }
                }
                q=q->next;
                p=p->next;
            }
            
            do
            {
                if(p->data==q->data){br1++;}
                q=q->next;
                p=p->next;
                
            }
            while(q==x);
            
            p=beg;
            q=beg->next;
            for(int i=0;i<4;i++)
            {
                if (p->data==q->data+1) flag++;
                q=q->next;
                p=p->next;
            }
            p=beg;
            cout<<endl;
            
            if(flag==4) cout<<"Straight";
            else
            {
                if(br==4) cout<<"Impossible";
                if(br==3||br1==3) cout<<"4 of a kinf";
                if((br==2&&br1==1)||(br==1&&br1==2)) {g++; cout<<"Full house";}
                if((br==2||br1==2)&&g==0) cout<<"3 of a kind";
                if(br==1&&br1==1) {cout<<"2 pairs"; f++;}
                if((br==1||br1==1)&&f==0&&g==0) cout<<"Pair";
                if(br==0&&br1==0) cout<<"Nothing; High card: "<<p->data;
                
            }
        }
};

int main()
{
    list<int> l;
    
    cout<<"Is list empty? -> "<<l.is_empty()<<endl;
    l.add(123,1);
    cout<<"Is list empty? -> "<<l.is_empty()<<endl;
    
    l.add(125,2);
    l.add(124,3);
    l.add(126,4);
    l.add(127,5);
    l.add(128,6);
    l.print();
    
    l.remove(6);
    l.print();
    l.printel(1);
    
    l.sort();
    l.print();
    
    l.reverse();
    l.print();
    
    l.reverse();
    l.poker();
    
    return 0;
}
