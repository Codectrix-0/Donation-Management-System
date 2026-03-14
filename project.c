#include <stdio.h>
#include <stdlib.h>

struct Donor {
    int id;
    char name[50];
    float amount;
};

void addDonation() {
    struct Donor d;
    FILE *fp;

    fp = fopen("donations.txt", "a");
    if (fp == NULL) {
        printf("File not found!\n");
        return;
    }

    printf("\nEnter Donor ID: ");
    scanf("%d", &d.id);

    printf("Enter Donor Name: ");
    scanf(" %[^\n]", d.name);

    printf("Enter Donation Amount: ");
    scanf("%f", &d.amount);

    fprintf(fp, "%d %s %.2f\n", d.id, d.name, d.amount);
    fclose(fp);

    printf("\n✅ Donation added successfully!\n");
}

void viewDonations() {
    struct Donor d;
    FILE *fp;

    fp = fopen("donations.txt", "r");
    if (fp == NULL) {
        printf("\nNo donations found!\n");
        return;
    }

    printf("\nID\tName\t\tAmount\n");
    printf("--------------------------------\n");

    while (fscanf(fp, "%d %s %f", &d.id, d.name, &d.amount) != EOF) {
        printf("%d\t%s\t\t%.2f\n", d.id, d.name, d.amount);
    }

    fclose(fp);
}

void totalDonation() {
    struct Donor d;
    float total = 0;
    FILE *fp;

    fp = fopen("donations.txt", "r");
    if (fp == NULL) {
        printf("\nNo donations found!\n");
        return;
    }

    while (fscanf(fp, "%d %s %f", &d.id, d.name, &d.amount) != EOF) {
        total += d.amount;
    }

    fclose(fp);
    printf("\n💰 Total Donation Amount: %.2f\n", total);
}

int main() {
    int choice;

    do {
        printf("\n===== Donation Management System =====");
        printf("\n1. Add Donation");
        printf("\n2. View Donations");
        printf("\n3. Total Donation Amount");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addDonation();
                break;
            case 2:
                viewDonations();
                break;
            case 3:
                totalDonation();
                break;
            case 4:
                printf("\nThank you for using the system 🙏\n");
                break;
            default:
                printf("\n❌ Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}