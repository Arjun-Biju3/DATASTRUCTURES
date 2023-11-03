#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prv;
};

struct node *head = NULL;
struct node *tail = NULL;

int count = 0;

void preinsert() {
    int num;
    printf("Enter the data: ");
    scanf("%d", &num);
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    temp->data = num;
    temp->next = head;
    temp->prv = NULL;
    head = temp;
    if (temp->next == NULL)
        tail = temp;
    ++count;
}

void del_beg() {
    if (count > 0) {
        struct node *temp = head;
        head = temp->next;
        free(temp);
        --count;
        if (head == NULL)
            tail = NULL;
    } else {
        printf("No elements to delete.\n");
    }
}

void position() {
    int num, pos;
    printf("Enter the position: ");
    scanf("%d", &pos);
    if (pos <= 0 || pos > count + 1) {
        printf("Invalid position.\n");
        return;
    }

    if (head == NULL || pos == 1) {
        preinsert();
    } else if (count >= pos) {
        printf("Enter the data: ");
        scanf("%d", &num);
        struct node *temp = head;
        while (temp->next != NULL && pos - 1 > 1) {
            temp = temp->next;
            pos--;
        }
        struct node *cur = (struct node*)malloc(sizeof(struct node));
        if (cur == NULL) {
            printf("Memory allocation failed.\n");
            return;
        }
        cur->data = num;
        cur->next = temp->next;
        temp->next = cur;
        ++count;
    }
}

void postinsert() {
    int num;
    printf("Enter the data: ");
    scanf("%d", &num);
    struct node *cur = (struct node*)malloc(sizeof(struct node));
    if (cur == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    cur->data = num;
    cur->next = NULL;
    if (tail == NULL)
        head = cur;
    else
        tail->next = cur;
    tail = cur;
    ++count;
}

void del_end() {
    if (count > 0) {
        if (head == tail) {
            free(head);
            head = tail = NULL;
        } else {
            struct node *temp = head;
            while (temp->next != tail)
                temp = temp->next;
            free(tail);
            tail = temp;
            tail->next = NULL;
        }
        --count;
    } else {
        printf("Insufficient elements\n");
    }
}

void traversal() {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void search() {
    int num, i = 1, j = 0;
    printf("Enter an element to search: ");
    scanf("%d", &num);
    struct node *temp = head;
    while (temp != NULL) {
        if (num == temp->data) {
            printf("%d is found in the position %d\n", temp->data, i);
            j = 1;
        }
        temp = temp->next;
        i++;
    }
    if (j == 0)
        printf("Entered element is not in the list.\n");
}

void del_pos(){
int pos;
printf("enter the position :");
scanf("%d",&pos);
  if(pos<=0){
   printf("invalid position");
   return;
   }
    if(head==NULL)
      {
       printf("list is empty");
      }
    else{
        struct node*temp=head;
        if (pos==1){
        del_beg();
        return;
        }

        while(temp->next->next!=NULL&&pos-1>1)

        {
        temp=temp->next;
        pos--;
        }
        if(pos-1<=1)
        {
        struct node*del;
        del=temp->next;
        temp->next=temp->next->next;
        free(del);
        }
        else{
        printf("invalid position");
}
}
}







int main() {
    int ch;
printf("\n DOUBLY LINKED LIST OPERATIONS \n ");

    do {
        printf("1.insert  at beginning\n");
        printf("2. insert at  end\n3. Add data in a position\n");
        printf("4. Display\n5. Search\n");
        printf("6. Delete from beginning\n7. Delete from the end \n 8.Delete at position \n9. EXIT\n \nEnter the choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                preinsert();
                traversal();
                break;
            case 2:
                postinsert();
                traversal();
                break;
            case 3:
                position();
                traversal();
                break;
            case 4:
                traversal();
                break;
            case 5:
                search();
                break;
            case 6:
                del_beg();
                traversal();
                break;
            case 7:
                del_end();
                break;
            case 8:
                del_pos();
                traversal();
                break;
            case 9:
                break;
            default:
                printf("Invalid input\n");
                break;
        }
    } while (ch != 9);

    while (head != NULL) {
        struct node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
