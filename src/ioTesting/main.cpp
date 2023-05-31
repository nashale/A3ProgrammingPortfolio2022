#include <iostream>
#include <fstream>
#include <random>
#include <vector>
using namespace std;

int main() {

  random_device rd;
  mt19937 rng(rd());
  vector<string> questions;
  
  ifstream input_file("input.txt");
  ofstream output_file("output.txt", ios::app);
  string line;
  while(getline(input_file,line)) {
    questions.push_back(line);
  }
  
  uniform_int_distribution<int> dist(0, questions.size());
  int randomIndex = dist(rng);
  string randomQuestion = questions[randomIndex];

  cout << randomQuestion;
  string inputAnswer;
  getline(cin, inputAnswer);

  output_file << randomQuestion << endl;
  output_file << inputAnswer << endl;

  input_file.close();
  output_file.close();

  return 0;
}