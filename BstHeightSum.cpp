// https://open.kattis.com/problems/bst

#include <iostream>
#include <vector>

using namespace std;

struct Node
{
  int val;
  struct Node *l;
  struct Node *r;
};

Node *CreateNode(int val)
{
  Node *node = new Node;

  node->val = val;
  node->l = NULL;
  node->r = NULL;

  return node;
}

void FindPlaceAndInsert(Node *root, int val, int &height)
{
  if (root == NULL)
    return;

  height++;
	
  if (val < root->val)
  {
    if (root->l == NULL)
      root->l = CreateNode(val);
    else
      FindPlaceAndInsert(root->l, val, height);
  }
  else
  {
    if (root->r == NULL)
      root->r = CreateNode(val);
    else
      FindPlaceAndInsert(root->r, val, height);
  }
}

int InsertNode(Node **root, int val, int existingHeight)
{
  if (*root == NULL)
  {
    *root = CreateNode(val);
    return 0;
  }

  int newHeight = 0;
  FindPlaceAndInsert(*root, val, newHeight);

  return existingHeight + newHeight;
}

vector<int> BuildTreeAndGetHeight(vector<int> input)
{
  vector<int> output;

  Node *tree = NULL;
  int height = 0;
  for (int i = 0; i < input.size(); i++)
  {
    height = InsertNode(&tree, input[i], height);
    output.push_back(height);
  }

  return output;
}

void PrintVector(vector<int> output)
{
  for (int i = 0; i < output.size(); i++)
    cout << output[i] << endl;

  cout << endl;
}

int main()
{
  vector<int> arr1 = {1, 2, 3, 4};
  vector<int> output1 = BuildTreeAndGetHeight(arr1);
  PrintVector(output1);

  vector<int> arr2 = { 3, 2, 4, 1, 5 };
  vector<int> output2 = BuildTreeAndGetHeight(arr2);
  PrintVector(output2);

  vector<int> arr3 = { 3, 5, 1, 6, 8, 7, 2, 4	};
  vector<int> output3 = BuildTreeAndGetHeight(arr3);
  PrintVector(output3);

  getchar();

  return 0;
}
