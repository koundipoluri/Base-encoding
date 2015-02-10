#include <stdio.h>

unsigned char hexchar(int i)
{
	unsigned char hexchar_arr[]="0123456789abcdef";
	return hexchar_arr[i];
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
void Base64_to_hex(unsigned char* in,size_t inlen,unsigned char* out,size_t outlen)
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
int main()
{
	unsigned char x[]="UKXO5d/Fazj28j4Hutlm/w==";
	unsigned char *y = calloc(32,1);
	
	Base64_to_hex(x,strlen(x),y,32);
	printf("y string is %s\n",y);
	return 0;
}
