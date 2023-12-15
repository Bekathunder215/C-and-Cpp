#include <iostream>
#include <iomanip>


using namespace std;

typedef class tn *tp;

class tn
{
    public:    
        int key;
        tp l,r;
};

void printBST(tp rt);
void Incertkey(tp *rt, int data);
void Delete(tp *rt, int data);
void findBST(tp *rt, int data);

int main()
{
    tp root;
    int key;
    root = NULL; //pointer to root node
    char answer,answer2;
    answer = '_';
    while(answer!='q' && answer!='Q')
    {
        cout << "\n\n--------------------------------------------------------------\n";
        cout << "Previous answer was:" << answer << "\nGive a new choice: \nI for incerting\nP for printing\n";
        cout << "D for deleteing\nF for searching\nQ for quiting\nChoice: ";
        cin >> answer;
        cout << "The new answer is:" << answer << endl;
        cout << "\n--------------------------------------------------------------\n";
        
        if(answer != 'I' && answer != 'i' && answer != 'P' && answer != 'p' && answer != 'D' && answer != 'd' && answer != 'Q' &&
       answer != 'q' && answer != 'f' && answer != 'F') 
       {
        cout << "\n\nInvalid input, please try again.\n";
        }
        if (answer=='q' || answer=='Q')
        {
            cout<< "\n You Quit\n BYE BYE" << endl;
            return 0;
        }
        if (answer=='i' || answer=='I')
        {
            cout << "\nProvide me with the KEY: ";
            cin >> key;
            cout << "\nIncerting KEY";
            Incertkey(&root, key);
            cout << "\nKEY Incerted";
        }
        if (answer=='d' || answer=='D')
        {
            cout << "\nProvide me with a KEY to delete: ";
            cin >> key;
            cout << "\nAttempting Delete";
            Delete(&root, key);
        }
        if (answer=='p' || answer=='P')
        { 
            cout << "\nPrinting the tree\n";

            if(root == NULL)
            {
                cout << "\nThere is nothing to print\n";
            }
            else
            {
                cout << endl;
                for(int i = 0; i < 23; i++) cout << "-";
                printBST(root);
                cout << endl;
            }
        }
        if (answer=='f' || answer=='F')
        {
            cout << "\nGive me the KEY you want to Find: ";
            cin >> key;
            if((root) == NULL)
            {
                cout << "Tree is empty";
            }
            else
            {
                findBST(&root, key);
            }
        }
    }
}

tp create(int data)
{
    tp temporary = new tn;
    temporary->key = data;
    temporary->l = NULL;
    temporary->r = NULL;
    return temporary;
}

void Incertkey(tp *rt, int data)
{
    if(*rt == NULL) //empty tree
    {
        *rt = create(data);
    }
    else if(data <= (*rt)->key ) //incert left
    {
        tp rt1 = (*rt)->l;
        Incertkey(&rt1, data);
    }
    
}

