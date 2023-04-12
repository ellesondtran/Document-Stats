//Elleson Tran
//Roberts
//Document Statistics
//Analyzes a document
//FINAL

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {

  ifstream file("input.txt");//declared and opened
  vector<string> distinctWords;

  //variables
  int totalWords = 0;
  int shortest, longest;
  double average, totalChar = 0, distinct = 0;
  bool answer;


  if(file.fail()){//checks if it fails to open
    cout<<endl<<"Error!";
  }
  else{//if the file does open
    string text;

    //to intialize the shortest, longest variables, and the first word in the vector
    file>>text;
    totalChar = totalChar + text.size();
    totalWords = totalWords + 1;
    distinctWords.push_back(text);
    distinct = distinct + 1;
    shortest = text.size();
    longest = text.size();

    while(file>>text){
      totalChar = totalChar + text.size();//adds each length of the word to the total
      totalWords = totalWords + 1;//adds one to the total 

      if(shortest > text.size()){//if the current text is smaller than the smallest text, it takes it spot
        shortest = text.size();
      }
      if(longest < text.size()){//if the current text is bigger than the biggest text, it takes it spot
        longest = text.size();
      }
      answer = false;

      for(int x = 0; x < distinctWords.size(); x++){//goes through the all the unique words
        if(text == distinctWords[x]){//if the current word is the same as any of the unique words
          answer = true;//sets to true
        }
      }
      if(answer == false){//if it goes through the whole forloop without finding a duplicate word, it adds it to the unique words
        distinctWords.push_back(text);
        distinct = distinct + 1;
      }

    }
  }
  average = totalChar/totalWords;//average word length

  cout<<endl;
  cout<<"Document Report:"<<endl;
  cout<<"Words: "<<totalWords<<endl;
  cout<<"Shortest word length: "<<shortest<<endl;
  cout<<"Longest word length: "<<longest<<endl;
  cout<<"Average word length: "<<average<<endl;
  cout<<"Total characters (without counting spaces): "<<totalChar<<endl;
  cout<<"Distinct Words: "<<distinct;

  file.close();//closed
}