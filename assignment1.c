/* ========================
   ||    Thomas Smith    ||
   ||      tsmith37      ||
   ||       CS 350       ||
   ||   Assignment One   ||
   ======================== */

#include <stdio.h>
#include <math.h>

void convInt(char[]);
void convFloat(char[]);
void parse(char[]);
void toUpper(char[]);
void toLower(char[]);
void reverseString(char[]);
void palindrome(char[]);
void reverseWords(char[]);
void subsetCheck(char[], char[]);
void partialCopy(char[], char);
void partCopyString(char*, char*, int, int);


int main(int argc, char *argv[])
{
  int choice = *(argv[argc-1])-48;

  if (((argv[argc-1][0])=='1') && ((argv[argc-1][1]=='0')))
    choice = 10;

  switch(choice)
    {
    case 1:
      convInt(argv[1]);
      break;
    case 2:
      convFloat(argv[1]);
      break;
    case 3:
      parse(argv[1]);
      break;
    case 4:
      toUpper(argv[1]);
      break;
    case 5:
      toLower(argv[1]);
      break;
    case 6:
      reverseString(argv[1]);
      break;
    case 7:
      palindrome(argv[1]);
      break;
    case 8:
      reverseWords(argv[1]);
      break;
    case 9:
      if(argc<4)
	printf("Error: parameters missing\n\n");
      else
	subsetCheck(argv[1],argv[2]);
      break;
    case 10:
      if(argc<4)
	printf("Error: parameters missing\n\n");
      else
	partialCopy(argv[1],*argv[2]);
      break;
    default:
      printf("Error: invalid function\n\n");
      break;
    }  

  return 0;

}

void convInt(char test[])
{
  int i=0, toReturn=0, current=0,isNegative=1;

  if (test[0] == '-')
    {
      i=1;
      isNegative=-1;
    }

  while ((test[i] != '\0') && (current!=-1))
    {
      if((test[i]>=48) && (test[i]<=57))
	current=test[i]-48;
      else
	{
	  current=-1;
	  printf("Error: the character %c is not supported in this operation\n\n", test[i]);
	}
      toReturn=(toReturn*10)+(isNegative*current);
      i++;
    } 
  if (current!=-1)
    printf("%d\n\n", toReturn);
}

void convFloat(char test[])
{
  int i=0;
  int current=0;
  int isNegative=1;
  int whole=0; 
  int decLoc = 0;
  double inter = 0;
  float decimal=0.0;
  float result=0.0;
  if (test[0] == '-')
    {
      i=1;
      isNegative=-1;
    }

  while ((test[i] != '\0') && (current!=-1) && (test[i] != '.'))
    {
      if((test[i]>=48) && (test[i]<=57))
	current=test[i]-48;
      else
	{
	  current=-1;
	  printf("Error: the character %c is not supported in this operation\n\n", test[i]);
	}
      whole=((whole*10)+(isNegative*current));
      i++;
    } 

  if (test[i] == '.')
    {
      decLoc=i;
      i++;
      while ((test[i] != '\0') && (current!=-1))
	{
	  if((test[i]>=48) && (test[i]<=57))
	    current=test[i]-48;
	  else
	    {
	      current=-1;
	      printf("Error: the character %c is not supported in this operation\n\n", test[i]);
	    }
	  inter=pow(10,decLoc-i);
	  decimal=decimal+(isNegative*current*inter);
	  i++;
	}
    }
  result = whole + decimal;
  if (current!=-1)
    printf("%2.5f\n\n", result);
}

void parse(char test[])
{
  char ints[100][100];
  int i=0;
  int count=0;
  int start=0;
  int end=0;
  int p=0;
  while (test[i]!='\0')
    {
      if ((test[i]>=48) && (test[i]<=57))
	{
	  start=i;
	  i++;
	  while ((test[i]>=48) && (test[i]<=57))
	    {
	      i++;
	    }
	  end=i;
	  count++;
	}
      partCopyString(ints[count],test,start,end-1);
      if (test[i]!='\0')
	i++;
    }
  for (p=1;p<=count;p++)
    convInt(ints[p]);
}

