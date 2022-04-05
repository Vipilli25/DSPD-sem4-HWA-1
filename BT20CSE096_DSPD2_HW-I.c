#include<stdio.h>
#include<stdlib.h>
#include <string.h> 

// structure for storing date //
typedef struct date
{
	int day;
	int month;
	int year;
}date;

// structure for storing data of a particluar passenger // 
typedef struct pass_node
{
	int passenger_id;
	char destination_station[50];
	int train_id;
	date dt;
	char boarding_station[50];
	char Travelling_class[10];
	int seat_num;
	int visited;
	int output_status;
	struct pass_node* next;
}pass_node;

// structure for implementing train database // 
typedef struct trainnode
{
	int train_id;
	date dt;
	int passenger_count;
	struct trainnode* next;
}trainnode;

// this function inserts a record passenger details for the reservation //
void insert_passenger_record(pass_node** head,int pass_id, char dest_stat[], int t_id, date dt, char boarding_station[], char Travelling_class[], int seat_num) 
{                                      
	  pass_node* n;
	  pass_node* temp = *head;     
	n=(pass_node*)malloc(sizeof(pass_node));
	
	// setting data //
	n->passenger_id=pass_id;             
	strcpy(n->destination_station,dest_stat);  
	n->train_id=t_id;
	  n->dt.day =dt.day;   
	  n->dt.month =dt.month;  
	  n->dt.year=dt.year;  
	  n->seat_num=seat_num;
	strcpy(n->boarding_station,boarding_station);
	strcpy(n->Travelling_class,Travelling_class);
   	n->next=NULL;
   	
   	if (*head == NULL)                
    {
       *head = n;
       return;
    }
    while (temp->next != NULL)
    {
    	temp=temp->next;
	}
 
    temp->next = n;
}

//this function deletes a record of passenger with given passenger id if the passenger cancels the reservation. //
void Delete_passenger_record(  pass_node** head,int id)
{
	  pass_node* temp = *head;
	  pass_node* del_link;
	if (*head==NULL)
	{
		printf("\nlist is already empty! ");
		printf("\n Reservation Cancellation failed !!");
	}
	else if(temp->passenger_id==id)                         // if the very first element to be deleted 
	{
		del_link=*head;
		*head=temp->next;
		free(del_link);
	}
	else
	{
	  while(temp->next->passenger_id!=id)
   	  {
   		temp=temp->next;
	  }  
	  del_link=temp->next;                  // del_link is the address of node which we want to delete //
	  if(del_link->next==NULL)               // if the very last element to be deleted 
	  {
	  	temp->next=NULL;
	  }	
	  else
	  {
	  	temp->next=del_link->next;
	  }
	  free(del_link);
    }
 printf("\n Reservation Cancellation successfull !!");
}

// Get the list of passengers having the same destination station and same train id

void get_list_destination(pass_node* head)
{
	pass_node* i=head;
	pass_node* j=head;
	
	while(i!=NULL)
	{
		i->visited=0;
		i->output_status=0;
		i=i->next;
	}
	i=head;
	printf("\n | Destination Station | | Train Id | | Passeneger ID's |\n");
	while(i!=NULL)
	{ 
	   j=i->next;
	   while(j!=NULL)
	   {
	   	 if(strcmp(i->destination_station,j->destination_station)==0 && i->train_id==j->train_id  )
	   	 {
	   	 	if(i->visited==0)
        	{
        		if(i->output_status==0)
	   	    	{
	   	 	 	  printf("           %s              %d ",i->destination_station,i->train_id);  // i gave a large gap between %s and %d just for making output look better and understandable//
	   	 	 	  i->output_status==1;
			    }
	   	       printf("            %d ",i->passenger_id);
	   	       i->visited=1;
	        }
			if(j->visited==0)
	   	 	{
	   	 		printf("%d ",j->passenger_id);
	   	 		j->visited=1;
			}	
		 }
		 j=j->next;
	   }
	   i=i->next;
	   printf("\n");
	}
}

// sub-function for sortbytraveldate //
void swap(pass_node* current, pass_node* index)
{
    char* char_temp=(char*)malloc(sizeof(char)*100);
	int int_temp ;
     //	// passeneegr id 
    int_temp = current->passenger_id;  
    current->passenger_id = index->passenger_id;  
    index->passenger_id = int_temp;
    	// train id
    int_temp = current->train_id;  
    current->train_id = index->train_id;  
    index->train_id = int_temp; 
    //    // destination 
    strcpy(char_temp,current->destination_station);
    strcpy(current->destination_station,index->destination_station);
    strcpy(index->destination_station,char_temp);
    // boarding station
    strcpy(char_temp,current->boarding_station);
    strcpy(current->boarding_station,index->boarding_station);
    strcpy(index->boarding_station,char_temp);
    // travelling class
    strcpy(char_temp,current->Travelling_class);
    strcpy(current->Travelling_class,index->Travelling_class);
    strcpy(index->Travelling_class,char_temp);
    // seat_num
    int_temp = current->seat_num;  
    current->seat_num = index->seat_num;  
    index->seat_num = int_temp; 
    // date
       int_temp = current->dt.day;  
       current->dt.day = index->dt.day;  
       index->dt.day = int_temp;
       
       int_temp = current->dt.month;  
       current->dt.month = index->dt.month;  
       index->dt.month = int_temp;
       
       int_temp = current->dt.year;  
       current->dt.year = index->dt.year;  
       index->dt.year = int_temp;
}

