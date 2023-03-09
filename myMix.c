//
//  main.c
//  myMixture
//
//  Created by mh0986 on 9/26/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <unistd.h>


int exclude_noc(char *input1, char *input2, char *output, const int n_marker, const int row, const int sim, const int noc){
    /*compress numeric format to binary files*/
    int i=0, j=0, k=0, p=0, temp1=0;
    
    FILE *fp_g=NULL, *fp_sim=NULL, *fp_r=NULL;
    char fileName_temp[1000] = "";
    
    strcpy (fileName_temp,input1);
    strcat (fileName_temp,".traw");
    if((fp_g=fopen(fileName_temp,"r"))==NULL){
        printf("The genotype file doesn't exist!\n");
        return -1;
    }
    strcpy (fileName_temp,input2);
    strcat (fileName_temp,".sim");
    if((fp_sim=fopen(fileName_temp,"r"))==NULL){
        printf("The sim_index file doesn't exist!\n");
        return -1;
    }
    strcpy (fileName_temp,output);
    strcat (fileName_temp,".exclude_NOC.txt");
    if((fp_r=fopen(fileName_temp,"w+"))==NULL){
        printf("The output file isn't exist!\n");
        return -1;
    }
    
    int *buf = (int*)calloc(row*2+10000, sizeof(int));
        char *temp = (char*)calloc(row*2+10000, sizeof(char));
        int *sample_sim = (int*)calloc(sim*noc*2+10000, sizeof(int));
        int *sim_out_temp = (int*)calloc(sim*2+10000, sizeof(int));
        int *sample_sim_out = (int*)calloc(sim*row+10000, sizeof(int));//for exclude noc
    
    
    for (j = 0; j < sim; j++){
        for (k = 0; k < noc; k++){
            fscanf(fp_sim,"%d" ,&sample_sim[j*noc+k]);
            
        }
    }
    for (j = 0; j < sim; j++){
        for (i = 0; i < row; i++)
        sample_sim_out[row*j+i]=0;
    }
    for (i = 0; i < row+6; i++)
        fscanf(fp_g,"%s" ,temp);
    for (p = 0; p < n_marker; p++ ){
        for (i = 0; i < 6; i++) {
            fscanf(fp_g,"%s" ,temp);
//            printf("%s\n",temp);
            
        }
        for (i = 0; i < row; i++) {
            fscanf(fp_g,"%d" , &buf[i]);
    //        fprintf(fp_m, "%s\n", temp);
//            printf("%s\n",&buf[i]);
//            printf("%d\n",i);
        }
        for (j = 0; j < sim; j++){
            temp1=0;
            for (k = 0; k < noc; k++){
                
                if (buf[sample_sim[j*noc+k]-1]==1){
                    temp1++;
                }
                else if (buf[sample_sim[j*noc+k]-1]==2){
                    temp1=temp1+2;
                }
            }
//            if(temp1>0 && temp1<noc*2){
//                sample_sim_out[j]++;//for include noc
//            }
            
            if(temp1==0){
                for(k = 0; k < row; k++){
                    if(buf[k]==1 || buf[k]==2){
                        sample_sim_out[row*j+k]++;//for exclude noc
                    }
                    
                }
            }
            else if(temp1==noc*2){
                for(k = 0; k < row; k++){
                    if(buf[k]==1 || buf[k]==0)
                    sample_sim_out[row*j+k]++;//for exclude noc
                }
            }
        }
    }
    
    for (j = 0; j < sim; j++){
        for (i = 0; i < row-1; i++)
            fprintf(fp_r, "%d\t", sample_sim_out[row*j+i]);
        i=row-1;
        fprintf(fp_r, "%d\n", sample_sim_out[row*j+i]);
        
    }
    
    free(buf);
    free(temp);
    free(sample_sim);
    free(sim_out_temp);
    free(sample_sim_out);
    fclose(fp_g);
    fclose(fp_sim);
    fclose(fp_r);
    printf("The simulation is done!\n");
    return 0;
}

