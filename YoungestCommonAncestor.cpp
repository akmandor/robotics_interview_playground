/*
##############################################
#          Coding Interview Questions
#      Created/Modified on: August 23, 2019
#           Author: Munir Jojo-Verge
##############################################
 */

/*
You're given three inputs, all of which are instances of a class that have an "ancestor" property pointing to their youngest ancestor.
The first input is the top ancestor in an ancestral tree (i.e., the only instance that has no ancestor), 
and the other two inputs are descendants in the ancestral tree. 
Write a function that returns the youngest common ancestor to the two descendants.

Sample input: Node A, Node E, Node I (from the ancestral tree below)
       A
     /   \
    B     C
   / \   / \
  D   E F   G
 / \
H   I

Sample output: Node B
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class AncestralTree
{
public:
    char name;
    AncestralTree *ancestor;

    AncestralTree(char name)
    {
        this->name = name;
        this->ancestor = NULL;
    }

    void addAsAncestor(vector<AncestralTree *> descendants);
};

void AncestralTree::addAsAncestor(vector<AncestralTree *> descendants)
{
    for (AncestralTree *descendant : descendants)
    {
        descendant->ancestor = this;
    }
}

// Time complexity O(A+B), Where A is the depth of descendent One and B is the depth of descendent B.
// Worse case this is max depth for both and therefore this becomes O(2D) => O(D) where D is the max depth of the tree.
AncestralTree* getYoungestCommonAncestor(
    AncestralTree* topAncestor,
    AncestralTree* descendantOne,
    AncestralTree* descendantTwo)
{
    // Write your code here.
    unordered_map<char, bool> desc_One_linage;

    // The linage starts with yourself.
    desc_One_linage.insert({descendantOne->name, true});

    AncestralTree* ancestor = descendantOne->ancestor;    
    while (ancestor != NULL)
    {
        desc_One_linage.insert({ancestor->name, true});
        ancestor = ancestor->ancestor;
    }
    
    AncestralTree* root;
    ancestor = descendantTwo;
    while (ancestor != NULL)
    {
        if (desc_One_linage.find(ancestor->name) != desc_One_linage.end())
            return ancestor;

        root = ancestor;
        ancestor = ancestor->ancestor;
    }

    return root;
}

int main()
{
    unordered_map<char, AncestralTree *> ancestralTrees;
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (char a : alphabet)
    {
        ancestralTrees.insert({a, new AncestralTree(a)});
    }

    ancestralTrees.at('A')->addAsAncestor({
        ancestralTrees.at('B'),
        ancestralTrees.at('C'),
        ancestralTrees.at('D'),
        ancestralTrees.at('E'),
        ancestralTrees.at('F'),
    });
    ancestralTrees.at('B')->addAsAncestor({
        ancestralTrees.at('G'),
        ancestralTrees.at('H'),
        ancestralTrees.at('I'),
    });
    ancestralTrees.at('C')->addAsAncestor({
        ancestralTrees.at('J'),
    });
    ancestralTrees.at('D')->addAsAncestor({
        ancestralTrees.at('K'),
        ancestralTrees.at('L'),
    });
    ancestralTrees.at('F')->addAsAncestor({
        ancestralTrees.at('M'),
        ancestralTrees.at('N'),
    });
    ancestralTrees.at('H')->addAsAncestor({
        ancestralTrees.at('O'),
        ancestralTrees.at('P'),
        ancestralTrees.at('Q'),
        ancestralTrees.at('R'),
    });
    ancestralTrees.at('K')->addAsAncestor({
        ancestralTrees.at('S'),
    });
    ancestralTrees.at('P')->addAsAncestor({
        ancestralTrees.at('T'),
        ancestralTrees.at('U'),
    });
    ancestralTrees.at('R')->addAsAncestor({
        ancestralTrees.at('V'),
    });
    ancestralTrees.at('V')->addAsAncestor({
        ancestralTrees.at('W'),
        ancestralTrees.at('X'),
        ancestralTrees.at('Y'),
    });
    ancestralTrees.at('X')->addAsAncestor({
        ancestralTrees.at('Z'),
    });

    AncestralTree *yca;

    cout << "Test Case 1: ";
    yca = getYoungestCommonAncestor(ancestralTrees.at('A'), ancestralTrees.at('A'), ancestralTrees.at('B'));
    cout << ((yca == ancestralTrees.at('A')) ? "PASS" : "FAIL") << endl;

    cout << "Test Case 2: ";
    yca = getYoungestCommonAncestor(ancestralTrees.at('A'), ancestralTrees.at('B'), ancestralTrees.at('F'));
    cout << ((yca == ancestralTrees.at('A')) ? "PASS" : "FAIL") << endl;

    cout << "Test Case 3: ";
    yca = getYoungestCommonAncestor(ancestralTrees.at('A'), ancestralTrees.at('G'), ancestralTrees.at('M'));
    cout << ((yca == ancestralTrees.at('A')) ? "PASS" : "FAIL") << endl;

    cout << "Test Case 4: ";
    yca = getYoungestCommonAncestor(ancestralTrees.at('A'), ancestralTrees.at('U'), ancestralTrees.at('S'));
    cout << ((yca == ancestralTrees.at('A')) ? "PASS" : "FAIL") << endl;

    cout << "Test Case 5: ";
    yca = getYoungestCommonAncestor(ancestralTrees.at('A'), ancestralTrees.at('Z'), ancestralTrees.at('M'));
    cout << ((yca == ancestralTrees.at('A')) ? "PASS" : "FAIL") << endl;

    cout << "Test Case 6: ";
    yca = getYoungestCommonAncestor(ancestralTrees.at('A'), ancestralTrees.at('O'), ancestralTrees.at('I'));
    cout << ((yca == ancestralTrees.at('B')) ? "PASS" : "FAIL") << endl;

    cout << "Test Case 7: ";
    yca = getYoungestCommonAncestor(ancestralTrees.at('A'), ancestralTrees.at('T'), ancestralTrees.at('Z'));
    cout << ((yca == ancestralTrees.at('H')) ? "PASS" : "FAIL") << endl;

    cout << "Test Case 8: ";
    yca = getYoungestCommonAncestor(ancestralTrees.at('A'), ancestralTrees.at('T'), ancestralTrees.at('V'));
    cout << ((yca == ancestralTrees.at('H')) ? "PASS" : "FAIL") << endl;

    cout << "Test Case 9: ";
    yca = getYoungestCommonAncestor(ancestralTrees.at('A'), ancestralTrees.at('T'), ancestralTrees.at('H'));
    cout << ((yca == ancestralTrees.at('H')) ? "PASS" : "FAIL") << endl;

    cout << "Test Case 10: ";
    yca = getYoungestCommonAncestor(ancestralTrees.at('A'), ancestralTrees.at('W'), ancestralTrees.at('V'));
    cout << ((yca == ancestralTrees.at('V')) ? "PASS" : "FAIL") << endl;

    cout << "Test Case 11: ";
    yca = getYoungestCommonAncestor(ancestralTrees.at('A'), ancestralTrees.at('Z'), ancestralTrees.at('B'));
    cout << ((yca == ancestralTrees.at('B')) ? "PASS" : "FAIL") << endl;

    cout << "Test Case 12: ";
    yca = getYoungestCommonAncestor(ancestralTrees.at('A'), ancestralTrees.at('Q'), ancestralTrees.at('W'));
    cout << ((yca == ancestralTrees.at('H')) ? "PASS" : "FAIL") << endl;

    cout << "Test Case 13: ";
    yca = getYoungestCommonAncestor(ancestralTrees.at('A'), ancestralTrees.at('A'), ancestralTrees.at('Z'));
    cout << ((yca == ancestralTrees.at('A')) ? "PASS" : "FAIL") << endl;

}
