#include "Inverted_search.h"
#include <string.h>

// Function to display the database
int Display_database(hash_t *arr)
{
    printf("|index|\t|word|\t\tfile count\tfile/s file\tfile name\tword count\n");
    /*loop until hash table index ends*/
    for(int i=0;i<27;i++)
    {
        /*check hashtable(index).link is null or not,if it is null skip the data*/
        if(arr[i].link == NULL)
        {
            continue;
        }
        /*if not create m_temp node and traverse */
        else
        {
            main_node *m_temp = arr[i].link;
            while(m_temp!=NULL)
            {
                /*print word, file count and index */
                printf("[%2d]\t[%-8s]\t%3d\t\t",i,m_temp->word,m_temp->file_count);
                /*create s_temp and traverse until null and print filename,wordcount*/
                sub_node *s_temp = m_temp->sub_node_link;
                printf("files/s: File:  ");
                while (s_temp != NULL)
                {
                    printf("%s\t%3d\t     ",s_temp->file_name,s_temp->word_count);
                    s_temp = s_temp->sub_node_link;
                }
                printf("\n");
                /*move to next node*/
                m_temp = m_temp->main_node_link;
            }
        }
    }
    return SUCCESS;
}