int het_count(char *input1, char *input2, char *output, const int n_marker, const int row, const int sim, const int noc){
    /*compress numeric format to binary files*/
    int i=0, j=0, k=0, p=0, temp1=0;
    
    FILE *fp_g=NULL, *fp_sim=NULL, *fp_r=NULL;
    char fileName_temp[1000] = "";
    
    strcpy (fileName_temp,input1);
    strcat (fileName_temp,".traw");
    if((fp_g=fopen(fileName_temp,"r"))==NULL){
        printf("The genotype file doesn't exist!\n");
        return -1;
    }
    strcpy (fileName_temp,input2);
    strcat (fileName_temp,".sim");
    if((fp_sim=fopen(fileName_temp,"r"))==NULL){
        printf("The sim_index file doesn't exist!\n");
        return -1;
    }
    strcpy (fileName_temp,output);
    strcat (fileName_temp,".het_count.txt");
    if((fp_r=fopen(fileName_temp,"w+"))==NULL){
        printf("The output file isn't exist!\n");
        return -1;
    }
    
    int *buf = (int*)calloc(row*2+10000, sizeof(int));
        char *temp = (char*)calloc(row*2+10000, sizeof(char));
        int *sample_sim = (int*)calloc(sim*noc*2+10000, sizeof(int));
        int *sim_out_temp = (int*)calloc(sim*2+10000, sizeof(int));
        int *sample_sim_out = (int*)calloc(sim*row+10000, sizeof(int));//for exclude noc
    
    
    for (j = 0; j < sim; j++){
        for (k = 0; k < noc; k++){
            fscanf(fp_sim,"%d" ,&sample_sim[j*noc+k]);
            
        }
    }
    for (j = 0; j < sim; j++){
        for (i = 0; i < row; i++)
        sample_sim_out[row*j+i]=0;
    }
    for (i = 0; i < row+6; i++)
        fscanf(fp_g,"%s" ,temp);
    for (p = 0; p < n_marker; p++ ){
        for (i = 0; i < 6; i++) {
            fscanf(fp_g,"%s" ,temp);
//            printf("%s\n",temp);
            
        }
        for (i = 0; i < row; i++) {
            fscanf(fp_g,"%d" , &buf[i]);
    //        fprintf(fp_m, "%s\n", temp);
//            printf("%s\n",&buf[i]);
//            printf("%d\n",i);
        }
        for (j = 0; j < sim; j++){
            temp1=0;
            for (k = 0; k < noc; k++){
                
                if (buf[sample_sim[j*noc+k]-1]==1){
                    temp1++;
                }
                else if (buf[sample_sim[j*noc+k]-1]==2){
                    temp1=temp1+2;
                }
            }
            if(temp1>0 && temp1<noc*2){
                sample_sim_out[j]++;//for include noc
            }
        }
    }
    
    for (j = 0; j < sim; j++){
        fprintf(fp_r, "%d\n", sample_sim_out[j]);
    }
    
    free(buf);
    free(temp);
    free(sample_sim);
    free(sim_out_temp);
    free(sample_sim_out);
    fclose(fp_g);
    fclose(fp_sim);
    fclose(fp_r);
    printf("The simulation is done!\n");
    return 0;
}


int main(int argc, char * argv[]) {
    char *fileName_input1 = "/Users/mh0986/Downloads/test";//target file name
    char *fileName_input2 = "/Users/mh0986/Downloads/sim1000_noc10";//data base file name
    char *fileName_output = "/Users/mh0986/Downloads/myMix";
    
    int i=0, n_marker=60000, row=2504, sim=1000, noc=10, type=1;
    
    char *s1, *s2, *s3, *s4, *s5, *s6, *s7, *s8;
    s1 = "--data";
    s2 = "--sim_index";
    s3 = "--out";
    s4 = "--snp";// type=1 means bcf(gvcf); type=2 means vcf;
    s5 = "--sample";//run=1 means loop the file list one by one; run=2 means conduct two input file only;
    s6 = "--sim_round";
    s7 = "--noc_number";
    s8 = "--type";
    
    for (i = 0; i < argc; i++) {
        if (strncmp(s1, argv[i], 6)==0) {
            fileName_input1 = argv[i+1];
//            printf(" --file %s\n", fileName_input1);
            fileName_output= argv[i+1];
        }
        if (strncmp(s2, argv[i], 11)==0) {
            fileName_input2 = argv[i+1];
//            printf(" --data %s\n", fileName_input2);
            fileName_output= argv[i+1];
        }
        if (strncmp(s3, argv[i], 5)==0) {
            fileName_output = argv[i+1];
//            printf(" --out %s\n", fileName_output);
        }
        if (strncmp(s4, argv[i], 5)==0) {
            n_marker = atoi(argv[i+1]);
//            printf(" --format %d\n", type);
        }
        if (strncmp(s5, argv[i], 8)==0) {
            row = atoi(argv[i+1]);
//            printf(" --module %d\n", run);
        }
        if (strncmp(s6, argv[i], 11)==0) {
            sim = atoi(argv[i+1]);
//            printf(" --path_app %s\n", path_input1);
        }
        if (strncmp(s7, argv[i], 12)==0) {
            noc = atoi(argv[i+1]);
//            printf(" --path_temp %s\n", path_input2);
        }
        if (strncmp(s8, argv[i], 6)==0) {
            type = atoi(argv[i+1]);
//            printf(" --path_temp %s\n", path_input2);
        }
    }
    
    
    
    if (type == 1){
        
        if (exclude_noc(fileName_input1, fileName_input2, fileName_output, n_marker, row, sim, noc)!=0) {
            printf("\nThe exclude_noc can't be finished!\n");
            return -1;
        }
    }
    
    if (type == 2){
        
        if (het_count(fileName_input1, fileName_input2, fileName_output, n_marker, row, sim, noc)!=0) {
            printf("\nThe het_count can't be finished!\n");
            return -1;
        }
    }
    
    return 0;
}


