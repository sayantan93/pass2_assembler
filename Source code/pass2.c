#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<ctype.h>
#include<memory.h>
#include<string.h>
#include "reg.c"
#include "instra.c"
int l=0,lb=0;
int checkHex(char *str)
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

char* appendLeft(char *address)
{
	int len,n;
	char *add;
	add = (char *)malloc(sizeof(char)*20);
	len=strlen(address);
	for(n=0;n<(20-len);n++)
		add[n]='0';
	add[n]='\0';
	strcat(add,address);

	return add;
}
char* toBin(int dec){
	int decimalNumber,remainder,quotient;
	
    int i=0,j,m;
    char *bin, temp;
    bin = (char *)malloc(sizeof(char)*50);
    decimalNumber=dec;
    quotient = decimalNumber;
    while(quotient!=0){

         bin[i]= (char) (quotient % 2 + (int)'0');
         quotient = quotient / 2;
				 i++;
    }
		bin[i]='\0';

		for(j=0, i = i -1; j <= i; j++, i--){
			temp = bin[j];
			bin[j] = bin[i];
			bin[i] = temp;
		}
    return bin;
}

char* hextoBin(char*hex){
    char *binaryNumber,*hexaDecimal,*bin;
    long int i=0;
	int n,len;
	binaryNumber = (char *)malloc(sizeof(char)*20);
	hexaDecimal = (char *)malloc(sizeof(char)*10);
	bin = (char *)malloc(sizeof(char)*20);
	hexaDecimal=hex;
	binaryNumber[0]='\0';
    while(hexaDecimal[i]){
         switch(hexaDecimal[i]){
             case '0': strcat(binaryNumber,"0000");
						break;
             case '1': strcat(binaryNumber,"0001"); 
						break;
             case '2': strcat(binaryNumber,"0010");
						break;
             case '3': strcat(binaryNumber,"0011");	
						break;
             case '4': strcat(binaryNumber,"0100"); 
						break;
             case '5': strcat(binaryNumber,"0101"); 
						break;
             case '6': strcat(binaryNumber,"0110"); 
						break;
             case '7': strcat(binaryNumber,"0111"); 
						break;
             case '8': strcat(binaryNumber,"1000"); 
						break;
             case '9': strcat(binaryNumber,"1001"); 
						break;
             case 'A': strcat(binaryNumber,"1010");
						break;
             case 'B': strcat(binaryNumber,"1011");
						break;
             case 'C': strcat(binaryNumber,"1100");		
						break;
             case 'D': strcat(binaryNumber,"1101"); 
						break;
             case 'E': strcat(binaryNumber,"1110"); 	
						break;
             case 'F': strcat(binaryNumber,"1111"); 
						break;
             case 'a': strcat(binaryNumber,"1010");
						break;
             case 'b': strcat(binaryNumber,"1011");
						break;
             case 'c': strcat(binaryNumber,"1100");
						break;
             case 'd': strcat(binaryNumber,"1101");
						break;
             case 'e': strcat(binaryNumber,"1110");
						break;
             case 'f': strcat(binaryNumber,"1111"); 
						break;
             default:  printf("\nInvalid hexadecimal digit %c ",hexaDecimal[i]); return 0;
         }
         i++;
    } 
	len=strlen(binaryNumber);
	for(n=0;n<(16-len);n++)
		bin[n]='0';
	bin[n]='\0';
	strcat(bin,binaryNumber);
    return bin;
}

void append()
{
	FILE *fp,*out;
	char *token,*str;
	int i,j,len;
	str = (char *)malloc(sizeof(char)*80);
	fp=fopen("onlymcode.txt","r");
	out=fopen("machinecode.txt","w");
	if(fp==NULL)
	{
		printf("error in oprnig file");
	}

	while( fgets(str,40,fp)!=NULL)
	{
		len=strlen(str);
		if(len>1)
		{
			for(i=len-1;i<32;i++)
			{
				str[i]='0';
			}
			str[i]='\0';
			fprintf(out,"%s\n",str);
		}
	}
}


typedef struct label
{
	char *labels,*mad;
}label;

