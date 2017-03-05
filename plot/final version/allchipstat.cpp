#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void stat(string& a)
{
  /*vector<string> s;
  vector<long> old(16,-1);
  vector<int> count(16,0); // counter
  vector<vector<long> > hit(17);
  for (int i=0;i<17;i++)
    {hit[i].resize(7,0);} // the 7th line is total hit of this bank
  */
  // initialization -- the following matrices will be resized to suit the 6 mem_chips case:
  vector<vector<long> > old(6);  // used to save the last hit row of this bank. old is a 2D matrix(#mem -- #bank)
  vector<vector<int> > count(6); // used to save the current continuous hit number of one bank. count is a 2D matrix(#mem -- #bank)
  vector<vector<vector<long> > > hit(6); // used to save every mem_chip's hit stats. hit is a 3D matrix(#mem -- #bank -- #row_hit_times)

  for (int i=0;i<6;i++)
  {
    old[i].resize(16,-1); // old elements' initial value sets to -1
    count[i].resize(16,0); // count elements' initial value sets to 0
    hit[i].resize(17); // every chip has its own hit record(16 banks + 1 total account)
    for (int j=0;j<17;j++)
    {
      hit[i][j].resize(7,0); // hit resize twice(3D matrix, 6 numbers + 1 total account)
    }
  }

  ifstream f(a,ios::in);
  int chip, bank, row;
  //char rw; // read or write operation, temporarily discard
  while (!f.eof())
  {
    f>>chip>>bank>>row;
    if (old[chip][bank]!=row)
    {
      if (old[chip][bank]!=-1)
      {
        count[chip][bank]-=1;
        hit[chip][bank][count[chip][bank]>5?5:count[chip][bank]]++;
      }
      old[chip][bank]=row;
      count[chip][bank]=1;
    }
    else
      {count[chip][bank]++;}
    //cout<<bank<<" "<<row<<" "<<rw<<"\t"<<count[bank]<<endl; getchar(); // debug flag
  }
  for (int n=0;n<6;n++){
    count[n][bank]--;
    for (int i=0;i<16;i++)
    {
      if (count[n][i]>0) {
        count[n][i]-=1;
        hit[n][i][count[n][i]>5?5:count[n][i]]++;
      }
    }
    for (int i=0;i<6;i++)
    {
      for (int j=0;j<16;j++)
      {
        hit[n][16][i]+=hit[n][j][i];
      }
    }
    for (int i=0;i<17;i++)
    {
      hit[n][i][6]=0;
      for (int j=0;j<6;j++)
        {hit[n][i][6]+=hit[n][i][j];}
    }
  }
  // save to files:
  string number="numbers";
  string percent="percent";
  string post=".txt";
  for (int n=0;n<6;n++) {
    string num, per;
    num=number+to_string(n+1)+post;
    per=percent+to_string(n+1)+post;
    ofstream amelia(num);
    ofstream pp(per);
    for (int i=0;i<17;i++)  // the 17th line is total amount
    {
      for (int j=0;j<7;j++)
      {
        amelia<<hit[n][i][j]<<'\t';
        if (j!=6){
          if (hit[n][i][6])
          {
            pp<<hit[n][i][j]/(double)hit[n][i][6]<<'\t';
          }
          else
          {
            pp<<0<<'\t';
          }
        }
      }
      amelia<<endl;
      pp<<endl;
      amelia.flush();
      pp.flush();
    }
    amelia.close();
    pp.close();
    cout<<"file "<<n+1<<" written."<<endl;
  }
  cout<<"All the stats have been written to files."<<endl;
}


int main()
{
  string a="hit.txt";
  stat(a);
  cout<<"Done."<<endl;
  return 0;
}