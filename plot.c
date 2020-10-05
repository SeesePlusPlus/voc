/*69:*/
#line 124 "./debug.w"

#include <soundpipe.h> 
#include <string.h> 
#include <stdlib.h> 
#include "voc.h"

static void plot_tract()
{
sp_voc*voc;
sp_data*sp;
SPFLOAT*tract;
int size;
int i;

sp_create(&sp);
sp_voc_create(&voc);
sp_voc_init(sp,voc);

tract= sp_voc_get_tract_diameters(voc);
size= sp_voc_get_tract_size(voc);

for(i= 0;i<size;i++){
printf("%i\t%g\n",i,tract[i]);
}

sp_voc_destroy(&voc);
sp_destroy(&sp);
}

static void plot_nose()
{
sp_voc*voc;
sp_data*sp;
SPFLOAT*nose;
int size;
int i;

sp_create(&sp);
sp_voc_create(&voc);
sp_voc_init(sp,voc);

nose= sp_voc_get_nose_diameters(voc);
size= sp_voc_get_nose_size(voc);

for(i= 0;i<size;i++){
printf("%i\t%g\n",i,nose[i]);
}

sp_voc_destroy(&voc);
sp_destroy(&sp);
}

static void plot_tongue_shape(int num)
{
sp_voc*voc;
sp_data*sp;
SPFLOAT*tract;
int size;
int i;

sp_create(&sp);
sp_voc_create(&voc);
sp_voc_init(sp,voc);

tract= sp_voc_get_tract_diameters(voc);
size= sp_voc_get_tract_size(voc);

switch(num){
case 1:
sp_voc_set_tongue_shape(voc,20.5,3.5);
break;
case 2:
sp_voc_set_tongue_shape(voc,25.5,3.5);
break;
case 3:
sp_voc_set_tongue_shape(voc,20.5,2.0);
break;
case 4:
sp_voc_set_tongue_shape(voc,24.8,1.4);
break;
}

for(i= 0;i<size;i++){
printf("%i\t%g\n",i,tract[i]);
}

sp_voc_destroy(&voc);
sp_destroy(&sp);
}

int main(int argc,char**argv)
{
if(argc<2){
fprintf(stderr,"Usage: %s plots/name.dat\n",argv[0]);
exit(1);
}
if(!strncmp(argv[1],"plots/tract.dat",100)){
plot_tract();
}else if(!strncmp(argv[1],"plots/nose.dat",100)){
plot_nose();
}else if(!strncmp(argv[1],"plots/tongueshape1.dat",100)){
plot_tongue_shape(1);
}else if(!strncmp(argv[1],"plots/tongueshape2.dat",100)){
plot_tongue_shape(2);
}else if(!strncmp(argv[1],"plots/tongueshape3.dat",100)){
plot_tongue_shape(3);
}else if(!strncmp(argv[1],"plots/tongueshape4.dat",100)){
plot_tongue_shape(4);
}else{
fprintf(stderr,"Plot: could not find plot %s\n",argv[1]);
exit(1);
}
return 0;
}
#line 138 "./voc.w"

#line 1 "./ugen.w"
/*:69*/
