#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<stdbool.h>
#define LETTER_NUM 26 
#define MAX_LEN 100
#define MAX_ROW 10000000
#define MAX_COL 100
#define ALPHA_NUM 26
typedef struct ListNode{
  struct ListNode * next;
  char val[MAX_LEN];
}ListNode;
void test();
void insert(ListNode*head, char* str);
void printNode(ListNode*head);
void printAns(ListNode*anagram[], char*target, int len);
void print_sub_ans(ListNode* node1, ListNode* node2, char* target);
bool is_create_anag(const char* target,const char* str1,const char* str2);
void freeList(ListNode*anagram[],int len);
bool check(char* ch, char* userInput);
bool check_argv(char* ch, char* target);

int main(int argc, char* argv[])
{
  //test();
  FILE* fl = fopen("34words.txt","r");
  if(fl==NULL){
    fprintf(stderr,"can not open this file");
    exit(EXIT_FAILURE);
  }
  char* target = argv[1];
  ListNode* list = (ListNode*)malloc(sizeof(ListNode));
  list->next = NULL;
  char ch[MAX_LEN];
  int index = 0;
  while(fscanf(fl,"%s",ch)==1){
    if(index>=MAX_ROW){
      fprintf(stderr,"file is so big");
      exit(EXIT_FAILURE);
    }
    //to do
  }
  int len = index;
  printAns(anagram,target,len);
  freeList(anagram,MAX_ROW);
  fclose(fl);
}

void test()
{
  
  //test insert
  /*
  ListNode* p = (ListNode*)malloc(sizeof(ListNode));
  p->next = NULL;
  insert(p,"bcd");
  strcpy(p->val,"abc");
  printNode(p);
  */
  /*ListNode* anagram[3]={NULL};
  for(int i=0;i<3;i++){
    anagram[i]=(ListNode*)malloc(sizeof(ListNode));
    anagram[i]->next = NULL;
    anagram[i]->val = NULL;
  }
  insert(anagram[0],"abc");*/
  //insert(anagram[1],"bcd");
  //insert(anagram[2],"cde");
  //for(int i=0;i<3;i++){
    //printNode(anagram[i]->next);
  //}
  //printAns(anagram);
 // freeList(anagram,3);
  /*
  ListNode* node1 = (ListNode*)malloc(sizeof(ListNode));
  strcpy(node1->val,"com");
  ListNode* node2 = (ListNode*)malloc(sizeof(ListNode));
  strcpy(node2->val,"pile");
  insert(node1,"ocm");
  insert(node1,"mco");
  insert(node2,"plie");
  insert(node2,"peil");
  */

  //assert(is_create_anag("compile","comp","ile"));
}

void insert(ListNode*head, char*str)
{
  if(!head){
    fprintf(stderr,"head is null");
    exit(EXIT_FAILURE);
  }
  ListNode*node = (ListNode*)malloc(sizeof(ListNode));
  node->next = head->next;
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

void printAns(ListNode*anagram[], char*target, int len){
  for(int j=0;j<len-1;j++){
    for(int i=j+1;i<len;i++){
      bool is_anag = is_create_anag(target, anagram[j]->next->val, anagram[i]->next->val);
      if(is_anag){
       print_sub_ans(anagram[j]->next, anagram[i]->next, target);
      }
    }
  }
}

void print_sub_ans(ListNode* node1, ListNode* node2, char* target){
  if(!node1||!node2){
    fprintf(stderr,"node1 or node2 is null pointer");
    exit(EXIT_FAILURE);
  }
  ListNode* p = node1;
  ListNode* q = node2;
  while(p){
    while(q){
      char temp[MAX_LEN];
      strcpy(temp,p->val);
      strcat(temp,q->val);
      if(strcmp(temp,target)){
        printf("%s\n",temp);
      }
      strcpy(temp,q->val);
      strcat(temp,p->val);
      if(strcmp(temp,target)){
        printf("%s\n",temp);
      }
      q=q->next;
    }
    p=p->next;
    q=node2;
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

bool is_create_anag(const char* target,const char* str1,const char* str2){
  if(!target||!str1||!str2){
    return false;
  }
  unsigned strlen_str1 = strlen(str1);
  unsigned strlen_str2 = strlen(str2);
  unsigned strlen_tar = strlen(target);
  if(strlen_str1+strlen_str2!=strlen(target)){
    return false;
  }
  int map[ALPHA_NUM]={0};
  for(int i=0;i<strlen_tar;i++){
    if(i<strlen_str1){
      map[str1[i]-'a']++;
    }
    if(i<strlen_str2){
      map[str2[i]-'a']++;
    }
    map[target[i]-'a']--;
  }
  for(int i=0;i<ALPHA_NUM;i++){
    if(map[i]){
      return false;
    }
  }
  return true;
}

bool check(char* ch, char* userInput)
{
  if(strlen(ch)!=strlen(userInput)){
    return false;
  }
  if(strcmp(ch,userInput)==0){
    return false;
  }
  int map[LETTER_NUM]={0};
  for(int i=0;i<(int)strlen(ch);i++){
    map[userInput[i]-'a']++;
    map[ch[i]-'a']--;
  }
  for(int i=0;i<LETTER_NUM;i++){
    if(map[i]){
      return false;
    }
  }
  return true;
}

bool check_argv(char* ch, char* target){
  if(strlen(ch)>=strlen(target)){
    return false;
  }
  


}
