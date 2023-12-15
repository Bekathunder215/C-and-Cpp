#include <iostream>
#include <iomanip>


using namespace std;

// Type Definition for Pointer on Student Struct
typedef class ph *pp;

// Student Struct Definition
class ph
{
    public:
        int am;
        double gr;
        pp next;
};

void printList(pp h);
void printListR(pp h);
void insertStudent(pp *h, int am, double gr);
void deleteStudent(pp *h, int am);

int main(void) {
  pp h = NULL;
  int am;
  double gr;
  char answer = '_';

  while(answer != 'Q' && answer != 'q') {
    cout << "\n\n--------------------------------------------------------------\n";
    cout << "Previous answer was:" << answer << "\nGive a new choice: \nI for incerting\nP for printing\n";
    cout << "D for deleteing\nR for reverse order print\nQ for quiting\nChoice: ";

    fflush(stdin);
    answer = getchar();
    getchar();

    cout << "The new answer is:" << answer << endl;
    cout << "\n--------------------------------------------------------------\n";

    if(answer != 'I' && answer != 'i' && answer != 'P' && answer != 'p' && answer != 'D' && answer != 'd' && answer != 'Q' &&
       answer != 'q' && answer != 'r' && answer != 'R') {
      cout << "\n\nInvalid input, please try again.\n";
    }

    if(answer == 'I' || answer == 'i') {
      cout << "\n\nInsert a Student in the List";

      cout << "\nProvide the AM: ";
      cin >> am;

      cout << "Provide the Grade: ";
      cin >> gr;

      insertStudent(&h, am, gr);
      cout << "Student Inserted!\n";
    }

    if(answer == 'P' || answer == 'p') {
      cout << "\n\nPrint the Student List";

      if(h == NULL) {
        cout << "\nThere is nothing to print\n";
      } else {
        cout << "\n";
        for(int i = 0; i < 23; i++) cout << "-";

        printList(h);
        cout << "\n";
      }
    }
    if(answer == 'r' || answer == 'R') {
      cout << "\n\nPrint the Student List";

      if(h == NULL) {
        cout << "\nThere is nothing to print\n";
      } else {
        cout << "\n";
        for(int i = 0; i < 23; i++) cout << "-";

        printListR(h);
        cout << "\n";
      }
    }

    if(answer == 'D' || answer == 'd') {
      cout << "\n\nExpel Student";
      cout << "\nThe Student's AM is: ";
      cin >> am;

      deleteStudent(&h, am);
    }
  }

  cout << "\n\nThe program has halted.";

  return 0;
}

// Print List Recursively
void printList(pp h) {
  if(h == NULL) return;
  cout << "\nAM: " << setfill('0') << setw(3) << h->am << ", has grade: ";
  cout << fixed << setfill(' ') << setw(5) << setprecision(2) << h->gr;
  printList(h->next);
}
// Reverse Print List Recursively
void printListR(pp h) {
  if(h == NULL) return;
  printListR(h->next);
  cout << "\nAM: " << setfill('0') << setw(3) << h->am << ", has grade: ";
  cout << fixed << setfill(' ') << setw(5) << setprecision(2) << h->gr;
}

// Insert Student in Sorted Order Considering AM
void insertStudent(pp *h, int am, double gr) {
  // Create Student
  pp st = new ph;
  st->am = am;
  st->gr = gr;
  // Temporary Node Pointer
  pp tmp;

  // Conditions
  int con1 = (*h == NULL);
  int con2 = ((*h != NULL) && (*h)->am > am);
  int con3 = ((*h != NULL) && (*h)->am < am);

  if(con1) {
    *h = st;
    st->next = NULL;
  }

  if(con2) {
    st->next = *h;
    *h = st;
  }

  if(con3) {
    tmp = *h;
    while(tmp->next != NULL && tmp->next->am < am) {
      tmp = tmp->next;
    }

    if(tmp->next == NULL) {
      tmp->next = st;
      st->next = NULL;
    } else {
      st->next = tmp->next;
      tmp->next = st;
    }
  }
}

// Expel Student from University
void deleteStudent(pp *h, int am) {
  pp tmp, exSt;

  // Conditions
  int con1 = (*h == NULL);
  int con2 = ((*h != NULL) && ((*h)->am != am));
  int con3 = ((*h != NULL) && ((*h)->am == am));

  if(con1) {
    cout << "There is no Student on the List\n";
  }

  if(con2) {
    tmp = *h;

    while(tmp->next != NULL && tmp->next->am != am) {
      tmp = tmp->next;
    }

    if(tmp->next == NULL) {
      cout << "There is no Student with AM " << am << " on the List\n";
    } else if(tmp->next->am == am) {
      exSt = tmp->next;
      tmp->next = tmp->next->next;
      delete(exSt);
      cout << "Student with AM " << am << " was Expelled\n";
    }
  }

  if(con3) {
    exSt = *h;
    *h = (*h)->next;
    delete(exSt);
    cout << "Student with AM " << am << " was Expelled\n";
  }
}