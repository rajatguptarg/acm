#include <stdio.h>
/*
  WARNING: I PRINT SOME BINARY DATA, YOU MIGHT CONSIDER REDIRECTING MY STANDARD OUTPUT TO A FILE
*/

int len=48;
char data[] = "B80C75E6E384F73B9DF31C264FDC664F818E3329DDCB4DB6";
int x[]={2,4,4,6,1,3,0,0};
int y[]={14,14,14,14,7,7,14,42};
int r=5;

void R(int r, char *D) {
int cnt=0;
    for(int i=0; i<r; i++)
    for(char *q=D;*q;q+=2) { char c1,c2; sscanf(q,"%c%c",&c1,&c2); printf("%c",(((c1>64)?(c1-55):(c1-48))<<4)|((c2>64)?(c2-55):(c2-48))); cnt++; }
}

void Rl(int r, long int l) {
    char s[10];
    sprintf(s,"%02X%02X%02X%02X",(int)(l&0xff),(int)((l>>8)&0xff),(int)((l>>16)&0xff),(int)((l>>24)&0xff));
    R(r,s);
}

int main(void) {
    char *q=data;
    int st=0;
    long int l=0;

    for (int i=0; i<len*4/3; i++) {
        char b=0;
        switch (st) {
    	    case 0: b=(*q>64)?((*q-55)>>1):((*q-48)>>1); break;
    	    case 1: b=((*q>64)?((*q-55)&1):((*q-48)&1))<<2; q++; b|=((*q>64)?((*q-55)>>2):((*q-48)>>2)); break;
    	    case 2: b=((*q>64)?((*q-55)&3):((*q-48)&3))<<1; q++; b|=((*q>64)?((*q-55)>>3):((*q-48)>>3)); break;
    	    case 3: b=((*q>64)?((*q-55)&7):((*q-48)&7)); q++; break;
        }
        st=(st+1)%4;
	l+=(long)(x[(int)b]*199) + (long)(y[(int)b]*30);
    }
    
    R(1,"52494646");
    Rl(1,l*r+36);
    R(1,"57415645666D74201000000001000100112B0000112B00000100080064617461");
    Rl(1,l*r);

    st=0;
    q=data;    
    for (int i=0; i<len*4/3; i++) {
        char b=0;
        switch (st) {
    	    case 0: b=(*q>64)?((*q-55)>>1):((*q-48)>>1); break;
    	    case 1: b=((*q>64)?((*q-55)&1):((*q-48)&1))<<2; q++; b|=((*q>64)?((*q-55)>>2):((*q-48)>>2)); break;
    	    case 2: b=((*q>64)?((*q-55)&3):((*q-48)&3))<<1; q++; b|=((*q>64)?((*q-55)>>3):((*q-48)>>3)); break;
    	    case 3: b=((*q>64)?((*q-55)&7):((*q-48)&7)); q++; break;
        }
      
        switch (b) {
	    case 0: R(r*1,"809FBDD7EBF9FFFDF4E3CBAF907051351E0C0200051327405E7E9DBBD6EA"
		 	  "F9FFFEF4E4CDB1927253371F0D02000512253F5C7C9CBAD4E9F8FFFEF5E5"
			  "CEB394745538200E03000411243D5A7A9AB8D3E8F7FFFEF6E6D0B4967656"
			  "3A210F03000410233C597898B7D2E7F7FFFEF6E7D1B69878583B22100400"
			  "030F223A577696B5D0E6F6FEFFF7E8D2B899795A3D24100400030E203955"
			  "7595B3CFE5F5FEFFF8E9D4B99B7B5C3E25110500030D1F37547393B2CDE4"
			  "F5FEFFF8EAD5BB9D7D5D4026120500020C1E36");
		    R(r*7,"807F8080807F7F80807F7F7E80807E807F80807F808080807F7F7F80807F");
		    R(r*1,"809FBDD7EBF9FFFDF4E3CBAF907051351E0C0200051327405E7E9DBBD6EA"
		 	  "F9FFFEF4E4CDB1927253371F0D02000512253F5C7C9CBAD4E9F8FFFEF5E5"
			  "CEB394745538200E03000411243D5A7A9AB8D3E8F7FFFEF6E6D0B4967656"
			  "3A210F03000410233C597898B7D2E7F7FFFEF6E7D1B69878583B22100400"
			  "030F223A577696B5D0E6F6FEFFF7E8D2B899795A3D24100400030E203955"
			  "7595B3CFE5F5FEFFF8E9D4B99B7B5C3E25110500030D1F37547393B2CDE4"
			  "F5FEFFF8EAD5BB9D7D5D4026120500020C1E36");
		    R(r*7,"807F8080807F7F80807F7F7E80807E807F80807F808080807F7F7F80807F");
		    break;

	    case 1: R(r*1,"809FBDD7EBF9FFFDF4E3CBAF907051351E0C0200051327405E7E9DBBD6EA"
		 	  "F9FFFEF4E4CDB1927253371F0D02000512253F5C7C9CBAD4E9F8FFFEF5E5"
			  "CEB394745538200E03000411243D5A7A9AB8D3E8F7FFFEF6E6D0B4967656"
			  "3A210F03000410233C597898B7D2E7F7FFFEF6E7D1B69878583B22100400"
			  "030F223A577696B5D0E6F6FEFFF7E8D2B899795A3D24100400030E203955"
			  "7595B3CFE5F5FEFFF8E9D4B99B7B5C3E25110500030D1F37547393B2CDE4"
			  "F5FEFFF8EAD5BB9D7D5D4026120500020C1E36");
		    R(r*7,"807F8080807F7F80807F7F7E80807E807F80807F808080807F7F7F80807F");
		    R(r*3,"809FBDD7EBF9FFFDF4E3CBAF907051351E0C0200051327405E7E9DBBD6EA"
		 	  "F9FFFEF4E4CDB1927253371F0D02000512253F5C7C9CBAD4E9F8FFFEF5E5"
			  "CEB394745538200E03000411243D5A7A9AB8D3E8F7FFFEF6E6D0B4967656"
			  "3A210F03000410233C597898B7D2E7F7FFFEF6E7D1B69878583B22100400"
			  "030F223A577696B5D0E6F6FEFFF7E8D2B899795A3D24100400030E203955"
			  "7595B3CFE5F5FEFFF8E9D4B99B7B5C3E25110500030D1F37547393B2CDE4"
			  "F5FEFFF8EAD5BB9D7D5D4026120500020C1E36");
		    R(r*7,"807F8080807F7F80807F7F7E80807E807F80807F808080807F7F7F80807F");
		    break;

	    case 2: R(r*3,"809FBDD7EBF9FFFDF4E3CBAF907051351E0C0200051327405E7E9DBBD6EA"
		 	  "F9FFFEF4E4CDB1927253371F0D02000512253F5C7C9CBAD4E9F8FFFEF5E5"
			  "CEB394745538200E03000411243D5A7A9AB8D3E8F7FFFEF6E6D0B4967656"
			  "3A210F03000410233C597898B7D2E7F7FFFEF6E7D1B69878583B22100400"
			  "030F223A577696B5D0E6F6FEFFF7E8D2B899795A3D24100400030E203955"
			  "7595B3CFE5F5FEFFF8E9D4B99B7B5C3E25110500030D1F37547393B2CDE4"
			  "F5FEFFF8EAD5BB9D7D5D4026120500020C1E36");
		    R(r*7,"807F8080807F7F80807F7F7E80807E807F80807F808080807F7F7F80807F");
		    R(r*1,"809FBDD7EBF9FFFDF4E3CBAF907051351E0C0200051327405E7E9DBBD6EA"
		 	  "F9FFFEF4E4CDB1927253371F0D02000512253F5C7C9CBAD4E9F8FFFEF5E5"
			  "CEB394745538200E03000411243D5A7A9AB8D3E8F7FFFEF6E6D0B4967656"
			  "3A210F03000410233C597898B7D2E7F7FFFEF6E7D1B69878583B22100400"
			  "030F223A577696B5D0E6F6FEFFF7E8D2B899795A3D24100400030E203955"
			  "7595B3CFE5F5FEFFF8E9D4B99B7B5C3E25110500030D1F37547393B2CDE4"
			  "F5FEFFF8EAD5BB9D7D5D4026120500020C1E36");
		    R(r*7,"807F8080807F7F80807F7F7E80807E807F80807F808080807F7F7F80807F");
		    break;

	    case 3: R(r*3,"809FBDD7EBF9FFFDF4E3CBAF907051351E0C0200051327405E7E9DBBD6EA"
		 	  "F9FFFEF4E4CDB1927253371F0D02000512253F5C7C9CBAD4E9F8FFFEF5E5"
			  "CEB394745538200E03000411243D5A7A9AB8D3E8F7FFFEF6E6D0B4967656"
			  "3A210F03000410233C597898B7D2E7F7FFFEF6E7D1B69878583B22100400"
			  "030F223A577696B5D0E6F6FEFFF7E8D2B899795A3D24100400030E203955"
			  "7595B3CFE5F5FEFFF8E9D4B99B7B5C3E25110500030D1F37547393B2CDE4"
			  "F5FEFFF8EAD5BB9D7D5D4026120500020C1E36");
		    R(r*7,"807F8080807F7F80807F7F7E80807E807F80807F808080807F7F7F80807F");
		    R(r*3,"809FBDD7EBF9FFFDF4E3CBAF907051351E0C0200051327405E7E9DBBD6EA"
		 	  "F9FFFEF4E4CDB1927253371F0D02000512253F5C7C9CBAD4E9F8FFFEF5E5"
			  "CEB394745538200E03000411243D5A7A9AB8D3E8F7FFFEF6E6D0B4967656"
			  "3A210F03000410233C597898B7D2E7F7FFFEF6E7D1B69878583B22100400"
			  "030F223A577696B5D0E6F6FEFFF7E8D2B899795A3D24100400030E203955"
			  "7595B3CFE5F5FEFFF8E9D4B99B7B5C3E25110500030D1F37547393B2CDE4"
			  "F5FEFFF8EAD5BB9D7D5D4026120500020C1E36");
		    R(r*7,"807F8080807F7F80807F7F7E80807E807F80807F808080807F7F7F80807F");
		    break;

	    case 4: R(r*1,"809FBDD7EBF9FFFDF4E3CBAF907051351E0C0200051327405E7E9DBBD6EA"
		 	  "F9FFFEF4E4CDB1927253371F0D02000512253F5C7C9CBAD4E9F8FFFEF5E5"
			  "CEB394745538200E03000411243D5A7A9AB8D3E8F7FFFEF6E6D0B4967656"
			  "3A210F03000410233C597898B7D2E7F7FFFEF6E7D1B69878583B22100400"
			  "030F223A577696B5D0E6F6FEFFF7E8D2B899795A3D24100400030E203955"
			  "7595B3CFE5F5FEFFF8E9D4B99B7B5C3E25110500030D1F37547393B2CDE4"
			  "F5FEFFF8EAD5BB9D7D5D4026120500020C1E36");
		    R(r*7,"807F8080807F7F80807F7F7E80807E807F80807F808080807F7F7F80807F");
		    break;

	    case 5: R(r*3,"809FBDD7EBF9FFFDF4E3CBAF907051351E0C0200051327405E7E9DBBD6EA"
		 	  "F9FFFEF4E4CDB1927253371F0D02000512253F5C7C9CBAD4E9F8FFFEF5E5"
			  "CEB394745538200E03000411243D5A7A9AB8D3E8F7FFFEF6E6D0B4967656"
			  "3A210F03000410233C597898B7D2E7F7FFFEF6E7D1B69878583B22100400"
			  "030F223A577696B5D0E6F6FEFFF7E8D2B899795A3D24100400030E203955"
			  "7595B3CFE5F5FEFFF8E9D4B99B7B5C3E25110500030D1F37547393B2CDE4"
			  "F5FEFFF8EAD5BB9D7D5D4026120500020C1E36");
		    R(r*7,"807F8080807F7F80807F7F7E80807E807F80807F808080807F7F7F80807F");
		    break;

	    case 6: R(r*14,"807F8080807F7F80807F7F7E80807E807F80807F808080807F7F7F80807F");
		    break;

	    case 7: R(r*42,"807F8080807F7F80807F7F7E80807E807F80807F808080807F7F7F80807F");
		    break;
	}
        st=(st+1)%4;
    }
}