int main(int argc, char *argv[])
{
	FILE *fp,*opfp,*omc,*mc,*testf;
	int test,n,c,ln,i,m,m1,m2,b,flag=0,len,last,digit=0,var,id=0,f,flen=0;
	long int madd=0;
	char ch,*nem[4],*str,*token,*s=" ",state,*str1,*s1="\t",*token1,*temp,*token2,c1;//*labels[10]

	str = (char *)malloc(sizeof(char)*50);
	str1 = (char *)malloc(sizeof(char)*50);
	token1 = (char *)malloc(sizeof(char)*50);
	token2 = (char *)malloc(sizeof(char)*50);
	register_init();
	instr_init();
	opfp = fopen("stable.txt","r"); 
	if(opfp == NULL) 
	{
		perror("Error while opening the file.\n");
		exit(EXIT_FAILURE);
	}

	//printf("file name %s\n", argv[1]);
	fp = fopen(argv[1],"r"); // opens file
	testf = fopen(argv[1],"r");
	omc = fopen("mcode.txt","w"); 
	mc= fopen("onlymcode.txt","w"); 

	if(fp == NULL)
	{
		perror("Error while opening the file.\n");
		exit(EXIT_FAILURE);
	}
	

	label lbl[10];

	for(m1=0;m1<10;m1++)
	{
		lbl[m1].labels = (char *)malloc(sizeof(char)*10);
	}

	for(m1=0;m1<10;m1++)
	{
		lbl[m1].mad = (char *)malloc(sizeof(char)*10);
	}
	
	while( fgets(str1,50,opfp)!=NULL) 
		{
			token=strtok(str1,s1);
			while(token!=NULL)
			{
				strcpy(lbl[lb].labels,token);
				token=strtok(NULL,s1);
				strcpy(lbl[lb].mad,token);
				token=strtok(NULL,s1);
			}++lb;	
		}

	/*for(m1=0;m1<lb;m1++)
	{
		printf("Labels :: %s \t address :: %s\n",lbl[m1].labels,lbl[m1].mad);
	}
	*/
	for (c1 = getc(testf); c1 != EOF; c1 = getc(testf)){
        if (c1 == '\n') // Increment count if this character is newline
            flen++;
	}
	fclose(testf);
	while( fgets(str,50,fp)!=NULL) //line reading
	{
	
		state='X';
		if(flen==l){
			strcat(str,"\0");
		}
		if((str!="")&&((flen!=l)))
			str[strlen(str)-1]='\0';
		
		
		if(l>0)
		{
			//printf( "\n%00000007ld\t%s",madd,str );
			fprintf(omc,"\n%00000007ld\t%s",madd,str );
			madd+=32;
			state='X';
			token = strtok(str,s); // instruction name
			
			len=strlen(token);
			last=token[len-1];
			if(last==58)
			{
				token = strtok(NULL,s);
			}

			while( token != NULL )
   			{

				for(b=1;b<=4;b++) // MOV
				{
					if(strcmp(token,(ins[b].nemo))==0)
					{
						state='M';
						id=b;
						break;
					}
				}
				
				for(b=5;b<=8;b++)  // direct address
				{
					if(strcmp(token,(ins[b].nemo))==0)
					{
						state='I';
						//printf("\nMCODE : %s ",ins[b].mcode);
						fprintf(omc,"\nMCODE : %s ",ins[b].mcode);
						fprintf(mc,"\n%s",ins[b].mcode);
						break;
					}
				}
				
				for(b=9;b<=10;b++)  // ADD
				{
					if(strcmp(token,(ins[b].nemo))==0)
					{
						state='A';
						id=b;
						break;
					}
				}
				
				for(b=11;b<=13;b++)  // MUL 
				{
					if(strcmp(token,(ins[b].nemo))==0)
					{
						state='A';
						id=b;
						break;
					}
				}
				
				for(b=14;b<=15;b++)  // AND
				{
					if(strcmp(token,(ins[b].nemo))==0)
					{
						state='A';
						id=b;
						break;
					}
				}

				for(b=16;b<=18;b++)  // OR
				{
					if(strcmp(token,(ins[b].nemo))==0)
					{
						state='O';
						break;
					}
				}

				for(b=19;b<=20;b++)  // NOT
				{
					if(strcmp(token,(ins[b].nemo))==0)
					{
						state='N';
						id=b;
						break;
					}
				}

				for(b=21;b<=26;b++)  // type INS r1
				{
					if(strcmp(token,(ins[b].nemo))==0)
					{
						//printf("\nMCODE : %s ",ins[b].mcode);
						fprintf(omc,"\nMCODE : %s ",ins[b].mcode);
						fprintf(mc,"\n%s",ins[b].mcode);
						state='R';
						break;
					}
				}

				if(strcmp(token,(ins[27].nemo))==0) // compare CMP
				{
					id=28;
					state='M';
				}
				for(b=28;b<=36;b++)  // branching instruction JMP
				{
					if(strcmp(token,(ins[b].nemo))==0)
					{
						state='B';
						//printf("\nMCODE : %s ",ins[b].mcode);
						fprintf(omc,"\nMCODE : %s ",ins[b].mcode);
						fprintf(mc,"\n%s",ins[b].mcode);
						break;
					}
				}

				for(b=37;b<=40;b++) // machine control instruction
				{
					if(strcmp(token,(ins[b].nemo))==0)
					{
						state='C';
						//printf("\nMCODE : %s  ",ins[b].mcode);
						fprintf(omc,"\nMCODE : %s\n",ins[b].mcode);
						fprintf(mc,"\n%s",ins[b].mcode);
					}
				}	
				
				switch(state)
				{
	
					case 'M':
						token = strtok(NULL,s); // 1st token-------
						if(token!=NULL){
							if(token[0]==91)
							{
								token++;
								token[strlen(token)-1]='\0';
								f=4;
							}
							for(m=0;m<64;m++)
							{
								if((strcmp(token,regs[m].regi)==0))
								{	
									strcpy(token1,regs[m].address);
									strcpy(token2,regs[m].address);
									strcat(token1," ");
									token = strtok(NULL,s); // 2nd token-------
									if(token!=NULL){
										if(token[0]==91)
										{
											token++;
											token[strlen(token)-1]='\0';
											for(m1=0;m1<64;m1++)
											{
												if((strcmp(token,regs[m1].regi)==0))
												{
													strcat(token1,regs[m1].address);
													strcat(token2,regs[m1].address);
													//printf("\nMCODE : %s %s",ins[3].mcode,token1);
													fprintf(omc,"\nMCODE : %s %s\n",ins[3].mcode,token1);
													fprintf(mc,"\n%s%s",ins[3].mcode,token2);
													break;
												}
											}
											token="xx";
										}
										for(m1=0;m1<64;m1++)
										{
											if((strcmp(token,regs[m1].regi)==0))
											{
												if(f!=4)
												{
													strcat(token1,regs[m1].address);
													strcat(token2,regs[m1].address);
													//printf("\nMCODE : %s %s",ins[id].mcode,token1);
													fprintf(omc,"\nMCODE : %s %s\n",ins[id].mcode,token1);
													fprintf(mc,"\n%s%s",ins[id].mcode,token2);
													state='F';
												}
												if(f==4)
												{
													strcat(token1,regs[m1].address);
													strcat(token2,regs[m1].address);
													//printf("\nMCODE : %s %s",ins[4].mcode,token1);
													fprintf(omc,"\nMCODE : %s %s\n",ins[4].mcode,token1);
													fprintf(mc,"\n%s%s",ins[4].mcode,token2);
													f=0;
													state='F';
												}
												break;
											}
											else
											{
												if(token[0]==35)
												{
													for(var=0;var<lb;var++)
													{
														if(strcmp(lbl[var].labels,token)==0)
														{
															lbl[var].mad[strlen(lbl[var].mad)-1]='\0';
															strcat(token1,appendLeft(toBin(atoi(lbl[var].mad))));
															strcat(token2,appendLeft(toBin(atoi(lbl[var].mad))));
															//printf("\nMCODE : %s %s",ins[++id].mcode,token1);
															fprintf(omc,"\nMCODE : %s %s\n",ins[id].mcode,token1);
															fprintf(mc,"\n%s%s",ins[id].mcode,token2);
															token++;
															break;
														}
													}
												}
											}
											
										}
										token = strtok(NULL,s);
										if(token!=NULL){state='X';break;}
										
									}break;
								}
							}
						}	
						
						break;
					case 'I':
						
							token = strtok(NULL,s); // 1st token-------
							if(token!=NULL){
								for(m=0;m<64;m++)
								{
									if((strcmp(token,regs[m].regi)==0))
									{	
										//printf("%s ",regs[m].address);
										fprintf(omc,"%s ",regs[m].address);
										fprintf(mc,"%s",regs[m].address);
										break;
									}
								}
							}
							token = strtok(NULL,s); // 2nd token-------
							//printf("%s",hextoBin(token));
							fprintf(omc,"%s\n",hextoBin(token));
							fprintf(mc,"%s",hextoBin(token));
						break;
					case 'A':
							token = strtok(NULL,s);//1st token
							for(m=0;m<64;m++)
							{
								if((strcmp(token,regs[m].regi)==0))
								{
									strcpy(token1,regs[m].address);
									strcpy(token2,regs[m].address);
									strcat(token1," ");
									token = strtok(NULL,s);//2nd token
									if(token[0]==91)
									{
										token++;
										token[strlen(token)-1]='\0';
										id++;
										f=6;
									}
									for(m1=0;m1<64;m1++)
									{
										if((strcmp(token,regs[m1].regi)==0))
										{
											strcat(token1,regs[m1].address);
											strcat(token2,regs[m1].address);
											if(f==6){
												//printf("\nMCODE : %s %s",ins[id].mcode,token1);
												fprintf(omc,"\nMCODE : %s %s\n",ins[id].mcode,token1);
												fprintf(mc,"\n%s%s",ins[id].mcode,token2);
												f=0;
												break;
											}
											token = strtok(NULL,s);//3rd token
											for(m2=0;m2<64;m2++)
											{
												if((strcmp(token,regs[m2].regi)==0))
												{
													strcat(token1," ");
													strcat(token1,regs[m2].address);
													strcat(token2,regs[m2].address);
													//printf("\nMCODE : %s %s",ins[id].mcode,token1);
													fprintf(omc,"\nMCODE : %s %s\n",ins[id].mcode,token1);
													fprintf(mc,"\n%s%s",ins[id].mcode,token2);
													break;
												}
											}
											break;
										}
									}
									break;
								}
							}
						break;
					case 'O':
							token = strtok(NULL,s);//1st token
							for(m=0;m<64;m++)
							{
								if((strcmp(token,regs[m].regi)==0))
								{
									strcpy(token1,regs[m].address);
									strcpy(token2,regs[m].address);
									strcat(token1," ");
									token = strtok(NULL,s);//2nd token
									if(token[0]==91)
									{
										token++;
										token[strlen(token)-1]='\0';
										id++;
										id++;
										f=6;
									}
									if(checkHex(token)==1)	
									{
										id++;
										//printf("\nMCODE : %s %s %s",ins[id].mcode,token1,hextoBin(token));
										fprintf(omc,"\nMCODE : %s %s %s\n",ins[id].mcode,token1,hextoBin(token));
										fprintf(mc,"\n%s%s%s",ins[id].mcode,token2,hextoBin(token));
										break;
									}
									for(m1=0;m1<64;m1++)
									{
										if((strcmp(token,regs[m1].regi)==0))
										{
											strcat(token1,regs[m1].address);
											strcat(token2,regs[m1].address);
											strcat(token1," ");
											if(f==6){
												//printf("\nMCODE : %s %s",ins[id].mcode,token1);
												fprintf(omc,"\nMCODE : %s %s\n",ins[id].mcode,token1);
												fprintf(mc,"\n%s%s",ins[id].mcode,token2);
												f=0;
												break;
											}
											token = strtok(NULL,s);//3rd token
											for(m2=0;m2<64;m2++)
											{
												if((strcmp(token,regs[m2].regi)==0))
												{
													//puts(token);
													strcat(token1,regs[m2].address);//puts(token1);
													strcat(token2,regs[m2].address);
													//printf("\nMCODE : %s %s",ins[id].mcode,token1);
													fprintf(omc,"\nMCODE : %s %s\n",ins[id].mcode,token1);
													fprintf(mc,"\n%s%s",ins[id].mcode,token2);
													break;
												}
											}
											break;
										}
									}
									break;
								}
							}
						break;
					case 'N':
							token = strtok(NULL,s); // 1st token-------
							if(token!=NULL){
								if(token[0]==91)
								{
									token++;
									token[strlen(token)-1]='\0';
									id++;
								}
								for(m=0;m<64;m++)
								{
									if((strcmp(token,regs[m].regi)==0))
									{	
										//printf("\nMCODE : %s %s",ins[id].mcode,regs[m].address);
										fprintf(omc,"\nMCODE : %s %s\n",ins[id].mcode,regs[m].address);
										fprintf(mc,"\n%s%s",ins[id].mcode,regs[m].address);
										break;
									}
								}
							}
						break;
					case 'R':
							token = strtok(NULL,s); // 1st token-------
							if(token!=NULL){
								for(m=0;m<64;m++)
								{
									if((strcmp(token,regs[m].regi)==0))
									{	
										//printf("%s",regs[m].address);
										fprintf(omc,"%s\n",regs[m].address);
										fprintf(mc,"%s",regs[m].address);
										break;
									}
								}
							}
						break;
					case 'B':
						token = strtok(NULL,s); // 1st token-------
						if(token!=NULL){
							for(m1=0;m1<lb;m1++)
							{
								if(strcmp(lbl[m1].labels,token)==0)
								{
									lbl[m1].mad[strlen(lbl[m1].mad)-1]='\0';
									//printf("%s",appendLeft(toBin(atoi(lbl[m1].mad))));
									fprintf(omc,"%s\n",appendLeft(toBin(atoi(lbl[m1].mad))));
									fprintf(mc,"%s",appendLeft(toBin(atoi(lbl[m1].mad))));
									break;
								}
									if(m1==lb-1)
									{
										printf("\nError in code!!No lebel found in jump instruction at line %d !! Exit from program !!",l+1);
										exit(0);
									}
							}
							if(lb==0)
							{
								printf("\nError in code!!No lebel found in jump instruction at line %d !! Exit from program !!",l+1);
								exit(0);
							}
						}
						break;

					default:
						state='X';	
				}	
				token = strtok(NULL,s);
				break;
			}
		}
		l++;
	}
	printf("compilation successful :D ");
	fclose(fp);
	fclose(opfp);
	fclose(mc);
	append();
	return 0;
}
