
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
int n;

struct student{
        char name[100];
        int ID ;
        int day , month ,year;
        int score;
        int num ;
        };

struct node {
        struct node *next;
        struct node *prev;
struct student student[];
};
struct new_node{
    struct new_node*next;
    struct new_node*prev;
    struct student k;
};


void push(struct node* head_ref, struct node* st,int n);
void insert_middle(struct node* head_ref, struct node*st,int n,int pos);
void insert_end(struct node* head_ref, struct node*st,int n);


int main()
{   /* Start with the empty list */
    struct node* head = NULL;
    int i,pos;
    char o;
    struct node* node=NULL;
    head = (struct node*) malloc(sizeof(struct node));
    node = (struct node*) malloc(sizeof(struct node));

  label:
    printf("Welcome to our program \n");
    printf("Enter the number of students\n");
    scanf("%d",&n);
    char c[10];
    if (n==0) {
                 printf("Bad input :( ... would you like to try again?\n      yes/no\n ");
                label1: scanf("%s", c);
               if ((strcmp("yes", c))==0) {goto label;}
                else if  ((strcmp("no", c)==0)) {exit(0);}
                else {goto label1;}

    }
    printf("Number of students:%d\n",n);putchar('\n');
    printf("Please Enter the students' information:\n");
    for (int i=1; i<=n; i++)
    { node->student[i].num =i;
     printf("student num[%d]\n" ,node->student[i].num);

		printf( "Enter Name: \n"); fflush(stdin);
        scanf(" %[^\n]s ", node->student[i].name);

        printf("Enter ID:\n");  scanf("%d", &node->student[i].ID);

         printf("Birth date\n");
         printf("Enter day:\n");   scanf("%d" ,&node->student[i].day);
         printf("Enter month:\n"); scanf("%d" ,&node->student[i].month);
         printf("Enter year:\n");  scanf("%d" ,&node->student[i].year);
         printf("Birth date:%d/%d/%d\n" ,node->student[i].day,node->student[i].month,node->student[i].year);
         printf("Enter score:\n"); scanf("%d",&node->student[i].score);

    }
    node->next=node;

   while (1)
    {
    //  time_t begin = time(NULL);
    printf( "\n\npress 1 to insert in the beginning.\n");
    printf("Press 2 to insert in the middle.\n");
    printf("Press 3 to insert at the end.\n");
    printf("Press 4 to display a certain student.\n");
    printf("Press 5 to exit.\n\n");

    scanf("%d",&o);

    switch(o)
    {
    case 1:
        push(head, node, n);
        break;
    case 2:
        printf( "Enter where you want to insert\n");
        scanf("%d",&pos);
        insert_middle(head,node,n,pos);
        break;
    case 3:
        insert_end(head,node,n);
        break;
    case 4:
        printf("\nchecking the information of students\n\n");
        printf("student number=%d\n",i);
        printf("student name=\n");   puts(node-> student[i].name);
        printf("student id= %d\n",node->student[i].ID);
        printf("student score= %d\n",node->student[i].score);
        printf( "student birthday=%d/%d/%d",node->student[i].day,node->student[i].month,node->student[i].year);
        break;
    case 5:
        exit(0);
    default:
        printf("Operation not realizable!\n");
    }}
    return 0;
}


void insert_end(struct node* head_ref, struct node*st,int n)
{
    struct new_node*new_node;
    /* 1. allocate node */
    new_node = (struct new_node*) malloc(sizeof(struct new_node*));
    printf("\nPlease Enter the informations of the student.\n");
        printf( "Enter Name: \n");
         fflush(stdin);
        scanf(" %[^\n]s ", new_node->k.name);
        printf("Enter ID:\n"); scanf("%d", &new_node->k.ID);
         printf("Birth date\n");
         printf("Enter day:\n"); scanf("%d" ,&new_node->k.day);
         printf("Enter month:\n"); scanf("%d" ,&new_node->k.month);
         printf("Enter year:\n"); scanf("%d" ,&new_node->k.year);
         printf("Birth date:%d/%d/%d\n" ,new_node->k.day,new_node->k.month,new_node->k.year);
         printf("Enter score:\n");
        scanf("%d",&new_node->k.score);
    /* 2. put in the data  */
     new_node->next=NULL;
     int pos=n+1;
     for (int i=n; i>=pos; i--)
    {
        st->next = st;
        st->student[i]=st->student[i-1];
    }
    st=st->next;
    st->next=new_node;
    st->student[pos]=new_node->k;
    n++;

    printf("\nresultant array of structure\n");
    for (int i=1; i<=n; i++)
    {
        printf("student name = %s\n",st->student[i].name);
        printf("student id= %d\n",st->student[i].ID);
        printf("student score= %d\n",st->student[i].score);
        printf( "student birthday=%d/%d/%d\n",st->student[i].day,st->student[i].month,st->student[i].year);
    }
     st->next=st;

};

