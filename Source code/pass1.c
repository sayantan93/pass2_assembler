#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<ctype.h>
#include<memory.h>
#include<string.h>
#include "reg.c"
#include "instra.c"
int l=0,lb=0;	
int checkHex(char *str) // checks if the token is a HEX no or not of length 4 bits
{
	int n,i,flag=0;
	n=strlen(str);
	if(n>4)
		flag=0;
	else{
		for(i=0;i<n;i++)
		{
			if((str[i]=='0')||(str[i]=='1')||(str[i]=='2')||(str[i]=='3')||(str[i]=='4')||(str[i]=='5')||(str[i]=='6')||(str[i]=='7')||(str[i]=='8')||(str[i]=='9')||(str[i]=='A')||(str[i]=='B')||(str[i]=='C')||(str[i]=='D')||(str[i]=='E')||(str[i]=='F')){
		
				flag=1;
			}
			else
			{
				flag=0;
				break;
			}
		}
	}


	return flag;
	
}



typedef struct label
{
	char *labels;
	long int mad;
}label;


int main(int argc, char *argv[])
{
	FILE *fp,*opfp,*testf;
	int test,n,c,ln,i,m,m1,m2,b,flag=0,flag1=1,len,last,first,dig,id,errorflag=0,flen=0;
	long int madd=0000000,mm=1048575;
	label lbl[10];
	char ch,*nem[4],*str,*token,*token1,*token2,*token3,*s=" ",state,c1;

	str = (char *)malloc(sizeof(char)*50);
	token1 = (char *)malloc(sizeof(char)*10);
	token2 = (char *)malloc(sizeof(char)*20);
	token3 = (char *)malloc(sizeof(char)*20);
	//printf("file name %s\n", argv[1]);
	fp = fopen(argv[1],"r"); // opens input file which contains assembly code
	testf = fopen(argv[1],"r");
	opfp = fopen("stable.txt","w");

	if( fp == NULL )
	{
		perror("Error while opening the file.\n");
		exit(EXIT_FAILURE);
	}

	for(m1=0;m1<10;m1++)
	{
		lbl[m1].labels = (char *)malloc(sizeof(char)*10);
	}
	
	register_init();
	instr_init();

	for (c1 = getc(testf); c1 != EOF; c1 = getc(testf)){
        if (c1 == '\n') // Increment count if this character is newline
            flen++;
	}
	fclose(testf);
	//printf("--%d--",flen);
	while( fgets(str,50,fp)!=NULL) //line reading
	{
	
		state='X';
		if(flen==l){
			strcat(str,"\0");
		}
		if((str!="")&&((flen!=l)))
			str[strlen(str)-1]='\0';
		if(strcmp(str,"")==0)
			strcpy(str,"BLANK LINE");
		
		if(l==0)
		{
			if(strlen(str)!=5)
			{
				printf("error in line : %d",l+1);
				errorflag=1;
			}
			strncpy(token1,str,5);//printf( "==%s",token1 );
			if(strcmp(token1,(ins[0].nemo))!=0)
			{
				printf("error in line : %d",l+1);
				errorflag=1;
			}
		}
		
		if(l>0)
		{
			//printf( "%00000007ld\t\t%s\n",madd,str );
			madd+=32;
			state='X';
			token = strtok(str,s); // instruction name
			
			len=strlen(token);
			last=token[len-1];
			if(last==58)
			{
				token[strlen(token)-1]='\0';//printf("--%s\n",token);
				strcpy(lbl[lb].labels,token);
				lbl[lb].mad=(madd-32);
				lb++;	
				token = strtok(NULL,s);
			}

			while( token != NULL )
			{
				
				for(b=1;b<=4;b++)  // data transfer (MOV)
				{
					if(strcmp(token,(ins[b].nemo))==0)
					{
						state='T';
						break;
					}
				}
	
				for(b=5;b<=8;b++)  // direct address
				{
					if(strcmp(token,(ins[b].nemo))==0)
					{
						state='I';
						break;
					}
				}
				
				for(b=9;b<=15;b++) // arithmatic instruction and AND
				{
					if(strcmp(token,(ins[b].nemo))==0)
					{
						state='A';
						id=b;
						break;
					}
				}

				for(b=16;b<=18;b++) // OR types
				{
					if(strcmp(token,(ins[b].nemo))==0)
					{
						id=b;
						state='O';
						break;
					}
				}

				for(b=19;b<=20;b++)  // NOT
				{
					if(strcmp(token,(ins[b].nemo))==0)
					{
						state='N';
						break;
					}
				}
				
				for(b=21;b<=26;b++)  // type INS r1
				{
					if(strcmp(token,(ins[b].nemo))==0)
					{
						state='R';
						break;
					}
				}

				if(strcmp(token,(ins[27].nemo))==0) // compare CMP
				{
					state='P';
				}
				for(b=28;b<=36;b++)  // branching instruction
				{
					if(strcmp(token,(ins[b].nemo))==0)
					{
						state='B';
						break;
					}
				}
				
				
				for(b=37;b<=40;b++) // machine control instruction
				{
					if(strcmp(token,(ins[b].nemo))==0)
					{
						state='C';
					}
				}
		

				
				switch(state)
				{
					case 'A':
						flag1=0;
						token = strtok(NULL,s); // 1st token
						if(token!=NULL){
							for(m=0;m<64;m++)
							{
								if((strcmp(token,regs[m].regi)==0))
								{
									regs[m].used=0;
									token = strtok(NULL,s); // 2nd token
									if(token!=NULL){
										if((token[0]==91)&&(id!=13)&&(token[strlen(token)-1]==93))
										{
											flag1=1;
											token++;
											token[strlen(token)-1]='\0';
											token2 = strtok(NULL,s);
											if(token2 != NULL){
												state='X';
												break;
											}
										}
										
										for(m1=0;m1<64;m1++)
										{
											if((strcmp(token,regs[m1].regi)==0))
											{
												regs[m1].used=0;
												if(flag1==1)
													state='F';
												token = strtok(NULL,s);// 3rd token
												if((token==NULL)&&(id==13))
													state='X';
												if((token!=NULL)){
													for(m2=0;m2<64;m2++){
														if((strcmp(token,regs[m2].regi)==0)){
															regs[m2].used=0;
															state='F';
															break;
														}
														else{
															flag=0;
															state='X';
														}
													}
													token = strtok(NULL,s);
													if(token!=NULL){state='X';break;}
												}
												break;
											}
										}
									}break;
								}
							}
						}
						break;
					case 'T':
						
						token = strtok(NULL,s); // 1st token
						if(token!=NULL){
							if(token[0]==91)
							{
								if(token[strlen(token)-1]!=93)
								{
									state='X';
								}
								token++;
								token[strlen(token)-1]='\0';
							}
							for(m=0;m<64;m++)
							{
								if((strcmp(token,regs[m].regi)==0))
								{
									regs[m].used=0;
									token = strtok(NULL,s); // 2nd token
									if(token!=NULL){
										if(token[0]==91)
										{
											if(token[strlen(token)-1]!=93)
											{
												state='X';
											}
											token++;
											token[strlen(token)-1]='\0';
										}
										if(token[0]==35)
										{
											if(strlen(token)!=1)
												strcpy(lbl[lb++].labels,token);
											else{
												state='X';
												break;
											}
										}
										for(m1=0;m1<64;m1++)
										{
											
											if((strcmp(token,regs[m1].regi)==0)||(token[0]==35))
											{
												if((m1<64)&&(token[0]!=35))
												{
													regs[m1].used=0;
												}
												state='F';
												break;
											}
										}
										token = strtok(NULL,s);
										if(token!=NULL){state='X';break;}
										
									}break;
								}
							}
						}	
						break;
					case 'O':
						flag=0;
						token = strtok(NULL,s); // 1st token
						if(token!=NULL){
							for(m=0;m<64;m++)
							{
								if((strcmp(token,regs[m].regi)==0))
								{
									regs[m].used=0;
									token = strtok(NULL,s); // 2nd token
									if(token!=NULL){
										if(token[0]==91&&(token[strlen(token)-1]==93))
										{
											token++;
											token[strlen(token)-1]='\0';
											flag=2;
											token1 = strtok(NULL,s);
											if(token1 != NULL){state='X';break;}
										}
										for(m1=0;m1<64;m1++)
										{
											if((strcmp(token,regs[m1].regi)==0))
											{
												regs[m1].used=0;
												token = strtok(NULL,s);// 3rd token
												if(token!=NULL){
													for(m2=0;m2<64;m2++){
														if((strcmp(token,regs[m2].regi)==0)){
															regs[m2].used=0;
															state='F';
															break;
														}
														else{
															flag=0;
															state='X';
														}
													}
													token = strtok(NULL,s);
													if(token!=NULL){state='X';break;}
												}
												else
													state='X';
												if(flag!=0){
													state='F';
												}break;
											}
											else
											{
												if((checkHex(token)==1)){
													state='F';
													token1 = strtok(NULL,s);
													if(token1 != NULL){state='X';break;}
												}
											}
										}
									}break;
								}
							}
						}
						break;
					case 'B':
						
						token = strtok(NULL,s); // 1st token-------
						if(token!=NULL){
							state='F';
						}
						token = strtok(NULL,s);
						if(token!=NULL){state='X';}
							
						break;

					case 'P':
						token = strtok(NULL,s); // 1st token
						if(token!=NULL){
							for(m=0;m<64;m++)
							{
								if((strcmp(token,regs[m].regi)==0))
								{	
										regs[m].used=0;
										token = strtok(NULL,s); //2nd token
										if(token!=NULL){
											for(m1=0;m1<64;m1++)
											{
												if((strcmp(token,regs[m1].regi)==0))
												{
													regs[m1].used=0;
													state='F';
												}	
											}
										}
				
										break;
								}
							}
						}
						
					token = strtok(NULL,s);
					if(token!=NULL){state='X';}
					break;

					case 'I':
						
						token = strtok(NULL,s); // 1st token
						if(token!=NULL){
							for(m=0;m<64;m++)
							{
								if((strcmp(token,regs[m].regi)==0))
								{	
										regs[m].used=0;
										break;
								}
							}
						}
						token = strtok(NULL,s); // 2nd token
						if(token!=NULL){
							if(checkHex(token)==1){
								state='F';
							}
						}
						token = strtok(NULL,s);
						if(token!=NULL){state='X';}
							
						break;
					case 'R':
						
						token = strtok(NULL,s); // 1st token
						if(token!=NULL){
							for(m=0;m<64;m++)
							{
								if((strcmp(token,regs[m].regi)==0))
								{	
										regs[m].used=0;
										state='F';
										break;
								}
							}
						}
						token = strtok(NULL,s);
						if(token!=NULL){state='X';}
						break;

					case 'N':
						token = strtok(NULL,s); // 1st token
						if(token!=NULL){
							if(token[0]==91)
								{
									token++;
									token[strlen(token)-1]='\0';
								}
							for(m=0;m<64;m++)
							{
								if((strcmp(token,regs[m].regi)==0))
								{	
										regs[m].used=0;
										state='F';
										break;
								}
							}
						}
						token = strtok(NULL,s);
						if(token!=NULL){state='X';}
						break;

					case 'C':
						state='F';
						token = strtok(NULL,s);
						if(token!=NULL)
							state='X';
							
						break;
					default:
						state='X';	
				}	
				token = strtok(NULL,s);
				if(state!='F')
				{
					printf("\nerror in line : %d",l+1);
					errorflag=1;
				}
				break;
			}
		}
		l++;
	}



	for(m1=0;m1<lb;m1++)
	{
		if(lbl[m1].labels[0]==35)
		{
			lbl[m1].mad=madd;
			madd+=32;
		}
	}

	for(m1=0;m1<lb;m1++)
	{
			//printf("Labels :: %s \t address :: %ld\n",lbl[m1].labels,lbl[m1].mad);
			fprintf(opfp,"%s\t%ld\n",lbl[m1].labels,lbl[m1].mad);
	}

	fclose(fp);
	fclose(opfp);
	strcpy(token3,"pass2.exe ");
	strcat(token3,argv[1]);
	if(errorflag==0)
		system(token3);
	exit(0);
	}
