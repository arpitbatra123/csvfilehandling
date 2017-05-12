#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<sstream>
//#define max 10000
#include<cstring>
using namespace std;

void create(string headers[],int nCol)
{
    char filename[20];
    string temp;
    char x;
    int nos,i=0,j=0,r=0,c=0;
    //string names[max];
    cout<<"CSV file is being created with the following column names "  <<endl;
    for(int m=0;m<nCol;m++)
        cout<<headers[m]<<" ";

    cout<<"\nEnter filename for CSV file"<<endl;
    fflush(stdin);
    gets(filename);
    ofstream op;
    op.open(filename);
    if(!(op.is_open()))
    {
        cout<<"\nUnable to create file\n ERROR!!!!"<<endl;
        exit(0);
    }
   cout<<"The filename is " << filename << endl;
   cout<<"Writing columns to file " <<endl;
   for(int m=0;m<nCol;m++)
    {  op<<headers[m];
        if(m==(nCol-1))
        continue;
        op<<",";

    }

   op<<endl;
   cout<<"columns written"<<endl;


   cout << "Enter no of rows to store in CSV file \n";
   cin>>nos;

   string matrix[nos][nCol];




   if(nos>0)
  { cout<<"Enter Data Column-wise ";
    cout<<"for " << nos << " rows\n" ;
    cout<<"Example if csv file is name,roll  and no of rows are 3 then enter a  ENTER 16 ENTER b  ENTER 17 ENTER n ENTER 18 ENTER"<<endl;
    cout<<"Enter in Format :\n";
    for(int m=0;m<nCol;m++)
        cout<<headers[m]<<" ";
        cout<<endl;



    for(i=0; i<nos; i++)

    {   for(j=0; j<nCol; j++)
         {    fflush(stdin);
              getline(cin,matrix[i][j]);
         }




    }

   cout<<"printing matrix\n";
}
   for(i=0; i<nos; i++)
     {
         for(j=0; j<nCol; j++)
            cout<<matrix[i][j]<<" ";
            cout<<"\n";

     }

     cout<<"Writing to file\n";

     for(i=0; i<nos; i++)
     {
         for(j=0; j<nCol; j++)
           { op<<matrix[i][j];
            if(j==(nCol-1))
            continue;
            op<<",";

           }

           op<<endl;
     }
    op.close();
    ifstream ip;
    ip.open(filename);
    printf("Verifying contents of  file\n");
    do
    {
        c = ip.get(); /* get one character from the file
                                        */
        putchar(c); /* display it on the monitor
                                        */
    }
    while (c != EOF);
    ip.close();

}
int isSameStructure(char file1[10],char  file2[10])
{
    int ncol1=0,ncol2=0;
    string header1;
    string header2;
    ifstream ip,ip1;
    char c;
    ip.open(file1);
    if( ip.is_open() !=1  )
    {

        cout<<"Unable to open file "<<file1<<endl;
        exit(1);
    }

    ip1.open(file2);
    if( ip1.is_open() !=1  )
    {

        cout<<"Unable to open file "<<file2<<endl;
        exit(1);
    }


    getline(ip,header1);
    getline(ip1,header2);
    ip1.seekg(0);
    ip.seekg(0);
    do
    {
        c = ip.get();
          if( c == ',')
            ncol1++;


    }
    while (c !='\n');
    do
    {
        c = ip1.get();
        if( c == ',')
            ncol2++;


    }while (c !='\n');

   // cout<<header1<<header2<<ncol1<<ncol2<<endl;
    if(header1==header2 && ncol1==ncol2)
        return 1;
    else
        return 0;


};