void insert_middle(struct node* head_ref, struct node*st,int n,int pos)
{   if (pos>n) {printf("\nError! Far beyond list capacity.\n"); return;}
    struct new_node*new_node;
    /* 1. allocate node */
    new_node = (struct new_node*) malloc(sizeof(struct new_node*));
    printf("Please Enter the informations of the students\n");
        printf( "Enter Name: \n");fflush(stdin);
        scanf(" %[^\n]s ", new_node->k.name);
        printf("Enter ID:\n");
        scanf("%d", &new_node->k.ID);
         printf("Birth date\n");
         printf("Enter day:\n"); scanf("%d" ,&new_node->k.day);
         printf("Enter month:\n"); scanf("%d" ,&new_node->k.month);
         printf("Enter year:\n"); scanf("%d" ,&new_node->k.year);
         printf("Birth date:%d/%d/%d\n" ,new_node->k.day,new_node->k.month,new_node->k.year);
         printf("Enter score:\n");
        scanf("%d",&new_node->k.score);
    /* 2. put in the data  */
     new_node->next=NULL;

     for(int i=n+1; i>=pos; i--)
        {
            st->next = st;
            st->student[i]=st->student[i-1];
        }
            new_node->next = st->next;  //Links the address part of new node
            st->next = new_node;
            st->student[pos]=new_node->k;
        n++;


        printf("resultant array of structure\n");
    for (int i=1; i<=n; i++)
    {
        printf("student name = %s\n",st->student[i].name);
        printf("student id= %d\n",st->student[i].ID);
        printf("student score= %d\n",st->student[i].score);
        printf( "student birthday=%d/%d/%d\n",st->student[i].day,st->student[i].month,st->student[i].year);
    }
     st->next=st;
}


void push(struct node* head_ref, struct node*st,int n)
{
    struct new_node*new_node;
    /* 1. allocate node */
    new_node = (struct new_node*) malloc(sizeof(struct new_node*));

    printf("Please Enter the informations of the students\n");
        printf( "Enter Name: \n");
       fflush(stdin);
        scanf(" %[^\n]s ", new_node->k.name);
        printf("Enter ID:\n");
        scanf("%d", &new_node->k.ID);
         printf("Birth date\n");
         printf("Enter day:\n"); scanf("%d" ,&new_node->k.day);
         printf("Enter month:\n"); scanf("%d" ,&new_node->k.month);
         printf("Enter year:\n"); scanf("%d" ,&new_node->k.year);
         printf("Birth date:%d/%d/%d\n" ,new_node->k.day,new_node->k.month,new_node->k.year);
         printf("Enter score:\n");
        scanf("%d",&new_node->k.score);
    /* 2. put in the data  */
     new_node->next=NULL;

    for (int i=n+1; i>=1; i--)
    {
        st->next=st;
        st->student[i+1]=st->student[i];


    }

 new_node->next=head_ref;
 head_ref->student[1].ID=new_node->k.ID;
 head_ref->student[1].score=new_node->k.score;
 head_ref->student[1].day=new_node->k.day;
 head_ref->student[1].month=new_node->k.month;
 head_ref->student[1].year=new_node->k.year;
    n++;
        printf("student name = %s\n",st->student[1].name);
        printf("student id= %d\n",head_ref->student[1].ID);
        printf("student score= %d\n",head_ref->student[1].score);
        printf( "student birthday=%d/%d/%d",head_ref->student[1].day,head_ref->student[1].month,head_ref->student[1].year);
        head_ref->next=head_ref;
        printf("\n\nresultant array of structure\n");

       for (int i=2; i<=n; i++)
       {printf("student name = %s\n",st->student[i].name);
        printf("student id= %d\n",st->student[i].ID);
        printf("student score= %d\n",st->student[i].score);
        printf( "student birthday=%d/%d/%d\n\n",st->student[i].day,st->student[i].month,st->student[i].year);

      }

    st->next=st;
}

//fun to get the total size of the linked list
//int getCountOfList()
//{
 //Node* temp = head; //assign a temp node to the head of the list
 //int count=0;

 //while(temp) {
  //count++;
  //temp = temp->next; //move to next node
 //}
 //return count;
//}
