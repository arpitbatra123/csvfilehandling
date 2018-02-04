int isSameStructure(char file1[10], char file2[10])
{
    
    string header1;
    string header2;
    ifstream ip, ip1;
    ip.open(file1);
    if (ip.is_open() != 1)
    {

        cout << "Unable to open file " << file1 << endl;
        exit(1);
    }

    ip1.open(file2);
    if (ip1.is_open() != 1)
    {

        cout << "Unable to open file " << file2 << endl;
        exit(1);
    }

    getline(ip, header1);
    getline(ip1, header2);

    if (header1 == header2)
        return 1;
    else
        return 0;
};
