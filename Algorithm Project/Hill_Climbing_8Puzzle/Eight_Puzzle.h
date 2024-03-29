#ifndef EIGHT_PUZZLE_H_INCLUDED
#define EIGHT_PUZZLE_H_INCLUDED

// ================================================================================
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

struct Node
{
    vector<int> state_table;
    Node *children[4];
    Node *parent;
    int heuristic;
    int distance;
    int empty_index;
};

void vectorDisplay(vector<int> state, ofstream& outFile);
void ReadFile(vector<int> &begin_state, vector<int> &goal_state);
void createRoot(Node *root, vector<int> state, vector<int> goal);
int misplacedHeuristic(Node *node, vector<int> goal_state);
int manhattanHeuristic(Node *node, vector<int> goal_state);
bool isGoal(Node *node, vector<int> goal_state);
void findIndex(Node *node);
bool Move(Node *parent, Node *child, char moving, vector<int> goal_state);
Node *createChild(Node *parent, vector<int> goal_state);
Node *hillClimbing(Node *node, vector<int> goal_state);
int ifDuplicateHueristic(Node **node, int minHeuristic);
int Heuristic(Node *node, vector<int> goal_state);

// ================================================================================

#endif // EIGHT_PUZZLE_H_INCLUDED
