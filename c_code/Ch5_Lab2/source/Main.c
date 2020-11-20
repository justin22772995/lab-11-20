#include <stdio.h>
#include <stdlib.h>

#define issues 5
#define rattings 10

void recordResponse(int, int);
void highestRatings();
void lowestRatings();
float averageRating(int);
void dispalyResults();

int responses[issues][rattings];
const char *topics[issues] = { "���y�x��","�g�ٰ��D","�Ԫ����D","���d���@","�Ш|���D" };

void recordResponse(int ISSUE, int RATING) {
	responses[ISSUE][RATING-1]++;
}

void highestRatings() {
	int highestRating = 0;
	int highTopic = 0;

	for (int i = 0; i < issues; i++) {
		int topicRating = 0;
		for (int j = 0; j < rattings; j++) {
			topicRating = topicRating + responses[i][j] * (j + 1);
		}

		if (highestRating < topicRating) {
			highestRating = topicRating;
			highTopic = i;
		}
	}

	printf("\n�Q�׫׳̰���ĳ�D���G%s �Q�׫׬�%d\n",topics[highTopic], highestRating);
}

void lowestRatings() {
	int lowestRating = 0;
	int lowTopic = 0;

	for (int i = 0; i < issues; i++) {
		int topicRating = 0;
		for (int j = 0; j < rattings; j++) {
			topicRating = topicRating + responses[i][j] * (j + 1);
		}
		if (i == 0) {
			lowestRating = topicRating;
		}
		if (lowestRating > topicRating) {
			lowestRating = topicRating;
			lowTopic = i;
		}
	}

	printf("\n�Q�׫׳̧C��ĳ�D���G%s �Q�׫׬�%d\n", topics[lowTopic], lowestRating);
}

float averageRating(int ISSUE) {
	float total = 0;
	int counter = 0;
	for (int i = 0; i < rattings; i++) {
		if (responses[ISSUE][i] != 0) {
			total = total + responses[ISSUE][i] * (i + 1);
			counter = counter + responses[ISSUE][i];
		}
	}
	return total / counter;
}


void dispalyResults() {
	printf("%20s", "Topic");

	for (int i = 1; i < rattings + 1; i++) {
		printf("%4d", i);
	}

	printf("%20s", "Average Rating");

	for (int i = 0; i < issues; i++) {
		printf("\n%20s", topics[i]);
		for (int j = 0; j < rattings; j++) {
			printf("%4d", responses[i][j]);
		}
		printf("%20.2f", averageRating(i));
	}

	highestRatings();
	lowestRatings();
}

int main(void) {
	int response;

	do {
		printf("�Ш̷ӤU�Cĳ�D��J�̾ڸ�ĳ�D���Q�׫�1-10��\n 1 = �̤����n, 10 = �̭��n\n");

		for (int i = 0; i < issues; i++) {
			do {
				printf("%s?", topics[i]);
				scanf_s("%d", &response);
			} while ((response < 1) || (response > 10));
			recordResponse(i, response);
		}
		
		printf("��J1��ܪ��,��J0���s��J�Q�׫�");
		scanf_s("%d", &response);

	} while (response != 1);

	dispalyResults();

	system("pause");
	return 0;
}