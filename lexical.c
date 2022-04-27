#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char ch;
    char operators[] = {"*+=/%-"};
    char brackets[] = {"(){}"};
    char key_word[12][10] = {"int", "float", "char", "void", "double", "return", "for", "while", "do", "switch", "if", "else"};
    char buffer[15];
    int indexofbuffer = 0;
    int flag = 0;
    FILE *fp,*bp;
    fp = fopen("input.txt", "r");
    bp = fopen("output.txt","w");
    while ((ch = fgetc(fp)) != EOF)
    {
        for (int i = 0; i < 6; i++)
        {
            if (ch == operators[i])
            {
                printf("%c is a Operator\n", ch);
                fprintf(bp,"%c is a Operator\n", ch);
            }
        }
        for (int i = 0; i < 4; i++)
        {
            if (ch == brackets[i])
            {
                printf("%c is a brakcet\n", ch);
                fprintf(bp,"%c is a brakcet\n", ch);
            }
        }

        if (isalnum(ch))
        {
            buffer[indexofbuffer++] = ch;
        }
        else if ((ch == ' ' || ch == '\n') && indexofbuffer != 0)
        {
            buffer[indexofbuffer] = '\0';
            indexofbuffer = 0;

            for (int i = 0; i < 12; i++)
            {
                if (strcmp(key_word[i], buffer) == 0)
                {
                    printf("%s is a keyword\n", buffer);
                    fprintf(bp,"%s is a keyword\n", buffer);
                    flag=1;
                }
            }

            if(!flag){
                    printf("%s is a identifier\n", buffer);
                    fprintf(bp,"%s is a identifier\n", buffer);
            }
        }
    }

    fclose(fp);
    return 0;
}



