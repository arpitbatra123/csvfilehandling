

long Rows(char file[20])
{
    char c2;
    ifstream ip(file);
    long row = 0;
    c2 = ip.get();
    while (c2 != EOF)
    {
        if (c2 == '\n')
            row++;
        c2 = ip.get();
    }
    return row++;
}

long Columns(char file[20])
{
    char c1;
    ifstream ip(file);
    long column = 0;
    c1 = ip.get();
    while (c1 != '\n')
    {
        if (c1 == ',')
            column++;
        c1 = ip.get();
    }
    return column++;
}


void intersectioncsv(char f1[20], char f2[20])
{
    ifstream ix(f1);
    ofstream oo("yoyoy.csv");
    string ff, ff1;
    while (ix.good())
    {
        fflush(stdin);
        getline(ix, ff);
        oo << ff << "," << endl;
    }
    ifstream ix1(f2);
    ofstream oo1("yoyoy1.csv");
    while (ix1.good())
    {
        fflush(stdin);
        getline(ix1, ff1);
        oo1 << ff1 << "," << endl;
    }
    long row1, row2, column1, column2, i, j, r = 1, c = 1, y, max, min, rp = 1;
    ifstream ip2("yoyoy.csv"), ip3("yoyoy1.csv");
    ofstream out("out.csv");
    row1 = Rows("yoyoy.csv");
    column1 = Columns("yoyoy.csv");
    row2 = Rows("yoyoy1.csv");
    column2 = Columns("yoyoy.csv");
    string Matrix1[row1 + 1][column1 + 1], Matrix2[row2 + 1][column2 + 1];
    while (r <= row1)
    {
        c = 1;
        while (c <= column1)
        {
            getline(ip2, Matrix1[r][c], ',');
            c++;
        }
        r++;
    }
    r = 1;
    c = 1;
    while (r <= row2)
    {
        c = 1;
        while (c <= column2)
        {
            getline(ip3, Matrix2[r][c], ',');
            c++;
        }
        r++;
    }
    cout << "Enter Column no.:-" << endl;
    cin >> y;
    if (row1 > row2)
    {
        max = row1;
        min = row2;
    }
    else
    {
        max = row2;
        min = row1;
    }
    string Result[max + 3];
    for (i = 1; i <= min; i++)
    {
        if (Matrix1[i][y] == Matrix2[i][y])
        {
            Result[rp++] = Matrix1[i][y];
        }
    }
    for (i = 1; i <= rp - 1; i++)
        out << Result[i] << ",";
    out.close();
}
