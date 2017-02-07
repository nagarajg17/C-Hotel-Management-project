#include<iostream>
#include<stdlib.h>
using namespace std;
int main(){

int noofclass,nooflec,perday,total,days,threshold,i=0,j=0,mini,feasible;
cout<<"Enter no of faculties available for invigilation duties:";
cin>>nooflec;
cout<<"Enter the threshold for faculty:";
cin>>threshold;
/*cout<<"Enter no of classes available:";
cin>>noofclass;*/
cout<<"Enter how days exams are conducted:";
cin>>days;
cout<<"Enter no of class needed for conduction of exams per day:";
cin>>perday;
int a[nooflec][3];
total=perday*days;
for(i=0;i<nooflec;i++){
    for(j=0;j<1;j++){
        a[i][j]=0;
        a[i][j+1]=threshold;
        a[i][j+2]=(i+1);

    }
}

mini=total/nooflec;
feasible=(threshold*nooflec)/total;
if((feasible==0)||(threshold<mini)){
    cout<<"Not feasible.Increase the threshold or number of faculties";/*exit since allotment not possible*/
    exit(0);
}

/*allocate atleast 1 class for each teacher*/
for(int i=0;i<nooflec;i++)
{
    for(int j=0;j<1;j++){
        if(a[j]<a[j+1]){
            a[i][j]+=1;
        }

    }
}
/*allocate if allocated count is less than minimum*/
if(mini>a[0][0]){
    for(int i=0;i<nooflec;i++)
{
    for(int j=0;j<1;j++){
        if(a[j]<a[j+1]){
            a[i][j]+=1;
        }

    }
}
}
int diff=total-a[0][0]*nooflec;//calculate still how many classes are left to be allocated
/*allocate remaining classes*/
for(int i=0;i<nooflec;i++)
{
    for(int j=0;j<1;j++){
        if(a[i][j]<threshold&&diff>0){
            a[i][j]+=1;
            diff--;
        }
        else{
            break;
        }

    }
}
/*for(int i=0;i<nooflec;i++)
{
for(int j=0;j<1;j++){
    cout<<"Faculty ID "<<a[i][j+2]<<" has been allocated for "<<a[i][j]<<" invigilation Duties "<<"\n";
}
}*/
cout<<"-----------------------------------------------------\n";
int perdaycount[days];
for(i=0;i<days;i++){
    perdaycount[i]=0;
}
int allocation[nooflec][2+days];
for(i=0;i<nooflec;i++){
    for(j=0;j<1;j++){
        allocation[i][j]=a[i][j];
        allocation[i][j+1]=a[i][j+2];
    }
}
/*for(i=0;i<nooflec;i++){
    for(j=0;j<2;j++){
        cout<<allocation[i][j]<<" ";
    }
    cout<<"\n";
}*/
for(i=0;i<nooflec;i++){
    for(j=2;j<(2+days);j++){
        allocation[i][j]=0;

    }
}
/*for(i=0;i<nooflec;i++){
    for(j=0;j<(2+days);j++){
        cout<<allocation[i][j]<<" ";
    }
    cout<<"\n";
}*/
/*for(i=0;i<4;i++){
    for(j=0;j<2;j++){
        cout<<allocation[i][j]<<" ";
    }
    cout<<"\n";

}*/
//cout<<"----------\n";
for(j=2;j<(2+days);j++){
    for(i=0;i<nooflec;i++){
        if((allocation[i][0]!=0)&&(perdaycount[j-2]!=perday)){
            allocation[i][j]=allocation[i][1];
            allocation[i][0]-=1;
            perdaycount[j-2]+=1;
            //cout<<allocation[i][0]<<" "<<allocation[i][1]<<" "<<allocation[i][2]<<" "<<allocation[i][3]<<" "<<allocation[i][4]<<"\n";
            continue;
        }
        if((perdaycount[j-2]==perday)&&(allocation[i][0]!=0)&&(perdaycount[j-1]!=perday)){
            allocation[i][j+1]=allocation[i][1];

            perdaycount[j-1]+=1;
            allocation[i][0]-=1;
             //cout<<allocation[i][0]<<" "<<allocation[i][1]<<" "<<allocation[i][2]<<" "<<allocation[i][3]<<" "<<allocation[i][4]<<"\n";
        }
    }
    //cout<<"-------------\n";
}
/*for(i=0;i<4;i++){
    for(j=0;j<2;j++){
        cout<<allocation[i][j]<<" ";
    }
    cout<<"\n";
}*/
/*for(i=0;i<nooflec;i++){
    for(j=0;j<(2+days);j++){
        cout<<allocation[i][j]<<" ";
    }
    cout<<"\n";
}*/


 for(j=2;j<(2+days);j++){
        cout<<"Day"<<j-1<<"\n";
    for(i=0;i<nooflec;i++){
                if(allocation[i][j]!=0){
                    cout<<"Faculty ID"<<allocation[i][1]<<" has been allocated room no"<<i+1<<"\n";
                }
            }
  cout<<"-----------------------------------------------\n";

    }


return 0;
}
