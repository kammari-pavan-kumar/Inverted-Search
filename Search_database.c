#include "Inverted_search.h"
#include <string.h>
// Function to search a word in the database
int Search_database(hash_t *arr)
{
    char word[100];
    /*read a word from user */
    printf("Enter word to search : ");
    scanf("%s",word);

    /* find index of word for hash table */
    int index;
    if(word[0]>='a'&&word[0]<='z')
    {
        index = word[0] - 'a';
    }
    else if(word[0]>='A'&&word[0]<='Z')
    {
        index = word[0] - 'A';
    }
    else
    {
        index = 26;
    }
    /*check the hashtable[index].link is NULL or not*/
    if(arr[index].link == NULL)
    {
        /*if null print error message and return*/
        printf("ERROR : DATA NOT FOUND\n");
        return FAILURE;
    }
    else
    {
        /*if not null create m_temp for traversal and run loop until m_temp reaches null*/
        main_node *m_temp = arr[index].link;
        while(m_temp!=NULL)
        {
            /* compare m_temp word and word same or not */
            /*if same print word,file count and loop s_temp upto null and print filename and wordcount*/
            if(strcmp(m_temp->word,word)==0)
            {
                printf("Word %s is present in %d file/s\n",m_temp->word,m_temp->file_count);
                sub_node *s_temp = m_temp->sub_node_link;
                while (s_temp != NULL)
                {
                    printf("In file: %s %d time/s\n",s_temp->file_name,s_temp->word_count);
                    s_temp = s_temp->sub_node_link;
                }
                printf("\n");
                return SUCCESS;
            }
            /*move to next node*/
            m_temp = m_temp->main_node_link;
        }
        printf("NOT FOUND\n"); 
        return FAILURE;

    }
}