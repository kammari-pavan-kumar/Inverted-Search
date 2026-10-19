#include "Inverted_search.h"
#include <string.h>
/*Function to validate command line arguments and files */
int validation(file_name_node **f_head, int argc, char *argv[])
{
    int i = 1, j,flag = 0;
    /* run loop for Command line args */
    while (i < argc)
    {
        flag = 0;
        // Check whether file extension contains .txt
        char *cmp = strstr(argv[i], ".txt");
        if (cmp)
        {
            if (strcmp(cmp, ".txt") != 0)
            {
                // Print error if extension is invalid
                printf("INFO : %s is not '.txt' file and failed to insert file name %s\n", argv[i],argv[i]);
                i++;
                continue;
            }
        }
        // If .txt extension is not found print error message
        else
        {
            printf("INFO : %s is not '.txt' file and failed to insert file name %s\n", argv[i],argv[i]);
            i++;
            continue;
        }

        // open file in read mode
        FILE *fptr = fopen(argv[i], "r");
        /*check file opened failed */
        if (fptr == NULL)
        {
            printf("ERROR : FILE %s NOT PRESENT\n", argv[i]);
            i++;
            continue;
        }
        fclose(fptr);

        // Check for duplicate file names
        for (j = 1; j < i; j++)
        {
            if (strcmp(argv[i], argv[j]) == 0)
            {
                flag = 1;
                printf("ERROR : DUPLICATE FILE  %s\n", argv[i]);
            }
        }
        /*if flag = 0 then insert files in to SLL */
        if(flag == 0)
        {
            file_insert_at_last(f_head, argv[i]);
            printf("Successful: inserting file name : %s into file linked list\n", argv[i]);
        }
        i++;
    }
    print_list(f_head);
    return SUCCESS;
}

// Function to insert file name node at the end of linked list
int file_insert_at_last(file_name_node **head, char *fname)
{
    /*allocate memory for new file node and check memory allocation failure*/
    file_name_node *new = malloc(sizeof(file_name_node));

    if (new == NULL)
    {
        return FAILURE;
    }

    // Allocate memory for file name string
    new->file_name = malloc(strlen(fname) + 1);
    // Copy file name into node
    strcpy(new->file_name, fname);
    // Initialize next link as NULL
    new->file_name_link = NULL;

    // check list is empty
    if (*head == NULL)
    {
        *head = new;
        return SUCCESS;
    }
    // if list contains nodes traverse till end and add new node
    else
    {
        file_name_node *temp = *head;
        while (temp->file_name_link != NULL)
        {
            temp = temp->file_name_link;
        }
        temp->file_name_link = new;
        return SUCCESS;
    }
}


/*function to create database */
int Create_DataBase(hash_t *arr, file_name_node **f_head)
{

    int index;
    /*create a f_temp node by assigning f_head pointer */
    file_name_node *f_temp = *f_head;
    /*traverse f_temp until NULL */
    while (f_temp != NULL)
    {
        /*open file in read mode */
        FILE *fptr = fopen(f_temp->file_name, "r");
        if (fptr == NULL)
        {
            printf("ERROR : ERROR IN OPENING FILE\n");
            f_temp = f_temp->file_name_link;
            continue;
        }
        char word[100];
        /*read a word from file*/
        while (fscanf(fptr, "%s", word) != EOF)
        {
            /*find the index of word*/
            if (word[0] >= 'a' && word[0] <= 'z')
            {
                index = word[0] - 'a';
            }
            else if (word[0] >= 'A' && word[0] <= 'Z')
            {
                index = word[0] - 'A';
            }
            else
            {
                index = 26;
            }

            // Create temporary pointer for main node traversal
            main_node *m_temp = arr[index].link;
            /*check hashtable(index) link is null or not */
            if (arr[index].link == NULL)
            {
                /*if null create main node and update the word,file count and main node link*/
                main_node *new_main = malloc(sizeof(main_node));
                new_main->word = malloc(strlen(word) + 1);
                strcpy(new_main->word, word);

                new_main->file_count = 1;

                new_main->main_node_link = NULL;
                new_main->sub_node_link = NULL;

                /*create subnode update filename,wordcount,subnode link*/
                sub_node *new_sub = malloc(sizeof(sub_node));
                new_sub->file_name = malloc(strlen(f_temp->file_name) + 1);
                strcpy(new_sub->file_name, f_temp->file_name);
                new_sub->word_count = 1;
                new_sub->sub_node_link = NULL;

                new_main->sub_node_link = new_sub;

                /*update hash table(index).link with main node address */
                arr[index].link = new_main;
            }
            else
            {
                // main node traversal until NULL
                while (m_temp != NULL)
                {

                    /*check m_temp->word and word same or not*/
                    if (strcmp(m_temp->word, word) == 0)
                    {
                        /*if same,check f_temp file name and s_temp filename same or not and inc wordcount*/
                        sub_node *s_temp = m_temp->sub_node_link;
                        /*traverse subnode until NULL*/
                        while (s_temp != NULL)
                        {
                            if (strcmp(f_temp->file_name, s_temp->file_name) == 0)
                            {
                                s_temp->word_count++;
                                break;
                            }
                            s_temp = s_temp->sub_node_link;
                        }
                        // If file not found in sub node list
                        if (s_temp == NULL)
                        {
                            // Create new sub node
                            sub_node *new_sub = malloc(sizeof(sub_node));
                            // Allocate memory for file name and Copy file name
                            new_sub->file_name = malloc(strlen(f_temp->file_name) + 1);
                            strcpy(new_sub->file_name, f_temp->file_name);

                            /*update word count and link */
                            new_sub->word_count = 1;
                            new_sub->sub_node_link = NULL;

                            /* insert subnode at last */
                            insert_at_last_sub(&m_temp->sub_node_link, new_sub);
                            // Increment file count
                            m_temp->file_count++;
                        }
                        break;
                    }
                    // Move to next main node
                    m_temp = m_temp->main_node_link;
                }

                // If word not found in main node list
                if (m_temp == NULL)
                {
                    /*create main node and update the word,file count and main node link*/
                    main_node *new_main = malloc(sizeof(main_node));
                    new_main->word = malloc(strlen(word) + 1);
                    strcpy(new_main->word, word);

                    new_main->file_count = 1;

                    new_main->main_node_link = NULL;
                    new_main->sub_node_link = NULL;

                    // Create new sub node
                    sub_node *new_sub = malloc(sizeof(sub_node));
                    // Allocate memory for file name and Copy file name
                    new_sub->file_name = malloc(strlen(f_temp->file_name) + 1);
                    strcpy(new_sub->file_name, f_temp->file_name);
                    /*update word count and link */
                    new_sub->word_count = 1;
                    new_sub->sub_node_link = NULL;
                    new_main->sub_node_link = new_sub;
                    /* insert subnode at last */
                    insert_at_last_main((main_node **)&arr[index].link, new_main);
                }
            }
        }
        // Close current file
        fclose(fptr);
        // Move to next file node
        f_temp = f_temp->file_name_link;
    }
    return SUCCESS;
}

void print_list(file_name_node **f_head)
{
    // check list is empty or not
    file_name_node *f_print = *f_head;
    if (f_print == NULL)
    {
        printf("INFO : List is empty\n");
    }
    // traverse till end and print data
    else
    {
        while (f_print)
        {
            printf("%s -> ", f_print->file_name);
            f_print = f_print->file_name_link;
        }

        printf("NULL\n");
    }
}