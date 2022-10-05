#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

short easy();
short medium();
short hard();

int main(){
    
    // Seeding the random number generator
    srand(time(NULL));

    // Keeping track of scores in a file
    bool scores_opened = true;
    FILE *scores = fopen("scores.csv","a+");
    if (scores == NULL){
        scores_opened = false;
    }
    
    // Reading player name
    char name[25];
    printf("Enter your playername: ");
    scanf("%[^\n]%*c", name);

    // Setting Difficulty
    int score;
    char difficulty;
    printf("Choose difficulty: Easy | Medium | Hard\n");
    while(1){
        printf("(E/M/H): ");
        scanf("\n%c", &difficulty);
        difficulty = toupper(difficulty);
        if (difficulty == 'E'){
            score = easy();
            break;
        }
        if (difficulty == 'M'){
            score = medium();
            break;
        }
        if (difficulty == 'H'){
            score = hard();
            break;
        }
    }

    // Printing results
    if (score > 0){
        printf("##########\nGreat job %s!\n", name);
        printf("Your score is: %i\n#########\n", score);
        if (scores_opened){
            fprintf(scores, "\"%s\",\"%c\",%i\n", name, difficulty, score);
        }
    }
    else{
        printf("Try again!\n");
    }

    // Closing this
    fclose(scores);
    return 0;
}

short easy(){
    short secret = rand() % 250 + 1;
    short score = 2000, guess, difference;
    char temp[20];
    printf("======EASY=MODE=====\n");
    printf("Hint: Guess a number between 1 and 250 (inclusive).\n");
    printf("Hint: Press 'q' to quit.\n");
    while(score){
        printf("Guess: ");
        scanf("%s", temp);
        if (temp[0] == 'q')
            exit(0);
        if (!atoi(temp)){
            printf("Not a number!\n");
            continue;
        }
        guess = atoi(temp);

        // Checking and reducing score
        if (guess == secret){
            return score;
        }
        else{
            difference = abs(secret - guess);

            // Affect score negatively
            score -= 3.14 * difference;
            if (score > 0)
                printf("Score: %i\n", score);
            else{
                return -1;
            }

            // Hint messages
            if (difference <= 10)
                printf(">>> Super Hot! <<<\n");
            else if (difference <= 25)
                printf(">>> Mildly Hot! <<<\n");
            else if (difference <= 75)
                printf(">>> Moderately Cold! <<<\n");
            else if (difference <= 125)
                printf(">>> Super Cold! <<<\n");
            else
                printf(">>> Freezing Cold! <<<\n");
        }
    }
    return score;
}

short medium(){
    printf("Under construction\n");
    exit(0);
}

short hard(){
    printf("Under construction\n");
    exit(0);
}