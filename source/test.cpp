#include "stdio.h"
#include "stdlib.h"
#include<math.h>
using namespace std;

int main()
{
	char *p[]={"zsxdzx","sdf","ZAcds"};
	int s1 = sizeof(p)/sizeof(p[0]);
	int s2 = sizeof(p)/sizeof(*p);
	printf("%d\n",s1);
        printf("%d\n",s2);
	printf("%c\n",p[1][0]);
	return 0;
}
