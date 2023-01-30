#include <stdio.h> 
#include <unistd.h> 
int main()
{
int k;
for(k=0; k<10; k=k+3){ fork(); }
return 0;
}
