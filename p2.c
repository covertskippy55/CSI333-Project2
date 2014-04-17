/*Name : Dilan Samarasinghe
  Lab : Friday 11:30
  login: DS697678
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_WORD_LENGTH 16 // the maximum length of the array including space for eof
char word[MAX_WORD_LENGTH]; // create array
int i,l,j; //temp variables
int numVowels; //number of vowels in word
int length = 0; // stores the total length
int numWords = 0; // stores the number of words
int numPalindromes = 0; // stores the number of palindromes
int totalNumVowels = 0; // total number of vowels
int num10 = 0;
int num11 = 0;
int num12 = 0;
int num13 = 0;
int num14 = 0;
int num15 = 0; // stores the number of words that are between 10 and 15 inclusive. 
float avLength = 0; // stores the average length by dividing length by the number of words
float avNumVowels = 0; // stores the average number of vowels in the input by dividing number of vowels by number of words
int countThreeVowels = 0; // stores the number of occurences of three or more vowels

int vowel_count(char word[]); // function to calculate number of vowels
int is_palindrome(char word[]); // function to determine if the word is a palindrome

int main(void){
  printf("Please enter the text: \n ");
  fflush(stdout);
  /* Checks to see if EOF is reached, if not store the word into a char array then increment the number of words by one, add to the length the length of the word array */
  while(scanf("%s",word) == 1)
    {
      // checks to see if the last character is a punctuation and if it is, chose the length to be length of array - 1, otherwise its the length of the array
      if(word[(strlen(word)-1)]== '.'||word[(strlen(word)-1)]== ',' ||word[(strlen(word)-1)]== ';' \
	 ||word[(strlen(word)-1)]== '?' ||word[(strlen(word)-1)]== '!')
	{

	  l = strlen(word) -1;
	}
      else
	{
	  l = strlen(word);
	}
      // checks to see if the length is between 10 and 15 and if it is increment the variable that keeps track of it
      switch(l)
	{
	case 10:
	  num10++;
	  break;
	case 11:
	  num11++;
	  break;
	case 12:
	  num12++;
	  break;
	case 13:
	  num13++;
	  break;
	case 14:
	  num14++;
	  break;
	case 15:
	  num15++;
	  break;
	default:
	  break;
	}
      // add to the length the length of the given array
      length+=( strlen(word));
      numWords++;
      // check to see if the last character in the word is a punctuation, and if so decrease the total length by one
      if(word[(strlen(word)-1)]== '.'||word[(strlen(word)-1)]== ',' ||word[(strlen(word)-1)]== ';' ||word[(strlen(word)-1)]== '?' ||word[(strlen(word)-1)]== '!')
      {
     
       length--;
      }
      totalNumVowels+= vowel_count(word); // add to the number of vowels the vowel count of the current work
      // check to see if the number of vowels is higher than 3 in the word and if so add one to the counter for that
      if(vowel_count(word)>=3)
      {
	countThreeVowels++;
      }
      // check to see if a word is a palidrome and if it is add one to counter
      if(is_palindrome(word) == 1)
	{
	  numPalindromes++;
	}

    }
  avLength =((float)length/numWords); // calculate avergae number of words
  avNumVowels = ((float) totalNumVowels/numWords); // calculate the average number of vowels
  // print statements for all the output
  printf("The average length of a word is: ");
   printf("%.2f \n", avLength);
  printf("The average number of vowels is: ");
   printf("%.2f \n", avNumVowels);
  printf("The number of words containing atleast three vowels is: ");
   printf("%i \n" , countThreeVowels);
  printf("The number of words which are palidromes is: ");
   printf("%i \n", numPalindromes);
  printf(" The number of words of length 10 = ");
   printf("%i \n", num10);
  printf(" The number of words of length 11 = ");
   printf("%i \n", num11);
  printf(" The number of words of length 12 = ");
   printf("%i \n", num12);
  printf(" The number of words of length 13 = ");
   printf("%i \n", num13);
  printf(" The number of words of length 14 = ");
   printf("%i \n", num14);
  printf(" The number of words of length 15 = ");
   printf("%i \n", num15);
  return 0;
}
/* vowel_count takes in an array of chars and returns the number of vowels in the array */
int vowel_count(char word[]){
  numVowels = 0;
  // loop through the array looking for vowels, if one is found increment the counter
  for(i =0; i < strlen(word); i++)
    {
      word[i] = tolower(word[i]);
      if(word[i] == 'a' ||(word[i]) == 'e' ||(word[i]) == 'i' ||(word[i]) == 'o' ||(word[i]) == 'u')
	{
	  numVowels++;
	}
    }
  return numVowels;
}
/* is_palindrome takes in an array of chars and returns a 1 if its a palidrome or a 0 if its not */
int is_palindrome(char word[]){
  // if the array is only 1 character then its automatically a palindrome and thus return 1
  if(strlen(word) == 1){ return 1;}
  // if the last character is a punctuation set j to be the index before it, otherwise j is the index of the last character
  if(word[(strlen(word)-1)]== '.'||word[(strlen(word)-1)]== ',' ||word[(strlen(word)-1)]== ';' ||word[(strlen(word)-1)]== '?' ||word[(strlen(word)-1)]== '!')
    {

      j = strlen(word)-2;
    }
  else{ j = strlen(word)-1;}
  // loop through the array comparing the first and the last characters, keep looking until both hits the middle of the array, if at any point they are not the same reutn 0
  for(i = 0; i < strlen(word)/2; j--,i++)
    {
      if(word[i] != word[j])
	  {
	    return 0;
	  }
       
    }
  return 1;
}
