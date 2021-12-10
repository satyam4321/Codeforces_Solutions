#include<stdio.h> 
#include<conio.h> 

void Intersection(int set1[10],int set2[10],int m,int n); 
void main() 
{ 
 int a[10],b[10],m,n,i,j; 
 printf("Enter the number of elements in first set: "); 
 scanf("%d",&m); 
 printf("Enter the elements: "); 
 for(i=0;i<m;i++)  
  scanf("%d",&a[i]); 

 printf("Enter the number of elements in second set: "); 
 scanf("%d",&n); 
 printf("Enter the elements: "); 
 for(i=0;i<n;i++)  
  scanf("%d",&b[i]); 

   Intersection(a,b,m,n); 
} 
void Intersection(int a[10],int b[10],int m,int n) 
{ 
 int c[20],i,j,k=0,flag=0; 
 for(i=0;i<m;i++) 
 { 
  flag=0; 
  for(j=0;j<n;j++) 
  { 
   if(a[i]==b[j]) 
   { 
    flag=1; 
    break; 
   } 
  } 
  if(flag==1) 
  { 
   c[k]=a[i]; 
   k++; 
  } 
 } 
 if(k==0)
 {
  printf("Resultant set is null set! ");
 }else{
  printf("Element of resultant set "); 
  for(i=0;i<k;i++) 
  { 
   printf("%d ",c[i]); 
  } 
 }
}