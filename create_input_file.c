#include <stdio.h>
#include <string.h>

#define MU 3.6
#define X 0.1
#define MU_ADD 0.2
#define X_ADD 0.3

char file_name[] = "01.in";
char dir[] = "./data/";

void add_filename()
{
    //  can only deal with 00~99.in
    file_name[1]++;
    if(file_name[1] == '9' + 1)
    {
        file_name[1] = '0';
        file_name[0]++;
    }
}

int main()
{
    float mu = MU, x = X;

    char full_name[50];
    while(mu < 4)
    {
        x = X;
        while(x < 1)
        {
            strcpy(full_name, dir);
            strcat(full_name, file_name);

            FILE *f = fopen(full_name, "w");
            fprintf(f, "%f %f", mu, x);

            x += X_ADD;
            add_filename();
            fclose(f);
        }
        mu += MU_ADD;
    }

    return 0;
}