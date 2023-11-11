#include<stdio.h>
#include<stdbool.h>
#define Max_size 5
int Q[Max_size];
int front=-1,rear=-1,data,item;
bool is_full(){
    if(front==((rear+1)%Max_size))
        return true;
    else
        return false;   
}
bool is_empty(){
    if(front==-1)
        return true;
    else 
        return false;   
}
void Enqueue(int data){
	if(is_full()){
        printf("\nQueue full");
    }
    else if (front==-1 && rear==-1){
            front=0;
    }   
    rear=((rear+1)%Max_size);
    Q[rear]=data;
}    
void Dequeue(){   
	if(is_empty()){
        printf("\nQueue empty");
        return;
    }
    else{
        item=Q[front]; 
        printf("\nDeleted element : %d\n",item); 
        if(front==rear){
            front=-1;   
            rear=-1;  
        }
        else{
            front=((front+1)%Max_size);
        }
    }
}
void Display_queue(){
	if(is_empty())
        printf("\nQueue empty");
    else{    
	    for (int i=front;i<=rear;i=((i + 1)%Max_size))
            printf("%d\n",Q[i]);
	} 
}
int main(){
    int op;
    printf("1.Enqueue\n2.Dequeue\n3.Display_queue\n");
    while(true){
        printf("\nEnter the Option (Press 0 to exit): ");
	    scanf("%d",&op);
        if(op!=0){
            switch(op){
                case 1:printf("\nEnter data:");
                        scanf("%d",&data);
                        Enqueue(data);
                        break;
                case 2:Dequeue();
                    break;
                case 3:Display_queue();  
                    break;      
            }
        }
        else{
            break;
        }
    }
	return 0;
}
