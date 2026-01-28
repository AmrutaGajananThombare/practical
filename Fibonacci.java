import java.util.Scanner ;
class Fibonacci 
{
public static void main (String [] args ) 
{
Scanner sc = new Scanner (System .in ) ;

System.out.println ("Enter the roll number : " ) ;
int rollNo = sc.nextInt () ;

int a = 0, b = 1 ;
System.out.println ("Fibonacci series : " ) ;
while (a <= rollNo )
{
System.out.println (a+ " " ) ;
int c = a + b ;
a = b ;
b = c ;
}
}
} 
