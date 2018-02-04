void removeDuplicates(string fname)
{
    string str1 = "", str2 = "";
    char filename[200], filenameTemp[200];
    string line;
    int w = 1;

    strcpy(filename, fname.c_str());
    strcpy(filenameTemp, filename);
    strcat(filenameTemp, ".bak");

    ifstream file(filename);

    if (file.is_open() == false)
    {
        cout << "Unable to open file\n";
        exit(-99);
    }

    while (file.good())
    {
        getline(file, str1);
        ifstream file1(filenameTemp);
        w = 1;

        while (file1.good())
        {
            getline(file1, str2);
            if (str1.compare(str2) == 0)
            {
                w = 0;
                break;
            }
        }

        file1.close();
        if (w)
        {
            ofstream file2(filenameTemp, ios::app);
            file2 << str1 << endl;
            file2.close();
        }
    }

    file.close();

    cout << "Duplicates rows of " << filename << " removed" << endl;
    remove(filename);
    rename(filenameTemp, filename);
}
