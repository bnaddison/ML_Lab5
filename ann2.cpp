// ADDBRA001 ML Lab 5

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <memory>
#include <string>
#include <math.h>

using namespace std;

vector <vector<pair<float,float> > > hidden_layer_nodes;

float sigmoid (float net) {
  float o = 1/(1 + exp(-net) );
  return o;
}

float output(vector <pair<float,float> > inputs, float b) {
  float o = 0;
  for (int i = 0; i < inputs.size(); i++) {
    o += (inputs[i].first)*(inputs[i].second);
  }
  o += b;

  float result = sigmoid(o);

  return result;
}

float error_function(float o, float t) {
  float e = 0.5f*(pow((t - o),2));
  return e;
}

int main () {

  vector <float> inputs = {1.3f, 2.7f, 0.8f};
  vector <float> weights1 = {0.1f, 0.2f, 0.5f};
  vector <float> weights2 = {-0.4f, 1.0f, -0.6f};

  vector < pair<float,float> > node1;
  vector < pair<float,float> > node2;

  for (int i = 0; i < inputs.size(); i++) {
    pair<float,float>input1(inputs[i], weights1[i]);
    pair<float,float>input2(inputs[i], weights2[i]);

    node1.push_back(input1);
    node2.push_back(input2);
  }

  float output1 = output(node1,  0.1f);
  float output2 = output(node2, -0.3f);

  cout << "Question 1:" << endl << "Hidden Layer Neuron 1 = " << output1 << endl << "Hidden Layer Neuron 2 = " << output2 << endl << endl;

  pair <float,float> final1(output1, 0.8f);
  pair <float,float> final2(output2, 1.0f);

  node1.clear();
  node1.push_back(final1);
  node1.push_back(final2);

  float out = output(node1, -0.3f);

  cout << "Question 2:" << endl << "Output Neuron = " << out << endl << endl;

  float error = error_function(out, 0.36f);

  cout << "Question 3:" << endl << "Mean Squared Error = " << error << endl << endl;




  //cout << output1 << " " << output2 << endl;




  return 0;




}