void toUpper(char test[])
{
  char final[100];
  int i=0;
  while (test[i] != '\0')
    {
      if ((test[i]>=97) && (test[i]<=122))
	final[i]=test[i]-32;
      else
	final[i]=test[i];
      i++;
    }
  final[i]='\0';
  printf("%s\n\n",final);
}

void toLower(char test[])
{
  char final[100];
  int i=0;
  while (test[i] != '\0')
    {
      if ((test[i]>=65) && (test[i]<=90))
	final[i]=test[i]+32;
      else
	final[i]=test[i];
      i++;
    }
  final[i]='\0';
  printf("%s\n\n",final);
}

void reverseString(char test[])
{
  int i=0;
  int j=0;
  char final[100];
  while (test[i] != '\0')
    i++;
  i--;
  while (i>=0)
    {
      final[j]=test[i];
      i--;
      j++;
    }
  final[j]='\0';
  printf("%s\n\n",final);
}

void palindrome(char test[])
{
  int i=0;
  int length=0;
  int j=0;
  int isPalindrome = 1;
  char final[100];
  while (test[i] != '\0')
    i++;
  length=i;
  i--;
  while (i>=0)
    {
      final[j]=test[i];
      i--;
      j++;
    }
  final[j]='\0';

  for (j=0;j<length;j++)
    {
      if (final[j] != test[j])
	isPalindrome=0;
    }

  if (isPalindrome==1)
    printf("Palindrome\n\n");
  else
    printf("Not a palindrome\n\n");
}

void reverseWords(char test[])
{
  char words[100][100];
  int start=0;
  int end=0;
  int i=0;
  int count=0;

  while (test[i] != '\0')
    {
      if(test[i] == ' ')
	{
	  end=i;
	  partCopyString(words[count],test,start,end-1);
	  start=end+1;
	  count++;
	}
      i++;
    }

  partCopyString(words[count],test,start,i);
  count++;

  for (i=count;i>0;i--)
    printf("%s ", words[i-1]);

  printf("\n\n");
}

void subsetCheck(char whole[], char part[])
{
  char subsets[100][100];
  int length_part=0;
  int length_whole=0;
  int check=0;
  int isSubset=0;
  int i=0;
  int j=0;

  while (part[i]!='\0')
    i++;
  length_part=i;

  i=0;
  while (whole[i]!='\0')
    i++;
  length_whole=i;

  for (i=0;i<=(length_whole-length_part);i++)
    partCopyString(subsets[i],whole,i,(i+length_part-1));
  
  for (i=0;i<=(length_whole-length_part);i++)
    {
      for (j=0;j<length_part;j++)
	{
	  if (subsets[i][j] == part[j])
	    isSubset++;
	  else
	    isSubset=0;
	}
      if (isSubset==length_part)
	check=1;
    }

  if (check==1)
    printf("True\n\n");
  else
    printf("False\n\n");
}

void partialCopy(char test[], char start)
{
  int toStart=-1;
  int i=0;
  int length=0;
  char copy[100];

  while(test[i] != '\0')
    {
      i++;
    }

  length=i;
  i=0;
  
  while ((test[i] != '\0') && (toStart==-1))
    {
      if (test[i] == start)
	toStart=i;
      i++;
    }

  if (toStart==-1)
    printf("Error: char not found\n\n");
  else
    {
      partCopyString(copy,test,toStart,length);
      printf("%s\n\n",copy);
    }
}

void partCopyString(char *copy, char *orig, int start, int end)
{
  int i;
  for(i=0;i<=(end-start);i++)
    {
      *copy++=*(orig+start);
      *orig++;
    }
  *copy = '\0';
}
