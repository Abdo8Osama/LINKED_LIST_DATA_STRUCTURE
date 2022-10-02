
#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"DIO_interface.h"
#include"LCD_int.h"
#include"util/delay.h"

#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct node
{
	u16 data ;
	struct node * next ;
};

struct node * head =NULL;
struct node * current =NULL ;
u8 i ;

void creatNode(u8 value)
{
	struct node * link ;
	current = head ;
	link = (struct node *)malloc(sizeof(struct node));
	link->data=value;
	link->next=NULL;
	if(head == NULL )
	{
		head = link ;
	}
	else{
		while(current->next != NULL)
		{
			current = current->next;
		}
		current->next = link ;
	}
}

void Add_Front_Node(u8 value)
{
	struct node * link ;
	current = head ;
	link = (struct node *)malloc(sizeof(struct node));
	link->data=value;
	link->next=current;
	head = link ;
}

void Add_Indexed_Node(u8 value , u8 index)
{
	u8 count =0;
	struct node * link ;
	current = head ;
	link = (struct node *)malloc(sizeof(struct node));
	link->data=value;
	for(count=0;count<index;count++)
	{
		if(count == index-1)
		{
			link->next=current->next;
			current->next=link;
		}
		current=current->next;
	}
}

void Update_Indexed_Node(u8 value , u8 index)
{
	u8 count =0;
	current = head ;
	for(count=0;count<index;count++)
	{
		current=current->next;
	}
	current->data = value ;
}

s8 search_Node_value(u8 value)
{
	u8 count =0;
	current = head ;
	while(current != NULL)
	{
		if(current->data == value)
		{
			return count ;
		}
		current=current->next;
		count++;
	}
	return -1 ;
}
void print_Linked_List(struct node * head_ptr)
{
	LCD_voidWriteString("head->");
	current = head_ptr ;
	LCD_WriteNum(current->data);
	LCD_voidWriteString("->");
	while(current->next != NULL)
	{
		current=current->next;
		LCD_WriteNum(current->data);
		LCD_voidWriteString("->");
	}
	LCD_voidWriteString("NULL");
}

void main()
{
	u8 searchValue =5;
	s8 searchResult ;
	for(i=5;i<=6;i++)
	{
		creatNode(i);
	}
	Add_Front_Node(4);
	Add_Indexed_Node(7,2);
	Update_Indexed_Node(9,2);
	searchResult =search_Node_value(searchValue);
	LCD_8voidInit();
	LCD_CLEAR_DISPLAY();
	print_Linked_List(head);
	LCD_voidGotoXY(1,0);
	if(searchResult <0)
	{
		LCD_voidWriteString("search:NOT_Found");
	}
	else
	{
		LCD_voidWriteString("value:");
		LCD_WriteNum((s32)searchValue);
		LCD_voidWriteString(" index:");
		LCD_WriteNum((s32)searchResult);
	}
}
