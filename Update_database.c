#include "Inverted_search.h"
#include <string.h>

// Function to update database from saved file
int Update_db(hash_t *arr, file_name_node **f_head)
{
    char main_file_name[100];
    int index;
    char word[100];
    int file_count;
    char file_name[100];
    int word_count;

    // Read database file name from user
    printf("Enter file name : ");
    scanf("%s", main_file_name);


    if (strstr(main_file_name, ".txt") == NULL)
    {
        printf("ERROR : %s IS NOT .txt FILE\n", main_file_name);
        return FAILURE;
    }

    /*open the file in read mode and check null or not,if null return failure*/
    FILE *fptr = fopen(main_file_name, "r");
    if (fptr == NULL)
    {
        printf("ERROR : FILE NOT FOUND\n");
        return FAILURE;
    }
    /*read a index,word,filecount from file */
    while (fscanf(fptr, " #%d;%[^;];%d;", &index, word, &file_count) == 3)
    {
        /*create a new main node update data and link */
        main_node *new_main = malloc(sizeof(main_node));
        if (new_main == NULL)
        {
            return FAILURE;
        }

        new_main->word = malloc(strlen(word) + 1);
        strcpy(new_main->word, word);

        new_main->file_count = file_count;
        new_main->sub_node_link = NULL;
        new_main->main_node_link = NULL;

        int i = 0;
        /*run loop until i < filecount*/
        for (int i = 0; i < file_count; i++)
        {
            /*read filename and word count from file*/
            fscanf(fptr, "%99[^;];%d;", file_name, &word_count);
            /*delete filename from linked list */
            delete_file_name(file_name, f_head);
            /*create subnode and update filename,wordcount and subnode link*/
            sub_node *new_sub = malloc(sizeof(sub_node));
            if (new_sub == NULL)
            return FAILURE;
            new_sub->file_name = malloc(strlen(file_name) + 1);
            if (new_sub->file_name == NULL)
            return FAILURE;
            strcpy(new_sub->file_name, file_name);

            new_sub->word_count = word_count;
            new_sub->sub_node_link = NULL;

            /*insert sub_node at last*/
            insert_at_last_sub(&new_main->sub_node_link, new_sub);
        }
        
        /*read # from file */
        fgetc(fptr);
        insert_at_last_main(&(arr[index].link), new_main);
    }
    /*print file nodes after deleting files*/
    print_list(f_head);
    /*close the file return success*/
    fclose(fptr);
    return SUCCESS;
}
int insert_at_last_sub(sub_node **head, sub_node *new_node)
{
    // Check whether new node is valid
    if (new_node == NULL)
    {
        return FAILURE;
    }
    // Initialize next link of new node as NULL
    new_node->sub_node_link = NULL;
    /* check list is empty, if it is empty Update the head with new node address */
    if (*head == NULL)
    {
        *head = new_node;
        return SUCCESS;
    }
    /* if list is not empty Traverse to the last node and establish the link between last node and new node. */
    else
    {
        sub_node *temp = *head;
        while (temp->sub_node_link != NULL)
        {
            temp = temp->sub_node_link;
        }
        temp->sub_node_link = new_node;
        return SUCCESS;
    }
}
int insert_at_last_main(main_node **head, main_node *new_node)
{
    // Check whether new node is valid
    if (new_node == NULL)
    {
        return FAILURE;
    }
    // Initialize next link of new node as NULL
    new_node->main_node_link = NULL;
    /* check list is empty, if it is empty Update the head with new node address */
    if (*head == NULL)
    {
        *head = new_node;
        return SUCCESS;
    }
    /* if list is not empty Traverse to the last node and establish the link between last node and new node. */
    else
    {
        main_node *temp = *head;
        while (temp->main_node_link != NULL)
        {
            temp = temp->main_node_link;
        }
        temp->main_node_link = new_node;
        return SUCCESS;
    }
}
int delete_file_name(char *file_name, file_name_node **head)
{
    /*asssign head pointer to temp and create a prev pointer */
    file_name_node *temp = *head;
    file_name_node *prev = NULL;
    /*check list empty or not */
    if (*head == NULL)
    {
        return FAILURE;
    }
    /*traverse until end and delete element */
    while (temp != NULL)
    {
        /*if given data not satisfy traverse next */
        if (strcmp(temp->file_name, file_name) != 0)
        {
            prev = temp;
            temp = temp->file_name_link;
        }
        else
        {
            /*delete element if it is present */
            if (prev == NULL)
            {
                *head = temp->file_name_link;
                free(temp->file_name);
                free(temp);
                return SUCCESS;
            }
            /*connect next node to prev node and delete temp */
            prev->file_name_link = temp->file_name_link;
            free(temp->file_name);
            free(temp);
            return SUCCESS;
        }
    }
    return DATA_NOT_FOUND;
}