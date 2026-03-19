#include <stdio.h>
#include <string.h>

int count = 0;

void add(char name[][50], long long phone[])
{
    int choice;

    do
    {
        printf("Enter Name: ");
        scanf("%s", name[count]);

        printf("Enter Phone Number: ");
        scanf("%lld", &phone[count]);

        count++;

        printf("Add more? (1 = Yes / 2 = No): ");
        scanf("%d", &choice);

    } while (choice == 1);
}

void display(char name[][50], long long phone[])
{
    if (count == 0)
    {
        printf("No contacts found\n");
        return;
    }

    printf("\n--- Contact List ---\n");
    for (int i = 0; i < count; i++)
    {
        printf("%d. %s - %lld\n", i + 1, name[i], phone[i]);
    }
}

void search(char name[][50], long long phone[])
{
    long long num;
    int found = 0;

    printf("Enter phone number to search: ");
    scanf("%lld", &num);

    for (int i = 0; i < count; i++)
    {
        if (phone[i] == num)
        {
            printf("Contact Found\n");
            printf("Name: %s\n", name[i]);
            printf("Phone: %lld\n", phone[i]);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Contact not found\n");
    }
}

void delete_contact(char name[][50], long long phone[])
{
    long long num;
    int found = 0;

    printf("Enter phone number to delete: ");
    scanf("%lld", &num);

    for (int i = 0; i < count; i++)
    {
        if (phone[i] == num)
        {
            for (int j = i; j < count - 1; j++)
            {
                strcpy(name[j], name[j + 1]);
                phone[j] = phone[j + 1];
            }

            count--;
            printf("Contact deleted successfully\n");
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Contact not found\n");
    }
}

int main()
{
    char name[100][50];
    long long phone[100];
    int choice;

    do
    {
        printf("\n1. Add Contact\n");
        printf("2. Delete Contact\n");
        printf("3. Search Contact\n");
        printf("4. Display All Contacts\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            add(name, phone);
            break;

        case 2:
            delete_contact(name, phone);
            break;

        case 3:
            search(name, phone);
            break;

        case 4:
            display(name, phone);
            break;

        case 5:
            printf("Exiting program...\n");
            break;

        default:
            printf("Invalid choice\n");
        }

    } while (choice != 5);

    return 0;
}