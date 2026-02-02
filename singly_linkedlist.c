#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *nxt;
}*st;

int insert_at_start() {
    struct node *t;
    int num;

    t = (struct node*)malloc(sizeof(struct node));
    if (t == NULL) {
        printf("Overflow\n");
        return 0;
    }

    printf("Enter the number: ");
    scanf("%d", &num);

   t->data = num;
    t->nxt = st;
    st = t;
    return 1;

}
int insert_at_end()
{
    struct node *t,*temp;
    int num;
    t=(struct node*)malloc(sizeof(struct node));


    if(t==NULL)
    {
        printf("OVERFLOW ");
        return 0;
    }

    printf("Enter the number :");
    scanf("%d",&num);

    t->data=num;
    t->nxt=NULL;
    if(st==NULL)
    {
        st=t;
    }
    else
    {
      temp=st;
      while(temp->nxt!=NULL)
    {
          temp=temp->nxt;
    }
      temp->nxt=t;
      t->nxt=NULL;

    }
    return 0;

}

int delete_at_start()
{
    struct node *t;
if(st==NULL)
    {
        printf("UNDRFLOW");
        return 0;
    }
else
    t=st;
    printf("%d",t->data);
    st=st->nxt;
    free(t);
    return 1;
}

int delete_at_end()
{
    struct node *t, *temp, *p;
    if (st == NULL)
    {
        printf("UNDERFLOW");
        return 0;
    }

    if (st->nxt == NULL)
    {
        t = st;
        printf("%d", t->data);
        st = st->nxt;
        free(t);
        return 0;
    }

    temp = st;

    while (temp->nxt != NULL)
    {
        temp = p;
        temp = temp->nxt;
    }

    printf("%d", t->data);

    p->nxt = NULL;
    free(temp);
    return 1;
}


int insert_at_given_location()
{
    int pos,num;
    struct node *t,*temp;
    printf("Enter the data ");
    scanf("%d",&num);
    t=(struct node*)malloc(sizeof(struct node));
    t->data=num;
    printf("Enter the position where you want to enter the data");
    scanf("%d",&pos);
    if(pos==1)
    {
        t->nxt=st;
        st=t;
    }
    else
    {
        temp=st;
    for(int i=1;i<pos-1&&temp!=NULL;i++)
        temp=temp->nxt;
    if(temp==NULL)
    {
        printf("Invallid postion");
    }
    else
    {
        t->nxt=temp->nxt;
        temp->nxt=t;
    }
    }
}
int delete_at_given_location()
{
    int pos,ct;
    struct node *temp,*pre;
    printf("Enter the location from where you want to delete the data :");
    scanf("%d",&pos);
    if(st==NULL)
    {
        printf("No linked list");
    }
    else
    {
        temp=st;
        pre=st;
    for(int i=1;i<pos&&temp!=NULL;i++)
    {
        pre=temp;
        temp=temp->nxt;
    }
    if(temp==NULL)
    {
        printf("Invalid position");
    }
    else
    {
        printf("%d",temp->data);
        pre->nxt=temp->nxt;
        free(temp);
    }
    }

    return 0;
}
int insert_before_data()
{
    int num, data;
    struct node *t, *temp, *prev;

    printf("Enter the data to insert: ");
    scanf("%d", &num);

    printf("Enter the data before which to insert: ");
    scanf("%d", &data);

    t = (struct node*)malloc(sizeof(struct node));
    if (t == NULL) {
        printf("Overflow\n");
        return 0;
    }
    t->data = num;


    if (st == NULL) {
        printf("List is empty, cannot insert before %d\n", data);
        free(t);
        return 0;
    }

    if (st->data == data) {
        t->nxt = st;
        st = t;
        return 1;
    }

    prev = NULL;
    temp = st;


    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->nxt;
    }

    if (temp == NULL) {
        printf("Data %d not found in the list.\n", data);
        free(t);
        return 0;
    }


    prev->nxt = t;
    t->nxt = temp;

    return 0;
}

int insert_after_data() {
    int num, data;
    struct node *t, *temp;

    printf("Enter the data to insert: ");
    scanf("%d", &num);

    printf("Enter the data after which to insert: ");
    scanf("%d", &data);

    t = (struct node*)malloc(sizeof(struct node));
    if (t == NULL) {
        printf("Overflow\n");
        return 0;
    }
    t->data = num;

    if (st == NULL) {
        printf("List is empty");

        return 0;
    }

    temp = st;


    while (temp != NULL && temp->data != data) {
        temp = temp->nxt;
    }

    if (temp == NULL) {
        printf("Data not found in the list.");
        return 0;
    }


    t->nxt = temp->nxt;
    temp->nxt = t;

    return 0;
}

int delete_by_data()
{
    int data_to_delete;
    struct node *temp,*pre;
    printf("Enter the data the youbwant to delete :");
    scanf("%d",&data_to_delete);
    if(st==NULL)
    {
        printf("No linked list");
        return 0;
    }

    if(st->data == data_to_delete)
    {
    	delete_at_start();
    	return 0;
    }

    temp=st;
    while(temp->data!=data_to_delete && temp->nxt != NULL)
    {
            pre=temp;
            temp=temp->nxt;
    }
    if(temp->data==data_to_delete)
    {
	    pre->nxt=temp->nxt;
	    free(temp);
    }
    else
    {
    	printf("Data Not Found...\n");
    }

}

void traversal()
{
    struct node *t;

    if (st==NULL)
{
        printf("No linked list exists\n");
        return;
}

    t = st;

    while (t != NULL)
        {
        printf("%d", t->data);
        t = t->nxt;
        }

}


int main() {
    int choice;
    do {
        printf("\n 1. Insert at start");
        printf("\n 2. Insert at End");
        printf("\n 3. Insert at Given Position");
        printf("\n 4. Delete at start");
        printf("\n 5. Delete at End");
        printf("\n 6. Delete at given location");
        printf("\n 7.Insert before data ");
        printf("\n 8.Insert after data");
        printf("\n 9.Delete by data");
        printf("\n 10. DISPLAY");
        printf("\n 11. Exit");
        printf("\n Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insert_at_start();
                break;
            case 2:
                insert_at_end();
                break;
            case 3:
                insert_at_given_location();
                break;
            case 4:
                delete_at_start();
                break;
            case 5:
                delete_at_end();
                break;
            case 6:
                delete_at_given_location();
                break ;
            case 7:
                insert_before_data();
                break;
            case 8:
                insert_after_data();
                break ;
            case 9:
                delete_by_data();
                break;

            case 10:
                traversal();
                break;
            case 11:
                printf("Exiting");
                break;
            default:
                printf("Invalid choice \n");
        }
    } while (choice != 11);

    return 1;
}
