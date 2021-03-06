#include <stdio.h>

struct edge
{
  int vertexIndex;
  int vertexWeight;
  struct edge *edgePtr;
}edge;

struct vertex
{
  int vertexKey;
  struct edge *edgePtr;
  struct vertex *vertexPtr;
}vertex;

int main()
{
  FILE *toRead;
  int line[4];
  int k;
  int i;
  int j;
  struct vertex v[4];
  struct edge e[4];
  int count=0;
  int edgeCount=0;
  int numVert=4;

  toRead = fopen("./test", "r");

  for (i=0;i<numVert;i++)
    v[i].vertexKey=i;

  for (i=0;i<numVert-1;i++)
    {
      v[i].vertexPtr=&v[i+1];
    }

  v[i].vertexPtr=NULL;
    for (k=0;k<numVert;k++)
    {
      count=edgeCount;
      for (i=0;i<numVert;i++)
	{
	  fscanf(toRead, "%d", &line[i]);

	  printf("%d ", line[i]);
	    if ((count==1) || (line[i]==-1))
	      {}
	    else
	      {
		e[edgeCount].vertexIndex=i;
		e[edgeCount].vertexWeight=line[i];
		edgeCount++;
		e[edgeCount-1].edgePtr=&e[edgeCount];
	      }
	}
      printf("\n");
      e[edgeCount].edgePtr=NULL;
      v[k].edgePtr=&e[count];
    }

    fclose(toRead);

    printf("Checking4\n");

    return 0;    
}
