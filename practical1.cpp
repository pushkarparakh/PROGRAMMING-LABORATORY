#include <iostream>
using namespace std;

/*Practical no.:1
Implementation of array and ojects and operations

Name : Pushkar Harshkumar Parakh
PRN: 202401040313
DIV : SY - C
ROLL NO.: 187
BATCH : C2
*/

// Defines the Mobile class representing a mobile phone in inventory
class Mobile
{
    long long imei;
    char model_name[50];
    char brand[50];
    float price;
    int quantity;

public:
    void read_data();
    void display_data() const; // <-- Added const
    long long getIMEI() const;  // <-- Added const
};

// Reads mobile data from user input
void Mobile::read_data()
{
    cout << "Enter IMEI Number (15 digits): ";
    cin >> imei;

    cout << "Enter Model Name (no spaces): ";
    cin >> model_name;

    cout << "Enter Brand Name (no spaces): ";
    cin >> brand;

    cout << "Enter Price: ";
    cin >> price;

    cout << "Enter Quantity: ";
    cin >> quantity;
}

// Displays mobile data to the console
void Mobile::display_data() const // <-- Added const
{
    cout << "--- Mobile Details ---" << endl;
    cout << "IMEI Number: " << imei << endl;
    cout << "Model Name:  " << model_name << endl;
    cout << "Brand:       " << brand << endl;
    cout << "Price:       $" << price << endl;
    cout << "Quantity:    " << quantity << endl;
    cout << "----------------------" << endl;
}

// Returns the IMEI number of the mobile
long long Mobile::getIMEI() const // <-- Added const
{
    return imei;
}

// --- Function Prototypes for Inventory Management ---

void addNewMobile(Mobile mobile_stock[], int& num_mobiles);
void displayAllMobiles(const Mobile mobile_stock[], int num_mobiles);
void updateMobile(Mobile mobile_stock[], int num_mobiles);
void deleteMobile(Mobile mobile_stock[], int& num_mobiles);
void searchMobile(const Mobile mobile_stock[], int num_mobiles);
void clearInputBuffer();

// --- Function Definitions for Inventory Management ---


// Function to add a new mobile to the stock
void addNewMobile(Mobile mobile_stock[], int& num_mobiles)
{
    if (num_mobiles < 50)
    {
        cout << "\n--- Adding New Mobile ---\n";
        mobile_stock[num_mobiles].read_data();
        num_mobiles++;
        cout << "\nMobile stock added successfully!" << endl;
    }
    else
    {
        cout << "Inventory is full! Cannot add more mobile types." << endl;
    }
}

// Function to display all mobiles in the stock
void displayAllMobiles(const Mobile mobile_stock[], int num_mobiles)
{
    if (num_mobiles == 0)
    {
        cout << "\nNo mobiles in stock." << endl;
    }
    else
    {
        cout << "\n--- Complete Mobile Stock ---\n";
        for (int i = 0; i < num_mobiles; i++)
        {
            mobile_stock[i].display_data();
        }
    }
}

// Function to update a mobile's data by its IMEI
void updateMobile(Mobile mobile_stock[], int num_mobiles)
{
    if (num_mobiles == 0)
    {
        cout << "\nNo mobiles in stock to update." << endl;
        return;
    }
    long long imei_to_find;
    cout << "\nEnter IMEI of mobile to update: ";
    cin >> imei_to_find;

    bool found = false;
    for (int i = 0; i < num_mobiles; i++)
    {
        if (mobile_stock[i].getIMEI() == imei_to_find)
        {
            cout << "--- Updating data for IMEI: " << imei_to_find << " ---\n";
            mobile_stock[i].read_data();
            found = true;
            cout << "\nStock updated successfully!" << endl;
            break;
        }
    }
    if (!found)
    {
        cout << "Mobile with specified IMEI not found!" << endl;
    }
}

// Function to delete a mobile from the stock by its IMEI
void deleteMobile(Mobile mobile_stock[], int& num_mobiles)
{
    if (num_mobiles == 0)
    {
        cout << "\nNo mobiles in stock to delete." << endl;
        return;
    }
    long long imei_to_find;
    cout << "\nEnter IMEI of mobile to delete: ";
    cin >> imei_to_find;

    bool deleted = false;
    for (int i = 0; i < num_mobiles; i++)
    {
        if (mobile_stock[i].getIMEI() == imei_to_find)
        {
            for (int j = i; j < num_mobiles - 1; j++)
            {
                mobile_stock[j] = mobile_stock[j + 1];
            }
            num_mobiles--;
            cout << "Mobile stock deleted successfully." << endl;
            deleted = true;
            break;
        }
    }
    if (!deleted)
    {
        cout << "Mobile with specified IMEI not found!" << endl;
    }
}

// Function to search for a mobile and display its details
void searchMobile(const Mobile mobile_stock[], int num_mobiles)
{
    if (num_mobiles == 0)
    {
        cout << "\nNo mobiles in stock to search." << endl;
        return;
    }
    long long imei_to_find;
    cout << "\nEnter IMEI to search for: ";
    cin >> imei_to_find;

    bool found = false;
    for (int i = 0; i < num_mobiles; i++)
    {
        if (mobile_stock[i].getIMEI() == imei_to_find)
        {
            cout << "\n--- Mobile Found ---" << endl;
            mobile_stock[i].display_data();
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "Mobile with specified IMEI not found!" << endl;
    }
}

// Main function to manage mobile shop inventory
int main()
{
    Mobile mobile_stock[50];
    int num_mobiles = 0;
    int choice;
    
    // Displays menu and processes user's choice
    do
    {
        cout << "\n===== Mobile Shop Management System =====\n";
        cout << "1. Add New Mobile Stock\n";
        cout << "2. Display All Mobiles\n";
        cout << "3. Update Mobile Stock by IMEI\n";
        cout << "4. Delete Mobile by IMEI\n";
        cout << "5. Search for Mobile by IMEI\n";
        cout << "6. Exit\n";
        cout << "=========================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addNewMobile(mobile_stock, num_mobiles);
            break;
        case 2:
            displayAllMobiles(mobile_stock, num_mobiles);
            break;
        case 3:
            updateMobile(mobile_stock, num_mobiles);
            break;
        case 4:
            deleteMobile(mobile_stock, num_mobiles);
            break;
        case 5:
            searchMobile(mobile_stock, num_mobiles);
            break;
        case 6:
            cout << "Exiting program. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 6);

    return 0;
}

