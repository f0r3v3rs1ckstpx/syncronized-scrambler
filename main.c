#include <stdio.h>

void self_sync_scramble(char *data, int length) {
    char feedback[8] = {0};
    for (int i = 0; i < length; i++) {
        char input = data[i];
        char output = input ^ feedback[2] ^ feedback[4];
        feedback[7] = feedback[6];
        feedback[6] = feedback[5];
        feedback[5] = feedback[4];
        feedback[4] = feedback[3];
        feedback[3] = feedback[2];
        feedback[2] = feedback[1];
        feedback[1] = feedback[0];
        feedback[0] = output;
        data[i] = output;
    }
}


void self_sync_descramble(char *data, int length) {
    char feedback[8] = {0}; 
    for (int i = 0; i < length; i++) {
        char input = data[i];
        char output = input ^ feedback[2] ^ feedback[4];
        feedback[7] = feedback[6];
        feedback[6] = feedback[5];
        feedback[5] = feedback[4];
        feedback[4] = feedback[3];
        feedback[3] = feedback[2];
        feedback[2] = feedback[1];
        feedback[1] = feedback[0];
        feedback[0] = input;
        data[i] = output;
    }
}

int main() {
    char data[] = "KKSO-03-20 BSA";
    int length = sizeof(data) / sizeof(data[0]);

    printf("Original data: %s \n", data);

    // Scramble the data
    self_sync_scramble(data, length);
    printf("Scrambled data: %s \n", data);

    // Descramble the data
    self_sync_descramble(data, length);
    printf("Descrambled data: %s \n", data);

    return 0;
}