int isDuplicate(char filename[20])
{
    int index=0,flag=0;
    cout<<"The name of the file is "<<filename<<endl;
    ifstream ip;
    ip.open(filename);
    if(!(ip.is_open()))
    {
        cout<<"\nUnable to read file\n ERROR!!!!"<<endl;
        exit(0);
    }

    string lines[1000],temp="";

    do
    {
        getline(ip,temp);
        //cout<<"temp is "<<temp<<endl;
        lines[index++]=temp;
        //cout<<"lines is  "<<lines[index-1]<<endl;

    }while(ip.peek()!=EOF);

   for(int i=0; i<index ;i++)
     { for(int j=i+1; j<index ;j++)
        { if(lines[i]==lines[j])
             {
                 flag=1;
                 break;
             }


        }
     }

     return flag;





}

 void removeDuplicates(string fname){
		 string str1="",str2="";
		 char filename[200],filenameTemp[200];
		 string line;
		 int lines=0;
		 int i=0,j=0,c;
		 int w=1;


		strcpy(filename,fname.c_str());
        strcpy (filenameTemp, filename);
        strcat (filenameTemp, ".bak") ;

		 ifstream file(filename);


		if( file.is_open()== false)
        {
            cout<<"Unable to open file\n";
            exit(-99);


        }


		while(file.good()){
			getline(file,str1);
			ifstream file1(filenameTemp);
			w=1;

			while(file1.good()){
				getline(file1,str2);
				if(str1.compare(str2)==0){
					w=0;
					break;
				}
			}

			file1.close();
			if(w){
				ofstream file2(filenameTemp,ios::app);
				file2<<str1<<endl;
				file2.close();
			}

		}

	     file.close();

	     	cout <<"Duplicates rows of " <<filename<<" removed"<<endl;
			remove (filename);
			rename(filenameTemp,filename);


 }

int sort(char filename[20])
{


    char filename1[100];
    //printf("Enter the file name to sort in ascending order\n\n");
    //scanf("%s",filename);
    char *strFileName = filename;
    printf("\nEnter the file name to written the data\n\n");
    scanf("%s",filename1);
    char *strFileSummary = filename1;
    char strTempData[100];
    char **strData = NULL;
    int i, j;
    int noOfLines = 0;

    FILE * ptrFileLog = NULL;
    FILE * ptrSummary = NULL;

    if ( (ptrFileLog = fopen(strFileName, "r")) == NULL ) {
        fprintf(stderr,"Error: Could not open %s\n",strFileName);
        return 1;
    }
    if ( (ptrSummary = fopen(strFileSummary, "w")) == NULL ) {
        fprintf(stderr,"Error: Could not open %s\n",strFileSummary);
        return 1;
    }


    while(fgets(strTempData, 100, ptrFileLog) != NULL) {

        if(strchr(strTempData,'\n'))
            strTempData[strlen(strTempData)-1] = '\0';
        strData = (char**)realloc(strData, sizeof(char**)*(noOfLines+1));
        strData[noOfLines] = (char*)calloc(100,sizeof(char));
        strcpy(strData[noOfLines], strTempData);
        noOfLines++;
    }
    printf("\n\nThe file is sorted....\n\n");
    for(i= 0; i < (noOfLines - 1); ++i) {
        for(j = 0; j < ( noOfLines - i - 1); ++j) {
            if(strcmp(strData[j], strData[j+1]) > 0) {
                strcpy(strTempData, strData[j]);
                strcpy(strData[j], strData[j+1]);
                strcpy(strData[j+1], strTempData);
            }
        }
    }
    printf("The file is written to %s\n",filename1);
    for(i = 0; i < noOfLines; i++)
        fprintf(ptrSummary,"%s\n",strData[i]);

    for(i = 0; i < noOfLines; i++)
        free(strData[i]);

    free(strData);
    fclose(ptrFileLog);
    fclose(ptrSummary);
    return 0;
}




