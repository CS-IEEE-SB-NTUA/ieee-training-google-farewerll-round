#include <iostream>
using namespace std;

typedef long long ll;
ll powFive[20];
ll prefixAmount[20];

namespace easy {
	// Παρακάτω ακολουθεί μία υλοποιήση της τατριμένης λύσης. Αν δεν θέλετε να χρησιμοποιηθεί
	// μπορείτε να αφαιρέσαι το easy μπροστά από το sol. 

	// υπολόγιζει το πλήθος των ψηφιών που έχει ένας αριθμός
	int manyDigits(int n) {
		int counter = 0;
		while (n > 0) {
			counter ++;
			n /= 10;
		}
		return counter;
	}

	// ελέγχει αν ο αριθμός είναι βαρετός, ελέγχοντας κανονικά τις συνθήκες στην
	// εκφώνηση. 
	bool checker (int n) {
		bool check = manyDigits(n) % 2;
		int input = n;

		while (n > 0) {
			if ((n % 2) != check) { 
				return 0;
			}
			n /= 10;
			check ^= true;
		}

		return 1;
	}

	// Διατρέχει από το 0 μέχρι το n για να δει πόσοι αριθμοί υπάρχουν. 
	int sol(int n){
		int counter = 0;
		for (int i = 0; i <= n; ++i) {
			counter += checker(i);
		}
		return counter;
	}
}

/*Παρακάτω ακολουθεί μια υλοποιήση της βέλτιστης λύσης. Δείτε ότι λόγω εύρους
είναι αναγκαία η χρήση του long long. 
*/
ll sol(ll n) {
	/*Πρέπει να έχουμε ξεχωριστά τα ψηφία του αριθμού στο δεκαδικό. 
	Ένας ευκόλος τρόπος που υπάρχει στην iostream έιναι το to_string
	*/
	string n_str = to_string(n);
	int digits = n_str.size();
	/*Με αυτό εδώ έχουμε υπολογίσει όλους τους βαρετούς αριθμούς μήκους 
	μικρότερου της εισόδου. (Κοιτά διαφάνειες)
	*/
	ll result = prefixAmount[digits - 1];

	// Διάτρεχουμε τα ψηφιά του αριθμού μας. 
	for (int i = 1; i <= digits; ++i) {
		int curr = (int) (n_str[i - 1] - '0');
		if (curr % 2 == i % 2) {
			/*Αν τελικά το ψηφίο βρίσκεται στην σωστή θέση, τότε
			διαιρούμε την τιμή του με 2 και πολλαπλασιάζουμε με το 5
			υψωμένο στο πλήθος των ψηφίων που απομένουν μέχρι τέλους
			*/
			result += ((curr) / 2) * powFive[digits - i];
			/*Αν είμαστε στο τελευταίο ψηφίο τότε για να το συμπεριλάβουμε θα 
			αυξήσουμε το αποτέλεσμα κατά 1. 
			*/
			if (i == digits) ++result;
		}
		else {
			/* Στην περίπτωση που το φηφίο του αριθμού μας δεν είναι στην σωστή
			Θέση τότε θα διαιρέσουμε το ψηφιό με το 2 rounding-up και θα 
			πολλαπλοσιάσουμε 5 υψωμένο στο πλήθος των εναπομήνων ψηφίων. 
			*/
			result += ((curr + 1) / 2) * powFive[digits - i];
			/* Μέτα από αυτό θα πρέπει να τερματίσουμε το πρόγραμμα καθώς δεν 
			δεν θα υπάρξει άλλο νόμιμο πρόθεμα για να πεις ότι θα υπόλοιπα 
			διάστηματα που θα κάλυπτε θα μπορούσαν να προσμετρηθούν. 
			*/ 
			break;
 		}
	}

	return result;
}



int main() {
	int t; 
	ll x, y = 0;
	ll L, R;
	powFive[0] = 1;
	for (int i = 1; i < 20; ++i) {
		powFive[i] = powFive[i - 1] * 5;
	}

	prefixAmount[0] = 0;
	for (int i = 1; i < 20; ++i) {
		prefixAmount[i] = prefixAmount[i - 1] + powFive[i];
	}

	cin >> t;
	for (int i = 1; i <= t; ++i) { 
		cin >> L >> R;
		x = easy::sol(L - 1);
		y = easy::sol(R);
		cout << "Case #" << i << ": " << y - x << endl;
	}
	return 0;
}
