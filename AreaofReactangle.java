import  java.util.Scanner ;
class ReactangleArea {
public static void main (String [] args ) 
{
 Scanner sc =new Scanner (System.in ) ;
 System.out.println("Enter  the length : ") ;
 int length = sc.nextInt () ;
 
 System.out.println ("Enter the breadth :") ;
 int breadth = sc.nextInt () ;
 
 System.out.println ("Enter the  roll number  :") ;
 int rollNo = sc.nextInt () ;
 
 length = length * rollNo ;
 breadth = breadth * rollNo ;
 
 int area = length * breadth ;
 System.out.println ("Area of Reactangle = " + area ) ;
 }
 }
