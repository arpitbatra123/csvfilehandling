#include "MASTER.H"

#include "FUNCTIONS.H"

int main()
{
    int choice, ncol;
    char f1[20], f2[20];
    printf("1.Create CSV file\n2.Check same structure\n3.Check "
           "duplicate\n4.Remove Duplicates\n5.Sort CSV file Column wise\n6.Union "
           "Operation\n7.Intersect Operation \n8.Print File\nEnter Your Choice\n");
    if (!(scanf("%d", &choice)))
    {
        cout << "Invalid Input Exiting Program\n";
        exit(-98);
    }
    int a = -98;
    switch (choice)
    {

        case 1:
        {
            cout << "Enter no of columns to store in csv file\n";
            if (!(cin >> ncol))
            {
                cout << "Invalid Input\n";
                cin.clear();
                cin.ignore();
                exit(-89);
            }
            if (ncol > 0)
            {

                cout << "number of columns are " << ncol << endl;

                string cols[ncol];
                cout << "Enter Columns\n";
                for (int r = 0; r < ncol; r++)
                {
                    fflush(stdin);
                    getline(cin, cols[r]);
                }

                create(cols, ncol);
            }

            else
                cout << "Enter columns greater than zero";
            break;
        }
        case 2:
            cout << "Enter Name of 2 csv files to compare structure" << endl;
            cin >> f1 >> f2;
            a = isSameStructure(f1, f2);
            if (a)
                printf("Both CSV files are of the same structure");
            else
                printf("Both CSV files are not of the same structure");
            break;
        case 3:
            cout << "Enter Name of  csv file to check if it has duplicate rows" << endl;
            cin >> f1;
            a = isDuplicate(f1);
            if (a == 1)
                printf("\nDuplicate Rows Exist");
            else
                printf("Duplicate Rows do not Exist");
            break;
        case 4:
            cout << "Enter Name of  csv file to remove  duplicate rows" << endl;
            cin >> f1;
            removeDuplicates(f1);
            break;
        case 5:
            cout << "Enter Name of  csv file to sort" << endl;
            cin >> f1;
            sort(f1);
            break;
        case 6:
            cout << "Enter Name of  2 csv files to perform union operation" << endl;
            cin >> f1 >> f2;
            unioncsv(f1, f2);
            break;
        case 7:
            cout << "Enter Name of  2 csv files to perform intersection operation" << endl;
            cin >> f1 >> f2;
            intersectioncsv(f1, f2);
            break;

        case 8:
        {

            cout << "Enter Name of  csv file to print" << endl;
            cin >> f1;
            char c;
            cout << "\nPrinting file" << endl;
            ifstream ip;
            ip.open(f1);
            do
            {
                c = ip.get(); /* get one character from the file
                                                */
                putchar(c); /* display it on the monitor
                                                */
            } while (c != EOF);
            ip.close();
        }
        break;
        default:
            cout << "Wrong Choice\n";
    }

    return 0;
}