int compare_dates (struct date d1, struct date d2)
{
    if (d1.year < d2.year)
       return -1;

    else if (d1.year > d2.year)
       return 1;

    if (d1.year == d2.year)
    {
         if (d1.month<d2.month)
              return -1;
         else if (d1.month>d2.month)
              return 1;
         else if (d1.day<d2.day)
              return -1;
         else if(d1.day>d2.day)
              return 1;
         else
              return 0;
    }
}

void SortByTravelDate(pass_node** head)
{
	printf("\n inside sortbytraveldate function\n");
	 pass_node *current = *head, *index = NULL;  
          
        if(*head == NULL) 
		{  
            return;  
        }  
        else 
		{  
            while(current != NULL) 
			{  
                index = current->next;     
                while(index != NULL) 
				{   
                    if(compare_dates(current->dt,index->dt)==1) 
					{  
					       swap(current,index);     
                    }      
                    index = index->next;  
                }  
                current = current->next;  
            }      
        } 
}

// Sort by travel date functons ends // 

// sub-function for sortTrains //
void insert_trainnode(trainnode** train_head, int train_id, date dt, int passenger_count)
{
	trainnode* tn;
	 trainnode* temp = *train_head;
	tn=(trainnode*)malloc(sizeof(trainnode));
	
	tn->train_id=train_id;
	 tn->dt.day=dt.day;
	 tn->dt.month=dt.month;
	 tn->dt.year=dt.year;
	tn->passenger_count=passenger_count;
   	if (*train_head == NULL)                 
    {
       *train_head = tn;
       return;
    }
    while (temp->next != NULL)
    {
    	temp=temp->next;
	}
 
    temp->next = tn;
}

void Display_train_data(trainnode* train_head)
{
	if(train_head==NULL)
	{
		printf("\n no train database \n");
	}
	printf("\n        train database      \n");
	printf("\n |train_id| |Date| |passenger count| \n");
	while(train_head!=NULL)
	{
		printf("  %d ",train_head->train_id);
		printf("       %d %d %d ",train_head->dt.day,train_head->dt.month,train_head->dt.year);
		printf("       %d ",train_head->passenger_count);
        train_head=train_head->next;
        printf("\n");
	}
	
}

void swap_train_database(trainnode* current, trainnode* index)
{
	
	char* char_temp=(char*)malloc(sizeof(char)*100);
	int int_temp ;
	
	 	// train id
      int_temp = current->train_id;  
      current->train_id = index->train_id;  
      index->train_id = int_temp;
        // date
       int_temp = current->dt.day;  
       current->dt.day = index->dt.day;  
       index->dt.day = int_temp;
       
       int_temp = current->dt.month;  
       current->dt.month = index->dt.month;  
       index->dt.month = int_temp;
       
       int_temp = current->dt.year;  
       current->dt.year = index->dt.year;  
       index->dt.year = int_temp;
       // passenger count 
      int_temp = current->passenger_count;  
      current->passenger_count = index->passenger_count;  
      index->passenger_count = int_temp;
}

int check (trainnode* train_head, int train_id) // checks whther given train _id already has database or not //
{
	while(train_head!=NULL)
	{
		if(train_head->train_id==train_id)
		{
			return 1;
		}
		train_head=train_head->next;
	}
   return 0;
}

void SortTrains(pass_node* head)
{
	trainnode* train_head=NULL;
	int t_id=0;
	int count=0;
	pass_node* temp1=head;
	pass_node* temp2 =head;
	// Initializing visiting status of passenger node //
	while(temp2!=NULL)
	{
		temp2->visited=0;
		temp2=temp2->next;
	}
	
	// counting the no of passengers per train and creating database //
	while(temp1!=NULL)
	{
		temp2=temp1->next;
		count=1;
		while(temp2!=NULL)
		{
			if(temp1->train_id==temp2->train_id && temp2->visited==0) 
			{
				count=count+1;
				temp2->visited=1;
			}
		  temp2=temp2->next;
		}
		
		if(check(train_head,temp1->train_id)!=1)
		{
			insert_trainnode(&train_head,temp1->train_id,temp1->dt,count);
		}
	 temp1=temp1->next;
	}
	
    // For sorting 
		 trainnode *current = train_head, *index = NULL;  
            while(current != NULL) 
			{  
                index = current->next;     
                while(index != NULL) 
				{   
                    if(current->passenger_count<index->passenger_count) 
					{  
					       swap_train_database(current,index);     
                    }      
                    index = index->next;  
                }  
                current = current->next;  
            }       
        Display_train_data(train_head);
}
//sorttrain related functions end here


