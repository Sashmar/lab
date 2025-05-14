#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
# define NOF_PACKETS 10
int mrand(int a){
int rn=(random()%10)%a;
return rn=0 ? 1 : rn;
}
int main(){
int i,p_sz_rm=0,p_sz,p_time,b_size,o_rate,op,packet_sz[NOF_PACKETS],clk;
printf("packet size:");
for(i=0;i<NOF_PACKETS;++i){
packet_sz[i]=mrand(6)*10;
}
for(i=0;i<NOF_PACKETS;++i){
printf("the packets[%d]: %d\n",i,packet_sz[i]);
}
printf("output rate:");
scanf("%d",&o_rate);
printf("bucket size:");
scanf("%d",&b_size);

for(i=0;i<NOF_PACKETS;++i){
if(p_sz_rm+packet_sz[i]>b_size){
if(packet_sz[i]>b_size){
printf("\nincomindg packet :%d bytes greater than bucket capacity(%d bytes)-PACKET REJECTED",packet_sz[i],b_size);}
else{
printf("\nPACKET REJECTED");
}}
else{
p_sz_rm+=packet_sz[i];
printf("\n the packet sizeis:%d",packet_sz[i]);
printf("\n the remaining bytes is %d",p_sz_rm);
p_time=mrand(4)*10;
printf("\nthe transmissioin time is %d",p_time);
for(clk=10;clk<p_time;clk+=10){
sleep(1);
if(p_sz_rm){
if(p_sz_rm<o_rate){
op=p_sz_rm,p_sz_rm=0;
}
else{
op=o_rate,p_sz_rm-=o_rate;}
printf("\n the packet size transmitted is:%d",op);
printf("\n the remaining bytes is %d",p_sz_rm);
}
else{
printf("\nthe transmitted time is :%d",p_time);
printf("\nall bytes are transmitted");
}
}
}
}
}
