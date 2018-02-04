int sort(char filename[20])
{

    char filename1[100];
    // printf("Enter the file name to sort in ascending order\n\n");
    // scanf("%s",filename);
    char* strFileName = filename;
    printf("\nEnter the file name to written the data\n\n");
    scanf("%s", filename1);
    char* strFileSummary = filename1;
    char strTempData[100];
    char** strData = NULL;
    int i, j;
    int noOfLines = 0;

    FILE* ptrFileLog = NULL;
    FILE* ptrSummary = NULL;

    if ((ptrFileLog = fopen(strFileName, "r")) == NULL)
    {
        fprintf(stderr, "Error: Could not open %s\n", strFileName);
        return 1;
    }
    if ((ptrSummary = fopen(strFileSummary, "w")) == NULL)
    {
        fprintf(stderr, "Error: Could not open %s\n", strFileSummary);
        return 1;
    }

    while (fgets(strTempData, 100, ptrFileLog) != NULL)
    {

        if (strchr(strTempData, '\n'))
            strTempData[strlen(strTempData) - 1] = '\0';
        strData = (char**)realloc(strData, sizeof(char**) * (noOfLines + 1));
        strData[noOfLines] = (char*)calloc(100, sizeof(char));
        strcpy(strData[noOfLines], strTempData);
        noOfLines++;
    }
    printf("\n\nThe file is sorted....\n\n");
    for (i = 0; i < (noOfLines - 1); ++i)
    {
        for (j = 0; j < (noOfLines - i - 1); ++j)
        {
            if (strcmp(strData[j], strData[j + 1]) > 0)
            {
                strcpy(strTempData, strData[j]);
                strcpy(strData[j], strData[j + 1]);
                strcpy(strData[j + 1], strTempData);
            }
        }
    }
    printf("The file is written to %s\n", filename1);
    for (i = 0; i < noOfLines; i++)
        fprintf(ptrSummary, "%s\n", strData[i]);

    for (i = 0; i < noOfLines; i++)
        free(strData[i]);

    free(strData);
    fclose(ptrFileLog);
    fclose(ptrSummary);
    return 0;
}