void print_passenger_database(  pass_node* head)
{
	if(head==NULL)
	{
		printf("\n No passenger database \n");
	}
	printf("\n        passenger database      \n");
	printf("\n |Passenger ID| |boarding station| |train_id| |Date| |boarding_station| |Travelling_class| | seat_num|\n");
	while(head!=NULL)
	{
		printf("[ %d ",head->passenger_id);
		printf(" %s ",head->destination_station);
		printf(" %d ",head->train_id);
		printf(" %d %d %d ",head->dt.day,head->dt.month,head->dt.year);
		printf(" %s ",head->boarding_station);
		printf(" %s ",head->Travelling_class);
		printf(" %d ]",head->seat_num);
		printf(" \n ");
        head=head->next;
	}
 printf("\n -----------------------------------------\n");
}

void create_passenger_database(int num,  pass_node** head)
{
	int pass_id=0;
	char *dest_stat,*board_stat,*trav_class;
	int t_id=0,seat_num=0;
	struct date d;
	dest_stat=(char*)malloc(sizeof(char)*50);
	board_stat=(char*)malloc(sizeof(char)*50);
	trav_class=(char*)malloc(sizeof(char)*10);
	printf(" \n For entering data refer sample test cases mentioned in end of the source code \n ");
	printf(" \n print in the given order \n ");
	printf("\n  |Passenger ID| |boarding station| |train_id| |Date| |boarding_station| |Travelling_class| |seat_num|\n");
	while(num>0)
	{
	   scanf("%d",&pass_id);
	   scanf("%s",dest_stat);
	   scanf("%d",&t_id);
	   scanf("%d %d %d", &d.day, &d.month, &d.year);
	   scanf("%s",board_stat);
	   scanf("%s",trav_class);
	   scanf("%d",&seat_num);
	   insert_passenger_record(head,pass_id,dest_stat,t_id,d,board_stat,trav_class,seat_num);
	   num--;
    }  
	 	printf("\n !! seat allocation request is approved !! \n");
}
int main()
{

   printf("------- Welcome to Train Registration portal --------\n");
    pass_node* head = NULL;
    int choice=0;
    printf("\n Initializing Database. ");
    printf("\n Enter total number of passengers for seat allocation : ");
    int num=0;
	scanf("%d",&num);
	create_passenger_database(num,&head);
	printf("\n printing database for confirmation \n ");
	print_passenger_database(head);
   while(1)
   {
       printf("1: Insert records \n");
       printf("2: Delete a record  \n");
       printf("3: Get the list of people with same destination station and  train id \n");
       printf("4: Get the list of destination stations for a particular passenger as per the dates of the travel \n");
       printf("5: Display the train number and the travel date in the sorted order of number of passengers on the train \n");
       printf("\n Choose an action: ");
       scanf("%d",&choice);
       fflush(stdin);
       switch(choice)
       {
           case 1: 	
	               printf("\n Enter total number of passengers for seat allocation : ");
	               int num=0;
	               scanf("%d",&num);
	               create_passenger_database(num,&head);
	               printf("\n printing database for confirmation :\n  ");
	               print_passenger_database(head);
                   break;
           case 2: 
                   printf("\n Enter passenger ID for cancelling reservation : ");
                   int id=0;
                   scanf("%d",&id);
                   Delete_passenger_record(&head,id);
                   printf("\n printing database for confirmation (after deleting record) \n : ");
	               print_passenger_database(head);
                   break;
           case 3: 
                   get_list_destination(head);
                   break;
           case 4:
           	       SortByTravelDate(&head);
           	       print_passenger_database(head);
                   break;
           case 5: 
                    SortTrains(head);
                    break;
           default: printf("\nWrong choice entered\n");  
       }
       printf("\n---------------------------\n");
   }

	return 0;
}

// test cases 
//1 hyd 201 4 4 22 nag 1AC 145
//2 bang 202 4 5 22 bang 1AC 135
//3 bang 202 12 2 22 nag 1AC 2
//4 hyd 201 10 1 22 sec sleeper 45
//5 sec 204  15 6 22 ker 3AC 66
//6 sec 205 12 8 20 tri sleeper 124
//7 bang 202 10 4 21 var 1AC 41
//8 hyd 201 7 7 21 ind 3AC 11
//9 bang 202 4 5 22 gan sleeper 124
//10 bang 202 4 5 22 chand sleeper 14