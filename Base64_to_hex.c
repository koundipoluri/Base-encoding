#include <stdio.h>

unsigned char hexchar(int i)
{
	unsigned char hexchar_arr[]="0123456789abcdef";
	return hexchar_arr[i];
}
unsigned char base64char(int i)
{
	unsigned char base64char_arr[]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
	return base64char_arr[i];
}
int decval_64(unsigned char x)
{
	int y=x;
	if(x == '+')
		return 62;
	if(x == '/')
		return 63;
		
	if(65<= y && y <=90)
	return y-65;
	
	if(97<= y && y <= 122)
	return (y- 97 + 26);
	
	if (48 <= y && y <= 57)
		return y-48+52;
}
int decval_16(unsigned char x)
{
	int y= x;
	if(48<=y && y<=57)
		return y-48;
	else if(97<=y && y<=102)
		return y-97+10;
	else if(65<=y && y<=70)
		return y-65+10;
}
void base64_to_hex(unsigned char* in,size_t inlen,unsigned char* out,size_t outlen)
{
	int i=0,j=0,a,b;
	for(i=0;i<inlen;i++)
	{
		a = decval_64(in[i++]);
		b = decval_64(in[i]);
		
		out[j++] = hexchar((a>>2));
		out[j++] = hexchar(((a & 3)<<2)+(b>>4));
		out[j++] = hexchar((b & 15));
	}

}
void hex_to_base64(unsigned char* in,size_t inlen,unsigned char *out,size_t outlen)
{
		int i,j=0,a,b,c;
		for(i=0;i<inlen;i++)
		{
			a= decval_16(in[i++]);
			b= decval_16(in[i++]);
			c= decval_16(in[i]);
			
			out[j++]= base64char((a<<2) + (b>>2));
			out[j++]= base64char(((b & 3)<<4) + (c));
		}
	
}
int main()
{
	unsigned char x[]="UKXO5d/Fazj28j4Hutlm/w==";
	unsigned char u[]= "50a5cee5dfc56b38f6f23e07bad966ff";
	unsigned char *y = calloc(32,1);
	unsigned char *v = calloc(24,1);
	hex_to_base64(u,strlen(u),v,24);
	base64_to_hex(x,strlen(x),y,32);
	printf("v string is %s\n",v);
	printf("y string is %s\n",y);
	return 0;
}
