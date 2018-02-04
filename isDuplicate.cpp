int isDuplicate(char filename[20])
{
    int index = 0, flag = 0;
    cout << "The name of the file is " << filename << endl;
    ifstream ip;
    ip.open(filename);
    if (!(ip.is_open()))
    {
        cout << "\nUnable to read file\n ERROR!!!!" << endl;
        exit(0);
    }

    string lines[1000], temp = "";

    do
    {
        getline(ip, temp);
        // cout<<"temp is "<<temp<<endl;
        lines[index++] = temp;
        // cout<<"lines is  "<<lines[index-1]<<endl;

    } while (ip.peek() != EOF);

    for (int i = 0; i < index; i++)
    {
        for (int j = i + 1; j < index; j++)
        {
            if (lines[i] == lines[j])
            {
                flag = 1;
                break;
            }
        }
    }

    return flag;
}
