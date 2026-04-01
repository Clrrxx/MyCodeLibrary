// import java library classes
// google "java api spec" to view available classes in JDK
// Scanner class is most commonly used class to get console input and others..(check API Spec)
import java.util.Scanner;

class ClassTemplate   // class name - file name must be same as class name
{
	// for a start, use "public static" when defining your methods (function)
	// "public static" make the method global just like 'C'
	// when you have learnt OO, you will use LESS of static
   // entry into a Java program - in 'C' is int main()
   public static void main(String[] args)
   {
		Scanner myObj = new Scanner(System.in);

		System.out.print("Enter your choice here (A , C, D) => ");
		String choice = myObj.nextLine();

		switch (choice){
			case "a": 
			case "A": System.out.print("Action movie fan\n"); break;
			
			case "C":
			case "c": System.out.print("Comedy movie fan\n"); break;

			case "D":
			case "d": System.out.print("Drama movie fan\n"); break;

			default: System.out.print("Invalid option\n");
		}
		myObj.close();
		//write your code here
		// think in 'C' syntax
	  // use "System.out.println" for output display
      // "System.out.println" uses "+" to concatenate (join) String and other variable data
   }
}