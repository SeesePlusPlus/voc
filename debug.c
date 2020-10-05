/*68:*/
#line 26 "./debug.w"

#include <soundpipe.h> 
#include <string.h> 
#include <stdlib.h> 
#include "voc.h"

static void process(sp_data*sp,void*ud)
{
SPFLOAT out;
sp_voc*voc= ud;

sp_voc_compute(sp,voc,&out);

sp_out(sp,0,out);
}

static void run_voc(long len,int type)
{
sp_voc*voc;
sp_data*sp;

sp_create(&sp);
sp->len= len;
sp_voc_create(&voc);
sp_voc_init(sp,voc);

if(type==0){
sp_process_plot(sp,voc,process);
}else{
sp_process(sp,voc,process);
}

sp_voc_destroy(&voc);
sp_destroy(&sp);
}

static void run_tongue(SPFLOAT tongue_index,SPFLOAT tongue_diameter)
{
sp_voc*voc;
sp_data*sp;

sp_create(&sp);
sp_voc_create(&voc);
sp_voc_init(sp,voc);

fprintf(stderr,"Tongue index: %g. Tongue diameter: %g\n",
tongue_index,
tongue_diameter);
sp_voc_set_tongue_shape(voc,tongue_index,tongue_diameter);
sp_process(sp,voc,process);

sp_voc_destroy(&voc);
sp_destroy(&sp);
}

int main(int argc,char*argv[])
{

if(argc==1){
fprintf(stderr,"Pick a mode!\n");
exit(0);
}

if(!strcmp(argv[1],"plot")){
if(argc<3){
fprintf(stderr,
"Usage: %s plot duration (samples)\n",
argv[0]);
exit(0);
}
run_voc(atoi(argv[2]),0);
}else if(!strcmp(argv[1],"audio")){
if(argc<3){
fprintf(stderr,
"Usage: %s audio duration (samples)\n",
argv[0]);
exit(0);
}
run_voc(atoi(argv[2]),1);
}else if(!strcmp(argv[1],"tongue")){
if(argc<4){
fprintf(stderr,"Usage %s tongue tongue_index tongue_diameter\n",
argv[0]);
exit(0);
}
run_tongue(atof(argv[2]),atof(argv[3]));
}else{
fprintf(stderr,"Error: invalid type %s\n",argv[1]);
}

return 0;
}

/*:68*/
