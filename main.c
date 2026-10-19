#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Inverted_search.h"

int main(int argc, char *argv[])
{
    /*declare choice,hash array,file_name_node f_head pointer */
    int choice;
    hash_t arr[27];
    file_name_node *f_head = NULL;

    /*call hash table function */
    create_HT(arr);

    if (argc <= 1)
    {
        printf("INFO : Invalid Arguments\n");
        return 0;
    }

    /*call validation function to validate command line args and insert files in to sll*/
    validation(&f_head, argc, argv);


    while (1)
    {
        printf("Select your choice among following options:\n");
        printf("1. Create Database\n2. Display Database\n3. Update Database\n4. Search\n5. Save Database\n6. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        /*use swith case for menu selection option to perform specific operation */
        switch (choice)
        {
        case 1:
        /*create temporary pointer f_tmp traverse and create database */
            file_name_node *f_tmp = f_head;
            while (f_tmp != NULL)
            {
                if (Create_DataBase(arr, &f_tmp) == FAILURE)
                {
                    printf("ERROR : Create Database Failure\n");
                }
                else
                {
                    printf("INFO : Creation of database for file %s is Successful\n", f_tmp->file_name);
                    
                }
                f_tmp = f_tmp->file_name_link;
            }
            break;

            /*Display Database */
        case 2:
            if (Display_database(arr) == FAILURE)
            {
                printf("ERROR : Display Database Failure\n");
            }
            else
            {
                printf("INFO : Display Database is Successful\n");
            }
            break;

            /* Update Database */
        case 3:

            if (Update_db(arr, &f_head) == FAILURE)
            {
                printf("ERROR : Update Database Failure\n");
            }
            else
            {
                printf("INFO : Update Database is Successful\n");
            }
            break;

            /*Search Database */
        case 4:
            if (Search_database(arr) == FAILURE)
            {
                printf("ERROR : Search Database Failure\n");
            }
            else
            {
                printf("INFO : Search Database is Successful\n");
            }
            break;

            /*Save Database */
        case 5:
            if (Save_database(arr) == FAILURE)
            {
                printf("ERROR : Save Database Failure\n");
            }
            else
            {
                printf("INFO : Save Database is Successful\n");
            }
            break;
            /* exit from operation */
            case 6:
            exit(0);
            break;

            /*default case*/
        default:
            printf("ERROR : Enter Proper Choice\n");
            break;
        }
       
    }
}

void create_HT(hash_t *HT)
{
    /*run a loop upto size */
    for (int i = 0; i < 27; i++)
    {
        /* set index with i,value with -1, link with NULL */
        HT[i].index = i;
        // HT[i].value = -1;
        HT[i].link = NULL;
    }
}