#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<stdio.h>
int main()
{
int fd,pt;
struct flock r1,r2;
fd=open("myfile22",O_CREAT|O_RDWR,0666);
r1.l_type=F_WRLCK;
r1.l_whence=SEEK_SET;
r1.l_start=40;
r1.l_len=20;
pt=fcntl(fd,F_SETLK,&r1);
if(pt==-1)
{
printf("Error in locking region1 in p2\n");

}
else
{
printf("Rescource allocated1 in p2 40 - 60\n");

}sleep(5);
r2.l_type=F_WRLCK;
r2.l_whence=SEEK_SET;
r2.l_start=10;
r2.l_len=20;
pt=-1;
while(pt==-1)
{
  pt=fcntl(fd,F_SETLK,&r2);
if(pt==-1)
{
printf("  waiting for resource(10-30) in P2\n"); sleep(3);

}
else
{
printf("Region2Locked in p2 10 - 30\n");

}
}

sleep(20);
}
