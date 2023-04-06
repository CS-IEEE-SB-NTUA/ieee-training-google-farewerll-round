#include <vector>
#include <iostream>
/*
Το παρακάτω είναι η πηγή που χρησιμοποιήσα για να φτιάξω τον κωδικά και την παρουσιάση καθώς δεν είχα χρόνο να λύσω ο ίδιος το πρόβλημα 
*/
// https://github.com/kamyu104/GoogleKickStart-2022/tree/main/Round%20E


using namespace std;

vector<int> getPrefix(string pattern) {

	vector<int> prefix (pattern.size(), -1);
	int j = -1;
	for (int i = 1; i < pattern.size(); ++i) {
		// Το παρακάτω and είναι εδώ για τον Σπύρο :P
		/*
		Όσο το j != -1: έχουμε βρει αρχή για παλίνδρομο.
		και 
		όσο δεν έχουμε βρει την τιμή του j για την οποία δεν έχουμε 
		ίδιο γράμμα με τον χαρακτήρα στην θέση i 
		Το j θα παίρνει την τιμή του j για την προηγούμενη θέση.  

		*/
		while (j != -1 and pattern[j+1] != pattern[i]) {
			j = prefix[j];
		}
		/*
		Αν ο χαρακτήρας είναι ίδιο τότε το j αυξάνεται κατά μία θέση
		*/
		if (pattern[j+1] == pattern[i]){
			j += 1;
		}
		/*
		αποθηκεύουμε το j στην προηγούμενη τιμή του πίνακα προθεμάτων. 
		*/
		prefix[i] = j;
	}
	return prefix;
}

string matching_palindrome(){
	int N; cin >> N;
	string palindrome; cin >> palindrome;
	// string palindrome;
	/*
	Διπλασιάζουμε το string της εισόδου με
	*/
	for (int i = 0; i < N; ++i) {
		palindrome += palindrome[i];
	}
	// for (int i = 0; i < N; ++i) {
	// 	palindrome += palindrome[i];
	// }

	vector <int> prefix = getPrefix(palindrome);
	/*
	Το παρακάτω είναι για να δείξουμε στο αναγνώστη πώς μοιάζει ο πίνακας μετά την εκτέλεση. 
	*/
	// cerr << endl;
	// cerr << "[";
	// for (auto &x: palindrome) {
	// 	cerr << "\t" <<  x << ", ";
	// }
	// cerr << "]\n";
	// cerr << "[";
	// for (auto &x: prefix) {
	// 	cerr << "\t" <<  x << ", ";
	// }
	// cerr << "]\n";
	/*
	Παίρνουμε την τελευταία τιμή από τον πίνακα prefix την αυξάνουμε κατά 1
	και επιστρέφουμε μέχρι τέλος του πίνακα. 
	*/
	return palindrome.substr(prefix[2*N-1] + 1, palindrome.size()-1);
}


int main () {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t){
		cout << "Case #" << t << ": " << matching_palindrome() << endl;
	}
	return 0;
}
