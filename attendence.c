struct record {
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


// create a wrapper structure all
struct all *create (void){
	struct all *new = malloc(sizeof(struct all));
	new->len = 0;
	new->r = malloc(sizeof(struct record) * new->len);
	new->curr_attendence = 0
	return new;
}

// create an individual record
struct record *new_record (void) {
	struct record *new = malloc(sizeof(struct record));
	char *s;
	if (scanf("%s",s) != 1) {
		break;
	}
	new->names = malloc((strlen(s)+1) * sizeof(char));
	strcpy(new->names, s);
	new->scorelen = 0;
	new->test_scores = malloc(sizeof(int) * new->scorelen);
	new->last_payment = 0;
	new->balance = 0;
	new->attendence = 0;
	return new;
}


// add a new individual record to the wrapper
void add_new (struct all *allrecords){
	struct record *new = new_record();
	allrecords->len += 1;
	allrecords->r = realloc(sizeof(struct record *) * allrecords->len);
	allrecords->r[len-1] = new;
}


void destroy_individual(struct record *r) {
	free(r->names);
	free(test_scores);
	free(r);
}

void destroy(struct all *allrecords) {
	for (int i = 0; i < allrecords->len; i++) {
		destroy_individual((allrecords->r)[i]);
	}
	free(allrecords);
}

// search the name and return the index that the record is located
// if the name is not in the allrecords, -1 will be returned
int search (struct all *allrecords, char *name) {
	for (int i = 0; i < allrecords->len; i++) {
		if (strcmp(((allrecords->r)[i])->names), name) == 0) {
			return i;
		}
	}
	return -1;
}

// return -1 if the student is not in the records
int number_of_tests (struct all *allrecords, char *name) {
	int index = search(allrecords, name);
	if (index == -1) {
		printf("This student is not in the class\n");
		printf("Add him first before changing his score\n");
		return -1;
	}
	struct record *target = (allrecords->r)[index];
	return target->scorelen;
}

// add a new test if score_number >= scorelen;
// otherwise change the score
void change_score(struct all *allrecords, char *name, int score_number, int score) {
	int index = search(allrecords, name);
	if (index == -1) {
		printf("This student is not in the class\n");
		printf("Add him first before changing his score\n");
		return;
	}
	struct record *target = (allrecords->r)[index];
	if (score_number >= target->scorelen) {
		target->scorelen += 1;
		target->test_scores = realloc(sizeof(int) * target->scorelen);
		target->test_scores(score_number) = score;
		printf("New score has been added successfully\n");
	} else {
		target->test_scores(score_number) = score;
		printf("Score has been modified successfully\n");
	}
}


void find_score ((struct all *allrecords, char *name, int score_number) {
	int index = search(allrecords, name);
	if (index == -1) {
		printf("This student is not in the class\n");
		printf("Add him first before changing his score\n");
		return;
	}
	if (score_number >= target->scorelen) {
		printf("This test is not available\n");
		return;
	}
	struct record *target = (allrecords->r)[index];
	int score = target->test_scores[score_number];
	printf("The test %d of the student %s is %d\n", score_number, name, score);
}


void balance(struct all *allrecords, char *name) {
	int index = search(allrecords, name);
	if (index == -1) {
		printf("This student is not in the class\n");
		printf("Add him first before changing his balance\n");
		return;
	}
	struct record *target = (allrecords->r)[index];
	int b = target->balance;
	printf("The currrent balance is %d\n", b);
}


void change_balance (struct all *allrecords, char *name, int payment) {
	int index = search(allrecords, name);
	if (index == -1) {
		printf("This student is not in the class\n");
		printf("Add him first before changing his balance\n");
		return;
	}
	struct record *target = (allrecords->r)[index];
	target->balance += payment;
	target->last_payment = payment;
}


void add_attendence_for_all (struct all *allrecords) {
	allrecords->curr_attendence += 1;
}

void change_attendence (struct all *allrecords, char *name) {
	int index = search(allrecords, name);
	if (index == -1) {
		printf("This student is not in the class\n");
		printf("Add him first\n");
		return;
	}
	struct record *target = (allrecords->r)[index];
	target->attendence += 1;
	printf("Student %s has gained 1 attendence successfully\n", name);
}

void find_attendence (struct all *allrecords, char *name) {
	int index = search(allrecords, name);
	if (index == -1) {
		printf("This student is not in the class\n");
		printf("Add him first\n");
		return;
	}
	struct record *target = (allrecords->r)[index];
	int max = allrecords->curr_attendence;
	int c = target->attendence;
	printf("Student %s's has attended classes %d times and has been absent for %d times\n", name, c, max-c);
}













