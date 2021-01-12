#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Carrick 100 -> Livia 99 -> Valencia 95
*/

struct Node{
    char name[255];
    int score;
    Node *next; // menunjuk ke node selanjutnya 
} *head, *tail;// global variabelnya, head dan tail
// head : node pertama dalam linked list
// tail: node terakir dalam linked list

Node *createNode(const char *name,int score){
    Node *newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name,name);
    newNode->score = score;
    newNode->next=NULL; // next code is NUll
    return newNode;
}

//push head, push tail
void pushHead(const char *name, int score){
    //1. buat dulu nodenya
    //2. cek kondisi
    //      jika tidak ada head, maka nodenya akan menjadi head dan tail
    //      jika ada head, node akan menjadi head baru dan node->next = head lama
    Node *temp = createNode(name,score);

    if(!head){ // head==NULL
        // head = temp;
        // tail = temp;
        head = tail = temp;
    }
    else{ // jika ada head
        temp->next = head; // node menunjuk ke head yang lama
        head=temp; // node akan menjadi head yang baru
    }
}

// untuk awal2 di sem2
// 1. apakah ada head dan head->next == NULL (1 node)

void pushTail(const char *name, int score){
    Node *temp = createNode(name,score); // buat dulu nodenya
    if(!head){
        head = tail = temp;
    }
    else{
        tail->next = temp; // tail menunjuk ke node
        tail = temp; // node menjadi tail
    }
}

void popHead(){
    if(!head){ // jika tidak ada head
        return;
    }
    else if(head == tail){ // kalau node cuma 1
        free(head);
        head = tail = NULL; // remove value
    }
    else{
        Node *temp = head->next; // 53(head) -> 70 (temp) -> 40 ->25
        head->next = NULL; // 53(head) ->NULL || 70(temp) -> 40 -> 25
        free(head); // perlu di free krn global , memory head yang lama akan alokasikan
        head = NULL; // 70 (head,temp) -> 40 ->25
    }
    //karna temp itu local,
    // 70(head) -> 40 -> 25

}

void popTail(){
    if(!head){
        return;
    }
    else if(head == tail){
        free(head);
        head = tail = NULL;
    }
    else{
        Node *temp = head; // 53 (head, temp) -> 70 -> 40 -> 25 (tail)

        while(temp->next != tail){
            temp = temp->next;   
        }
        // 53(head) -> 70 -> 40(temp) -> 25 (tail) -> NULL

        temp->next = NULL; // 53(head) -> 70 -> 40(temp) -> 25 (tail) -> NULL
        free(tail);
        tail = temp;
    }

}


// 53 (head) -> 70 -> 40 -> 25
// 70 (head) -> 40 -> 25

void printList(){
    /*
    //base case buat ngecek

        if(!head){
            return; 
        }

    */
    Node *curr = head; // 53 (curr,head) -> 70 -> 40(tail) -> NULL

    while(curr){

        if(curr == head){
            printf(" (head) ");
        }
        else if(curr == tail){
            printf(" (tail) ");
        }
        
        printf("%s %d ->",curr->name,curr->score);
        curr = curr->next;
    }
    puts("NULL");
}

int main(){
    pushHead("Carrik",100);// Carrik(head,tail) -> N
    pushTail("Bryan",90); // Carrik(head), bryan (tail) -> N
    pushTail("Valencia",95); // Cariik(head), bryan, Valencia(tail) -> N

    printList();
    return 0;
}
