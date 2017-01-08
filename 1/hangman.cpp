#include "hangman.h"
#include <iostream>
using namespace std;


int guessLetter(const std::string& word, char letter, char letters[]){
int found=0;
for(int i=0; i<word.length(); i++){
if(letter==word[i]){
letters[i]=word[i];
found++;
}
}
cout<<letters<< endl;
return found;
}

bool playHangman(std::string word, unsigned int maxWrong){
maxWrong=8;
int wordLength=word.length();
bool win=0;
int letterMatch;
int match=0;
char nextGuess;
char letters[wordLength];
int wrong=0;

for (int j=0;j<wordLength;j++){
letters[j]='*';
cout<<letters[j];
}

for(int k=0;wrong<maxWrong&&match<wordLength;k++){
	nextGuess=getNextGuess(letters, wordLength);
	letterMatch=guessLetter(word,nextGuess,letters);
	match+=letterMatch;
	if (letterMatch==0)
		wrong++;
}
if (match>=wordLength)
win=1;

return win;
}




