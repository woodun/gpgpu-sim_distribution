#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void stat(string& a)
{
  vector<string> s;
  //cout<<std::atoi(s[1].c_str())<<'\t'<<s[2]<<'\t'<<std::atoi(s[0].c_str())<<endl;
  vector<long> old(16,-1);
  vector<int> count(16,0); // counter
  vector<vector<long> > hit(17);
  for (int i=0;i<17;i++)
    {hit[i].resize(7,0);} // the 7th line is total hit of this bank

  ifstream f(a,ios::in);
  int chip, bank, row;
  //char rw;
  while (!f.eof())
  {
    f>>chip>>bank>>row;
    /*if (bank ==0)
      {cout<<bank<<'\t'<<row<<endl;}*/
    if (chip==0){
      if (old[bank]!=row)
      {
        if (old[bank]!=-1)
        {
          count[bank]-=1;
          hit[bank][count[bank]>5?5:count[bank]]++;
        }
        old[bank]=row;
        count[bank]=1;
      }
      else
        {count[bank]++;}
    }
    //cout<<bank<<" "<<row<<" "<<rw<<"\t"<<count[bank]<<endl;
    //getchar();
  }
  //cout<<"count bank before: "<<count[bank]<<endl;
  count[bank]--;
  //cout<<"count bank new: "<<count[bank]<<endl;
  for (int i=0;i<16;i++)
  {
    if (count[i]>0) {
      count[i]-=1;
      hit[i][count[i]>5?5:count[i]]++;
    }
  }
  // print to console and write to file.
  for (int i=0;i<6;i++)
  {
    for (int j=0;j<16;j++)
    {
      hit[16][i]+=hit[j][i];
    }
  }
  for (int i=0;i<17;i++)
  {
    hit[i][6]=0;
    for (int j=0;j<6;j++)
      {hit[i][6]+=hit[i][j];}
  }
  ofstream amelia("numbers.txt");
  ofstream pp("percent.txt");
  for (int i=0;i<17;i++)  // the 17th line is total amount
  {
    for (int j=0;j<7;j++)
    {
      //cout<<hit[i][j]<<'\t';
      amelia<<hit[i][j]<<'\t';
      if (j!=6){
        if (hit[i][6])
        {
          //cout<<hit[i][j]/(double)hit[i][6]<<'\t';
          pp<<hit[i][j]/(double)hit[i][6]<<'\t';
        }
        else
        {
          //cout<<0<<'\t';
          pp<<0<<'\t';
        }
      }
    }
    //cout<<endl;
    amelia<<endl;
    pp<<endl;
    amelia.flush();
    pp.flush();
  }
  //cout<<"Total line is: "<<line<<endl;
  amelia.close();
  pp.close();
  cout<<"All the stats have been written to files."<<endl;
}


int main()
{
  string a="hit.txt";
  stat(a);
  cout<<"Done."<<endl;
  return 0;
}