void unioncsv(char file1[20],char file2[20])
{   string heads1[100],heads2[100],temp1,temp2,temp3,ff;
    int if1=0,if2=0,cn1=0,cn2=0;
    ifstream ip1(file1),ip2(file2);
     if(  !(ip1.is_open()) )
    {  cout<<"Unable to open file"<<file1<<endl;
       exit(0);





    }

    ip1.seekg(0, ios::end);
    if (ip1.tellg() == 0) {
      cout<< "file empty "<<file1<<endl;
      exit(0);
    }

    ip1.seekg(0);

     if(  !(ip2.is_open()) )
    {  cout<<"Unable to open file"<<file2<<endl;
       exit(0);




    }
    ofstream op1("t.csv");
    ofstream o1("yoyoy.csv");
    ofstream o2("yoyoy2.csv");
    fstream oo1("yoyoy.csv");
    fstream oo2("yoyoy2.csv");

     if(  !(oo1.is_open()) )
    {  cout<<"Unable to open file yoyoy.csv";
       exit(0);




    }

     if(  !(oo2.is_open()) )
    {  cout<<"Unable to open file yoyoy2.csv";
       exit(0);




    }
  int count1=0,count2=0,nrow1=0,nrow2=0;
  getline(ip1,temp1);
  getline(ip2,temp2);
  temp1=temp1+",";
  temp2=temp2+",";
  stringstream x;
  x<<temp1;
  stringstream y;
  y<<temp2;


 while(x.good())
  {  getline(x,heads1[count1++],',');



  }
  count1--;

  while(y.good())
  {  getline(y,heads2[count2++],',');



  }
  count2--;


  while(ip1.good() )
  {
      getline(ip1,temp3);
      nrow1++;
  }

     while(ip2.good() )
  {
      getline(ip2,temp3);
      nrow2++;
  }
  ip1.close();
  ip2.close();
  ip1.open(file1);
  ip2.open(file2);
  //cout<<count1<<" "<< count2<<endl;
  //cout<<nrow1<<" "<<nrow2<<endl;

   string mat1[nrow1][count1]={""};
   string mat2[nrow2][count2]={""};


    getline(ip1,temp1);
    getline(ip2,temp2);



    while (ip1.good())
    {   fflush(stdin);
        getline(ip1,ff);
       oo1<< ff << "," <<endl;

    }

    while (ip2.good())
    {   fflush(stdin);
        getline(ip2,ff);
        oo2<< ff << "," <<endl;


    }

    oo1.seekg(0);
    oo2.seekg(0);

     string truck="              ";

    for(int i=0;i<nrow1;i++)
    {   for(int j=0;j<count1;j++)
           {   fflush(stdin);
               if(oo1.good())
               {  getline(oo1,truck,',');
                  //cout<<truck<<" ";
                  mat1[i][j]=truck;
               }

                else
                break;

           }




    }

  for(int i=0;i<nrow2;i++)
    {   for(int j=0;j<count2;j++)
           {   fflush(stdin);
               if(oo2.good())
               {  getline(oo2,truck,',');
                  //cout<<truck<<" ";
                  mat2[i][j]=truck;
               }

                else
                break;

           }





    }

    for(int i=0;i<nrow1;i++)
     { for(int j=0;j<count1;j++)
        cout<< mat1[i][j];
        cout<<endl;

     }

        for(int i=0;i<nrow2;i++)
       {

       for(int j=0;j<count2;j++)
        cout<< mat2[i][j];
        cout<<endl;
       }

    cout<<"The first file contains the following columns\n";
    for(int c=0;c<count1;c++)
        cout<<heads1[c]<< " ";
        cout<<endl;
    cout<<"The second file contains the following columns\n";
    for(int c=0;c<count2;c++)
        cout<<heads2[c]<< " ";
        cout<<endl;

        string fu;
        cout<<"Enter a column name that exists in both files to perform union operation\n";
        getline(cin,fu);



        for(int c=0;c<count1;c++)
         {  if (heads1[c]==fu)
            {   cn1++;
                if1++;
                break;
            }

         }
         for(int c=0;c<count2;c++)
          { if (heads2[c]==fu)
            {   cn2++;
                if2++;
                break;
            }
          }

          //cout<<if1<<if2;



         if ( !(if1>0 && if2>0) )
         {
             cout<<"Column name not in both files\n";
             exit(-980);


         }





        else{
                ofstream file3("result.csv");
                int r=cn1;
                int r1=cn2;


                 for(int j=0;j<count1;j++)
                    file3<<mat1[j][r]<<endl;

                 for(int j=0;j<count2;j++)
                    file3<<mat2[j][r1]<<endl;

                    file3.close();



              removeDuplicates("result.csv");

              cout<<"Union file saved in file"<<" result.csv";












           }





}
long Rows(char file[20])
{
    char c2;
    ifstream ip(file);
    long row=0;
    c2=ip.get();
    while(c2!=EOF)
    {
        if(c2=='\n')
            row++;
        c2=ip.get();
    }
    return row++;
}
long Columns(char file[20])
{
    char c1;
    ifstream ip(file);
    long column=0;
    c1=ip.get();
    while(c1!='\n')
    {
        if(c1==',')
            column++;
        c1=ip.get();
    }
    return column++;
}
void intersectioncsv(char f1[20],char f2[20])
{
    ifstream ix(f1);
    ofstream oo("yoyoy.csv");
    string ff,ff1;
    while (ix.good())
    {
       fflush(stdin);
       getline(ix,ff);
       oo<< ff << "," <<endl;
    }
    ifstream ix1(f2);
    ofstream oo1("yoyoy1.csv");
    while (ix1.good())
    {
       fflush(stdin);
       getline(ix1,ff1);
       oo1<< ff1<< "," <<endl;
    }
    long row1,row2,column1,column2,i,j,r=1,c=1,y,max,min,rp=1;
    ifstream ip2("yoyoy.csv"),ip3("yoyoy1.csv");
    ofstream out("out.csv");
    row1=Rows("yoyoy.csv");
    column1=Columns("yoyoy.csv");
    row2=Rows("yoyoy1.csv");
    column2=Columns("yoyoy.csv");
    string Matrix1[row1+1][column1+1],Matrix2[row2+1][column2+1];
    while(r<=row1)
    {
        c=1;
        while(c<=column1)
        {
            getline(ip2,Matrix1[r][c],',');
            c++;
        }
        r++;
    }
    r=1;
    c=1;
    while(r<=row2)
    {
        c=1;
        while(c<=column2)
        {
            getline(ip3,Matrix2[r][c],',');
            c++;
        }
        r++;
    }
    cout << "Enter Column no.:-"<<endl;
    cin >> y;
    if(row1>row2)
    {
        max=row1;
        min=row2;
    }
    else
    {
        max=row2;
        min=row1;
    }
    string Result[max+3];
    for(i=1;i<=min;i++)
    {
        if(Matrix1[i][y]==Matrix2[i][y])
        {
            Result[rp++]=Matrix1[i][y];
        }
    }
    for(i=1;i<=rp-1;i++)
        out << Result[i] <<",";
    out.close();
}

