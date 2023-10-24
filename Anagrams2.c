#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<stdbool.h>
#define LETTER_NUM 26 
#define MAX_LEN 100
#define MAX_ROW 10000
#define MAX_COL 100
typedef struct ListNode{
  struct ListNode * next;
  char* val;
}ListNode;

void test();
bool check(char* ch, char* userInput);
void insert(ListNode*head, char* str);
void printNode(ListNode*head);
void printAns(ListNode*anagram[]);
void freeList(ListNode*anagram[],int len);
int main(void)
{
  test();
  /*FILE* fl = fopen("34words.txt","r");
  if(fl==NULL){
    fprintf(stderr,"can not open this file");
    exit(EXIT_FAILURE);
  }
  ListNode* anagram[MAX_ROW]={NULL};
  for(int i=0;i<MAX_ROW;i++){
    anagram[i]=(ListNode*)malloc(sizeof(ListNode));
    anagram[i]->next = NULL;
    anagram[i]->val = NULL;
  }
  char str[MAX_LEN];
  while(!feof(fl)){
    fgets(str,MAX_LEN,fl);
    for(int i=0;i<MAX_ROW;i++){
      if(anagram[i]->next!=NULL&&check(anagram[i]->next->val,str)){
        insert(anagram[i],str);
	break;
      }else if(anagram[i]->next==NULL){
	insert(anagram[i],str);
	break;
      }
    }
  }

  //printAns(anagram);
  // to do free
  fclose(fl);*/
}

void test()
{
  ListNode* anagram[3];
  for(int i=0;i<3;i++){
    anagram[i]=(ListNode*)malloc(sizeof(ListNode));
    anagram[i]->next = NULL;
    anagram[i]->val = NULL;
  }
  insert(anagram[0],"abc");
  insert(anagram[1],"bcd");
  insert(anagram[2],"cde");
  printAns(anagram);
  freeList(anagram,3);
}


bool check(char* ch, char* userInput)
{
  if(strlen(ch)-1!=strlen(userInput)-1){
    return false;
  }
  int map_ch[LETTER_NUM]={0};
  int map[LETTER_NUM]={0};
  int tag = true;
  for(int i=0;i<(int)(strlen(ch)-1);i++){
    map_ch[ch[i]-'a']++;
    map[userInput[i]-'a']++;
    if(ch[i]!=userInput[i]){
      tag=false;
    }
  }
  if(tag){
    return false;
  }
  for(int i=0;i<LETTER_NUM;i++){
    if(map[i]!=map_ch[i]){
      return false;
    }
  }
  return true;
}

void insert(ListNode*head, char*str)
{
  while(head!=NULL&&head->next!=NULL){
    head=head->next;
  }
  ListNode*node = (ListNode*)malloc(sizeof(ListNode));
  node->next = NULL;
  strcpy(node->val,str);
  head->next = node; 
}    
  
void printNode(ListNode*head)
{
  while(head!=NULL){
    printf("%s",head->val);
    head=head->next;
  }
}

void printAns(ListNode*anagram[]){
  int index = 0;
  while(anagram[index]->next!=NULL){
    int total = 0;
    ListNode*p = anagram[index]->next;
    while(p!=NULL){
      total++;
      p=p->next;
    }
    p = anagram[index]->next;
    printf("%i ",total);
    while(p!=NULL){
      printf("%s ",p->val);
      p=p->next;
    }
    printf("\n.\n.\n.\n"); 
  }
}


void freeList(ListNode*anagram[],int len){
  for(int i=0;i<len;i++){
    ListNode* p = anagram[i];
    ListNode* q = p->next;
    while(q!=NULL){
      free(p);
      p=q;
      q=q->next;
    }
    free(p);
  }
}

