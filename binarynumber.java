import java.util.Scanner ;
class binary
{
public static void main (String [] args )
{
Scanner sc = new Scanner (System .in );
System.out.println ("Enter the number : " ) ;
int num = sc.nextInt () ;

int binary = 0 ;
int place = 1 ;
while (num > 0 )
{
 int remainder = num % 2 ;
 binary = binary + remainder * place ;
 num = num / 2 ;
 }
  System.out.println("Binary number = " + binary ) ;
  }
}