int main()
{
    int choice,ncol;
    char f1[20],f2[20];
     printf("1.Create CSV file\n2.Check same structure\n3.Check duplicate\n4.Remove Duplicates\n5.Sort csv file Column wise\n6.Union Operation\n7.Intersect Operation \n10.Print File\nEnterChoice\n");
     if(  !(scanf("%d",&choice)))
     {
         cout<<"Invalid Input Exiting Program\n";
         exit(-98);

     }
    int a=-98;
    switch(choice)
    {

    case 1:
       {  cout<<"Enter no of columns to store in csv file\n";
          if ( ! (cin>>ncol) )
          {
              cout<<"Invalid Input\n";
              cin.clear();
              cin.ignore();
              exit(-89);

          }
        if(ncol>0)
        {


        cout<<"number of columns are "<<ncol<<endl;

        string cols[ncol];
        cout<<"Enter Columns\n";
        for(int r=0;r<ncol;r++)
             {   fflush(stdin);
                 getline(cin,cols[r]);
             }

        create(cols,ncol);
        }

        else
            cout<<"Enter columns greater than zero";
        break;

       }
    case 2:
        cout<<"Enter Name of 2 csv files to compare structure"<<endl;
        cin>>f1>>f2;
        a=isSameStructure(f1,f2);
        if(a)
            printf("Both CSV files are of the same structure");
        else
            printf("Both CSV files are not of the same structure");
        break;
    case 3:
        cout<<"Enter Name of  csv file to check if it has duplicate rows"<<endl;
        cin>>f1;
        a=isDuplicate(f1);
       // printf("\na is %d  \n",a);
        if(a==1)
            printf("\nDuplicate Rows Exist");
        else
            printf("Duplicate Rows do not Exist");
        break;
   case 4:
        cout<<"Enter Name of  csv file to remove  duplicate rows"<<endl;
        cin>>f1;
        removeDuplicates(f1);
        break;
   case 5:
        cout<<"Enter Name of  csv file to sort"<<endl;
        cin>>f1;
        sort(f1);
        break;
   case 6:
        cout<<"Enter Name of  2 csv files to perform union operation"<<endl;
        cin>>f1>>f2;
        unioncsv(f1,f2);
        break;
   case 7:
        cout<<"Enter Name of  2 csv files to perform intersection operation"<<endl;
        cin>>f1>>f2;
        intersectioncsv(f1,f2);
        break;

    case 10:
       {

        cout<<"Enter Name of  csv file to print"<<endl;
        cin>>f1;
        char c;
         cout<<"\nPrinting file"<<endl;
             ifstream ip;
             ip.open(f1);
    do
    {
        c = ip.get(); /* get one character from the file
                                        */
        putchar(c); /* display it on the monitor
                                        */
    }
    while (c != EOF);
    ip.close();
    }
    break;
    default:
        cout<<"Wrong Choice\n";

    }


    return 0;
}

