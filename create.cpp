
void create(string headers[], int nCol)
{
    string filename;
    string temp;
    int nos, i = 0, j = 0,c = 0;
    // string names[max];
    cout << "CSV file is being created with the following column names " << endl;
    for (int m = 0; m < nCol; m++)
        cout << headers[m] << " ";

    cout << "\nEnter filename for CSV file" << endl;
    fflush(stdin);
    getline(cin,filename);
    ofstream op;
    op.open(filename.c_str());
    if (!(op.is_open()))
    {
        cout << "\nUnable to create file\n ERROR!!!!" << endl;
        exit(0);
    }
    cout << "The filename is " << filename << endl;
    cout << "Writing columns to file " << endl;
    for (int m = 0; m < nCol; m++)
    {
        op << headers[m];
        if (m == (nCol - 1))
            continue;
        op << ",";
    }

    op << endl;
    cout << "columns written" << endl;

    cout << "Enter no of rows to store in CSV file \n";
    cin >> nos;

    string matrix[nos][nCol];

    if (nos > 0)
    {
        cout << "Enter Data Column-wise ";
        cout << "for " << nos << " rows\n";
        cout << "Example if CSV file is name,roll  and no of rows are 3 then enter\n "
                << "a  ENTER 16 ENTER b  ENTER 17 ENTER n ENTER 18 ENTER"
             << endl;
        cout << "Enter in Format :\n";
        for (int m = 0; m < nCol; m++)
            cout << headers[m] << " ";
        cout << endl;

        for (i = 0; i < nos; i++)

        {
            for (j = 0; j < nCol; j++)
            {
                fflush(stdin);
                getline(cin, matrix[i][j]);
            }
        }

        cout << "printing matrix\n";
    }
    for (i = 0; i < nos; i++)
    {
        for (j = 0; j < nCol; j++)
            cout << matrix[i][j] << " ";
        cout << "\n";
    }

    cout << "Writing to file\n";

    for (i = 0; i < nos; i++)
    {
        for (j = 0; j < nCol; j++)
        {
            op << matrix[i][j];
            if (j == (nCol - 1))
                continue;
            op << ",";
        }

        op << endl;
    }
    op.close();
    ifstream ip;
    ip.open(filename.c_str());
    printf("Verifying contents of  file\n");
    do
    {
        c = ip.get(); /* get one character from the file
                                        */
        putchar(c); /* display it on the monitor
                                        */
    } while (c != EOF);
    ip.close();
}
