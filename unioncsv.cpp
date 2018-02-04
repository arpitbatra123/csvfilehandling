void unioncsv(char file1[20], char file2[20])
{
    string heads1[100], heads2[100], temp1, temp2, temp3, ff;
    int if1 = 0, if2 = 0, cn1 = 0, cn2 = 0;
    ifstream ip1(file1), ip2(file2);
    if (!(ip1.is_open()))
    {
        cout << "Unable to open file" << file1 << endl;
        exit(0);
    }

    ip1.seekg(0, ios::end);
    if (ip1.tellg() == 0)
    {
        cout << "file empty " << file1 << endl;
        exit(0);
    }

    ip1.seekg(0);

    if (!(ip2.is_open()))
    {
        cout << "Unable to open file" << file2 << endl;
        exit(0);
    }
    ofstream op1("t.csv");
    ofstream o1("yoyoy.csv");
    ofstream o2("yoyoy2.csv");
    fstream oo1("yoyoy.csv");
    fstream oo2("yoyoy2.csv");

    if (!(oo1.is_open()))
    {
        cout << "Unable to open file yoyoy.csv";
        exit(0);
    }

    if (!(oo2.is_open()))
    {
        cout << "Unable to open file yoyoy2.csv";
        exit(0);
    }
    int count1 = 0, count2 = 0, nrow1 = 0, nrow2 = 0;
    getline(ip1, temp1);
    getline(ip2, temp2);
    temp1 = temp1 + ",";
    temp2 = temp2 + ",";
    stringstream x;
    x << temp1;
    stringstream y;
    y << temp2;

    while (x.good())
    {
        getline(x, heads1[count1++], ',');
    }
    count1--;

    while (y.good())
    {
        getline(y, heads2[count2++], ',');
    }
    count2--;

    while (ip1.good())
    {
        getline(ip1, temp3);
        nrow1++;
    }

    while (ip2.good())
    {
        getline(ip2, temp3);
        nrow2++;
    }
    ip1.close();
    ip2.close();
    ip1.open(file1);
    ip2.open(file2);
    // cout<<count1<<" "<< count2<<endl;
    // cout<<nrow1<<" "<<nrow2<<endl;

    string mat1[nrow1][count1] = { "" };
    string mat2[nrow2][count2] = { "" };

    getline(ip1, temp1);
    getline(ip2, temp2);

    while (ip1.good())
    {
        fflush(stdin);
        getline(ip1, ff);
        oo1 << ff << "," << endl;
    }

    while (ip2.good())
    {
        fflush(stdin);
        getline(ip2, ff);
        oo2 << ff << "," << endl;
    }

    oo1.seekg(0);
    oo2.seekg(0);

    string truck = "              ";

    for (int i = 0; i < nrow1; i++)
    {
        for (int j = 0; j < count1; j++)
        {
            fflush(stdin);
            if (oo1.good())
            {
                getline(oo1, truck, ',');
                // cout<<truck<<" ";
                mat1[i][j] = truck;
            }

            else
                break;
        }
    }

    for (int i = 0; i < nrow2; i++)
    {
        for (int j = 0; j < count2; j++)
        {
            fflush(stdin);
            if (oo2.good())
            {
                getline(oo2, truck, ',');
                // cout<<truck<<" ";
                mat2[i][j] = truck;
            }

            else
                break;
        }
    }

    for (int i = 0; i < nrow1; i++)
    {
        for (int j = 0; j < count1; j++)
            cout << mat1[i][j];
        cout << endl;
    }

    for (int i = 0; i < nrow2; i++)
    {

        for (int j = 0; j < count2; j++)
            cout << mat2[i][j];
        cout << endl;
    }

    cout << "The first file contains the following columns\n";
    for (int c = 0; c < count1; c++)
        cout << heads1[c] << " ";
    cout << endl;
    cout << "The second file contains the following columns\n";
    for (int c = 0; c < count2; c++)
        cout << heads2[c] << " ";
    cout << endl;

    string fu;
    cout << "Enter a column name that exists in both files to perform union "
            "operation\n";
    getline(cin, fu);

    for (int c = 0; c < count1; c++)
    {
        if (heads1[c] == fu)
        {
            cn1++;
            if1++;
            break;
        }
    }
    for (int c = 0; c < count2; c++)
    {
        if (heads2[c] == fu)
        {
            cn2++;
            if2++;
            break;
        }
    }

    // cout<<if1<<if2;

    if (!(if1 > 0 && if2 > 0))
    {
        cout << "Column name not in both files\n";
        exit(-980);
    }

    else
    {
        ofstream file3("result.csv");
        int r = cn1;
        int r1 = cn2;

        for (int j = 0; j < count1; j++)
            file3 << mat1[j][r] << endl;

        for (int j = 0; j < count2; j++)
            file3 << mat2[j][r1] << endl;

        file3.close();

        removeDuplicates("result.csv");

        cout << "Union file saved in file"
             << " result.csv";
    }
}
