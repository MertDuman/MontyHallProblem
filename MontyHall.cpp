#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <ctime>

using namespace std;

class Doors {
public:
	Doors() {
		doorCount = 3;
		prizeSelection = rand() % doorCount;
	}

	Doors(int doorCount) {
		this->doorCount = doorCount;
		prizeSelection = rand() % doorCount;
	}

	void select() {
		curSelection = rand() % doorCount;
	}

	// If the first selection is the prize, offer an empty selection.
	// Else, offer the prize selection.
	void offerSelection() {
		if (curSelection == prizeSelection) {
			int random = rand() % doorCount;
			// loop till we get a selection other than the prize
			while (random == prizeSelection) {
				random = rand() % doorCount;
			}
			offering = random;
		} else {
			offering = prizeSelection;
		}
	}

	// Change from your decision to the unrevealed door
	void changeDecision() {
		curSelection = offering;
	}

	bool didWin() {
		return curSelection == prizeSelection;
	}

private:
	int prizeSelection;
	int curSelection;
	int offering;
	int doorCount;
};

int main() {
	cout << "Monty Hall Problem" << endl;
	cout << "You are asked to choose one from 3 closed doors. Behind two doors there is nothing (or a goat)," << endl;
	cout << "behind one door there is a prize. After you choose a door, someone who knows what's behind each door" << endl;
	cout << "opens one of the other doors and reveals to you that it is empty (or has a goat). Then you are given the" << endl;
	cout << "chance to change your selection and choose the unrevealed door. Would you stick with your first" << endl;
	cout << "selection or change to win the prize?" << endl;
	cout << "The original monty hall problem is out of 3 doors, however to explain why you should always change" << endl;
	cout << "your decision, we can have more doors. Try out different amounts of doors to see how it affects" << endl;
	cout << "your success if you played X many times." << endl;
	cout << endl;

	char goAgain;

	do {
		srand(time(NULL));	// random seed

		int runs;
		cout << "Amount of times to play: ";
		cin >> runs;

		int doorCount;
		do {
			cout << "Amount of doors: ";
			cin >> doorCount;
		} while (doorCount < 3);

		char changeDecision;
		do {
			cout << "Change decision? (Y or N): ";
			cin >> changeDecision;
		} while (changeDecision != 'Y' && changeDecision != 'y' && changeDecision != 'N' && changeDecision != 'n');

		int runs_cons = runs;
		int success = 0;
		for (; runs >= 0; runs--) {
			Doors s = Doors(doorCount);
			s.select();
			if (changeDecision == 'Y' || changeDecision == 'y') {
				s.offerSelection();
				s.changeDecision();
			}
			if (s.didWin()) {
				success++;
			}
		}

		double percentage = success * 100.0 / runs_cons;
		cout << "Prizes won: " << success << endl;
		cout << "Percentage: " << percentage << "%" << endl;


		cout << "Go again? (Y or N): ";
		cin >> goAgain;
		cout << endl;
	} while (goAgain != 'N' && goAgain != 'n');

	return 0;
}






