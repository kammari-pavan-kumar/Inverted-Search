#ifndef INVERTED_SEARCH_H
#define INVERTED_SEARCH_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SUCCESS 0
#define FAILURE -1
#define DATA_NOT_FOUND -2

/* Hash table structure */
typedef struct hash_node
{
    int index;
    struct main_node *link;
}hash_t;

// Structure for main node
typedef struct main_node
{
    char *word;
    int file_count;

    struct main_node *main_node_link;
    struct sub_node *sub_node_link;
}main_node;

// Structure for sub node
typedef struct sub_node
{
    char *file_name;
    int word_count;

    struct sub_node *sub_node_link;
}sub_node;

// Structure for file name node
typedef struct file_name_node
{
    char *file_name;
    struct file_name_node *file_name_link;
}file_name_node;


/*Function to validate command line args */
int validation(file_name_node **f_head,int argc, char *argv[]);

/*For Creating Hash Table*/
void create_HT(hash_t *HT);

/*To insert files in file name node linked list*/
int file_insert_at_last(file_name_node **head, char *fname);

/* To create database */
int Create_DataBase(hash_t *arr, file_name_node **f_head);

/* To search database */
int Search_database(hash_t *arr);

/* To display database */
int Display_database(hash_t *arr);

/* To save database */
int Save_database(hash_t *arr);

/* Updating database */
int Update_db(hash_t *arr,file_name_node **f_head);

/*Function to insert at last for sub node */
int insert_at_last_sub(sub_node **head, sub_node *new_node);

/*Function to insert at last for main node */
int insert_at_last_main(main_node **head, main_node *new_node);

/* Function for deleting file name */
int delete_file_name(char *file_name, file_name_node **head);

/*print file_name_node sll */
void print_list(file_name_node **f_head);

#endif