#include "Inverted_search.h"
#include <string.h>

// Function to save database contents into a file
int Save_database(hash_t *arr)
{
    char file_name[100];
    /*read filename from user input*/
    printf("Enter file name : ");
    scanf("%s", file_name);
    /*check file extendion is .txt or not*/
    char *cmp = strstr(file_name, ".txt");
    if (cmp)
    {
        if (strcmp(cmp, ".txt") != 0)
        {
            printf("ERROR : %s IS NOT .txt FILE\n", file_name);
            return FAILURE;
        }
    }
    /*open file in read mode*/
    FILE *fptr = fopen(file_name,"w");
    if(fptr==NULL)
    {
        printf("ERROR : UNABLE TO OPEN FILE\n");
        return FAILURE;
    }
    /*run loop until hashtable index ends*/
    for (int i = 0; i < 27; i++)
    {
        /*if hashtable index is null continue */
        if (arr[i].link == NULL)
        {
            continue;
        }
        /*if not create m_temp for traversal */
        else
        {
            main_node *m_temp = arr[i].link;
            /*traverse m_temp unti end and print word,file_count and index*/
            while (m_temp != NULL)
            {
                fprintf(fptr, "#%d;%s;%d;", i, m_temp->word, m_temp->file_count);
                /*create s_temp traverse until null */
                sub_node *s_temp = m_temp->sub_node_link;
                while (s_temp != NULL)
                {
                    // Write file name and word count into file
                    fprintf(fptr, "%s;%d;",s_temp->file_name, s_temp->word_count);
                    s_temp = s_temp->sub_node_link;
                }
                /*write end marker and add newline*/
                fprintf(fptr,"#\n");
                /*move to next main node*/
                m_temp = m_temp->main_node_link;
            }
        }
    }

    /*close the file and return success*/
    fclose(fptr);
    return SUCCESS;
}