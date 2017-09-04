stru
ct record {
	char *names;
	int *test_scores;
	int scorelen;
	int last_payment;
	int balance;
	int attendence;
};

struct all{
	struct record **r;
	int len;
	int curr_attendence;
}

// create returns a pointer to a structure struct all
struct all *create (void);

// new_record return a pointer to a structure struct record which contains all the information of that student
struct record *new_record (void);

// add_new mutate allrecords by adding a new student
void add_new (struct all *allrecords);

// destroy_individual frees the memory allocated to a single record
void destroy_individual(struct record *r);

// destroy frees the memory allocated to allrecords
void destroy(struct all *allrecords);

// search return the index of the student in the structure all, starting from 0, and returns -1 if the
// the student is not in allrecords
int search(struct all *allrecords, char *name);

// number_of_tests returns the total number of tests a particular student has taken
int number_of_tests (struct all *allrecords, char *name);

// change_score changes the score of a particular test of a student; if the test does not exist
// it add the test score to allrecords for that student
void change_score(struct all *allrecords, char *name, int score_number, int score);

// find_score prints the score of a test; if the test does not exist in allrecords, a warning will be printed
void find_score ((struct all *allrecords, char *name, int score_number);


// balance returns the current balance of a student
void balance(struct all *allrecords, char *name);


// change_balance mutates allrecords by changing the balance of a particular student
void change_balance (struct all *allrecords, char *name, int payment);

// add_attendence_for_all increase the maximum attendence by 1
void add_attendence_for_all (struct all *allrecords);


// change_attendence increase the attendence of a student by 1
void change_attendence (struct all *allrecords, char *name);

// find_attendence prints the total attendence and absence of a student
void find_attendence (struct all *allrecords, char *name);
