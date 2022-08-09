#include <iostream>
#include<vector>
//for finding minimum element
#include<algorithm> 
using namespace std;

int find(char frame[], char page_no)
{
    int i = 0;
    while (frame[i] != '\0')
    {
        if (page_no == frame[i])
        {
            return 1;
        }
        i++;
    }
    return 0;
}

//find the position to be replaced
int future_position(char reference[], char frame[])
{
    vector<int> position;
    int i = 0, j = 0, len = 0;

    //get the length of the reference string
    while (reference[len] != '\0')
    {
        len++;
    }

    //traversing the future reference string
    while (frame[j] != '\0')
    {
        i = 0;
        while (reference[i] != '\0')
        {
            if (reference[i] == frame[j])
            {
                position.push_back(i);
                break;
            }
            i++;
        }
        if (i == len)
        {
            position.push_back(128);
        }
        j++;
    }

    //return the maximum index element in the future reference string
    return max_element(position.begin(), position.end()) - position.begin();
}

void optimal(int n_frames, char reference[])
{
    //to count the no. of page faults
    int page_fault = 0;

    //creating an array to store the page no. in free frames
    //initializing with null character
    //so that no garbage value will take place
    char frame[n_frames + 1]={'\0'};

    //no. of empty frames
    int empty = n_frames;
    char page_no;

    //traversing the reference string
    int i = 0, j = 0,k=0;
    while (reference[i] != '\0')
    {
        //store the page no.
        if (reference[i] != ' ')
        {
           
            page_no = reference[i];
            //printf("%c ",page_no);

            //if page already present in frame
            if (find(frame, page_no))
            {
                //printf("I am inside find if.\n");
                
            }
            else if (empty != 0)
            {
                frame[j] = page_no;
                page_fault++;
                empty--;
                j++;
            }
            else if (empty == 0)
            {
                int index = future_position(reference + i, frame);
                //replace the element at the index
                frame[index] = page_no;
                page_fault++;
            }

            printf("\nIntermediate frame\n");
            k=0;
            while(frame[k]!='\0')
            {
                printf("%c ",frame[k]);
                k++;
            }
        }
        i++;
    }
    printf("\nNo. of page faults are %d\n", page_fault);
}

int main(void)
{
    int n_frames = 0;
    char temp;

    //input the no. of free frames
    printf("Enter the no. of free frames: ");
    scanf("%d", &n_frames);
    scanf("%c", &temp); //temp statement to clear buffer

    //input the reference string
    char reference[100];
    printf("Enter the reference string: ");
    //%[^\n] is a scanset character in C.
    //%[^\n] means read everything until newline is found.
    scanf("%[^\n]", reference);
    //printf("%s\n",reference);

    optimal(n_frames,reference);

    return 0;
}